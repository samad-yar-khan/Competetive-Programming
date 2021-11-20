#include<bits/stdc++.h>
#define ll long long
using namespace std;



int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r" , stdin);
        freopen("../output.txt", "w", stdout);
    #endif

    ll T =0;cin>>T;

    while(T--){

        ll n =0;
        cin>>n;
        vector<ll>lens;
        for(ll i =0;i< n ;i++){
            ll a =0;
            cin>>a;
            lens.push_back(a);
        }
        vector<ll>a;
        vector<ll>b;
        for(ll i =0;i< n ;i++){
            ll c =0;
            cin>>c;
            a.push_back(c);
        }
        for(ll i =0;i< n ;i++){
            ll c =0;
            cin>>c;
            b.push_back(c);
        }

        for(ll i=0 ;i < n ;i++){
            if(a[i]>b[i]){
                swap(a[i],b[i]);
            }
        }
        ll currMax = lens[n-1]+2+b[n-1]-a[n-1]-1;
        ll contAns =currMax;
        if(a[n-1]==b[n-1]){
            contAns=-1;
        }
        for(ll i = n-2 ;i>0;i--){
            ll myLoop = lens[i]+2+b[i]-a[i]-1;

            if(contAns!=-1){
                ll contAns2 = contAns-(b[i+1]-a[i+1])+a[i+1]-1+lens[i]-b[i+1]+2+b[i]-a[i];
                contAns=contAns2;
                myLoop=max(contAns,myLoop);
            }
            currMax=max(myLoop,currMax);
            if(a[i]==b[i]){
                contAns= -1;
            }else{
                contAns=myLoop;
            }
        }

        cout<<currMax<<"\n";

    }

    return 0;
   
}