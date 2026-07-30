class Solution {
    private:
    void merge(vector<int>& nums,int left,int mid,int right){
        int an=mid-left+1;
        int bn=right-mid;

        vector<int>a(an);
        vector<int>b(bn);

        for(int i=0;i<an;i++){
            a[i]=nums[left+i];
        }

        for(int j=0;j<bn;j++){
            b[j]=nums[mid+1+j];
        }


        int i=0,j=0,k=left;
        
        while(i<an && j<bn){
         if(a[i]<b[j]) nums[k++]=a[i++];
         else nums[k++]=b[j++];
        }

        while(i<an){
            nums[k++]=a[i++];
        }

        while(j<bn){
            nums[k++]=b[j++];
        }


    }


    void mergeSort(vector<int>& nums,int l,int r){
        if(l>=r) return;

        int mid=l+(r-l)/2;
        mergeSort(nums,l,mid);
        mergeSort(nums,mid+1,r);
        merge(nums,l,mid,r);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};