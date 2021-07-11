#include <bits/stdc++.h>
using namespace std;
#define modVal 1000000007
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
 
    cin.tie(NULL);
 

    int T{0};
    cin>>T;
    while(T){
       
        ll n = 0 , l = 0 , r =0;

        cin>>n>>l>>r;

        ll *arr = new ll[n]{0};
        
        for(ll i = 0 ; i < n ; i++){
            cin>>arr[i];
        }

        if(r < l){
            cout<<0<<"\n";
            T--;
            continue;
        }
        
        sort(arr , arr+n);

        ll i = 0 ;
        ll j = n -1;
        ll sa = 0 , la = 0 ;
        while(i < j ){
            if(arr[i] + arr[j] >= l){
                j--;
            }else{
                sa += (j-i);
                i++;
            }
        }

        i = 0 ; j = n-1;

         while(i < j ){
            if(arr[i] + arr[j] <= r){
                i++;
            }else{
                la += (j-i);
                j--;
            }
        }

        ll ans = (n*(n-1))/2;
        ans -= la ;
        ans -= sa;


        cout<<ans<<'\n';
      delete[] arr;
      T--;
    }

}