#include<bits/stdc++.h>
using namespace std;
#define ll long long 
// #define modVal 10e9+7
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
long long const modVal = 1000000007;

long long minCost(vector<int>&deg,int N,vector<vector<int>>&g){

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    for(int i =1;i<=N;i++){
        pq.push(make_pair(deg[i],i));
    }

    int cuts =0;
    long long ans =0;
    while ( pq.size()>0 && cuts < N-1 ){
        pair<int,int>tn = pq.top();pq.pop();
        int n = tn.second;
        if(deg[n] == 0){
            continue;
        }

        ll mydeg = deg[n];
        for(int i =0;i<g[n].size();i++){
            int nb = g[n][i];
            ll nbdeg = deg[nb];
          
            if(nbdeg==0){
                continue;
            }
            cuts++;
            ans +=(nbdeg*mydeg);
            mydeg--;
            deg[nb]--;
            if(deg[nb]>0){
                pq.push(make_pair(deg[nb],nb));

            }
        }
        deg[n] = 0;

    }

    return ans;
    

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

        int N =0 ,Q=0;

        cin>>N>>Q;
        vector<pair<int,int>>edges(N+1,{0,0});
        for(int i =0;i<N-1;i++){
            cin>>edges[i].first>>edges[i].second;
        }
        

        vector<vector<int>>qs(Q,vector<int>(4,0));
        for(int i =0;i<Q;i++){
            cin>>qs[i][0];
            cin>>qs[i][1];
            cin>>qs[i][2];
            cin>>qs[i][3];
        }


        vector<vector<int>>g(N+1,vector<int>(0));
        for(int i =0;i<N-1;i++){
            int a =edges[i].first,b=edges[i].second;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        vector<int>deg1(N+1,0);
        for(int i =1;i<=N;i++){
            deg1[i]=g[i].size();
        }
        ll currAns =  0;
        for(int i =1;i<=N;i++){
            ll d= deg1[i];
            d = (d*(d+1))/2;
            currAns+=d;
        }
        currAns-=(N-1);
        cout<<currAns<<"\n";
        // cout<<minCost(deg1,N,g)<<"\n";
        for(int i =0;i<Q;i++){
            ll cA=currAns;
            int A=0;int B=0;
            int C=0,D=0;
            A=min(qs[i][0],qs[i][1]);
            B=max(qs[i][0],qs[i][1]);
            C=qs[i][2];
            D=qs[i][3];

            cA-=(deg1[A]);
            cA-=(deg1[B]);
            deg1[A]--;
            deg1[B]--;
            cA+=(deg1[C]+1);
            cA+=(deg1[D]+1);
            deg1[A]++;
            deg1[B]++;
            // vector<vector<int>>g(N+1,vector<int>(0));
            // for(int i =0;i<N-1;i++){
            //     int a = min(edges[i].first,edges[i].second);
            //     int b = max(edges[i].first,edges[i].second);
            //     if(A==a && b==B){
            //         continue;
            //     }
            //     g[a].push_back(b);
            //     g[b].push_back(a);
            // }
            // g[C].push_back(D);
            // g[D].push_back(C);
            // vector<int>deg1(N+1,0);
            // for(int i =1;i<=N;i++){
            //     deg1[i]=g[i].size();
            // }
          cout<<cA<<"\n";
        }
        

    }
        
       
        
  
}