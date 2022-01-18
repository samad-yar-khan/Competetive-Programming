#include<bits/stdc++.h>
using namespace std;
#define ll long long

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

ll modVal = 1000000009;

long long calculate(long long p,
                    long long q)
{
    long long mod = 998244353, expo;
    expo = mod - 2;
    while (expo) {

        if (expo & 1) {
            p = (p * q) % mod;
        }
        q = (q * q) % mod;
        expo >>= 1;
    }
    return p;
}

ll solve(vector<ll> arr , ll n , ll b){
    ll s=0;
    ll factn=1;
    for(int i =0;i<n;i++){
        s=(s + arr[i]);

        factn*=(i+1);
    }
    ll B=1;
    ll s2=0;
    for(int i=0;i<n;i++){
        B=(B*b);
    }

    if(b!=1){
         return calculate(s*b*(B-1) , factn*(b-1));
    }
    return calculate(s*n ,factn);
}




int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../../input.txt", "r" , stdin);
        freopen("../../output.txt", "w", stdout);
    #endif
   
    int T= 0 ;
    cin>>T;
 
    while(T--){ 
        
        ll n =0 ; ll b=0; 
        cin>>n>>b;
        vector<ll> arr(n,0);
        for(int i=0;i<n ;i++){
            cin>>arr[i];
        }

        cout<<solve(arr,n,b)<<"\n";

    }

    for(int n=1;n<=20;n++){
        vector<vector<int>> temp = graph;
        for(int i =1;i<=20;i++){
            for(int j =1;j<=20;j++){
                if(i==n || j==n){
                    temp[i][j] =0;
                }
            }
        }
    }
    

    
   
}