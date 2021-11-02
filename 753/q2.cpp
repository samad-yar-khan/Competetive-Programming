#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define modVal 10e9
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;


ll solve(ll sp , ll j){

    if(sp%2 == 0){

        ll sp2= (j/4)*4;

        ll r = j%4;

        if(r==0){
            return sp;
        }
        ll add=0;
        if(r>=1){
            add-=(sp2+1);
        }
        if(r>=2){
            add+=(sp2+2);
        }
        if(r>=3){
            add+=(sp2+3);
        }

        sp+=add;

    }else{

        ll sp2= (j/4)*4;

        ll r = j%4;

        if(r==0){
            return sp;
        }
        ll add=0;
        if(r>=1){
            add+=(sp2+1);
        }
        if(r>=2){
            add-=(sp2+2);
        }
        if(r>=3){
            add-=(sp2+3);
        }
      
    sp+=add;
    }
    return sp;

}



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

        ll sp = 0 ;
        ll j =0; 
        cin>>sp>>j;
        cout<<solve(sp , j)<<'\n';
        
    }
   
}