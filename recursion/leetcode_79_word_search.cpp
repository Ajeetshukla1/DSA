class Solution {
public:
    bool fn(int i,int j, int ind, vector<vector<int>>&visited,vector<vector<char>>&board,string &word){
        
        int n =board.size();
        int m=board[0].size();
        if(i < 0 || i >= n || j < 0 || j >= m) return false;
        if (visited[i][j]==-1 || board[i][j] != word[ind]) return false;
        if(ind==word.size()-1) return true;

        visited[i][j]=-1;
        
        bool right=fn(i,j+1,ind+1,visited,board,word); 
        bool left=fn(i,j-1,ind+1,visited,board,word); 
        bool top=fn(i-1,j,ind+1,visited,board,word); 
        bool bottom=fn(i+1,j,ind+1,visited,board,word); 
        visited[i][j]=0;

        return right || left || top || bottom;
        
    }
    bool exist(vector<vector<char>>& board, string word) {

        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                // find the first matching letter than start dfs search
                if(word[0]==board[i][j]){
                    if(fn(i,j,0,visited,board,word)) return true;
                }
                
            }
        }
        return false;
        
    }
};