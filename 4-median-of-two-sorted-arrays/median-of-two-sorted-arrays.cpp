class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        int i=0;
        int j=0;
        if((n1+n2)==0) return 0;
        vector<int> mergeArr;
        while(i<n1 && j<n2){
            if(nums1[i]>nums2[j] ){
                mergeArr.push_back(nums2[j]);
                j++;
            }
            else if(nums1[i]<=nums2[j]){
                    mergeArr.push_back(nums1[i]);
                    i++;
                }
            }
        while(i<n1){
            mergeArr.push_back(nums1[i]);
            i++;
        }
        while(j<n2 ){
            mergeArr.push_back(nums2[j]);
            j++;
        }
        int m=mergeArr.size();
        if(m%2==0){
            return ((double)mergeArr[m/2]+(double)mergeArr[(m/2)-1])/2;
        }
        return (double)mergeArr[m/2];
    }
};