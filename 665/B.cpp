#include<bits/stdc++.h>
using namespace std;
#define ll long long 
// #define modVal 10e9+7
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
long long const modVal = 1000000007;


int main(){
     
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r" , stdin);
        freopen("../output.txt", "w", stdout);
    #endif



    
    int T=0;cin>>T;
    while(T--){

        ll a1=0,b1=0,c1=0;
        cin>>a1>>b1>>c1;
        ll a2=0,b2=0,c2=0;
        cin>>a2>>b2>>c2;
        ll ans =0;
        if(c1 >=  b2){
            ans+=(b2*2);
           
            c1-=b2;
             b2=0;
        }else{
            ans+=(c1*2);
           
            b2-=c1;     
             c1=0;   
        }

        if(c1 >= c2  ){
            c1-=c2;
            c2=0;
        }else{
            c2-=c1;
            c1=0;
        }
        if(c1 >= a2){
            c1-=a2;
            a2=0;
        }else{
            a2-=c1;
            c1=0;
        }


        if(b1>=b2){
            b1-=b2;
            b2=0;
        }else{
            b2-=b1;
            b1=0;
        }

        if(b1>=a2){
            b1-=a2;
            a2=0;
        }else{
            a2-=b1;
            b1=0;
        }

        if(b1>=c2){
            ans-=(c2*2);
        }else{
            ans-=(b1*2);
        }
        cout<<ans<<"\n";

        





    }
}