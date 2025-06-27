class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n= grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));


        queue<pair<int,int>> q;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m; j++){
                if(grid[i][j]==2){
                    vis[i][j]=1;
                    q.push({i,j});
                }
            }
        }

        int minutes=-1;
        while(!q.empty()){
            int dc=q.size();
            for(int k=0 ; k<dc ; k++){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
    
                int row[4]={-1,0,1,0};
                int col[4]={0,1,0,-1};
                for(int i=0 ; i<4 ; i++){
                    int nr=r+row[i];
                    int nc=c+col[i];
                    if( nr>=0 && nc>=0 && nr<n && nc<m && vis[nr][nc]==0 && grid[nr][nc]==1){
                        
                        vis[nr][nc]=1;
                        grid[nr][nc]=2;
                        q.push({nr,nc});
                        
                    }
                }
            }
            


            minutes+=1;
        }

        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m; j++){
                cout<<grid[i][j]<< " ";
                if(grid[i][j]==1) return -1;
                
            }
            cout<<endl;
        }

        if(minutes==-1) return 0;
        return minutes;
    }
};