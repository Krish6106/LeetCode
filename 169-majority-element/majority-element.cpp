class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n =nums.size();
        int freq = 0, ans = 0;
        for(int i=0; i<n; i++){
            if(freq==0){
                ans = nums[i];
            }
            if(ans==nums[i]){
                freq++;
            }
            else{
                freq--;
            }
        }
        int count =0;
        for(int val: nums){
            if(val==ans){
                count++;
            }        
        }
        if(count> n/2){
            return ans;
        }
        else{
            return -1;
        }
        return ans;
        
    }
};