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
    blockSwap2(nums, left, mid, right);
}

void blockSwap2(vector<int>& nums, int left, int mid, int right) {
    int l = left, r = mid + 1;
    while (l < r && r <= right) {
        // find the leftmost element to the left side of r which is > nums[r]
        while (l < r && nums[l] <= nums[r]) ++l;
        int idx = r;
        // find the leftmost element to the right side of r which is >= nums[l]
        while (r <= right && nums[r] < nums[l]) ++r;
        exchange2(nums, l, idx - 1, r - 1);
    }
}

void exchange2(vector<int>& nums, int l, int idx, int r) {
    reverse2(nums, l, idx);
    reverse2(nums, idx + 1, r);
    reverse2(nums, l, r);
}

void reverse2(vector<int>& nums, int l, int r) {
    while (l < r) {
        swap(nums, l++, r--);
    }
}


/*3.自底向上迭代--非原地
Time: O(nlogN)
Space: O(n)
*/
vector<int> mergeSort3(vector<int>& nums) {
    if (nums.size() < 2)    return nums;
    int len = nums.size();
    vector<int> vec(len);
    for (int gap = 1; gap < len; gap *= 2) {
        for (int l = 0, r; l < len - gap; l += gap * 2) {
            r = std::min(l + gap * 2 - 1, len - 1);
            merge3(nums, vec, l, l + gap - 1, r);
        }
    }
    return nums;
}

void merge3(vector<int>& nums, vector<int>& vec, int left, int mid, int right) {
    int l = left, r = mid + 1;
    int idx = left;
    while (l <= mid && r <= right) {
        vec[idx++] = nums[l] < nums[r] ? nums[l++] : nums[r++];
    }
    while (l <= mid) {
        vec[idx++] = nums[l++];
    }
    while (r <= right) {
        vec[idx++] = nums[r++];
    }
    // copy values of vec to nums
    for (; left <= right; ++left) {
        nums[left] = vec[left];
    }
}


/*4.自底向上迭代--原地
Time: O(n^2)
Space: O(1)
*/
vector<int> mergeSort4(vector<int>& nums) {
    if (nums.size() < 2)    return nums;
    int len = nums.size();
    for (int gap = 1; gap < len; gap *= 2) {
        for (int l = 0, r; l < len - gap; l += gap * 2) {
            r = std::min(l + gap * 2 - 1, len - 1);
            blockSwap4(nums, l, l + gap - 1, r);
        }
    }
    return nums;
}

void blockSwap4(vector<int>& nums, int left, int mid, int right) {
    int l = left, r = mid + 1;
    while (l < r && r <= right) {
        // find the leftmost element to the left of nums[r] which is > nums[r]
        while (l < r && nums[l] <= nums[r]) ++l;
        int idx = r;
        // find the leftmost element to the right of nums[l] which is >= nums[l]
        while (r <= right && nums[r] < nums[l]) ++r;
        exchange4(nums, l, idx - 1, r - 1);
    }
}

void exchange4(vector<int>& nums, int left, int mid, int right) {
    reverse4(nums, left, mid);
    reverse4(nums, mid + 1, right);
    reverse4(nums, left, right);
}

void reverse4(vector<int>& nums, int left, int right) {
    while (left < right) {
        swap(nums, left++, right--);
    }
}