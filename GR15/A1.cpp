#include <bits/stdc++.h>
using namespace std;
#define modVal 1000000007
#define ll long long


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r" , stdin);
        freopen("output.txt", "w", stdout);
    #endif
    

    int T= 0 ;
    cin>>T;
    while(T--){

        ll n =0 , s=0;
        cin>>n>>s;

        ll mid = n/2;
        if(n%2!=0){
            mid+=1;
        }
        ll left = (n-mid+1);
        ll ans = s/left;
        cout<<ans<<"\n";


    }




}

