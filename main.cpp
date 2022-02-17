#include <iostream>
#include <fstream>
#include "Trie.h"

using namespace std;

int main(int argc, char *argv[]) {
    freopen(argv[2],"w",stdout);  // Using cout for writing in the output file.

    Trie *trie = new Trie();

    fstream file;
    file.open(argv[1]);

    string line;
    while (getline(file,line)){
        int i;
        string key, value;
        if (line.substr(0,4) == "list") trie->list();
        else if (line.substr(0,6) == "search" || line.substr(0,6) == "delete") {
            for (i = 7 ; i<line.size() -1 ; i++){
                key.push_back(line[i]);
            }
            if (line.substr(0,6) == "search") cout << '"' << trie->search(key) << '"' << endl;
            else trie->remove(key);
        }
        else if (line.substr(0,6) == "insert"){
            for (i = 7 ; line[i] != ',' ; i++){
                key.push_back(line[i]);
            }
            for (i = ++i; i < line.size() - 1 ; i++){
                value.push_back(line[i]);
            }
            trie->insert(key,value);
        }
    }

    return 0;
}
