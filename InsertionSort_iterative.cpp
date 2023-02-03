
// tc=O(n^2)


void insertionSort(vector<int> &nums) {
	int sortedInd, unsortedInd, key, size = nums.size();
	if (size <= 1) return;
	for (unsortedInd = 1; unsortedInd < size; unsortedInd++) {
		key = nums[unsortedInd], sortedInd = unsortedInd;
		while (--sortedInd >= 0 and key < nums[sortedInd])
			nums[sortedInd + 1] = nums[sortedInd];
		nums[sortedInd + 1] = key;
	}
}

//OR

void insertionSort(vector<int>&nums){
    int n=nums.size();
    for(int i=1; i<n; i++){
        int j=i-1;
        int x = nums[i];
        while(j>=0 && nums[j] > x){
        
            nums[j+1]=nums[j];
            j--;
        
        }
        nums[j+1]=x;
        
    }    
 }




}
