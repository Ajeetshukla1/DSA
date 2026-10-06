class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int ans=0;
        int win=n-k;
        for(int i=0;i<win;i++){
            ans+=cardPoints[i];
        }
        int total=ans;
        int mini=ans;
        int j=0;
        for(int i=win;i<n;i++){
            ans+=cardPoints[i];
            ans-=cardPoints[j];
            mini=min(ans,mini);
            j++;
            total+=cardPoints[i];

        }
        return total-mini;

        
        
    }
};