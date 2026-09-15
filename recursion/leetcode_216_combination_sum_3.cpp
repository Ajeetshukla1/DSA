class Solution {
public:
vector<vector<int>>ans;
    void fn(int ind,int k,int target,vector<int>&temp){
        if(target==0 && k==0){
            ans.push_back(temp);
        };
        if(k==0) return;
        if(ind==10) return;
        
        for(int i=ind;i<=9;i++){
            if(target-ind<0) return;
            temp.push_back(i);
            fn(i+1,k-1,target-i,temp);
            temp.pop_back();
            

        }

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>temp;
        fn(1,k,n,temp);
        return ans;
        
        
    }
};