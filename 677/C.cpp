#include<bits/stdc++.h>
using namespace std;
#define ll long long 
// #define modVal 10e9+7
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
long long const modVal = 1000000007;

ll exp(ll m , ll n){    //m^n

    ll number = m ;
    ll power = n ;
    ll answer = 1;
    while( power > 0){
        if((power & 1 ) > 0){
            answer *= number ;
            answer%=modVal;
        } 
        //square the number 
        number*=number;
        number%=modVal;
        //right shift power
        power = power>>1;
    }
    return answer;
}


int main(){
    
   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r" , stdin);
        freopen("../output.txt", "w", stdout);
    #endif
   
    long long T= 0 ;
    cin>>T;

    while(T--){
        
       int n =0;cin>>n;
       vector<int>arr(n,0);
       for(int i = 0 ;i < n ;i++){
           cin>>arr[i];
       }
        int maxNum = INT_MIN;
        for(int i =0;i<n ;i++   ){
            maxNum= max(maxNum,arr[i]);
        }
        int ans =-1;
        if(arr[0] == maxNum && arr[1] < maxNum){
            ans = 1;
            cout<<ans<<'\n';continue;
        }
         if(arr[n-1] == maxNum && arr[n-2] < maxNum){
            ans = n;
            cout<<ans<<'\n';continue;
        }
        for(int i =1;i<n-1;i++){
            if(arr[i] == maxNum){
                if(arr[i-1]<maxNum || arr[i+1]<maxNum){
                    ans = i+1;
                    break;
                }
            }
        }
        cout<<ans<<"\n";

    }

}