class Solution {
public:

    int maxEvents(vector<vector<int>>& events) {

        int n=events.size();
        sort(events.begin(),events.end());
        priority_queue<int,vector<int>,greater<int>> pq;

        int maxDay=0;
        int cnt=0;
        for(int i=0 ; i<n ; i++) maxDay=max(events[i][1],maxDay);
        
        for(int day=0 , j=0 ; day<=maxDay ; day++){

            //put all events end date inside whose starting day is lesser or equal to current day
            while(j<n && events[j][0]<=day){
                pq.push(events[j][1]);
                j++;
            }
            //remove all events end date which has expired ie end date is past current day
            while(!pq.empty() && pq.top()<day){
                pq.pop();
            }
            //if still an event exist then it will be executed on that day
            if(!pq.empty()){
                pq.pop();
                cnt++;
            }
        }
      
        return cnt;
    }
};