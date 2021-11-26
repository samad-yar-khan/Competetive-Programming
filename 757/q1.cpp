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
        ll n =0,l=0,r=0,k=0;
        cin>>n>>l>>r>>k;
        vector<int>vec;
        for(int i =0;i<n ;i++){
            ll a =0;
            cin>>a;
            vec.push_back(a);
        }
        sort(vec.begin(),vec.end());
        int ans =0;
        ll i =0;
        for(;i<n && vec[i]<l ; i++){
            ;
        }

        for( ;i<n && vec[i]<=r ; i++){
            if(vec[i]<=k){
                k-=vec[i];
                ans++;
            }else if(vec[i]>k){
                break;
            } 
        }
        cout<<ans<<'\n';



    }

    return 0;
   
}