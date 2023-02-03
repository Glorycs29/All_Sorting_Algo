void inPlaceMerge(vector<int> &nums, int low, int mid, int high) {
	if (low >= high) return;
	int l = low, r = mid + 1, size = high - low + 1;
	while (l <= mid and r <= high) {
		if (nums[l] <= nums[r]) l++;
		else {
			int val = nums[r];
			for (int k = r++; k > l; k--)
				nums[k] = nums[k - 1];
			nums[l++] = val;
			mid++;
		}
	}
}

void mergeSort(vector<int> &nums, int low, int high) {
	if (low >= high) return;
	int mid = (high - low) / 2 + low;
	mergeSort(nums, low, mid);
	mergeSort(nums, mid + 1, high);
	inPlaceMerge(nums, low, mid, high);
}
