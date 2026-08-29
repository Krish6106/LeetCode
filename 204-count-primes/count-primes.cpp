class Solution {
public:
    int countPrimes(int n) {
        if(n<=2) return 0;
        int size=n/2;
        vector<bool> p(size,true);
        p[0]=false; //1 is not prime
        for(int i=1;2*i+1 <= sqrt(n-1);i++){
            if(p[i])
            {
                int k=2*i+1;
                int s=(k*k)/2;
                for(int j=s;j<size;j+=k){
                    p[j]=false;
                }
            }
        }
        int c=1;
        for(int i=1;i<size;i++){
            if(p[i])
            c++;
        }
        return c;
    }
};