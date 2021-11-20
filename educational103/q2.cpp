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

    int T =0;cin>>T;

    while(T--){
        
        ll n = 0 ; ll k=0;
        cin>>n>>k;
        ll sum=0;
        vector<ll>vec(n , 0);

        for(int i =0;i<n ; i++){
            cin>>vec[i];
        }
      
        ll presum =vec[0];
        ll changes =0;
        for(int i =1 ;i<n;i++){

            ll p=vec[i]*100;
            ll den = presum;

            ll perc = p/den;
            if(p%den != 0){
                perc++;
            }
            // cout<<perc<<" ";
            if(perc > k){
                
                ll c = (p/k) - presum;
                ll newP = p/(den+c);
                if(p%(den+c)!=0){
                    newP++;
                }
                if(newP >k){
                    c++;
                }
                presum+=c;
                changes +=c;

            }

            presum+=vec[i];

        }

        cout<<changes<<'\n';
    }

    return 0;
   
}