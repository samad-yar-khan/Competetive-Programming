#include <bits/stdc++.h>
using namespace std;
#define modVal 1000000007
#define ll  unsigned long long

int main()
{
    ios_base::sync_with_stdio(false);
 
    cin.tie(NULL);
 
   ll n = 0 , k= 0 ,  x= 0;
   cin>>n>>k>>x;
    ll arr[200001] = {0} ;
    for(ll i = 0 ; i < n ; i++){
        cin>>arr[i];
    }
    
    sort(arr,arr+n);

    vector<ll> s_needed ;

    ll c = 1;
    for(ll i =  1 ; i< n ; i++){
        if(arr[i]-arr[i-1] > x){
            c++;
            ll a = (arr[i]-arr[i-1] -1 )/(x);
            // ll rem = (arr[i]-arr[i-1])%((2*x) + 1);
           s_needed.push_back(a);
        }  
    }

    ll f= k;
    sort(s_needed.begin() , s_needed.end());
    ll it = 0;
    while(it < s_needed.size() && f >0 ){
        if(s_needed.at(it) <= f){
            c-=1;
            f= f - s_needed.at(it);
            it++;
        }else{
            break;
        }
    }
    cout<<c<<"\n";



}
/*


8 2 3
1 1 9 12 13 20 22 26


*/