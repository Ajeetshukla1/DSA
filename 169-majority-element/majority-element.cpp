class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int majCurr=nums[0];
        int cnt=0;
        for(int i=0;i<n;i++){
            if(majCurr==nums[i]){
                cnt++;
            }
            else{
                cnt--;
                if(cnt==0) {
                    majCurr=nums[i];
                    cnt=1;
                }
            }
        }
        return majCurr;
        
    }
};