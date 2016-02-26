// Design a data structure that supports the following two operations:

// void addWord(word)
// bool search(word)

// search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

// For example:

// addWord("bad")
// addWord("dad")
// addWord("mad")
// search("pad") -> false
// search("bad") -> true
// search(".ad") -> true
// search("b..") -> true


class TrieNode {
public:
    bool isWord;
    TrieNode *children[26];
    TrieNode() : isWord(false) {
        memset(children, 0, sizeof(children));
    }
};

class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }

    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode *p = root;
        for (auto i : word) {
            if (p->children[i-'a'] == NULL)
                p->children[i-'a'] = new TrieNode();
            p = p->children[i-'a'];
        }
        p->isWord = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return query(root, word.c_str());
    }
private:
    TrieNode *root;
    
    bool query(TrieNode *node, const char* word){
        TrieNode *p = node;
        for (int i=0; word[i]; i++) {
            if (p && word[i] != '.')
                p = p->children[word[i]-'a'];
            else if (p && word[i] == '.') {
                TrieNode *tmp = p;
                for (int j = 0; j < 26; j++) {
                    p = tmp->children[j];
                    if (query(p, word+i+1))
                        return true;
                }
            }
            else
                break;
        }
        return p && p->isWord;
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
