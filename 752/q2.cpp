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

        if(n%2==0 || n == 1){
            cout<<"YES\n";
        }else{
            
            bool quit = false;
            for(int i = 0 ; i < n - 1 ; i++){
                if(arr[i]>=arr[i+1]){
                    cout<<"YES\n";
                    quit=true;
                    break;
                }
            }
            if(quit){
                continue;
            }
            cout<<"NO\n";

        }


    }
  
 
 
}