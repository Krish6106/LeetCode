class Solution {
public:
    bool possible(vector<int>&bloomDay, int day ,int a, int b){
        int cnt = 0;
        int noOfb = 0;
        for(int i = 0; i<bloomDay.size();i++){
            if(bloomDay[i]<=day){
                cnt++;
            }
            else{
                noOfb +=(cnt)/b;
                cnt = 0;
            }
            
        }
        noOfb +=(cnt)/b;

        return noOfb >= a;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long value = m * 1LL * k * 1LL;
        if(value>bloomDay.size()) return -1;
        int maxi = INT_MIN , mini = INT_MAX;
        for(int i=0;i<bloomDay.size();i++){
            mini = min(mini,bloomDay[i]);
            maxi = max(maxi,bloomDay[i]);
        }
        int st= mini, end = maxi;
        while(st<=end){
            int mid = st +(end-st)/2;
            if(possible(bloomDay,mid,m,k)){
                end = mid -1;
            }
            else{
                st = mid +1;
            }
        }
        return st;

        
    }
};