class TrieNode{
public:
    TrieNode* children[26];
    bool endofword;

    TrieNode() {
        for(int i=0; i < 26; i++){
            children[i] = nullptr;
        }
        endofword = false;
    }
};

class PrefixTree {
private:
    TrieNode* root;

public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* cur = root;
        for(char c : word){
            int i = c - 'a';
            if(cur->children[i] == nullptr){
                cur->children[i] = new TrieNode();
            }
            cur = cur->children[i];
        }
        cur->endofword = true;
    }
    
    bool search(string word) {
        TrieNode* cur = root;
        for(char c : word){
            int i = c - 'a';
            if(cur->children[i] == nullptr){
                return false;
            }
            cur = cur->children[i];
        }
        return cur->endofword;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for(char c : prefix){
            int i = c -'a';
            if(cur->children[i] == nullptr){
                return false;
            }
            cur = cur->children[i];
        }
        return true;
    }
};
