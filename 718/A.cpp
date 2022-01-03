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
 
   
    int T =0;cin>>T;

    while(T--){
        ll n =0;
        ll ten= 10;
        ll _e = 17;
        ll tens = pow(ten,_e);

        cin>>n;
        ll tzfz=2050;
        if(n%tzfz != 0){    
            cout<<-1<<'\n';continue;
        }

        n/=tzfz;
        ll ans =0;
        
        while(n>0 && tens>0){

            // cout<<n<<"-"<<<<"\n";
            ll dens = n/tens;
            ll left = n%tens;
            n = n- dens*tens;
            tens/=10;
            ans+=dens;
        }
        cout<<ans<<"\n";

    }

    
}