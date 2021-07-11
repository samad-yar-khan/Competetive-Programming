#include <bits/stdc++.h>
using namespace std;
#define modVal 1000000007
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
 
    cin.tie(NULL);
 
    ll arr[100001] = {0};
    string s={""};
    ll n = 0 ;
    ll q = 0 ;
    cin>>n>>q;

    cin>>s;
    arr[0] = s[0] - 'a' +1 ;
    for(int i = 1; i < n ; i++){

        arr[i] = arr[i-1] + (s[i] - 'a' + 1);
    }

    while(q--){
        ll l =0 , r= 0 ;
        cin>>l>>r;
        l--;
        r--;
        if(l== 0){
            cout<<arr[r]<<"\n";
        }else{
            cout<<arr[r]-arr[l-1]<<"\n";
        }
    }


}