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

        ll N=0 ;
        cin>>N;

        vector<ll>arr;
        vector<int>z;
        for(int i=0;i<N;i++){
            ll a =0;
            cin>>a;
            arr.push_back(a);

            // if(a==0)
            // {
            //     z.push_back(i);
            // }

        }
        sort(arr.begin(),arr.end());
        for(int i=0;i<N;i++){
          
            if(arr[i]==0)
            {
                z.push_back(i);
            }

        }
        ll ans=0;
        if(z.size()!=0){

            for(int i =0;i<z.size();i++){
                int ind = z[i];
                ind=(ind+1)%N;
                ll c=0;
                while(arr[ind]!=0)
                {
                     ind=(ind+1)%N;
                     c++;
                }
                ans = max(c,ans);
            }

        }else{
            
            ll minE=INT_MAX;

            for(int i =0;i<N;i++){
                minE= min(minE,arr[i]);
            }
            

            ans = minE*N;

            for(int i=0;i<N;i++){
                if(arr[i] == minE){
                    arr[i] = 0;
                    z.push_back(i);
                }
            }

            ll C=0;

            for(int i =0;i<z.size();i++){
                int ind = z[i];
                ind=(ind+1)%N;
                ll c=0;
                while(arr[ind]!=0)
                {
                     ind=(ind+1)%N;
                     c++;
                }
                C = max(c,C);
            }
            ans=ans+C;

        }

        cout<<ans<<"\n";
    }
   
}