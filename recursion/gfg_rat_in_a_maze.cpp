class Solution {
  public:
   vector<string>ans;
    void fn(int i,int j,vector<vector<int>>&maze,string &temp){
        int n=maze.size();
      
        
        if (i < 0 || i >= n || j < 0 || j >= n ) return;
        if(maze[i][j]==0) return;
        if(i==n-1 && j==n-1){
            ans.push_back(temp);
            return;
        }
        maze[i][j]=0;
        temp+='D';
        fn(i+1,j,maze,temp);
        temp.pop_back();
        temp+='U';
        fn(i-1,j,maze,temp);
        temp.pop_back();
        temp+='R';
        fn(i,j+1,maze,temp);
        temp.pop_back();
        temp+='L';
        fn(i,j-1,maze,temp);
        temp.pop_back();
        maze[i][j]=1;
        
        
        
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        string temp="";
        fn(0,0,maze,temp);
        sort(ans.begin(),ans.end());
        return ans;
        
        
    }
};