#pragma once
#include <iostream>
#include <string>



const int ALPHABET_SIZE = 26;
const int WORD_SIZE = 10;

class Trie
{
public:
    struct TrieNode
    {
        TrieNode* children[ALPHABET_SIZE];
        bool isEndOfWord;
        int count = 0;

    };
    Trie() {};
    ~Trie() {
        if (root != nullptr) { delete root; root = nullptr; }
    }

    TrieNode* getNewNode(void);
    void insert(std::string&);
    bool isEmpty(TrieNode*);
    void findMinPrefixes(TrieNode*, char[], int, std::string&);
    TrieNode* insertion(std::string[], int);
    void findAllPrefix(std::string& key);

private:
    TrieNode* root = getNewNode();
};