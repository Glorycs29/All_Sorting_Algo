void selectionSort(vector<int> &nums) {
	int minInd, startInd, currInd, size = nums.size();
	if (size <= 1) return;
	for (startInd = 0; startInd < size - 1; startInd++) {
		for (currInd = startInd + 1, minInd = startInd; currInd < size; currInd++)
			if (nums[minInd] > nums[currInd])
				minInd = currInd;
		if (minInd != startInd)
			swap(nums[startInd], nums[minInd]);
	}
}
