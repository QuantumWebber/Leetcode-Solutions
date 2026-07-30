class Solution {
public:
    string reorganizeString(string s) {


        // get freq of each char in string 

        int n=s.length();


        unordered_map<int,int>freq;

        for(char c:s){
            freq[c]++;



            if(freq[c]>(n+1)/2)  return ""; 
            // agr bhai freq of ek char halkf of length se zada to arrangement not possible 
        }



               priority_queue<pair<int, char>> maxHeap;


               for(auto& pair:freq){
                maxHeap.push({pair.second,pair.first});
               }        



               string result="";


               pair<int,char>block={-1,'#'};



               while(!maxHeap.empty()){


                auto current=maxHeap.top();
                maxHeap.pop();


                result+=current.second;
                current.first--;

                   // agr koi purana character block mei baitha tha to usse vapis heap mei daal do 
                   if (block.first > 0) {
                maxHeap.push(block);
            }

            block=current;


               }

               return result;
    }
};