#include<bits/stdc++.h>
using namespace std;
#define ll long long 
// #define modVal 10e9+7
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
long long const modVal = 1000000007;

int dp[1001][1001][2];

ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

ll solve(ll n , ll k , ll planeNumber , bool direction){
    
    //base cases
   
  
    if(n<planeNumber){
        if(k>0){
            return 1;
        }else{
            return 0;
        }
    }

    if(planeNumber==0){
        if(k>0){
            return 1;
        }else{
            return 0;
        }
    }
    if(k==0){
        return 0;
    }

    int dir = direction?0:1;
    if(dp[planeNumber][k][dir]!=-1){
        return dp[planeNumber][k][dir];
    }

    ll case1 = 0;
    ll case2 = 0;
   
   if(direction){
        case1 = solve(n,k,planeNumber+1,direction)%modVal;
        case2 = solve(n,k-1,planeNumber-1,!direction)%modVal;
   }else{
        case1 = solve(n,k,planeNumber-1,direction)%modVal;
        case2 = solve(n,k-1,planeNumber+1,!direction)%modVal;
   }
   
    dp[planeNumber][k][dir]=(case1%modVal + case2%modVal)%modVal;
    return dp[planeNumber][k][dir];


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

        ll n =0, k=0;
        cin>>n>>k;
        memset(dp,-1,sizeof(dp));
       cout<<solve(n,k,1,true)<<"\n";
      

    }
    
   
 
    
}