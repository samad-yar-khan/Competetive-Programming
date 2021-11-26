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

        
        int n =0;
        string s;
        cin>>n;
        cin>>s;
        int b=0;
        int w=0;
        int c=0;
        int c2=0;
        for(int i =0  ;i<n ;i++){
            if(s[i]=='W'){
                c++;
            }else{
               if(c>0){
                   w++;
               }
               c=0;
            }
        }           
        if(s[n-1]=='W'){
            if(c>0){
                   w++;
               }
               c=0;
        }

        c=0;
         for(int i =0  ;i<n ;i++){
            if(s[i]=='B'){
                c++;
            }else{
             if(c>0){
                 b++;
             }
             c=0;
            }
        }         
         if(s[n-1]=='B'){
              if(c>0){
                 b++;
             }
             c=0;
        }
        
        
        cout<<min(b,w)<<'\n';

        
    }
   
}