#include<bits/stdc++.h>
using namespace std;
#define ll long long

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

ll modVal = 1000000009;

ll solve(vector<ll> &arr , ll n , ll h ){

    

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
        
        int n =0;cin>>n;
        vector<ll> problem (n,0);
        for(int i=0;i<n ;i++)
        {
            cin>>problem[i];
        }
        ll hs =0;cin>>hs;
        cout<<solve(problem , n , hs)<<"\n";

    }
   
}