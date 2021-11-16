#include<bits/stdc++.h>
#define ll long long
using namespace std;


ll dfsGreedy(int index, vector<bool>&visited,int currVal , vector<vector<int>>&edges , vector<vector<ll>>&vertex , vector<vector<ll>>&dp , int select){

    
    ll myAns = 0 ;
    if(dp[index][select] != -1){
        return dp[index][select];
    }
    
    visited[index] = true;
    for(int i = 0 ; i< edges[index].size() ;i++){

        if(visited[edges[index][i]]){
            continue;
        }
        ll c1 = abs(vertex[index][select] - vertex[edges[index][i]][0]) + dfsGreedy(edges[index][i] ,visited,vertex[edges[index][i]][0],edges,vertex,dp,0);
        ll c2 = abs(vertex[index][select] - vertex[edges[index][i]][1]) + dfsGreedy(edges[index][i] ,visited,vertex[edges[index][i]][1],edges,vertex,dp,1);
        myAns+=max(c1,c2);

    }
    visited[index] = false;
    
    dp[index][select] = myAns;
    return myAns;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r" , stdin);
        freopen("../output.txt", "w", stdout);
    #endif



    int T=0;
    cin>>T;

    while(T--){

        int N=0;
        cin>>N;
      
        vector<vector<ll>> vertex;
        for(int i = 0 ; i< N ; i++){
            ll a =0;
            ll b =0;
            cin>>a>>b;
            vector<ll>v;
            v.push_back(a);v.push_back(b);
            vertex.push_back(v);
        }
        vector<vector<int>> edges(N,vector<int>(0));

        for(int i =0;i<N-1;i++){
            int a =0,b=0;
            cin>>a>>b;
            a--;b--;
            
            edges[a].push_back(b);
            edges[b].push_back(a);
        }
        vector<vector<ll>>dp(N,vector<ll>(2,-1));
        vector<bool> visited(N,false);
        ll a = dfsGreedy(0,visited,vertex[0][0],edges,vertex,dp,0);
        ll b = dfsGreedy(0,visited,vertex[0][1],edges,vertex,dp,1);
        cout<<max(a,b)<<"\n";
    }
 

}