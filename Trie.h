#ifndef TRIE_H
#define TRIE_H

#include <string>
#include <iostream>

using namespace std;

const int ALPHABET_SIZE = 26;

struct TrieNode{
    TrieNode *children[ALPHABET_SIZE];
    string value;

    bool isEmpty() {
        for (int i = 0; i < ALPHABET_SIZE; i++)
            if (children[i])
                return false;
        return true;
    }
};

class Trie {

private:
    TrieNode *root = getNode();

public:
    /// Initialized trie node (makes its children to nullptr)
    TrieNode *getNode();

    /// Inserts key and value into trie.
    void insert(string &key, string &value);

    /// Searches the given key in the trie.
    string search(string &key);

    /// Deletes the given key int the trie.
    void remove(string &key);
    TrieNode *remove(TrieNode* rootNode, string &key, int depth);

    /// Lists all keys and values.
    void list();
    void list(TrieNode* rootNode, char str[], int index);

};


#endif //TRIE_H
