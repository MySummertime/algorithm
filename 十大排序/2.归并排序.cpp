#include <vector>

using std::vector;


void swap(vector<int>& nums, int i, int j) {
    nums[i] = nums[i] + nums[j];
    nums[j] = nums[i] - nums[j];
    nums[i] = nums[i] - nums[j];
}


/*1.自顶向下递归--非原地
Time: O(nlogN)
Space: O(n)
*/
vector<int> mergeSort1(vector<int> nums) {
    if (nums.size() < 2)    return nums;
    vector<int> vec(nums.size());
    sort1(nums, vec, 0, nums.size() - 1);
    return nums;
}

void sort1(vector<int>& nums, vector<int>& vec, int left, int right) {
    if (left >= right)  return;
    int mid = left + ((right - left) >> 1);
    sort1(nums, vec, left, mid);
    sort1(nums, vec, mid + 1, right);
    merge1(nums, vec, left, mid, right);
}

void merge1(vector<int>& nums, vector<int>& vec, int left, int mid, int right) {
    int l = left, r = mid + 1;
    int idx = left;
    while (l <= mid && r <= right) {
        vec[idx++] = nums[l] <= nums[r] ? nums[l++] : nums[r++];
    }
    while (l <= mid) {
        vec[idx++] = nums[l++];
    }
    while (r <= right) {
        vec[idx++] = nums[r++];
    }
    // copy values of vec into nums
    for (; left <= right; ++left) {
        nums[left] = vec[left];
    }
}


/*2.自顶向下递归--原地
Time: O(n^2)
Space: O(logN)
*/
vector<int> mergeSort2(vector<int>& nums) {
    if (nums.size() < 2)    return nums;
    sort2(nums, 0, nums.size() - 1);
    return nums;
}

void sort2(vector<int>& nums, int left, int right) {
    if (left >= right)  return;
    int mid = left + ((right - left) >> 1);
    sort2(nums, left, mid);
    sort2(nums, mid + 1, right);
    blockSwap(nums, left, mid, right);
}

void blockSwap(vector<int>& nums, int left, int mid, int right) {
    int l = left, r = mid + 1;
    while (l < r && r <= right) {
        while (l < r && nums[l] <= nums[r]) ++l;
        int idx = r;
        while (r <= right && nums[r] < nums[l]) ++r;
        exchange(nums, l, idx - 1, r - 1);
    }
}

void exchange(vector<int>& nums, int l, int idx, int r) {
    reverse(nums, l, idx);
    reverse(nums, idx + 1, r);
    reverse(nums, l, r);
}

void reverse(vector<int>& nums, int l, int r) {
    while (l < r) {
        swap(nums, l++, r--);
    }
}