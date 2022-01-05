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
   
    int T=0;cin>>T;
    while(T--){

        ll a =0,b=0;
        cin>>a>>b;
        int currAns =INT_MAX;
        int count =0;
        if(a<b){
            cout<<1<<"\n";
        }else if(a==b){
            cout<<2<<"\n";
        }else{
            int  c=0;
            int curr_c=0;
            if(b==1){
                c++;
                b++;
            }   
            
            while(b){
                
                int currC=0;
                int A=a;
                while(A>=b){
                    A/=b;
                    currC++;

                }
                if(A==b){
                    currC+=2;
                }else if(A<b && A!=0){
                    currC+=1;
                }
                currC+=c;
                if(currC > currAns){
                    break;
                }else{
                    currAns=currC;
                }
                c++;
                b++;
            }
           
             cout<<currAns<<"\n";

        }

    }
    
   
 
    
}