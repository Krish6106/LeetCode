class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>hash(256,-1);
        int n = s.size();
        int l = 0, r =0, max_length= 0;
        while(r<n){
            if(hash[s[r]] != -1){
                if(hash[s[r]] >= l){
                    l = hash[s[r]]+ 1;
                }
            }
            int len = r-l+1;
            max_length= max(max_length,len);
            hash[s[r]]=r;
            r++;
        }
        return max_length;
    }
};