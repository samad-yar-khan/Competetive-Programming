#include <bits/stdc++.h>
using namespace std;
#define modVal 1000000007
#define ll long long


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r" , stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    

    int T= 0 ;
    cin>>T;
    for(int i = 1 ; i <= T ; i++){

        ll n = 0 ;
        cin>>n;

        ll sum = (n*(n+1))/2;

        if(sum%2 == 0){
            cout<<n<<"\n";
        }else{
            cout<<n-1<<"\n";
        }

    }

}

