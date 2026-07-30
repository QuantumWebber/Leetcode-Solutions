class Solution {

    void solve(string& s,unordered_set<string>& dict, string temp, vector<string>& ans, int index){
        if(index==s.size()){
            // temp mei kuch na kuch hoga nikl do 
            temp.pop_back();
            ans.push_back(temp);
            return;
        }


        for(int end=index;end<s.size();end++){

            string word=s.substr(index,end-index+1);
              
              // agr fict mei hai to 
            if(dict.count(word)){
                //include

                solve(s,dict,temp+word+" ",ans,end+1);
            }
        }
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {

    unordered_set<string>dict(wordDict.begin(),wordDict.end());

    string temp= "";
    vector<string>ans;
    int index=0;

    solve(s,dict,temp,ans,index);
    return ans;
        
    }
};