class Solution {
public:
    
    
    
    vector<int> maxPrimes(int n, int s) {
        vector<int> p;
        for(int i=2;i<=n;i++){
            bool prime=true;
            for(int j=2;j*j<=i;j++){
                if(i%j==0){
                    prime=false;
                    break;
                }
            }
            if(prime){
                if(s-i<0) return p;
                p.push_back(i);
                s-=i;
            }
        }
        return p;
        
        
    }
};