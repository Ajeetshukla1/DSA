class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        long long cnt = 0;
        for (int i = 0; i < n; i++) {
            while (!pq.empty() && pq.top() < intervals[i][0]) {
                pq.pop();
            }
            cnt += pq.size();
            pq.push(intervals[i][1]);
        }
        return cnt;
    }
};