int partitionArray(vector<int> &nums, int low, int high) {
	if (low >= high) return -1;
	int pivot = low, l = pivot + 1, r = high;
	while (l <= r)
		if (nums[l] < nums[pivot]) l++;
		else if (nums[r] >= nums[pivot]) r--;
		else swap(nums[l], nums[r]);
	swap(nums[pivot], nums[r]);
	return r;
}

void quickSort(vector<int> &nums, int low, int high) {
	if (low >= high) return;
	swap(nums[low + rand() % (high - low + 1)], nums[low]);
	int pivot = partitionArray(nums, low, high);
	quickSort(nums, low, pivot);
	quickSort(nums, pivot + 1, high);
}
