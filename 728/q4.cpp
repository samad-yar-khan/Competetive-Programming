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
    while(T--){
        
        
           
        ll n = 0 , x = 0 , t=0;
        cin>>n>>x>>t;


        ll d = t/x;
        if(n > d){
             ll s1 = n-d;
            ll ans = (s1*d);
            ll ans2 =  (d*(d-1))/2;
            if(ans2>0){
                ans+=ans2;
            }
            cout<<ans<<"\n";
        }else{
            cout<<(n*(n-1))/2<<"\n";
        }
       


    }

}