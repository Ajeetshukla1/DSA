class Solution {
public:
    long long countCommas(long long n) {
        long long sum=0;
        if(n-999>0) sum+=n-999;
        if(n-999999>0) sum+=n-999999;
        if(n-999999999>0) sum+=n-999999999;
        if(n-999999999999>0) sum+=n-999999999999;
        if(n-999999999999999>0) sum+=n-999999999999999;

        return sum;    
    }
};
