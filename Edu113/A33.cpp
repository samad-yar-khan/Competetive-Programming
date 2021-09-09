#include <bits/stdc++.h>
using namespace std;
#define ll long long

//https://codeforces.com/blog/entry/94721

int main(){
    const ll modVal = 998244353;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r" , stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    // for(int i = 0 ;i < 10 ; i++){
    //     cout<<ops[i]<<"\n";
    // }

    // ll fact[200001] = {0};
    // fact[0] = 1;
    // for(ll i = 1 ; i <=200000 ; i++){
    //     fact[i]= i*fact[i-1] %modVal;
    // }
    

    int T= 0 ;
    cin>>T;
     ll tasks[200001];
    while(T--){
        
        ll n = 0 ;
        cin>>n;
        ll mn = INT_MIN;

        for(int i = 0 ; i < n ; i++){
            cin>>tasks[i];
            mn= max(tasks[i] ,mn);
        }
        ll smn=INT_MIN;
        for(int i = 0 ; i < n ; i++){
            if(tasks[i] > smn && tasks[i]!=mn){
                smn = tasks[i];
            }
        }


        sort(tasks,tasks+n);
        int maxF =0;
        int secondMaxF=0;
     
        bool na = false;
        for(int i =0 ; i < n ; i++)
        {

            if(tasks[i] == mn){
                maxF++;
            }
            if(tasks[i]  == smn){
                secondMaxF++;
            }

        }
        ll factn=1, subValue=1;
        for(long long i = 1 ; i <= n ; i++){

            factn = factn * i % modVal;
            if(i != secondMaxF+1){//because we have n!/k+1 , so we skips k+1
                subValue = subValue * i %modVal;
            }

        }


        if(maxF>1){
            cout<<factn<<"\n";
            continue;
        }



        if(mn - smn > 1){
            cout<<0<<"\n";
            continue;
        }


        ll invalidPerms = subValue;//C( n , k+1 )k! (N-k-1)!
        ll ans = (factn - subValue + modVal)%modVal;
        cout<<ans<<"\n";
       
    }
}

