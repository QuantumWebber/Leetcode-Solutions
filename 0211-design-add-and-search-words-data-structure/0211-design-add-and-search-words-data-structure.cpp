class WordDictionary {

    class TrieNode{
        public:
        TrieNode* children[26];
        bool isEnd;



        TrieNode(){
             isEnd=false;


             for(int i=0;i<26;i++){
                children[i]=NULL;
             }
        }
    };


    TrieNode* root;



    bool dfs(string &word,int index,TrieNode* node){


        if(index==word.size())  return node->isEnd;


        char ch=word[index];
        

        if(ch!='.'){
            int idx=ch-'a';


            if(node->children[idx]==NULL)  return false;


            return dfs(word,index+1,node->children[idx]);
        }

        // Try every possible child
        for (int i = 0; i < 26; i++) {

            if (node->children[i] != NULL) {

                if (dfs(word, index + 1, node->children[i]))
                    return true;
            }
        }

        return false;
    

    }
public:
    WordDictionary() {
        root=new TrieNode();
        
    }
    
    void addWord(string word) {

        TrieNode* node=root;


        for(char ch:word){
            int idx=ch-'a';


            if(node->children[idx]==NULL) node->children[idx]=new TrieNode();


            node=node->children[idx];
        }


        node->isEnd=true;
        
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */