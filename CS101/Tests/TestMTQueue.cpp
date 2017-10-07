#include "StdAfx.h"
#include "TestMTQueue.h"

#include "CS101/MTQueue.h"

#include <thread>
#include <chrono>

namespace Helper
{
	struct SJob
	{
		SJob(int _id)
			: id(_id)
		{}
	
		bool operator==(const SJob& rhs) const { return id == rhs.id; }
		bool operator!=(const SJob& rhs) const { return id != rhs.id; }
		
		int         id;
		std::string debugName;
	};
	
	typedef CS101::CMTQueue<SJob> TJobs;
	
	const static SJob INVALID_JOB = SJob(-1);
	const static int  PRODUCER_DELAY_MS = 4;
	const static int  CONSUMER_DELAY_MS = 9;
	
	void Producer(TJobs& jobs)
	{
		const int jobCount = 50;
		for (int i = 1; i <= jobCount; ++i)
		{
			printf("Producer: Adding job %d.\n", i);
			
			jobs.Push(SJob(i));
			std::this_thread::sleep_for(std::chrono::milliseconds(PRODUCER_DELAY_MS));
		}
		
		// Notify consumers that we are done
		jobs.Push(INVALID_JOB);
		
		printf("--Producer done (Job count = %d)--\n", jobCount);
	}
	
	void Consumer(int consumerId, TJobs& jobs)
	{
		int consumedJobs = 0;
		while(true)
		{
			SJob nextJob = jobs.Pop();
			if (nextJob != INVALID_JOB)
			{
				consumedJobs++;
				printf("\tConsumer %d: Taking job %d.\n", consumerId, nextJob.id);
				std::this_thread::sleep_for(std::chrono::milliseconds(CONSUMER_DELAY_MS + consumerId));
			}
			else
			{
				printf("--Consumer done (Job count = %d)--\n", consumedJobs);
				jobs.Push(INVALID_JOB);
				break;
			}
		}
	}
}

void CTestMTQueue::Run()
{
	Helper::TJobs jobs;
	
	std::thread producer(Helper::Producer, std::ref(jobs));
	std::thread consumer01(Helper::Consumer, 1, std::ref(jobs));
	std::thread consumer02(Helper::Consumer, 2, std::ref(jobs));
	
	producer.join();
	consumer01.join();
	consumer02.join();
}
