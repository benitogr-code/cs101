#include "StdAfx.h"
#include "TestStringBuilder.h"

#include "CS101/StringBuilder.h"

CTestStringBuilder::CTestStringBuilder()
	: CBaseTest("StringBuilder")
{

}

void CTestStringBuilder::Run()
{
	CS101::CStringBuilderDefault builder1;
	builder1.Append("Hello").Append(" ").AppendLine("World!");

	printf("Builder (Append) => %s\n", builder1.ToString().c_str());

	//////////////////////////////////////

	const int kIterations = 250000;
	const std::string kMessage = "This is the message to be repeated\n";

	printf("Performance Test:\n");

	std::string result;
	
	clock_t time1 = clock();
	for (int i = 0; i < kIterations; ++i)
	{
		result += kMessage;
	}
	time1 = clock() - time1;

	printf("\t Normal string concat. Iterations %d - Time %.6f seconds.\n", kIterations, ((float)time1 / CLOCKS_PER_SEC));

	std::ostringstream oss;

	clock_t time2 = clock();
	for (int i = 0; i < kIterations; ++i)
	{
		oss << kMessage;
	}
	time2 = clock() - time2;

	printf("\t OStringStream string concat. Iterations %d - Time %.6f seconds.\n", kIterations, ((float)time2 / CLOCKS_PER_SEC));

	CS101::CStringBuilder<1024*16> builder2;
	
	clock_t time3 = clock();
	for (int i = 0; i < kIterations; ++i)
	{
		builder2.Append(kMessage);
	}
	time3 = clock() - time3;

	printf("\t Builder string concat. Iterations %d - Time %.6f seconds.\n", kIterations, ((float)time3 / CLOCKS_PER_SEC));
}