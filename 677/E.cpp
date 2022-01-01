#include<bits/stdc++.h>
using namespace std;
#define ll long long 
// #define modVal 10e9+7
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
long long const modVal = 1000000007;

ll exp(ll m , ll n){    //m^n

    ll number = m ;
    ll power = n ;
    ll answer = 1;
    while( power > 0){
        if((power & 1 ) > 0){
            answer *= number ;
            answer%=modVal;
        } 
        //square the number 
        number*=number;
        number%=modVal;
        //right shift power
        power = power>>1;
    }
    return answer;
}


int main(){
    
   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r" , stdin);
        freopen("../output.txt", "w", stdout);
    #endif
   
    // long long T= 0 ;
    // cin>>T;
    vector<ll>NCRDP;
    ll aa =1;
    NCRDP.push_back(1);
    for(ll i =1;i<=20;i++){
        aa*=i;
        NCRDP.push_back(aa);
    }

   
       
       ll a =0;
       cin>>a;

       ll m=(NCRDP[a/2-1]);
       m*=m;
       ll mn = NCRDP[a]/(NCRDP[a/2]*NCRDP[a/2]*2);
       ll ans = m*mn;
       cout<<ans<<"\n";
        
    // }

    
}