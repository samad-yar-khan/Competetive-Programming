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
    
   //the logic behin the qn was that for n=2 the answers of 12th smallest numebr was 12 
   //this jhinted towars the binary number syustem , the numbers are of the form 2^2 + 2^0 = 101 and so on
   //so thsi hinted towards changing the base of the numebr 
   //i juts have to tak ethe number k and change sits base , and that would be the kth smallest number
   //of the given form
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r" , stdin);
        freopen("../output.txt", "w", stdout);
    #endif
   
    long long T= 0 ;
    cin>>T;

    while(T--){
        ll N = 0 ;cin>>N;
        ll K=0; cin>>K;
        ll ans =0;
        ll currNum =1;
        while(K>0){
            if(K&1 == 1){
                ans = (ans +currNum)%modVal;
            }
            currNum = (currNum*N)%modVal;
            K = K>>1;
        }
        cout<<ans<<"\n";

    }


}