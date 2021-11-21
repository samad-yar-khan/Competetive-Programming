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

        int a=0,b=0,c=0;
        cin>>a>>b>>c;

        int curr =0;
        if(c%2!=0){
            curr+=3;
        }

      
            if(curr == 0){
                curr+=((b%2 == 0)?0:2);
            }else{
                curr=1;
            }
     
        
       if(a>curr){
           a-=curr;
           if(a%2==0){
               curr=0;
           }else{
               curr=1;
           }
       }else{   
           curr-=a;
       }
       cout<<curr<<"\n";
        
    }
   
}