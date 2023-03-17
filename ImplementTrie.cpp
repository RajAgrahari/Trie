//https://leetcode.com/problems/implement-trie-prefix-tree/
class TrieNode{
        TrieNode* ch[26];
        bool isEnd;
        int cp;
        int cw;
        public:
        TrieNode()
        {
            for(int i=0;i<26;i++)
            ch[i] = NULL;
            isEnd = false;
            cp=cw=0;
        }
        void putNode(char c)
        {
           ch[c-'a'] = new TrieNode();
        }
        
        TrieNode* getNode(char c)
        {
            ch[c-'a']->cp++;
            return ch[c-'a'];
        }
        bool isend()
        {
            return isEnd;
        }
        bool containsKey(char c)
        {
            return ch[c-'a']!=NULL;
        }
        void setEnd()
        {
           cw++;
           isEnd = true;
        }
    };
class Trie {
private: TrieNode* root;
public:
    
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for(int i=0;i<word.size();i++)
        {
            if(!node->containsKey(word[i]))
            node->putNode(word[i]);
            node = node->getNode(word[i]); 
        }
        node->setEnd();
    }
    
    bool search(string word) 
    {
        TrieNode* node = root;
        for(int i=0;i<word.size();i++)
        {
            if(!node->containsKey(word[i]))
            return false;
            node = node->getNode(word[i]); 
        }
        return node->isend();

    }
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(int i=0;i<prefix.size();i++)
        {
            if(!node->containsKey(prefix[i]))
            return false;
            node = node->getNode(prefix[i]); 
        }
        return true;
    }
};
