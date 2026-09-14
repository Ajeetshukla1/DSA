class Solution {
public:
vector<vector<int>>ans;
    void fn(int ind,vector<int>&curr,int target,vector<int> &candidates){
        if(target==0){
            ans.push_back(curr);
            return;
        }
        for(int i=ind;i<candidates.size();i++){
            if(i>ind && candidates[i]==candidates[i-1]) continue; //to avoid duplicates
            if(candidates[i]>target) break;
            curr.push_back(candidates[i]);
            fn(i+1,curr,target-candidates[i],candidates);
            curr.pop_back();

        }
        
        
        
        

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
         int n =candidates.size();
        vector<int> curr;
        sort(candidates.begin(),candidates.end()); // to get the target subsequence in sorted order
        fn(0,curr,target,candidates);
        return ans;
    }
};