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
   
    int T= 0 ;
    cin>>T;
 
    while(T--){ 
        
       string s{""};
       cin>>s;
        ll n = s.length();
        bool oo=true;
        bool onlt=true;
        for(ll i =0;i<n-1 ; i++){   

            int l = s[i]-'0';
            int r = s[i+1]-'0';
           
            if(l+r>= 10){
                oo=false;
                break;
            }

        }
        ll x=0, y=0,R=0;
        if(oo){

           x=0,y=1;
                int l = s[0]-'0';
                int r = s[1]-'0';
                R=l+r;

        }else{
             for(ll i =0;i<n-1;i++){
                    int l = s[i]-'0';
                    int r = s[i+1]-'0';
                    if(l+r>=10){
                        x=i;
                        y=i+1;
                        R=l+r;    
                    }
                }
        }
        for(ll i =0;i<n;i++){
            if(i==y){
                continue;
            }else if(i==x){
                cout<<R;
            }else{
                cout<<s[i];
            }
        }
        cout<<'\n';
    }
}