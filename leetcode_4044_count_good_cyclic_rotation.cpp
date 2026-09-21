class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n=nums.size();
        long long rightSum=0;
        long long leftSum=0;
    
        
        for(int i=0;i<n/2;i++){
            rightSum+=nums[i];
        }
        for(int i=n/2;i<n;i++){
            leftSum+=nums[i];
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            rightSum+=nums[(n/2+i)%n]-nums[i];
            leftSum+=nums[i]-nums[(n/2+i)%n];
            if(leftSum<rightSum) cnt++;
        }
        return cnt;
        
    }
};