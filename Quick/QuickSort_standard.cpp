//TC=O(n^2)


int partition(int arr[],int l,int h){
    //making the first element of given array as pivot
    int pivot=arr[l];
    vector<int> temp;

    for(int i=l;i<=h;i++){
        if(arr[i] < pivot){
            temp.push_back(arr[i]);
        }
    }
    int partitionedIndex=temp.size()+l;
    for(int i=l;i<=h;i++){
        if(arr[i] == pivot){
            temp.push_back(arr[i]);
        }
    }
    for(int i=l;i<=h;i++){
        if(arr[i] > pivot){
            temp.push_back(arr[i]);
        }
    }
    //most important step
    for(int i=l;i<=h;i++){
        arr[i]=temp[i-l];
    }
    return partitionedIndex;
}

void QuickSort(int arr[],int l,int h){
    if(l >= h)return;
    //getting the partitioned  index after the partitioning..
    int pIndex=partition(arr,l,h);
    QuickSort(arr,l,pIndex-1);
    QuickSort(arr,pIndex+1,h);
}

//OR
/*

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
	int pivot = partitionArray(nums, low, high);
	quickSort(nums, low, pivot);
	quickSort(nums, pivot + 1, high);
}


*/

