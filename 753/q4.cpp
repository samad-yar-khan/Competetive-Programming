#include<bits/stdc++.h>
using namespace std;
#define ll long long int
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
        cin>>n;
        vector<ll> vec(n,0);
        for(int i =0;i<n ; i++){
            ll a =0;
            cin>>a;
            vec[i] = a;
        }
       string S;
       cin>>S;
       vector<ll> red;
       vector<ll> blue;

       for(int i =0;i<n ; i++){
           if(S[i] == 'R'){
               red.push_back(vec[i]);
           }else{
               blue.push_back(vec[i]);
           }
       }
       sort(red.begin(),red.end());
       sort(blue.begin() ,blue.end());
       int j =0;
       int k =0;
       bool no=false;
        int i = 1;
       while(k < blue.size()){
           if(i<= blue[k]){
               k++;
               i++;
           }else{
               no=true;
               break;
           }
       }

       while(j < red.size()){
            if(i>=red[j]){
               j++;
               i++;
           }else{
               no=true;
               break;
           }
       }

       if(no || i<n){
           cout<<"NO\n";
       }else{
           cout<<"YES\n";
       }

        
    }
   return 0;
}