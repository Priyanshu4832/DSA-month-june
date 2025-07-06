class Solution {
public:

    long long func(int i , int j , int time , vector<vector<int>>& waitCost ,vector<vector<vector<long long>>>& dp ){

        int m=waitCost.size();
        int n=waitCost[0].size();
        if( i==m-1 && j==n-1){
            return 1;
        }

        if(dp[i][j][time]!=-1) return dp[i][j][time];
        long long cost=LLONG_MAX;
        
        if(time==0){
            cost = waitCost[i][j] + func(i,j,1,waitCost,dp);
        }
        else {
            int dr[2]={0,1};
            int dc[2]={1,0};
            for(int k=0 ; k<2 ; k++){
                int nr=dr[k]+i;
                int nc=dc[k]+j;
                if(nr<m && nc<n && nr>=0 && nc>=0){
                    cost = min(cost,  (nr+1)*(nc+1)+func(nr,nc,0,waitCost,dp));
                }
            }
        }
        return dp[i][j][time]=cost;

    }
    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
        
        vector<vector<vector<long long>>> dp(m,vector<vector<long long>>(n,vector<long long>(2,-1)));
        return func(0,0,1,waitCost,dp);
    }
};