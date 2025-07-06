class DisjointSet {
    vector<int> rank,parent;
    int components;
public:
    DisjointSet(int n){
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        components=n;
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
        components--;
        
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
    int compo(){
        return components;
    }
  
    
    
};



class Solution {
public:

    int func(int k , int n , vector<vector<int>>& edges ){
        DisjointSet ds(n);

        for(auto it : edges){
            if(it[2]>k){
                ds.UnionByRank(it[0],it[1]);
            }
        }
        
        //cout<<" for mid or k: "<<k<<" components : "<<st.size()<<endl;
        return ds.compo();

    }
    int minTime(int n, vector<vector<int>>& edges, int k) {
        
        int temp=func(0,n,edges);
        if(temp>=k) return 0;
        if(edges.size()==0 && n==k) return 0;
        //else if(temp>k) return -1;
        int high=0;
        int low=0;
        for(auto it : edges) high=max(high,it[2]);


        while(low<high){
            int mid = (low+high)/2;
            int compo = func(mid,n,edges);
            
            if(compo>=k){
                high=mid;
            }
            else{
                low=mid+1;
            }

        }
        return low;
    }
};