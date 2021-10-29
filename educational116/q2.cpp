#include<bits/stdc++.h>
using namespace std;
#define ll long long
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
        
        ll n =0, k =0;
        cin>>n>>k;

        ll  val= 1;
        ll ans =0;
        while(val < k && val < n){
            val=val<<1;
            ans++;
        }        
        ll valLeft = n-val;
        if(valLeft <=0 ){
            cout<<ans<<"\n";
            continue;
        }

        ll timeLeft = valLeft/k;
        if(valLeft%k > 0){
            timeLeft++;
        }

        ans=ans+timeLeft;
        cout<<ans<<'\n';


    }
  
 
 
}