class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {



        if(edges.size()==0 && n==1) return 0;

        vector<vector<pair<int,pair<int,int>>>> adj(n);
        int flag=0;
        int t=INT_MIN;
        for(auto it : edges){

            adj[it[0]].push_back({it[1],{it[2],it[3]}});
            if(it[1]==n-1) flag=1;
            t=max(t,it[3]);

        }
        if(flag==0) return -1;

    

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        //time,node
        vector<int> dist(n,INT_MAX);

        pq.push({0,0});
        dist[0]=0;

        while(!pq.empty()){
            int time = pq.top().first;
            int node = pq.top().second; 
            pq.pop();
            if(node==n-1) return dist[node];

            if(time>dist[node]) continue;

            //wait
            if (time + 1 < dist[node]) {
                dist[node] = time + 1;
                pq.push({time + 1, node});
            }
               
            for(auto it : adj[node]){
                int next_node=it.first;
                int start = it.second.first;
                int end = it.second.second;

                if(time>end) continue;

                int arrival_time = max(time, start) + 1;
                if (arrival_time < dist[next_node]) {
                    dist[next_node] = arrival_time;
                    pq.push({arrival_time, next_node});
                }
                
                
            }
           
            
        }

        return -1;
    }
};