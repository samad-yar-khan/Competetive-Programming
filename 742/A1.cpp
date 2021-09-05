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
    

    int T= 0 ;
    cin>>T;
    while(T--){

        int n = 0 ;
        cin>>n;
        string s{""};
        cin>>s;

        for(int i = 0 ; i < n ; i++){
            if(s[i] == 'L' || s[i] == 'R'){
                cout<<"LR";
                i++;
            }else if(s[i] == 'U'){
                cout<<'D';
            }else{
                cout<<'U';
            }
        }
        cout<<'\n';

    }




}

