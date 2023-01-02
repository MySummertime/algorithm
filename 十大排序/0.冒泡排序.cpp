#include <vector>

using std::vector;


void swap(vector<int>& nums, int i, int j) {
    if (i == j) return;
    nums[i] = nums[i] + nums[j];
    nums[j] = nums[i] - nums[j];
    nums[i] = nums[i] - nums[j];
}

/*优化1：提前结束循环
当某一轮循环中未发生交换，说明整体排序已完成。
设置一个布尔值记录每轮排序中是否发生了交换，如果没有交换，则立刻退出循环，结束程序
*/

void bubbleSort1(vector<int>& nums) {
    if (nums.size() < 2)    return;
    bool flag = false;
    for (int i = 0, len = nums.size(); i < len; ++i) {
        for (int j = 1; j < len - i; ++j) {
            if (nums[j - 1] > nums[j]) {
                swap(nums, j - 1, j);
                flag = true;
            }
        }
        if (!flag)  break;
    }
}


/*优化2：冒泡边界优化
记录上一轮排序进行交换的最终下标位置，该位置之后的元素为已排序状态。
下一轮排序只需执行到该位置即可，通过缩小每轮循环的边界来提前结束循环。
*/

void bubbleSort2(vector<int>& nums) {
    if (nums.size() < 2)    return;
    int last_idx = nums.size() - 1;
    while (last_idx) {
        int cur_idx;
        for (int i = 0; i < last_idx; ++i) {
            if (nums[i] > nums[i + 1]) {
                swap(nums, i, i + 1);
                cur_idx = i;
            }
        }
        last_idx = cur_idx;
    }
}