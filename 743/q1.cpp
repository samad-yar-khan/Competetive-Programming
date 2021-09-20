#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
#define modVal 10e9
 
// Common file
#include <ext/pb_ds/assoc_container.hpp>
// Including tree_order_statistics_node_update
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
 
 
int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //     freopen("../input.txt", "r" , stdin);
    //     freopen("../output.txt", "w", stdout);
    // #endif
   
    int T= 0 ;
    cin>>T;
    while(T--){ 
        char z = '0';
        int N = 0 ;
        cin>>N;
        string s{""};
        cin>>s;
        ll ans =0;
        int c =0;
        for(int i=0;i < s.size() -1 ; i++){
            if(s[i]!=z){
                c++;
            }
            ans += (s[i]-z);
        }
        ans += (s[s.size()-1] - z);
        ans += c;
        cout<<ans<<'\n';
    }
  
 
 
}