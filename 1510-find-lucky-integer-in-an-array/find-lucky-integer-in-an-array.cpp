class Solution {
public:
    int findLucky(vector<int>& arr) {
        
        map<int,int> mpp;
        for(int i=0 ; i<arr.size() ; i++){
            mpp[arr[i]]++;
        }
        int maxi=-1;
        for(auto it : mpp){
            if(it.first==it.second && it.first>maxi) maxi=it.first;
        }
        return maxi;


    }
};