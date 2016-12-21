#pragma once

namespace CS101
{
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

			size_t Append(const std::string& value, size_t offset)
			{
				const size_t space = Capacity - m_data.length();
				const size_t writeCount = std::min(space, value.length() - offset);

				m_data.append(value.data() + offset, writeCount);
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

		inline CStringBuilder& Append(const std::string& value)
		{
			if (!value.empty())
			{
				size_t pos = 0;
				while (pos < value.length())
				{
					SBuffer& buffer = m_data.back();
					pos += buffer.Append(value, pos);

					if (buffer.IsFull())
						m_data.push_back(SBuffer());
				}
				m_totalSize += value.length();
			}

			return *this;
		}

		inline CStringBuilder& AppendLine(const std::string& value)
		{
			Append(value + "\n");
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
		// Do not implement
		CStringBuilder(const CStringBuilder& rhs);
		CStringBuilder& operator=(const CStringBuilder& rhs);

	private:
		Container m_data;
		size_t    m_totalSize;
	};

	typedef CStringBuilder<4096> CStringBuilderDefault;
}
