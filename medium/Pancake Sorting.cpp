class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            int max_ind = find(arr, i);
            flip(arr, max_ind + 1);
            flip(arr, n - i);
            ans.push_back(max_ind + 1);
            ans.push_back(n - i);
        }
        print(arr);
        return ans;
    }

    template<typename T>
    void print(vector<T>& nums) {
        for (auto &x : nums) cout << x << ' ';
        cout << endl;
    }

    void flip(vector<int>& arr, int k) {
        for (int i = 0; i < k / 2; i++) {
            swap(arr[i], arr[k - i - 1]);
        }
    }

    int find(vector<int>& arr, int l) {
        int max_ = INT_MIN;
        int ind = -1;
        for (int i = 0; i < arr.size() - l; i++) {
            if (arr[i] > max_) {
                max_ = arr[i];
                ind = i;
            }
        }
        return ind;
    }
};
