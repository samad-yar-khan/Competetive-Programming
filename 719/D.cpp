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

        int n=0;
        cin>>n;
        vector<int>arr(n,0);
        unordered_map<ll,ll> m;

        for(int i=0;i<n;i++){
            cin>>arr[i];
            m[arr[i]-i]+=1;
        }
        ll a =0;
        for(auto i=m.begin();i!=m.end();i++){
            ll c=i->second;
            a+=((c*(c-1))/2);
        }
        cout<<a<<"\n";
    }
   
}