#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define modVal 10e9+7
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;


bool comp(pair<int,int>p1 , pair<int,int>p2 ){
    if(p1.first!=p2.first){
        return p1.first<p2.first;
    }
    return p1.second <p2.second;
}

int dfs(vector<vector<int>>&g , vector<bool>&vis , int si){
    if(vis[si]){
        return 0;
    }

    vis[si] = true;
    int e=0;
    int c=0;
    for(int i=0;i<g[si].size();i++)
    {
        if(!vis[g[si][i]]){
            e++;
            c=c+dfs(g,vis,g[si][i]);
        }
    }
    return c+e;
}

int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r" , stdin);
        freopen("../output.txt", "w", stdout);
    #endif
   
    int T= 0 ;
    cin>>T;
    
    while(T--){ 

        int n=0;
        cin>>n;
        int k =0;
        cin>>k;
        vector<pair<int,int>>ps;
        for(int i =0;i<k ;i++){
            int a =0;cin>>a;
            int b=0;
            cin>>b;
            ps.push_back(make_pair(min(a,b),max(a,b)));
        }
        sort(ps.begin(),ps.end(),comp);

        vector<bool>vis(n+1,false);
        int edges=0;
        vector<vector<int>> graph(n+1, vector<int>(0));
        int i=0;
        while(i<k){
            
            int f = ps[i].first;
            int s = ps[i].second;
            int j=i;
            while(j < k && ps[j].first == f && ps[j].second == s){
                j++;
            }
            graph[f].push_back(s);
            graph[s].push_back(f);
            i=j;
           
        }

        
        for(int i=1;i<=n ;i++){
            int a= dfs(graph,vis,i);
            edges+=a;
        }


        
        cout<<k-edges<<"\n";
    }

   
}