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
        cin>>n>>s;

        char a ='a' ;
        int c = INT_MAX;
        int i =0;while(i<26){
            int ch=0;
            int sp=0;
            int ep=n-1;
            char curr = a+i;
            while(sp<=ep){
                if(s[sp]==s[ep]){
                    sp++;ep--;
                }else if(s[sp]==curr){
                    ch+=1;
                    sp++;
                }else if(s[ep]==curr){
                    ch+=1;
                    ep--;
                }else{
                    ch = INT_MAX;
                    break;
                }
            }

            c=min(c,ch);
            i++;
        }
        if(c==INT_MAX){
            c=-1;
        }
        cout<<c<<"\n";
    
    }
   
}