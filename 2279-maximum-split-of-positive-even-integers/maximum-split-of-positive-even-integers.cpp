class Solution {
public:

    // long long func(int idx , int sum , vector<long long> res , vector<vector<long long>> &ans,vector<vector<long long>>& dp){

    //     if (sum==0) {
    //         ans.push_back(res);
    //         return 0;
    //     }
    //     if(idx*2>sum){
    //         return 0;

    //     }
    //     if(dp[idx][sum]!=-1) return dp[idx][sum];

    //     long long pick=0;
    //     if(2*idx<=sum){
    //         res.push_back(2*idx);
    //         pick = 1+func(idx+1,sum-2*idx,res,ans,dp);
    //         res.pop_back();
    //     }
    //     long long not_pick = 0 + func(idx+1 , sum , res,ans,dp);

    //     return dp[idx][sum]=max(pick,not_pick);


    // }

    vector<long long> maximumEvenSplit(long long finalSum) {
        
        if(finalSum%2!=0) return {};
        if(finalSum==2) return {2};
        // vector<long long > res;
        // vector<vector<long long>> ans;

        // vector<vector<long long>> dp(finalSum/2 +1 , vector<long long>(finalSum+1,-1));
        // long long maxi= INT_MIN;
        // long long store;
        // for(int i=0 ; i<ans.size() ; i++){
        //     if(ans[i].size()>maxi){
        //         store=i;
        //     }
        // }
        // func(1,finalSum,res,ans,dp);
        // return ans[store];
        vector<long long > res;

        long long sum = finalSum;
        for(int i=1 ; i<=finalSum/2 ; i++){
            if( (sum-(2*i))>= (2*i) +2   ){
                res.push_back(2*i);
                sum-=2*i;
            }
            else if((sum-2*i)==0){
                res.push_back(2*i);
                sum-=2*i;
                break;
            }
            else if( (sum-2*i)<(2*i)+2 ){
                res.push_back(sum);
                break;
            }
            
            else break;
        }
        return res;




    }
};