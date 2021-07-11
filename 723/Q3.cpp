#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
 
    cin.tie(NULL);
 

   ll N{0};
   cin>>N;

   ll arr[200000];
   for(ll i = 0 ; i<N ; i++){
       cin>>arr[i];
   }

   priority_queue <ll, vector<ll>, greater<ll>> pq ;
   ll ans=0;
   ll s = 0 ;

    for(ll i = 0 ; i <N ; i++){

        if(arr[i] < 0){
            pq.push(arr[i]);
        }
        s+=arr[i];
        ans++;
        
        if(s<0 ){
            ll subt = pq.top();
            pq.pop();
            s-=(subt);
            ans--;
        }

    }

    cout<<ans<<"\n";

}