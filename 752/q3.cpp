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
    
    int arr[100001] = {0};
    while(T--){ 
        
        int n = 0 ;
        cin>>n;
        for(int i = 0 ; i < n ; i++){
            cin>>arr[i];
        }   

        int room = 0;
        bool lost = false;
        for(int i = 0 ; i < n ; i++){

            if(arr[i]%(i+2)!=0){
                room++;
            }else{
                lost = true;
                for(int j = 1 ; j<=room ; j++){
                    if(arr[i]%(i+2-j)!=0){
                        room++;
                        lost = false;
                        break;

                    }
                }
            }
            if(lost){
                break;
            }
        } 
        if(lost){
            cout<<"NO\n";
        }else{
            cout<<"YES\n";
        }  
    }    
}
  
 
 
