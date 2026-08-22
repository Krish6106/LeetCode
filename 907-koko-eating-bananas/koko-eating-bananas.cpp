class Solution {
public:
    int findMax(vector<int>& piles) {
        int maxi = INT_MIN;
        for (int i = 0; i < piles.size(); i++) {
            maxi = max(maxi, piles[i]);
        }
        return maxi;
    }

    // CRITICAL: This MUST return a 'long long'
    long long calculateTotalHours(vector<int>& piles, int hourly) {
        long long totalH = 0; 
        for (int i = 0; i < piles.size(); i++) {
            totalH += piles[i] / hourly + (piles[i] % hourly != 0);
        }
        return totalH;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int st = 1; 
        int end = findMax(piles);
        int ans = end;

        while (st <= end) {
            int mid = st + (end - st) / 2;
            
            // CRITICAL: This variable MUST be 'long long' to hold the result
            long long totalH = calculateTotalHours(piles, mid);
            
            if (totalH <= h) {
                ans = mid;      
                end = mid - 1;  
            } else {
                st = mid + 1;   
            }
        }
        return ans;
    }
};
