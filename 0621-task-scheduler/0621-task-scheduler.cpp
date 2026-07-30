class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {


        // count freq of each task 

        vector<int>freq(26,0);
        for(char task:tasks){
            freq[task-'A']++;
        }

        // sort on basis of maxfreq
        sort(freq.begin(),freq.end());

        int max_freq=freq[25];

        int empty_slots=(max_freq-1)*n;



        for(int i=24;i>=0 && freq[i]>0;i--){
            empty_slots-=min(max_freq-1,freq[i]);


            
        }


        // if ideal slots negative 
        empty_slots=max(0,empty_slots);



        return tasks.size()+empty_slots;
        
    }
};