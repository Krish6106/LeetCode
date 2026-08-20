class Solution {
public:
    int findMin(vector<int>& nums) {
        int st = 0, end = nums.size()-1;
        int ans = INT_MAX;
        while(st<=end){
            int mid = st +(end-st)/2;
            if(nums[mid]>=nums[st]){
                ans = min(ans,nums[st]);
                st = mid +1;
            }
            else{
                ans = min(ans, nums[mid]);
                end = mid -1;
            }
        }
        return ans;
        
    }
};