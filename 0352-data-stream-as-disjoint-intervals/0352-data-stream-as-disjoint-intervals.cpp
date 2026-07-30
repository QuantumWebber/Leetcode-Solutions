class SummaryRanges {
    private:
    set<int>values;
public:
    SummaryRanges() {
        // no need of initialization
    }
    
    void addNum(int value) {
        values.insert(value);
        
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>>intervals;


        if(values.empty())   return intervals;


        int start=-1;
        int end=-1;

        for(int num:values){
            if(start==-1){
                start=num;
                end=num;
            }else if(num==end+1){
                // consectutive number hai
                end=num; 
            }else{
                //store prev interval
                intervals.push_back({start,end});

                // new range start for gap 
                start=num;
                end=num;
            }
        }
        intervals.push_back({start,end});
        return intervals;
     }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */