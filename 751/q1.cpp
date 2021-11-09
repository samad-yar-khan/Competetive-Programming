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

        string s;cin>>s;

        char c = 'z';
        int index = -1;
        for(int i = 0 ; i < s.length() ; i++){
            if(c >= s[i]){
                c= s[i];
                index = i;
            }
        }
        cout<<s[index]<<" ";
        cout<<s.substr(0,index)<<s.substr(index+1)<<"\n";       
    }
   return 0;
}