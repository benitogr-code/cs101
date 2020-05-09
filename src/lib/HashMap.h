#pragma once

template<typename KEY>
struct SDefaultHash
{
	unsigned long operator()(const KEY& key) const
	{
		return static_cast<unsigned long>(key);
	}
};

/**
	HashMap
	Stores key/valure pairs to a indexed bucket in a table.
	Each bucket contains a linked list to avoid collisions.

	Usage: CHashMap<int, MyType>, CHashMap<string, MyType, StringHashFunc>, ...
*/

template<typename KEY, typename VALUE, typename HASH_FUNC = SDefaultHash<KEY>>
class CHashMap
{
private:
	enum { eHashMapSize = 512 };

	template<typename NODE_KEY, typename NODE_VALUE>
	class CNode
	{
	public:
		CNode(const NODE_KEY& key, const NODE_VALUE& value)
			: m_key(key)
			, m_value(value)
			, m_pNext(nullptr)
		{
		}

		const NODE_KEY& Key() const { return m_key; }

		void SetValue(const NODE_VALUE& value) { m_value = value; }
		const NODE_VALUE Value() const { return m_value; }

		void   SetNext(CNode* pNode) { m_pNext = pNode; }
		CNode* Next() { return m_pNext; }

	private:
		NODE_KEY    m_key;
		NODE_VALUE  m_value;
		CNode* m_pNext;
	};

public:
	CHashMap()
	{
		m_pTable = new CNode<KEY, VALUE> * [eHashMapSize]();
	}

	~CHashMap()
	{
		for (int i = 0; i < eHashMapSize; ++i)
		{
			CNode<KEY, VALUE>* pNode = m_pTable[i];
			while (pNode != nullptr)
			{
				CNode<KEY, VALUE>* pCurrent = pNode;
				pNode = pNode->Next();
				delete pCurrent;
			}

			m_pTable[i] = nullptr;
		}

		delete[] m_pTable;
	}

	void Insert(const KEY& key, const VALUE& value)
	{
		unsigned long hashIndex = GetHashIndex(key);

		CNode<KEY, VALUE>* pNode = m_pTable[hashIndex];
		CNode<KEY, VALUE>* pLastNode = nullptr;

		while ((pNode != nullptr) && (pNode->Key() != key))
		{
			pLastNode = pNode;
			pNode = pNode->Next();
		}

		if (pNode == nullptr)
		{
			pNode = new CNode<KEY, VALUE>(key, value);
			if (pLastNode != nullptr)
			{
				pLastNode->SetNext(pNode);
			}
			else
			{
				m_pTable[hashIndex] = pNode;
			}
		}
		else
		{
			pNode->SetValue(value);
		}
	}

	void Remove(const KEY& key)
	{
		unsigned long hashIndex = GetHashIndex(key);

		CNode<KEY, VALUE>* pNode = m_pTable[hashIndex];
		CNode<KEY, VALUE>* pPrev = nullptr;

		while ((pNode != nullptr) && (pNode->Key() != key))
		{
			pPrev = pNode;
			pNode = pNode->Next();
		}

		if (pNode != nullptr)
		{
			if (pPrev != nullptr)
			{
				pPrev->SetNext(pNode->Next());
			}
			else
			{
				m_pTable[hashIndex] = pNode->Next();
			}

			delete pNode;
		}
	}

	bool TryGet(const KEY& key, VALUE& outValue) const
	{
		unsigned long hashIndex = GetHashIndex(key);

		CNode<KEY, VALUE>* pNode = m_pTable[hashIndex];
		while (pNode != nullptr)
		{
			if (pNode->Key() == key)
			{
				outValue = pNode->Value();
				return true;
			}

			pNode = pNode->Next();
		}

		return false;
	}

private:
	unsigned long GetHashIndex(const KEY& key) const
	{
		return m_hashFunc(key) % eHashMapSize;
	}

private:
	CNode<KEY, VALUE>** m_pTable;
	HASH_FUNC           m_hashFunc;
};

