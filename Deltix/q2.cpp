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


        ll arr[1002];
        int n{0};
        cin>>n;

        for(int i = 0 ; i < n ; i++){
            cin>>arr[i];
        }

        int ans  = 0;

        cout<<n*3<<"\n";
       for(int i = 0 ; i < n ; i+=2){

           cout<<1<<" "<<i+1<<" "<<i+2<<"\n";
           cout<<2<<" "<<i+1<<" "<<i+2<<"\n";
           cout<<2<<" "<<i+1<<" "<<i+2<<"\n";
           cout<<1<<" "<<i+1<<" "<<i+2<<"\n";
           cout<<2<<" "<<i+1<<" "<<i+2<<"\n";
            cout<<2<<" "<<i+1<<" "<<i+2<<"\n";
           
       }


    }

}