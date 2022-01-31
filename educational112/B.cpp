#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define modVal 10e9
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;


int main(){
     
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r" , stdin);
        freopen("../output.txt", "w", stdout);
    #endif

    int T=0;cin>>T;
    while(T--){

    
        ll hc , dc , hm , dm, k, w ,a ;
        cin>>hc>>dc;
        cin>>hm>>dm,
        cin>>k>>w>>a;

        // ll x =(a*dc + a*k*w - hc)/(-w*a);

        // if((hc+a*x)/dm >= hm/(dc+(k-x)*w)){
        //     cout<<"YES\n";
        // } else{
        //     cout<<"NO\n";
        // }

        // cout<<ceil((hc+a*k)/dm)<<"\n";
        // cout<<ceil(hm/dc)<<"\n";
        // cout<<ceil((hc)/dm)<<"\n";
        // cout<<ceil(hm/(dc+k*w))<<"\n";
        bool f=false;
        for(int i =0;i<=k;i++){
            ll n1=(hc+a*(k-i))/dm;
            if((hc+a*(k-i))%dm !=0){
                n1++;
            }
            ll n2 =hm/(dc+(i*w));
            if(hm%(dc+(i*w))!=0){
                n2++;
            }
            if(n1>=n2){
                f=true;
                break;
            }
        }
       
       if  (f){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
        

    }
}