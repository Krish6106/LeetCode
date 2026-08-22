class Solution {
public:
    bool isValid(vector<int>& quantities, int n, int maxAllowedQuant) {
        int stores = 0;

        for(int q : quantities) {
            stores += (q + maxAllowedQuant - 1) / maxAllowedQuant;

            if(stores > n) {
                return false;
            }
        }

        return true;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {
        int ans = -1;

        int st = 1;
        int end = *max_element(quantities.begin(), quantities.end());

        while(st <= end) {
            int mid = st + (end - st) / 2;

            if(isValid(quantities, n, mid)) {
                ans = mid;
                end = mid - 1;
            }
            else {
                st = mid + 1;
            }
        }

        return ans;
    }
};