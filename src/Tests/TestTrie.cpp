#include "pch.h"
#include "TestTrie.h"

#include "lib/Trie.h"

CTestTrie::CTestTrie()
	: CBaseTest("Trie")
{
	
}

void CTestTrie::Run()
{
	const int kWordCount = 5;
	const char* words[kWordCount] = { "tree", "trie", "BAD$0WORD", "alphabet", "test" };
	
	printf("Trie alphabet size: %d\n", CS101::TRIE_ALPHABET_SIZE);
	
	CS101::CTrie trie;
	
	printf("Test insertion:\n");
	for (int i = 0; i < kWordCount; ++i)
	{
		const bool bInserted = trie.Insert(words[i]);
		printf("\t'%s': %d\n", words[i], bInserted ? 1 : 0);
	}
	
	printf("Test search:\n");
	const char* words2[kWordCount] = { "trie", "B87", "alphabet", "tes", "tree" };
	for (int i = 0; i < kWordCount; ++i)
	{
		const bool bFound = trie.Search(words2[i]);
		printf("\t'%s': %d\n", words2[i], bFound ? 1 : 0);
	}
}
