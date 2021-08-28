#include <bits/stdc++.h>
using namespace std;
#define modVal 1000000007
#define ll long long


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //cout.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r" , stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    

    int T= 0 ;
    cin>>T;
    for(int i = 1 ; i <= T ; i++){

        int a = 0 ;
        int b= 0 ; 
        int c= 0 ;
        int d=0;
        int e = 0;
        int f=0;

        cin>>a>>b>>c>>d>>e>>f;

        if(a>b){
            swap(a,b);
        }
        if(c>d){
            swap(c,d);
        }

        if(e>f){
            swap(e,f);
        }

        if(a==c && b==d){
            cout<<1<<"\n";
        }else if( a==e && b ==f){
             cout<<2<<"\n";
        }else{
            cout<<0<<"\n";
        }
        

    }




}

