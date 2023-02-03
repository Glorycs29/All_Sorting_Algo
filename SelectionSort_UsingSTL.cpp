void selectionSort(vector<int> &nums) {
	int minInd, startInd, size = nums.size();
  
	if (size <= 1) return;
    for (startInd = 0; startInd < size - 1; startInd++) {

      minInd = min_element(nums.begin() + startInd, nums.end()) - nums.begin();

      if (minInd != startInd)
        swap(nums[startInd], nums[minInd]);
    }
}
