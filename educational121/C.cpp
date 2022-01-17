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
        
        int n =0;cin>>n;
        vector<ll>times(n, 0);
        vector<ll>health(n, 0);

        for(int i =0;i < n ;i++){
            cin>>times[i];
        }
        for(int i =0;i < n ;i++){
            cin>>health[i];
        }
        vector<pair<ll , ll>> segments;
        for(int i=0;i<n;i++){
            ll rightB=times[i];
            ll left = times[i]-health[i]+1;
            segments.push_back(make_pair(left,rightB));
        }

        sort(segments.begin(),segments.end());

        ll l_ = segments[0].first;
        ll r_ = segments[0].second;
        ll ans=0;

        for(int i =1;i<segments.size() ;i++){
            if(segments[i].first<=r_){
                r_=max(segments[i].second,r_);
            }else{
                ans+=(((r_-l_+1)*(r_-l_+2))/2);
                l_=segments[i].first;
                r_=segments[i].second;
            }   
        }

         ans+=(((r_-l_+1)*(r_-l_+2))/2);
            cout<<ans<<"\n";
    }
    return 0;
}