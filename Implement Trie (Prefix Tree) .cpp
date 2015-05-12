//Implement a trie with insert, search, and startsWith methods.
//Note:
//You may assume that all inputs are consist of lowercase letters a-z.

class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode(): value(' '), is_end(false), num_of_shared_node(0) {}
    TrieNode(char ch): value(ch), is_end(false), num_of_shared_node(0) {}
    
    TrieNode* get_child(char ch) {
        if (children.empty())   return nullptr;
        
        for (auto child : children) {
            if (child->value == ch)
                return child;
        }
        return nullptr;
    }
    
    ~TrieNode() {
        for (auto child : children)
            delete child;
    }
    
    char value; //value of the node 
    bool is_end; // the node is an end of a word?
    int num_of_shared_node; // how many nodes shared this node
    vector<TrieNode*> children; // all the nodes in one level down 
};

class Trie : public TrieNode{
public:
    Trie() {
        root = new TrieNode(); // root is empty
    }

    // Inserts a word into the trie.
    void insert(string s) {
        if (search(s))  return;
        
        TrieNode* cur = root;
        for (auto ch : s) {
            TrieNode *child = cur->get_child(ch);
            if (child)
                cur = child;
            else {
                TrieNode *newNode = new TrieNode(ch);
                cur->children.push_back(newNode);
                cur = newNode;
            }
            ++cur->num_of_shared_node; // parent node is shared
        }
        cur->is_end = true;
    }

    // Returns if the word is in the trie.
    bool search(string key) {
        TrieNode *cur = root;
        for(auto ch : key) {
            cur = cur->get_child(ch);
            if (cur == nullptr)
                return false;
        }
        return cur->is_end;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *cur = root;
        for (auto ch : prefix) {
            cur = cur->get_child(ch);
            if (cur == nullptr)
                return false;
        }
        return true;
    }

    ~Trie() {delete root;}
    
private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
