class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int min1 = nums1.size(), max1 = 6 * nums1.size();
        int min2 = nums2.size(), max2 = 6 * nums2.size();
        if (min2 > max1 || min1 > max2) return -1;

        int sum1 = accumulate(nums1.begin(), nums1.end(), 0);
        int sum2 = accumulate(nums2.begin(), nums2.end(), 0);

        int ans = 0;

        if (sum1 > sum2) {
            swap(nums1, nums2);
            swap(sum1, sum2);
        }
        for (int x = 1; x < 7 && sum1 < sum2; x++) {

            for (int i = 0; i < nums1.size() && sum1 < sum2; i++) {
                if (x != 6 && nums1[i] == x) {
                    nums1[i] = 6;
                    sum1 += 6 - x;
                    ans++;
                }
            }
            for (int i = 0; i < nums2.size() && sum1 < sum2; i++) {
                if (x != 6 && nums2[i] == 7 - x) {
                    nums2[i] = 1;
                    sum2 -= 6 - x;
                    ans++;
                }
            }

        }

        return ans;
    }
};
