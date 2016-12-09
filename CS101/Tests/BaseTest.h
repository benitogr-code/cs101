#pragma once

class CBaseTest
{
public:
	CBaseTest(const char* szName)
		: m_name(szName)
	{
	}

	virtual ~CBaseTest()
	{
	}

	void Setup()
	{
		printf("============= Test '%s' starts =======================\n\n", m_name.c_str());

		OnSetup();
	}

	void TearDown()
	{
		OnTearDown();

		printf("\n============= Test ends =======================\n\n");
	}

	void Execute()
	{
		Run();
	}

protected:
	// API for derivated tests
	virtual void OnSetup() {};
	virtual void OnTearDown() {};
	virtual void Run() = 0;

private:
	std::string m_name;
};