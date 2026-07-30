class TrieNode{
    public:
    TrieNode* Children[26];
    string word;

    TrieNode(){
        for(int i=0;i<26;i++){
            Children[i]=nullptr;

        }
        word=" ";
    }
};




class Solution {
  
   
private:


void insertToTrie(TrieNode* root,string& word){
    TrieNode* curr=root;



    for(char ch:word){
        int idx=ch-'a';
        if(curr->Children[idx]==nullptr){
            curr->Children[idx]=new TrieNode();
        }
        curr=curr->Children[idx];
    }
    curr->word=word; // jabtak current ka word word ke brabar nhi ho jata 

}
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* curr, vector<string>& ans) {
        

        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] == '#') {
            return;
        }
        char ch = board[i][j];
        int idx= ch-'a';


        // agr ye ch trie ke path mei nhi to aage mt badao 

        if (curr->Children[idx]==nullptr){
            return;
        }



        curr=curr->Children[idx]; 

        if(curr->word!=" "){
            ans.push_back(curr->word);
            curr->word=" ";
        }
        board[i][j] = '#'; // Mark Visited

       dfs(board, i + 1, j, curr, ans);
        dfs(board, i - 1, j, curr, ans);
        dfs(board, i, j + 1, curr, ans);
        dfs(board, i, j - 1, curr, ans);
        board[i][j] = ch; // Backtrack
        
    }


public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();

// input words ko trie mei daal do 
       for (string& word : words) {
            insertToTrie(root, word);
        }
vector<string> ans;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                dfs(board, i, j, root, ans);
            }
        }
        return ans;
    
    }

};