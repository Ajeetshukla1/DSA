class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int k=2;
        int n=fruits.size();
        int left=0;
        map<int,int>mp;
        int cnt=0;
        int maxi=INT_MIN;
        for(int right=0;right<n;right++){
            mp[fruits[right]]++;
            while(mp.size()>k){
                mp[fruits[left]]--;
                maxi=max(maxi,right-left);
                if(mp[fruits[left]]==0) mp.erase(fruits[left]);
                left++;
            }
            if(mp.size()<=k) maxi=max(maxi,right-left+1);
            
           
        }
        return maxi;
    }
};