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




int main(){
     
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r" , stdin);
        freopen("../output.txt", "w", stdout);
    #endif


   


    
    int T=0;cin>>T;
    while(T--){
        
       
       int n=0;cin>>n;
       
       ll currentMin=INT_MAX;
       vector<ll> vec(n,0);
       vector<ll> o(n,0);
       for(int i=0;i<n;i++){
           cin>>vec[i];
           o[i] = vec[i];
           currentMin=min(currentMin,vec[i]);
       }   

        bool no=false;
       sort(vec.begin(),vec.end() );
       for(int i =0;i<n;i++){
           if(vec[i]!=o[i] && o[i]%currentMin!=0 ){
               no=true;
               break;
           }
       }
        
        if(no){
            cout<<"NO\n";
        }else{
            cout<<"YES\n";
        }
    
    }
}