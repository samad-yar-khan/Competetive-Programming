#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define modVal 10e9+7
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

        ll sum =0;
        ll n=0;
        cin>>n;
        for(int i=0;i<n ;i++){
            ll a =0;cin>>a;
            sum+=a;
        }
        if(sum >= n){
            cout<<sum-n<<"\n";
        }else{
            cout<<1<<'\n';
        }
    }
   
}