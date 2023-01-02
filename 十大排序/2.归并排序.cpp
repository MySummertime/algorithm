#include <vector>

using std::vector;


/*1.自顶向下递归--非原地
Time: O(nlogN)
Space: O(n)
*/
vector<int> mergeSort1(vector<int> nums) {
    if (nums.size() < 2)    return nums;
    vector<int> vec(nums.size());
    sort(nums, vec, 0, nums.size() - 1);
    return nums;
}

void sort(vector<int>& nums, vector<int>& vec, int left, int right) {
    if (left >= right)  return;
    int mid = left + ((right - left) >> 1);
    sort(nums, vec, left, mid);
    sort(nums, vec, mid + 1, right);
    merge(nums, vec, left, mid, right);
}

void merge(vector<int>& nums, vector<int>& vec, int left, int mid, int right) {
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
    
}