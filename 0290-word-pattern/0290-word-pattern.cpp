class Solution {
public:
    bool wordPattern(string pattern, string s) {

        //extended version of isomorphic strings 
        // sabse pehle string s mei jo words hai unhe array mei daal lete hai uske baad same isomorphic stirgs wala logic lagayege

        vector<string>words;
        string temp=""; 

        for(char ch: s){
            if(ch==' '){
                words.push_back(temp);
                temp="";
            }else{
             temp+=ch;
            }
        }
        words.push_back(temp); //push last word

if(words.size()!=pattern.size()) return false;
//because length hi fail hogyi 
 unordered_map<char,string> mp1;
        unordered_map<string,char> mp2;

        for(int i=0;i<pattern.size();i++){
            char c = pattern[i];
            string w = words[i];

            // c->w
            if(mp1.count(c)){
                if(mp1[c] != w) return false;
            } else {
                mp1[c] = w;  
            }

            // w->s
            if(mp2.count(w)){
                if(mp2[w] != c) return false;
            } else {
                mp2[w] = c;  
            }
        }

        return true;
    }
};