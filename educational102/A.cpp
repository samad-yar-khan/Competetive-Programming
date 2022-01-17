#include<bits/stdc++.h>
using namespace std;
#define ll long long 
// #define modVal 10e9+7
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
long long const modVal = 1000000007;


ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

ll sd(ll n){
    ll a=0;
    while (n>0)
    {
        a+=(n%10);
        n/=10;
    }
    
    return a;
}

ll dp[200010];

int main(){
     
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r" , stdin);
        freopen("../output.txt", "w", stdout);
    #endif
   
   for(int i=0;i<=8;i++){
       dp[i]=2;
   }
   for(int i=9;i<=200001;i++){
       int x1=1;
       int x2=1;
       if(i>=10){
           x2=dp[i-10];
       }
       if(i>=9){
           x1=dp[i-9];
       }
       dp[i]=(x1%modVal+x2%modVal)%modVal;
   }

    
    int T=0;cin>>T;
    while(T--){
       
       ll a=0,b=0 ,c=0;
       cin>>a>>b>>c;
       ll s=a+b+c;
       if(s%9!=0 || min(a,min(b,c))<s/9){
           cout<<"NO\n";
       }else{
             cout<<"YES\n";
       }


    }
}