#pragma once

namespace CS101
{
	enum { eHashMapSize = 512 };

	template<typename KEY>
	struct SDefaultHash
	{
		unsigned long operator()(const KEY& key) const
		{
			return static_cast<unsigned long>(key) % eHashMapSize;
		}
	};

	struct SStringHash
	{
		unsigned long operator()(const std::string& key) const
		{
			unsigned long hash = 1024 * 32;
			for (int i = 0; i < key.length(); i += 3)
			{
				hash += key.at(i);
			}

			return (hash % eHashMapSize);
		}
	};

	template<typename KEY, typename VALUE, typename HASH_FUNC = SDefaultHash<KEY>>
	class CHashMap
	{
	private:

		template<typename KEY, typename VALUE>
		class CNode
		{
		public:
			CNode(const KEY& key, const VALUE& value)
				: m_key(key)
				, m_value(value)
				, m_pNext(nullptr)
			{
			}

			const KEY&   Key() const { return m_key; }
			
			void        SetValue(const VALUE& value) { m_value = value; }
			const VALUE Value() const { return m_value; }

			void   SetNext(CNode* pNode) { m_pNext = pNode; }
			CNode* Next() { return m_pNext; }

		private:
			KEY    m_key;
			VALUE  m_value;
			CNode* m_pNext;
		};

	public:
		CHashMap()
		{
			m_pTable = new CNode<KEY, VALUE>*[eHashMapSize]();
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
			unsigned long hashIndex = m_hashFunc(key);

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
			unsigned long hashIndex = m_hashFunc(key);

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
			unsigned long hashIndex = m_hashFunc(key);

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
		CNode<KEY, VALUE>** m_pTable;
		HASH_FUNC           m_hashFunc;
	};
}
