int getDigit(int num, int factor) {
	return (abs(num) / abs(factor)) % 10;
}

void radixCountingSort(vector<int> &nums, int factor) {
	int freqSize = 10, size = nums.size();
	vector<int> freq(freqSize, 0), sorted(size, 0);
	for (int ind = 0; ind < size; ind++)
		freq[getDigit(nums[ind], factor)]++;
	for (int ind = 1; ind < freqSize; ind++)
		freq[ind] += freq[ind - 1];
	// for stable sorting start ind from end and decrement till 0
	for (int ind = size - 1; ind >= 0; ind--)
		sorted[freq[getDigit(nums[ind], factor)]-- - 1] = nums[ind];
	nums = sorted;
}

void radixSort(vector<int> &nums) {
	int minVal = *min_element(nums.begin(), nums.end());
	for (auto &num : nums) num -= minVal;
	int factor = 1, maxVal = *max_element(nums.begin(), nums.end());
	while (maxVal / factor) {
		radixCountingSort(nums, factor);
		factor *= 10;
	}
	for (auto &num : nums) num += minVal;
}
