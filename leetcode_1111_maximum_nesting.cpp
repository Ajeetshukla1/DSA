class Solution {
public:
    
    vector<int> maxDepthAfterSplit(string seq) {
        int depth=0;
        int n=seq.size();
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            
            if(seq[i]=='('){
                arr[i]=depth%2;
                depth++;
            }
            else {
                depth--;
                arr[i]=depth%2;
            }
            
        }
        return arr;

       
    }
};