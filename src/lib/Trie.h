#pragma once

namespace CS101
{
	const int TRIE_ALPHABET_FIRST = int('a');
	const int TRIE_ALPHABET_LAST  = int('z');
	const int TRIE_ALPHABET_SIZE = (TRIE_ALPHABET_LAST - TRIE_ALPHABET_FIRST) + 1;
	
	struct STrieNode
	{
		STrieNode()
			: bWord(false)
		{
			
		}
		
		std::shared_ptr<STrieNode> children[TRIE_ALPHABET_SIZE];
		bool bWord;
	};
	typedef std::shared_ptr<STrieNode> STrieNodePtr;
	
	class CTrie
	{
	public:
		CTrie()
			: m_pRoot(new STrieNode())
		{
			
		}
		
		bool Insert(const char* szKey)
		{
			return InsertKey(szKey, (int)strlen(szKey));
		}
		
		bool Search(const char* szKey)
		{
			return SearchKey(szKey, (int)strlen(szKey));
		}
		
	private:
		bool InsertKey(const char* szKey, const int keyLength)
		{
			if (!ValidateKey(szKey, keyLength))
				return false;
		
			STrieNodePtr pNode = m_pRoot;
			for (int i = 0; i < keyLength; ++i)
			{
				const int idx = int(szKey[i]) - TRIE_ALPHABET_FIRST;
				if (pNode->children[idx] == nullptr)
					pNode->children[idx].reset(new STrieNode());
				
				pNode = pNode->children[idx];
			}
			
			pNode->bWord = true;
			
			return true;
		}
		
		bool SearchKey(const char* szKey, const int keyLength)
		{
			if (!ValidateKey(szKey, keyLength))
				return false;
			
			STrieNodePtr pNode = m_pRoot;
			for (int i = 0; i < keyLength; ++i)
			{
				const int idx = int(szKey[i]) - TRIE_ALPHABET_FIRST;
				if (pNode->children[idx] == nullptr)
					return false;
				
				pNode = pNode->children[idx];
			}
			
			return (pNode != nullptr) && pNode->bWord;
		}
		
		bool ValidateKey(const char* szKey, const int keyLength)
		{
			if (keyLength <= 0)
				return false;
			
			for (int i = 0; i < keyLength; ++i)
			{
				const int idx = int(szKey[i]) - TRIE_ALPHABET_FIRST;
				if ((idx < 0) || (idx >= TRIE_ALPHABET_SIZE))
					return false;
			}
			
			return true;
		}
		
	private:
		STrieNodePtr m_pRoot;
	};
}
