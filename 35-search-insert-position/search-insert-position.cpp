class Solution {
public:
    int searchInsert(vector<int>& nums, int x) {
        int n = nums.size();
        int st = 0 , end = n - 1;
        int ans = n;
        while(st<=end){
            int mid = st + (end-st)/2;
            if(nums[mid]>= x){
                ans = mid;
                end = mid -1;
            }
            else{
                st = mid + 1;
            }
        }
        return ans;
        
    }
};