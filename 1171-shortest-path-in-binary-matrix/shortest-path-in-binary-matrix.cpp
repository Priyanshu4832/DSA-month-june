class Solution {
public:
    void SP(int row , int col , int steps , int &ans, vector<vector<int>>& grid,vector<vector<int>>& vis ){
        
    }

   
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        if(grid[0][0]==1) return -1;

        int ans=INT_MAX;
        vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(),0));
        vis[0][0]=1;
        queue<pair<int,int>> q;
        q.push({0,0});

        int steps=1;
        while(!q.empty()){
            int a = q.size();
            for(int b=0 ; b<a ; b++){
                int r=q.front().first;
                int c=q.front().second;
                q.pop();

                if(r==grid.size()-1 && c== grid[0].size()-1) return steps;
            
                int drow[8]={-1,-1,0,1,1,1,0,-1};
                int dcol[8]={0,1,1,1,0,-1,-1,-1};

                for(int i=0 ; i<8 ; i++){
                    int nr=drow[i]+r;
                    int nc=dcol[i]+c;
                    if(nr>=0 && nc>=0 && nr<grid.size() && nc<grid[0].size() && grid[nr][nc]==0 && vis[nr][nc]==0){
                        vis[nr][nc]=1;
                        q.push({nr,nc});
                        cout<<" row "<<nr<<" col "<<nc;
                    }
                }
                cout<<endl;
            }
            steps+=1;
        }
        return -1;



    }
};