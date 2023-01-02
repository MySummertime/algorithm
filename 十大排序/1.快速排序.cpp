#include <vector>
#include <stack>

using std::vector;
using std::stack;


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


/*1.单轴快排（首位轴）--递归
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


/*2.单轴快排（随机轴）--递归
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


/*3.单轴快排（三数取中轴）--递归
*/
void quickSort3(vector<int>& nums) {
    if (nums.size() < 2)    return;
    sort3(nums, 0, nums.size() - 1);
}

void sort3(vector<int>& nums, int left, int right) {
    getMedian3(nums, left, right);
    int pivot = partition(nums, left, right);
    sort3(nums, left, pivot - 1);
    sort3(nums, pivot + 1, right);
}

int getMedian3(vector<int>& nums, int left, int right) {
    // execute this function so that nums[mid] < nums[left] < nums[right]
    int mid = left + ((right - left) >> 1);
    if (nums[left] > nums[mid]) swap(nums, left, mid);
    if (nums[mid] > nums[right])    swap(nums, mid, right);
    if (nums[mid] > nums[left]) swap(nums, mid, left);
}


/*4.单轴快排（首位轴）--迭代
*/
void quickSort4(vector<int>& nums) {
    if (nums.size() > 2)    return;
    stack<int> stk;
    stk.push(nums.size() - 1);
    stk.push(0);
    while (!stk.empty()) {
        int right = stk.top();  stk.pop();
        int left = stk.top();   stk.pop();
        if (left >= right)  break;
        int pivot = partition(nums, left, right);
        stk.push(pivot - 1);
        stk.push(left);
        stk.push(right);
        stk.push(pivot + 1);
    }
}


/*5.单轴快排（随机轴）--迭代
*/
void quickSort5(vector<int>& nums) {
    if (nums.size() < 2)    return;
    stack<int> stk;
    stk.push(nums.size() - 1);
    stk.push(0);
    while (!stk.empty()) {
        int right = stk.top();  stk.pop();
        int left = stk.top();   stk.pop();
        if (left >= right)  break;
        int idx = rand() % (right - left + 1) + left;
        swap(nums, left, idx);
        int pivot = partition(nums, left, right);
        stk.push(pivot - 1);
        stk.push(left);
        stk.push(right);
        stk.push(pivot + 1);
    }
}


/*6.单轴快排（三数取中轴）--迭代
*/
void quickSort6(vector<int>& nums) {
    if (nums.size() < 2)    return;
    stack<int> stk;
    stk.push(nums.size() - 1);
    stk.push(0);
    while (!stk.empty()) {
        int right = stk.top();  stk.pop();
        int left = stk.top();   stk.pop();
        if (left >= right)  break;
        getMedian6(nums, left, right);
        int pivot = partition(nums, left, right);
        stk.push(pivot - 1);
        stk.push(left);
        stk.push(right);
        stk.push(pivot + 1);
    }
}

void getMedian6(vector<int>& nums, int left, int right) {
    // execute the function so that nums[mid] < nums[left] < nums[right]
    int mid = left + ((right - left) >> 1);
    if (nums[left] > nums[mid]) swap(nums, left, mid);
    if (nums[mid] > nums[right])    swap(nums, mid, right);
    if (nums[mid] > nums[left]) swap(nums, mid, left);
}


/*7.双轴快排
*/
void dualPivotQuickSort(vector<int>& nums) {
    if (nums.size() < 2)    return;

}

void dualPivotSort(vector<int>& nums, int left, int right) {
    if (left >= right)  return;
    if (nums[left] > nums[right]) {
        swap(nums, left, right);
    }
    // 3 intervals:
    // [left, lower)中的元素确定属于interval 1
    // [lower, index)中的元素确定属于interval 2, [index, upper] 中的元素待确定
    // (upper, right]中的元素确定属于interval 3
    int idx = left + 1;
    int lower = left + 1;   // 1 element in interval 1
    int upper = right - 1;  // 1 element in interval 3
    while (idx <= upper) {
        if (nums[idx] < nums[left]) {
            swap(nums, idx, lower);
            ++lower;
        }
        else if (nums[idx] > nums[right]) {
            while (nums[upper] > nums[right] && idx < upper) {
                --upper;
            }
            swap(nums, idx, upper);
            --upper;
            if (nums[idx] < nums[left]) {
                swap(nums, idx, lower);
                ++lower;
            }
        }
        ++idx;
    }
    --upper;
    ++lower;
    // put the left pivot element to its original index
    swap(nums, lower, left);
    // put the right pivot element to its original index
    swap(nums, upper, right);
    dualPivotSort(nums, left, lower - 1);
    dualPivotSort(nums, lower + 1, upper - 1);
    dualPivotSort(nums, upper + 1, right);
}