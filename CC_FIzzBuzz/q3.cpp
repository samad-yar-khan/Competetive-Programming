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
        ll N= 0,M=0;

        cin>>N>>M;
        if(M>=N/2){
            cout<<N-M<<"\n";
            continue;
        }

        ll leftOver = N-M;
        ll K = leftOver/(M+1);
        ll Ct= leftOver%(M+1);

        ll numK= M+1-Ct;

        ll ans = (numK*(K*(K+1)))/2 ;
        ans+=((Ct*(K+1)*(K+2))/2);
        cout<<ans<<"\n";



    }
   
}