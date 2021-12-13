class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quicksort(nums, 0, nums.size() - 1);
        return nums;
    }
    
    void quicksort(vector<int>& nums, int left, int right) {
        if (left < right) {
            int q = partition(nums, left, right);
            quicksort(nums, left, q - 1);
            quicksort(nums, q + 1, right);
        }
    }
    
    int partition(vector<int>& nums, int left, int right) {
        int piv_ind = rand() % (right - left + 1) + left;
        swap(nums[piv_ind], nums[right]);
        
        int pivot = nums[right];
        int i = left - 1;
        for (int j = left; j < right; j++) {
            if (nums[j] <= pivot) {
                i++;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[right], nums[i + 1]);
        return i + 1;
    }
};
