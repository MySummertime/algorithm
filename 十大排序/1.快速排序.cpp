#include <vector>

using std::vector;


void swap(vector<int>& nums, int i, int j) {
    nums[i] = nums[i] + nums[j];
    nums[j] = nums[i] - nums[j];
    nums[i] = nums[i] = nums[j];
}

int partition(vector<int>& nums, int pivot, int right) {
    int l = pivot + 1;
    for (int r = l; r <= right; ++r) {
        if (nums[r] < nums[pivot]) {
            // nums[l] is the rightmost element which is < nums[pivot]
            swap(nums, l, r);
            ++l;
        }
    }
    // put the pivot element back to its original index
    swap(nums, pivot, l - 1);
    // return the index of new pivot
    return l - 1;
}


/*1.单轴（首位轴）快排--递归
*/
void quickSort1(vector<int>& nums) {
    if (nums.size() < 2)    return;
    sort1(nums, 0, nums.size() - 1);
}

void sort1(vector<int>& nums, int left, int right) {
    if (left >= right)  return;
    int pivot = partition(nums, left, right);
    sort1(nums, left, pivot - 1);
    sort1(nums, pivot + 1, right);
}


/*2.单轴（随机轴）快排--递归
*/
void quickSort2(vector<int>& nums) {
    if (nums.size() < 2)    return;
    sort2(nums, 0, nums.size() - 1);
}

void sort2(vector<int>& nums, int left, int right) {
    if (left >= right)  return;
    int idx = rand() % (right - left + 1) + left;
    swap(nums, left, idx);
    int pivot = partition(nums, left, right);
    sort2(nums, left, pivot - 1);
    sort2(nums, pivot + 1, right);
}


/*3.单轴（三数取中轴）快排--递归
*/
void quickSort3(vector<int>& nums) {
    if (nums.size() < 2)    return;
    sort3(nums, 0, nums.size() - 1);
}

void sort3(vector<int>& nums, int left, int right) {
    getMedian(nums, left, right);
    int pivot = partition(nums, left, right);
    sort3(nums, left, pivot - 1);
    sort3(nums, pivot + 1, right);
}

int getMedian(vector<int>& nums, int left, int right) {
    // execute this function so that nums[mid] < nums[left] < nums[right]
    int mid = left + ((right - left) >> 1);
    if (nums[left] > nums[mid]) swap(nums, left, mid);
    if (nums[mid] > nums[right])    swap(nums, mid, right);
    if (nums[mid] > nums[left]) swap(nums, mid, left);
}

