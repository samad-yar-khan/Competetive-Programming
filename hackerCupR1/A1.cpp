#include <bits/stdc++.h>
using namespace std;
#define modVal 1000000007
#define ll long long


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("weak_typing_chapter_1_input.txt", "r" , stdin);
        freopen("output.txt", "w", stdout);
    #endif
    

    int T= 0 ;
    cin>>T;
    for(int i = 1 ; i <= T ; i++){
        ll N = 0;
        cin>>N;
        string S{""} ;
        cin>>S;
        
        ll j = 0 ; 
        char setChar = 'F';
        while(j < N){
           if(S[j]=='X'||S[j] =='O'){
               setChar=S[j];
                j++;
                break;
           } 
           j++;
        }
        ll count = 0 ;
        ll k = j;
        while(k < N){
            if(S[k]!='F' && S[k]!=setChar ){
                count++;
                setChar = S[k];
            }
            k++;
        }
    

        cout<<"Case #"<<i<<": "<<count<<"\n";

    }
}

