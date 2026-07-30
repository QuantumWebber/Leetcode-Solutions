class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>s;
        // mujhe ye dekhna ki konse asteroids mere collision ke baad alive hai 
        for(int i=0;i<asteroids.size();i++){
            bool alive=true;
            while(!s.empty() && s.top()>0 && asteroids[i]<0 ){
                if(s.top()<-asteroids[i]){
                    s.pop();
                   continue; 
                }else if(s.top()==-asteroids[i] ){
                    s.pop();
                }
                alive=false;
                break;
            }
            if(alive){
                s.push(asteroids[i]);
            }


        }

        vector<int>result(s.size());
        for(int i=s.size()-1;i>=0;i--){
            result[i]=s.top();
            s.pop();
        }
        return result;
    }
};




