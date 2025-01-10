#include <iostream>
#include <string>
using namespace std;

class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch) {
        data = ch;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root, string word) {
        // base case
        if (word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        // assumption: word will be in lowercase
        int index = word[0] - 'a';
        TrieNode* child;

        // present
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            // absent
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // recursion
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word) {
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode* root, string word) {
        // base case
        if (word.length() == 0) {
            return root->isTerminal;
        }

        int index = word[0] - 'a';
        TrieNode* child;

        // present
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            // absent
            return false;
        }

        // recursion
        return searchUtil(child, word.substr(1));
    }

    bool searchWord(string word) {
        return searchUtil(root, word);
    }

    bool removeUtil(TrieNode* root, string word, int depth = 0) {
        // base case: if tree is empty
        if (!root) return false;

        // if last character of word is being processed
        if (depth == word.size()) {
            // this node is no longer end of word after removal of given key
            if (root->isTerminal) root->isTerminal = false;

            // if given is not prefix of any other word
            return root->isTerminal == false && isEmpty(root);
        }

        // if not last character, recur for the child obtained using ASCII value
        int index = word[depth] - 'a';
        if (removeUtil(root->children[index], word, depth + 1)) {
            // last node marked, delete it
            delete root->children[index];
            root->children[index] = NULL;

            // recursively climb up and delete eligible nodes
            return !root->isTerminal && isEmpty(root);
        }

        return false;
    }

    void removeWord(string word) {
        removeUtil(root, word);
    }

    bool isEmpty(TrieNode* root) {
        for (int i = 0; i < 26; i++) {
            if (root->children[i] != NULL) return false;
        }
        return true;
    }
};

int main() {
    Trie* t = new Trie();
    t->insertWord("abcd");

    if (t->searchWord("abcd")) {
        cout << "The word 'abcd' is present in the trie." << endl;
    } else {
        cout << "The word 'abcd' is not present in the trie." << endl;
    }

    t->removeWord("abcd");

    if (t->searchWord("abcd")) {
        cout << "The word 'abcd' is still present in the trie." << endl;
    } else {
        cout << "The word 'abcd' has been removed from the trie." << endl;
    }

    delete t; // Clean up memory
    return 0;
}
