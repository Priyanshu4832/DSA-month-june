class FindSumPairs {
private:
    vector<int> nums1;
    vector<int> nums2;
    unordered_map<int, int> freq1; 
    unordered_map<int, int> freq2; 
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1=nums1;
        this->nums2=nums2;

        for(auto it : nums1) freq1[it]++;
        for(auto it : nums2) freq2[it]++;
    }
    
    void add(int index, int val) {
        
        freq2[nums2[index]]--;
        if(freq2[nums2[index]]==0) freq2.erase(nums2[index]);

        nums2[index]+=val;
        freq2[nums2[index]]++;
    }
    
    int count(int tot) {
        int cnt=0;
        for(auto it : freq1){
            int rem=tot-it.first;
            if(freq2.find(rem)!=freq2.end()){
                cnt+=it.second*freq2[rem];
            }
        }
        return cnt;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */