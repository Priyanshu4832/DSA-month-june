class Solution {
public:
    int possibleStringCount(string word) {
        // unordered_map<char,int> mpp;
        // for(int i=0 ; i<word.size() ; i++){
        //     mpp[word[i]]++;
        // }

        // int cnt=1;
        // for(auto it : mpp){
        //     if(it.second>1){
        //         cnt+=it.second-1;
        //     }
        // }
        // return cnt;
        
        int cnt=1;
        for(int i=0 ; i<word.size()-1 ; i++){
            if(word[i]==word[i+1]){
                cnt+=1;
            }
        }
        return cnt;
    }
};