#include<bits/stdc++.h>
using namespace std;
#define ll long long 
// #define modVal 10e9+7
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
long long const modVal = 1000000007;

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
        vector<vector<int>>g(N+1,vector<int>(0));
        for(int i =0;i<N-1;i++){
            int a =0,b=0;cin>>a>>b;
            g[a].push_back(b);
            g[b].push_back(a);
        }


    }
        
       
        
  
}