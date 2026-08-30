class Solution {
public:
    int count(vector<int>& nums, int mid, int n, int m) {
        int count = 0;
        for (int i = 0; i < n; i++) {
            count += (nums[i] + mid - 1) / mid;
        }
        if (count <= m) return 1;
        return 2;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int low = 1;
        int high = INT_MIN;
        for (int i = 0; i < n; i++) {
            high = max(high, nums[i]);
        }
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int div = count(nums, mid, n, threshold);
            if (div <= 1) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};