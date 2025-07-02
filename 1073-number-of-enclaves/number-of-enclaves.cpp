class Solution {
public:

    int numEnclaves(vector<vector<int>>& grid) {

        int m= grid.size();
        int n= grid[0].size();
        
        //vector<vector<int>> vis(m,vector<int>(n,0));


        queue<pair<int,int>> q;

        for(int i=0 ; i<m ; i++){
            if(grid[i][0]==1){
                grid[i][0]=0;
                q.push({i,0});
            }
            if(grid[i][n-1]==1){
                grid[i][n-1]=0;
                q.push({i,n-1});
            }
        }
        for(int i=0 ; i<n ; i++){
            if(grid[0][i]==1){
                grid[0][i]=0;
                q.push({0,i});
            }
            if(grid[m-1][i]==1){
                grid[m-1][i]=0;
                q.push({m-1,i});
            }
        }


        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();

            int drow[4]={-1,0,1,0};
            int dcol[4]={0,1,0,-1};
            for(int i=0 ; i<4 ; i++){
                int nr=drow[i]+r;
                int nc=dcol[i]+c;
                if(nr>=0 && nc>=0 && nr<grid.size() && nc<grid[0].size() && grid[nr][nc]==1){
                    grid[nr][nc]=0;
                    q.push({nr,nc});
                }
            }

        }


        int cnt=0;
        for(int i=0 ; i<m ; i++){
            for(int j=0  ; j<n ; j++){
                if(grid[i][j]==1){
                    cnt+=1;
                }
            }
        }
        return cnt;
    }
};