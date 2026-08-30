class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int start = INT_MIN, end = 0;
        for (int i = 0; i < n; i++) {
            start = max(start, nums[i]);
            end += nums[i];
        }
        int ans = 0;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            int sum = 0, noOfSubarrays = 1;
            for (int i = 0; i < n; i++) {
                if (sum + nums[i] > mid) {
                    sum = nums[i];
                    noOfSubarrays++;
                } else
                    sum += nums[i];
            }
            if (noOfSubarrays <= k) {
                ans = mid;
                end = mid - 1;
            } else
                start = mid + 1;
        }
        return ans;
    }
};