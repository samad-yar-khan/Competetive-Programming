#include<bits/stdc++.h>
#define ll long long int
using namespace std;



int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r" , stdin);
        freopen("../output.txt", "w", stdout);
    #endif


    int T =0;
    cin>>T;
    while(T--){
        

        ll x = 0; ll y = 0;
        ll n = 0 ;
        cin>>n>>x>>y;
        int N =n;
        ll diff = y-x;
        if(n==2){
            cout<<x<<" "<<y<<"\n";continue;
        }
        n--;
        while(diff%n!=0){
            n--;
        }

        ll diff2 = diff/n ;

        vector<ll>vec;
        int i = x;
        while(N > 0 && i<= y){
            vec.push_back(i);
            i+=diff2;
            N--;
        }
        i=x-diff2;
        while(N>0 && i > 0){
            vec.push_back(i);
            i-=diff2;
            N--;
        }
        i=y+diff2;
        while(N>0){
            vec.push_back(i);
            i+=diff2;
            N--;
        }
        
        for(auto num : vec){
            cout<<num<<" ";
        }
        cout<<"\n";

        

    }
    return 0;
}