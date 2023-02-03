void bubbleSort(vector<int> &nums) {
	int endInd, currInd, size = nums.size();
	if(size <= 1) return;
	
  for(endInd = size - 1; endInd; endInd--)
		  for(currInd = 0; currInd < endInd; currInd++)
			    if(nums[currInd] > nums[currInd + 1])
				     swap(nums[currInd], nums[currInd + 1]);
}
