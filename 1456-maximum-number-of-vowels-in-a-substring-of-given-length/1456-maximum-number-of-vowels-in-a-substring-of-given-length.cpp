class Solution {
    private:
    bool isVowels(char c){
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }
public:
    int maxVowels(string s, int k) {
        
      int count=0;
      for(int i=0;i<k;i++){
        if(isVowels(s[i])){
            count++;
        }
      }
      int best=count;

      for(int r=k;r<s.length();r++){
       count+=isVowels(s[r]);
       count-=isVowels(s[r-k]);
       best=max(best,count);

       if(best==k) return k;
      }
      return best;
    }
};