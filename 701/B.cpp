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
   
    // int T=0;cin>>T;
    // while(T--){

        ll n = 0,k=0,q=0;
        cin>>n>>q>>k;
        vector<ll> vec(n,0);
        for(int i = 0;i<n ;i++){
            cin>>vec[i];
        }

        vector<ll> buffer(n+2,0);
        vector<pair<int,int>>qs(q,{0,0});
        for(int i =0;i<q;i++){
            cin>>qs[i].first>>qs[i].second;
        }
        for(int i =1;i<n-1;i++){
            buffer[i] = vec[i+1]-vec[i-1]-2+buffer[i-1];
        }
        for(int i=0;i<q;i++){
           
            ll l=qs[i].first;
            ll r=qs[i].second;
            l--;r--;
            if(r-l == 0){
                cout<<k-1<<'\n';
                continue;
            }
            ll l_=l+1;
            ll r_=r-1;
            ll ans = vec[l_]-2 + k+1-vec[r_]-2;
            if(l_<=r_){
                ans+=(buffer[r_]-buffer[l]);
            }

            cout<<ans<<"\n";
        }
        



    // }
    /*
6 5 10
2 4 6 7 8 9
1 4
1 2
3 5
1 6
5 5

*/
    
    //2 4 6 7 8 9
    //2 2 1 0 0 1
    //2 4 5 5 5 6
   
 
    
}