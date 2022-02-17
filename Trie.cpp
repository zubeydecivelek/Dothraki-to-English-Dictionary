#include "Trie.h"
#include <string>
#include <iostream>

using namespace std;

TrieNode *Trie::getNode() {
    TrieNode *trieNode =  new TrieNode;

    for (auto & i : trieNode->children)
        i = nullptr;

    return trieNode;
}

void Trie::insert(string &key, string &value) {
    TrieNode *iter = root;

    for (char i : key){
        int index = i - 'a';
        if (!iter->children[index])
            iter->children[index] = getNode();

        iter = iter->children[index];
    }

    if (iter->value == value) cout << '"' << key << '"' << " already exist" << endl;
    else if (!iter->value.empty()) cout << '"' << key << '"' << " was updated" << endl;
    else cout << '"' << key << '"' <<" was added" << endl;

    iter->value = value;
}

string Trie::search(string &key) {
    TrieNode *iter = root;

    for (int i = 0; i < key.length(); i++){
        int index = key[i] - 'a';
        if (i == 0 && !iter->children[index]) {
            return "no record";
        }
        else if (!iter->children[index]) {
            return "incorrect Dothraki word";
        }
        iter = iter->children[index];
    }

    if (iter->value.empty()) return "not enough Dothraki word";

    else return "The English equivalent is " + iter->value ;
}


TrieNode *Trie::remove(TrieNode* rootNode, string &key, int depth) {
    if (depth == key.size()) {// If the function is on the last character of key

        if (!rootNode->value.empty()) // If node has a value, remove the value of key
            rootNode->value = "";

        if (rootNode->isEmpty()) { // If node hasn't a child
            delete (rootNode);
            rootNode = nullptr;
        }
        return rootNode;
    }

    // If node has a child, call the function recursively for the child.
    int index = key[depth] - 'a';
    rootNode->children[index] = remove(rootNode->children[index], key, depth + 1);

    if (rootNode->isEmpty() && rootNode->value.empty()) { // If node does not have any child, and it hasn't a value delete the node.
        delete (rootNode);
        rootNode = nullptr;
    }

    return rootNode;

}

void Trie::remove(string &key) {
    string str = search(key);
    if (str.substr(0,3) == "The"){
        remove(root, key, 0);
        cout<< '"'<< key << '"' << " deletion is successful" << endl;
    }
    else cout << '"' << str << '"' << endl;
}

void Trie::list() {
    list(root, new char[30], 0);
}

void Trie::list(struct TrieNode *rootNode, char *str, int index) {

    if (!rootNode->value.empty()){ // If node has a value , it adds string a null character and prints to the output file
        str[index] = '\0';
        cout << "\t-" << str << "(" << rootNode->value << ")" << endl;
    }

    int i;
    for (i = 0; i < ALPHABET_SIZE; i++) {

        if (rootNode->children[i]) { // If child is not null, add parent key to str and call the function recursively for child.
            str[index] = i + 'a';
            list(rootNode->children[i], str, index + 1);
        }
    }
}
