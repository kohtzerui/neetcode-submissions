class TrieNode {
public:
    TrieNode* children[26];
    bool end;

    TrieNode() {
        for(int i=0; i<26; i++){
            children[i] = nullptr;
        }
        end = false;
    }
};

class WordDictionary {
private:
    TrieNode* root;
    
    bool dfs(string& word, int pos, TrieNode* node){
        if(node == nullptr){
            return false;
        }

        if(pos == word.size()){
            return node->end;
        }

        char c = word[pos];

        if(c == '.'){
            for(int i=0; i<26; i++){
                if(dfs(word, pos+1, node->children[i])){
                    return true;
                }
            }
            return false;
        } else {
            int index = c -'a';
            return dfs(word, pos + 1, node->children[index]);
        }
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* cur = root;
        for(char c : word){
            int index = c - 'a';
            if(cur->children[index] == nullptr){
                cur->children[index] = new TrieNode();
            }
            cur = cur->children[index];
        }
        cur->end = true;
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }
};
