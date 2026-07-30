class Solution {

    private:
    void merge(vector<pair<int,int>>&nums,int left,int mid,int right,vector<int>& count){

        // value aur original index pair hai array 
        //rightCount mei right mei kitne zero hai 
        //cout me right ke smaller wale store krege 
        int an=mid-left+1;
        int bn=right-mid;
        vector<pair<int,int>>a(an);
        vector<pair<int,int>>b(bn);

        for(int i=0;i<an;i++){
            a[i]=nums[left+i];
        }

        for(int j=0;j<bn;j++){
            b[j]=nums[mid+1+j];
        }
      int i=0,j=0,k=left;
      int rightCount=0;

      while(i<an && j<bn){
        if(a[i].first>b[j].first){
            rightCount++;
            nums[k++]=b[j++];
        }
        else{
             count[a[i].second]+=rightCount;
             nums[k++]=a[i++];
        }

      }

      while(i<an){ count[a[i].second] += rightCount; nums[k++] = a[i++]; }
       while(j<bn){ nums[k++] = b[j++]; } }



       void mergeSort(vector<pair<int,int>>& nums, int l, int r, vector<int>& count){ if(l>=r) return; int mid = l + (r-l)/2; mergeSort(nums,l,mid,count); mergeSort(nums,mid+1,r,count); merge(nums,l,mid,r,count); }

    
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();

        vector<pair<int,int>>arr;
        for(int i=0;i<n;i++){
            arr.push_back({nums[i],i});
        }

        vector<int>count(n,0);
        mergeSort(arr,0,n-1,count);

        return count;
        
    }
};