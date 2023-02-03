int partitionArray(vector<int> &nums, int low=0, int high=-1) {
	high = high < 0 ? nums.size() - 1 : high;
	if (low >= high) return -1;
	int pivot = low, l = pivot + 1, r = high;
	while (l <= r)
		if (nums[l] < nums[pivot]) l++;
		else if (nums[r] >= nums[pivot]) r--;
		else swap(nums[l], nums[r]);
	swap(nums[pivot], nums[r]);
	return r;
}

int getDigit(int num, int factor) {
	return (abs(num) / abs(factor)) % 10;
}

pair<int, int> getMinAndNonNegMinInd(vector<int> &nums) {
	int minInd = nums.size(), minVal = INT_MAX;
	int nonNegMinInd = nums.size(), minNonNegVal = INT_MAX;
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] >= 0 and nums[i] < minNonNegVal)
			nonNegMinInd = i, minNonNegVal = nums[i];
		if (nums[i] < minVal)
			minInd = i, minVal = nums[i];
	}
	return {minInd, nonNegMinInd};
}

int radixSortPartionArray(vector<int> &nums) {
	auto [minInd, nonNegMinInd] = getMinAndNonNegMinInd(nums);
	if (nonNegMinInd < nums.size()) {
		if (nonNegMinInd) swap(nums[0], nums[nonNegMinInd]);
		if (nums[minInd] >= 0) nonNegMinInd = 0;
		else nonNegMinInd = partitionArray(nums);
	}
	return nonNegMinInd;
}

void radixCountingSort(vector<int> &nums, int factor, int low, int high, bool isAscending=true) {
	if (low >= high) return;
	int freqSize = 10, size = high - low + 1;
	vector<int> freq(freqSize, 0), sorted(size, 0);
	for (int ind = 0; ind < size; ind++)
		freq[getDigit(nums[ind + low], factor)]++;
	if (isAscending)
		// reference: http://analgorithmaday.blogspot.com/2011/03/counting-sortlinear-time.html
		for (int ind = 1; ind < freqSize; ind++)
			freq[ind] += freq[ind - 1];
	else
		for (int ind = freqSize - 2; ind >= 0; ind--)
			freq[ind] += freq[ind + 1];
	// for stable sorting start ind from end and decrement till 0
	for (int ind = size - 1; ind >= 0; ind--)
		sorted[freq[getDigit(nums[ind + low], factor)]-- - 1] = nums[ind + low];
	for (int ind = 0; ind < size; ind++)
		nums[ind + low] = sorted[ind];
}

void radixSortHelper(vector<int> &nums, int low, int high, bool isAscending=true) {
	if (low >= high) return;
	int maxVal = *max_element(nums.begin() + low, nums.begin() + high + 1, [] (int &a, int &b) {
		return abs(a) < abs(b);
	});
	int factor = 1;
	while (maxVal / factor) {
		radixCountingSort(nums, factor, low, high, isAscending);
		factor *= 10;
	}
}

void radixSort(vector<int> &nums) {
	int nonNegMinInd = radixSortPartionArray(nums);
	if (nonNegMinInd <= 1)
		radixSortHelper(nums, nonNegMinInd + 1, nums.size() - 1);
	else {
		radixSortHelper(nums, 0, nonNegMinInd - 1, false);
		radixSortHelper(nums, nonNegMinInd + 1, nums.size() - 1);
	}
}
