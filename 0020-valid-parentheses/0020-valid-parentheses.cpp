class Solution {
public:
    bool isValid(string s) {
        stack<char>St;
        for(char ch:s){

            // openining bracket ko stack mei push krdo 
             if( ch=='(' || ch=='{' || ch=='['){
                St.push(ch);
             }else{
                if(!St.empty()){
                    char top =St.top();


                    if((ch==')' && top=='(') || (ch==']' && top=='[') || (ch=='}' && top=='{')){
                        St.pop();
                    }else{
                        return false;
                    }


                }else{
                    return false;
                }
             }
        }
        return St.empty();

    }
};