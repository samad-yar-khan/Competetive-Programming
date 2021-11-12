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
    string combinations[7] = {"aa","aba","aca","abca","acba","abbacca","accabba"};
    while(T--){ 
        
        int n =0;string s;
        cin>>n;
        cin>>s;
        int ans = -1;
        for(int i = 0 ; i < 7 ; i++){
            int len=combinations[i].length();
            for(int j = 0 ;j+len<=s.length(); j++){
                if(s.substr(j,len)==combinations[i]){
                    ans = len;
                    break;
                }
            }
            if(ans!=-1){
                break;
            }
        }
        cout<<ans<<"\n";
    }
   
}