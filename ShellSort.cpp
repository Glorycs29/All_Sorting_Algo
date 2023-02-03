class Solution {
public:
    
    void shellSort(vector<int>&nums, int n)
    {
        // Start with a big gap, then reduce the gap
        for(int gap=n/2;gap>=1;gap/=2)
        {
            // repeat insertion sort with different gaps 
            // Code exactly similar to insertion sort, only difference is that in case of insertion sort there is only `gap == 1`
            // but here gap start from n/2 and keep reducing untill it becomes 0.
            for(int i=gap;i<n;i++)
            {
               int key = nums[i];
               int j=i-gap;
               while(j>=0 and nums[j] > key)
               {
                   nums[j+gap] = nums[j];
                   j=j-gap;
               }
               nums[j+gap] = key; 
            }
        }
    }
    
    vector<int> sortArray(vector<int>& nums) {
        if(nums.size() < 2) return nums;
        shellSort(nums, nums.size()); 
        return nums;
    }
};
