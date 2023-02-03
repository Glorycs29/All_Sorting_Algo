void countingSort(vector<int> &nums, bool isAscending=true) {
	int minVal = *min_element(nums.begin(), nums.end());
	int maxVal = *max_element(nums.begin(), nums.end());
	// int freqSize = maxVal - minVal + 1 is enough i.e its also correct
	int freqSize = maxVal - minVal + 1 + 1, size = nums.size();
	vector<int> freq(freqSize, 0), sorted(size, 0);
	for (int ind = 0; ind < size; ind++)
		freq[nums[ind] - minVal]++;
	if (isAscending)
		for (int ind = 1; ind < freqSize; ind++)
			freq[ind] += freq[ind - 1];
	else
		for (int ind = freqSize - 2; ind >= 0; ind--)
			freq[ind] += freq[ind + 1];
	// for stable sorting start ind from end and decrement till 0
	for (int ind = size - 1; ind >= 0; ind--)
		sorted[freq[nums[ind] - minVal]-- - 1] = nums[ind];
	nums = sorted;
}
