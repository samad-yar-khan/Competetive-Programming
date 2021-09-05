#include <bits/stdc++.h>
using namespace std;
#define modVal 1000000007
#define ll long long


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r" , stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int XorVals[300001] = {0};     
    for(int i =1 ;  i<300001 ; i++){
        XorVals[i] = XorVals[i-1]^i;
    }

    int T= 0 ;
    cin>>T;
    while(T--){

        int a=0,b=0;
        cin>>a>>b;
        int ans =0;
        int xor_val = XorVals[a-1];
        
        if(xor_val == b){
            ans = a;
        }else{
           
           if((xor_val^b) == a){
               ans = a+2;
           }else{
               ans = a+1;
           }
          
        }
        cout<<ans<<"\n";
    }
   
}

