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
 
        ll a=0,b=0,c=0,m=0;
        cin>>a>>b>>c>>m;
 
        priority_queue<ll> pn;
        pn.push(a);
        pn.push(b);
        pn.push(c);
        ll A = 0,B=0,C=0;        
        A=pn.top();pn.pop();
        B=pn.top();pn.pop();
        C=pn.top();pn.pop();
        
        int maxM = A-1+B-1+C-1;
        int minM = A-B-C-1; 
        if(minM<0){
            minM=0;
        }
 
        if(m<=maxM && m>=minM){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
 
 
    }
}