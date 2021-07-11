#include <bits/stdc++.h>
using namespace std;
#define modVal 1000000007
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
 
    cin.tie(NULL);
 

    ll T{0};
    cin>>T;
    while(T--){
        
        ll n = 0 ;
        cin>>n;
        int*arr = new int[n]{0};
        int*check = new int[2*n+1]{0};

        for(int i = 0 ; i< n ; i++){
            cin>>arr[i];
            check[arr[i]] = i+1;
        }

        int ans=0;
        for(int i = 1 ; i <= 2*n ;  i++){
            for(int j = i+1 ; j <= (2*n)/i ; j++ )
            {
                if(check[i]!=0 && check[j]!=0 && check[i]+check[j] == i*j){
                    ans++;
                }
            }
        }
        cout<<ans<<"\n";
        delete [] arr;
        delete [] check;
    }

}