#pragma once

#include <deque>
#include <string>


/** 
	String Builder
	Helper class to concatenate strings reducing allocations
*/
template<int BUFFER_SIZE>
class CStringBuilder
{
private:
	struct SBuffer
	{
		enum { Capacity = BUFFER_SIZE };

		SBuffer()
		{
			m_data.reserve(Capacity);
		}

		size_t Append(const char* szValue, size_t offset)
		{
			const size_t inputLength = strlen(szValue);
			const size_t space = Capacity - m_data.length();
			const size_t writeCount = std::min(space, inputLength - offset);

			m_data.append(szValue + offset, writeCount);
			return writeCount;
		}

		bool IsFull() const { return m_data.length() >= Capacity; }
		const std::string& GetData() const { return m_data; }

	private:
		std::string m_data;
	};

	typedef std::deque<SBuffer> Container;

public:
	CStringBuilder()
		: m_totalSize(0)
	{
		m_data.push_back(SBuffer());
	}

	CStringBuilder(const std::string& value)
		: m_totalSize(0)
	{
		m_data.push_back(SBuffer());
		Append(value);
	}

	CStringBuilder& Append(const std::string& value)
	{
		return Append(value.c_str());
	}

	CStringBuilder& AppendLine(const std::string& value)
	{
		return AppendLine(value.c_str());
	}

	inline CStringBuilder& AppendLine(const char* szValue)
	{
		return Append(szValue).Append("\n");
	}

	CStringBuilder& Append(const char* szValue)
	{
		const size_t inputLenght = strlen(szValue);
		if (inputLenght > 0)
		{
			size_t pos = 0;
			while (pos < inputLenght)
			{
				SBuffer& buffer = m_data.back();
				pos += buffer.Append(szValue, pos);

				if (buffer.IsFull())
					m_data.push_back(SBuffer());
			}
			m_totalSize += inputLenght;
		}

		return *this;
	}

	std::string ToString() const
	{
		std::string result;
		if (m_data.empty())
			return result;

		result.reserve(m_totalSize + 1);

		for (const auto& value : m_data)
		{
			result.append(value.GetData());
		}

		return result;
	}

private:
	CStringBuilder(const CStringBuilder& rhs);
	CStringBuilder& operator=(const CStringBuilder& rhs);

private:
	Container m_data;
	size_t    m_totalSize;
};

typedef CStringBuilder<4096> CStringBuilderDefault;
