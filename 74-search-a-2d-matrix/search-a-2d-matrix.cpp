class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int l=0,h=n*m-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            int val=matrix[mid/m][mid%m];
            if(val==target) return true;
            else if(val<target) l=mid+1;
            else
            h=mid-1;
        }
        return false;
    }
};