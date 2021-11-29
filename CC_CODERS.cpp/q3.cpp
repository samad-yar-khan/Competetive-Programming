#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define modVal 10e9+7
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

        int n=0;int p=0;int q=0;
        cin>>n>>p>>q;


        string s;
        cin>>s;

        int x=0,y=0;
        bool curr = true;
        for(int i =0;i<n ;i++){

            if(s[i]=='1'){
                if(curr){
                    if(x > p){
                        x--;
                    }else{
                        x++;
                    }
                }else{
                    if(y > q){
                        y--;
                    }else{
                        y++;
                    }
                }
            }else{
                curr=!curr;
                 if(curr){
                    if(x > p){
                        x--;
                    }else{
                        x++;
                    }
                }else{
                    if(y > q){
                        y--;
                    }else{
                        y++;
                    }
                }
            }

        }

        int x_1 =x;int y_1=y;
        x=0;y=0;
        curr = false;
        for(int i =0;i<n ;i++){

            if(s[i]=='1'){
                if(curr){
                    if(x > p){
                        x--;
                    }else{
                        x++;
                    }
                }else{
                    if(y > q){
                        y--;
                    }else{
                        y++;
                    }
                }
            }else{
                curr=!curr;
                 if(curr){
                    if(x > p){
                        x--;
                    }else{
                        x++;
                    }
                }else{
                    if(y > q){
                        y--;
                    }else{
                        y++;
                    }
                }
            }

        }


        if((x_1==p && y_1==q) ||(x==p && y==q)){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }

    }
   
}