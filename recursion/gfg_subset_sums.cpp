class Solution {
  public:
    void fn(vector<int>&arr,int i,int sum,vector<int>&ans){
        if(i==arr.size()){
            ans.push_back(sum);
            return;
        }
        fn(arr,i+1,sum+arr[i],ans);
        fn(arr,i+1,sum,ans);
    }
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        
        vector<int>ans;
        fn(arr,0,0,ans);
        return ans;
        
    }
};