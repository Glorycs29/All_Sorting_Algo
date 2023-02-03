void recInsert(vector<int> &nums, int val) {
	if (!nums.size() or nums.back() <= val)
		return nums.push_back(val);
	int last = nums.back();
	nums.pop_back();
	recInsert(nums, val);
	nums.push_back(last);
}
	
void recInsertionSort(vector<int> &nums) {
	if (nums.size() <= 1) return;
	int last = nums.back();
	nums.pop_back();
	recInsertionSort(nums);
	recInsert(nums, last);
}
