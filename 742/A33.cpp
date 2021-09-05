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
    int ops [10]={1};
    ops[1] = 1 ;
    for(int i =2 ; i < 10 ; i++){
        ops[i] = i/2 + 1;
    }

    // for(int i = 0 ;i < 10 ; i++){
    //     cout<<ops[i]<<"\n";
    // }
    

    int T= 0 ;
    cin>>T;


    while(T--){

        string s{""};
        cin>>s;

        //if we llook closely we see that the we can couple odd an even colums seperately
        /*

            2039
            2976
            now odd  possns carry to odd and even posns carry to even
            so get even posn number ans add them and get odd posns number together and add them and plabce the digits alternately
            09+96 = 105
            23+27 = 50 
            now place them alternativly 1 5 0 0 5
    
        */

        ll a = 0;
        ll b = 0;

        for(int i = 0 ; i < s.length() ; i++){
            if(i%2==0){
                a = (10*a) + (s[i]-'0');
            }else{
                b = (10*b) + (s[i]-'0');
            }
        }
       
        //number of ways to make n using parirs = n+1
        ll ans = (a+1)*(b+1);
        ans = ans- 2 ;//0,n and n,0 nikalo

        cout<<ans<<'\n';
      
    }
   
}

