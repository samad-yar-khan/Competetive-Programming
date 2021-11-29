#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define modVal 1000000007
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

        ll n =0 , m=0;
        cin>>n>>m;
        vector<ll> vec;
        ll total_or = 0 ;
        for(int i =0;i< m ;i++){
            ll l=0,r=0,x=0;
            cin>>l>>r>>x;
            vec.push_back(x);
            total_or=(total_or|x);
        }
        ll one =1;
        ll p=1;

        for(int i =0;i<n-1 ;i++){
            p=(p*2)%modVal;
        }

        ll ans=(p%modVal)*(total_or%modVal) % modVal  ;
        cout<<ans<<"\n";
       
    }
   
}