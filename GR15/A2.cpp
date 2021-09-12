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
    // int XorVals[300001] = {0};     
    // for(int i =1 ;  i<300001 ; i++){
    //     XorVals[i] = XorVals[i-1]^i;
    // }

    int T= 0 ;
    cin>>T;
    while(T--){

        string s{""};
        cin>>s;
        
        ll ans =0;
        int i =0;
        int j =0;  
        ll c=0;
        ll o=0;
        while (i<s.length())
        {
            j=i;
           while(j<s.length() && s[j] == '1'){
               o++;
               j++;
           }
           while(j<s.length() && s[j]== '0'){
               j++;
               if((j<s.length() && s[j]=='1') || j==s.length()){
                   c++;
               }
           }
           i=j;
        }

        if(o==0 || c==1){
            cout<<1<<"\n";
            continue;
        }

        if(c==0){
            cout<<0<<"\n";
            continue;
        }

        if(c>1){
            cout<<2<<"\n";
            continue;
        }


    }
   
}

