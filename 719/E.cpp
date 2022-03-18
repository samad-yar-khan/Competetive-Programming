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
        
        int n =0;cin>>n;
        string s;
        cin>>s;
        ll countSheeps=0;
        for(auto i : s){
            if(i=='*'){
                countSheeps++;
            }
        }
        ll cc=0;
        ll ans =0;
        for(auto i : s){
            if(i=='*'){
                cc++;
            }else{
                ans += min(cc, countSheeps-cc);
            }
        }
        cout<<ans<<"\n";
    }
   
}