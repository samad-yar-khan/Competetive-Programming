#include<bits/stdc++.h>
using namespace std;
#define ll long long 
// #define modVal 10e9+7
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
long long const modVal = 1000000007;

int main(){
     
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r" , stdin);
        freopen("../output.txt", "w", stdout);
    #endif

    ll T=0;cin>>T;

   
    while(T--){

        ll n =0,k=0;
        cin>>n>>k;

        if(k>=n-1 && n<=4){
            cout<<-1<<"\n";
            continue;
        }
        if(k==n-1 && n>4){
            vector<pair<ll,ll>> ans;
        for(ll i =0;i<n/2;i++){
            ans.push_back(make_pair(i,n-1-i));

         
        }

        swap(ans[0].first,ans[1].second);
        swap(ans[1].second,ans[n/2-1].first);
           for(int i =0;i<ans.size();i++){
            cout<<ans[i].first<<" "<<ans[i].second<<"\n";
        }
        continue;

        }

        vector<pair<ll,ll>> ans;
        if(k==0){
         
            ans.push_back(make_pair(0,n-1));
        }

        int s=0;
        for(ll i =1;i<n/2;i++){

            if(i==k){
                ans.push_back(make_pair(0,n-1-i));
                 ans.push_back(make_pair(i,n-1));
                // cout<<0<<" "<<(n-i-1)<<"\n";
                // cout<<i<<" "<<n-1<<"\n";
            }else if(n-1-i == k){
    
                ans.push_back(make_pair(0,i));
                ans.push_back(make_pair(n-i-1,n-1));
            
            }else{

                ans.push_back(make_pair(i,n-1-i));
            }
         
        }
      
        if(k!=0){
            sort(ans.begin(),ans.end());
        }
        for(int i =0;i<ans.size();i++){
            // cout<<ans[i].first<<" "<<ans[i].second<<"\n";
            s+=(ans[i].first&ans[i].second);
            }
            cout<<s<<"\n";
      

      
    }
}