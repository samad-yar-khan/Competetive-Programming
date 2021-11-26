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

        ll n=0;
        cin>>n;
        vector<pair<ll,ll>> vec;
        for(int i =0;i<n ;i++){
            ll a =0;
            cin>>a;
            vec.push_back({a,i+1});
        }

        sort(vec.begin(),vec.end());
        reverse(vec.begin(),vec.end());
        vector<ll> x(n+1,0);
        x[0]=1;
        ll i =0;
        ll j =2;
        ll ans =0;
        for(int k=0;k<n ;k+=2){
            ll times=vec[k].first;
            ll ind = vec[k].second;
            ans+=(abs(1-i)*2*times);
            x[ind]=i;
            i--;
        }
         for(int k=1;k<n ;k+=2){
            ll times=vec[k].first;
            ll ind = vec[k].second;
            ans+=((abs(j-1))*times*2);
            x[ind]=j;
            j++;
        }
        cout<<ans<<"\n";
        for(int i =0;i<n+1 ;i++){
            cout<<x[i]<<" ";
        }
        cout<<'\n';



        
    }
   
}