class DisjointSet {
    vector<int> rank,parent;
public:
    DisjointSet(int n){
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
       
        for(int i=0 ;i<=n ;i++){
            parent[i]=i;
           
        }
    }
    
    int findPar(int node){
        if(node==parent[node]){
            return node;
        }
        
        return parent[node]=findPar(parent[node]);
    }
    
    void UnionByRank(int u,int v){
        
        int ulp_u=findPar(u);
        int ulp_v=findPar(v);
        
        if(ulp_u==ulp_v) return;
        
        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
            
        }
        else if(rank[ulp_v]<rank[ulp_u]){
            parent[ulp_v]=ulp_u;
        }
        else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }
    
    vector<int> g(){
        return parent;
    } 
    
    
};



class Solution {
public:

    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {

        vector<int> parent;
        DisjointSet ds(c);
   
        for(auto it : connections){
            ds.UnionByRank(it[0],it[1]);
        }

       
       
        map<int,set<int>> mpp;
        
       for (int i = 1; i <= c; i++) {
            int par = ds.findPar(i);
            mpp[par].insert(i);
        }
            
        
        // map is Parent , set of nodes whose parent is Parent
        
        vector<int> res;
        for(auto it : queries){

            if(it[0]==1){
                //check  if online else  resolve with someone else
                int station = it[1];
                int par = ds.findPar(station);

                if(mpp[par].find(station)!=mpp[par].end()){
                    res.push_back(station);
                }
                else{
                    if(mpp[par].size()==0) res.push_back(-1);
                    else{
                        auto firstElement = mpp[par].begin();
                        res.push_back(*firstElement);

                     

                    }
                }
            }
            else if(it[0]==2){
                int station = it[1];
                int par=ds.findPar(station);
                mpp[par].erase(station);
            }
        }
        return res;
    }
};