#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define modVal 10e9
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;





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

        int n =0;
        cin>>n;
        vector<ll> vec(n,0);
        for(int i =0;i<n ; i++){
            ll a =0;
            cin>>a;
            vec[i] = a;
        }
        if(n==1){
            cout<<vec[0]<<"\n";continue;
        }
        sort(vec.begin() , vec.end());
        ll ans=vec[0];
        for(int i = 0 ; i< vec.size()-1 ;i++){
            ans = max(ans ,vec[i+1]-vec[i] );
        }
        cout<<ans<<"\n";

        
    }
   return 0;
}