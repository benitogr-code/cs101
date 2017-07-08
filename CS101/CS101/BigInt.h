#pragma once

namespace CS101
{
	class CBigInt
	{
	private:
		enum
		{
			eBase = 1000000000
		};
		
		typedef std::vector<int> Storage;
		
	public:
		CBigInt();
		CBigInt(long long value);
		CBigInt(const CBigInt& value);
		
		void operator=(long long value);
		void operator=(const CBigInt& value);
		
		bool operator==(const CBigInt& rhs) const;
		bool operator!=(const CBigInt& rhs) const;
		
		bool operator<(const CBigInt& rhs) const;
		bool operator<=(const CBigInt& rhs) const;
		
		bool operator>(const CBigInt& rhs) const;
		bool operator>=(const CBigInt& rhs) const;
		
		CBigInt operator-() const;
		
		CBigInt operator+(long long value) const;
		CBigInt operator+(const CBigInt& value) const;
		
		CBigInt& operator+=(long long value);
		CBigInt& operator+=(const CBigInt& value);
		
		CBigInt operator-(long long value) const;
		CBigInt operator-(const CBigInt& value) const;
		
		CBigInt& operator-=(long long value);
		CBigInt& operator-=(const CBigInt& value);
		
		CBigInt operator*(long long value) const;
		CBigInt operator*(const CBigInt& value) const;
		
		CBigInt& operator*=(long long value);
		CBigInt& operator*=(const CBigInt& value);
		
		std::string ToString() const;
		
	private:
		void    Trim();
		static CBigInt Sum(const CBigInt& a, const CBigInt& b, size_t shift = 0);
		
	private:
		Storage m_data;
		bool    m_bPositive;
	};
}
