#include "StdAfx.h"
#include "BigInt.h"


namespace CS101
{
	CBigInt::CBigInt()
	{
		m_bPositive = true;
		m_data.push_back(0);
	}
	
	CBigInt::CBigInt(long long value)
	{
		*this = value;
	}
	
	CBigInt::CBigInt(const CBigInt& value)
	{
		*this = value;
	}
	
	void CBigInt::operator=(long long value)
	{
		m_bPositive = (value >= 0);
		
		if(value != 0)
		{
			value = m_bPositive ? value : -value;
			while (value != 0)
			{
				const int mod = (int)(value % eBase);
				value /= eBase;
				m_data.push_back(mod);
			}
		}
		else
		{
			m_data.push_back(0);
		}
	}
	
	void CBigInt::operator=(const CS101::CBigInt &value)
	{
		m_bPositive = value.m_bPositive;
		m_data = value.m_data;
	}
	
	bool CBigInt::operator==(const CBigInt& rhs) const
	{
		if (m_bPositive != rhs.m_bPositive)
			return false;
		
		if (m_data.size() != m_data.size())
			return false;
		
		for (size_t idx = 0; idx < m_data.size(); ++idx)
		{
			if (m_data[idx] != rhs.m_data[idx])
				return false;
		}
		
		return true;
	}
	
	bool CBigInt::operator<(const CBigInt& rhs) const
	{
		if (m_bPositive && !rhs.m_bPositive)
			return false;
		
		if (!m_bPositive && rhs.m_bPositive)
			return true;
		
		if (m_data.size() > rhs.m_data.size())
			return false;
		
		if (m_data.size() < rhs.m_data.size())
			return true;
		
		for (size_t idx = m_data.size(); idx > 0; --idx)
		{
			if (m_data[idx-1] == rhs.m_data[idx-1])
				continue;
			
			return m_data[idx-1] < rhs.m_data[idx-1];
		}
		
		return false;
	}
	
	CBigInt CBigInt::operator+(long long value) const
	{
		const CBigInt temp(value);
		return (*this + temp);
	}
	
	CBigInt CBigInt::operator+(const CBigInt &value) const
	{
		// If numbers have different sign, do a substraction
		if (m_bPositive != value.m_bPositive)
		{
			CBigInt temp(!m_bPositive ? *this : value);
			temp.m_bPositive = true;
			
			return !m_bPositive ? (value - temp) : (*this - temp);
		}
		
		CBigInt result(*this);
		
		while (result.m_data.size() < value.m_data.size())
			result.m_data.push_back(0);
		
		int carry = 0;
		size_t i  = 0;
		for (i = 0; i < value.m_data.size(); ++i)
		{
			const int temp = result.m_data[i] + value.m_data[i] + carry;
			
			result.m_data[i] = temp % eBase;
			carry = temp / eBase;
		}
		
		for (; (i < result.m_data.size()) && (carry > 0); ++i)
		{
			const int temp = result.m_data[i] + carry;
			
			result.m_data[i] = temp % eBase;
			carry = temp / eBase;
		}
		
		if (carry > 0)
			result.m_data.push_back(1);
		
		return result;
	}
	
	CBigInt& CBigInt::operator+=(long long value)
	{
		*this = (*this + value);
		return *this;
	}
	
	CBigInt& CBigInt::operator+=(const CBigInt &value)
	{
		*this = (*this + value);
		return *this;
	}
	
	CBigInt CBigInt::operator-(long long value) const
	{
		const CBigInt temp(value);
		return (*this - temp);
	}
	
	CBigInt CBigInt::operator-(const CBigInt &value) const
	{
		if (!value.m_bPositive)
		{
			CBigInt temp(value);
			temp.m_bPositive = true;
			
			return (*this + temp);
		}
		
		CBigInt result;
		CBigInt op2;
		if (*this < value)
		{
			result = value;
			result.m_bPositive = false;
			op2 = *this;
		}
		else
		{
			result = *this;
			op2 = value;
		}
		
		int borrow = 0;
		size_t i;
		for (i = 0; i < op2.m_data.size(); ++i)
		{
			const int temp = result.m_data[i] - (op2.m_data[i] + borrow);
			if (temp < 0)
			{
				result.m_data[i] = (temp + eBase);
				borrow = 1;
			}
			else
			{
				result.m_data[i] = temp;
				borrow = 0;
			}
		}
		
		for (; (i < result.m_data.size()) && (borrow > 0); ++i)
		{
			const int temp = result.m_data[i] - borrow;
			if (temp < 0)
			{
				result.m_data[i] = temp + eBase;
				borrow = 1;
			}
			else
			{
				result.m_data[i] = temp;
				borrow = 0;
			}
		}
		
		result.Trim();
		
		return result;
	}
	
	CBigInt& CBigInt::operator-=(long long value)
	{
		*this = (*this - value);
		return *this;
	}
	
	CBigInt& CBigInt::operator-=(const CBigInt &value)
	{
		*this = (*this - value);
		return *this;
	}
	
	std::string CBigInt::ToString() const
	{
		std::string result;
		result.reserve(m_data.size() * 10);
		
		if (!m_bPositive)
			result.append("-");
		
		for (auto it = m_data.rbegin(); it != m_data.rend(); ++it)
		{
			std::string value = std::to_string(*it);
			if (it != m_data.rbegin())
			{
				size_t addZeros = (value.size() < 9) ? (9 - value.size()) : 0;
				value.insert(0, addZeros, '0');
			}
			result.append(value);
		}
		
		return result;
	}
	
	void CBigInt::Trim()
	{
		while((m_data.size() > 1) && (m_data[m_data.size() - 1] == 0))
			m_data.erase(m_data.begin() + (m_data.size() - 1));
	}
	
}
