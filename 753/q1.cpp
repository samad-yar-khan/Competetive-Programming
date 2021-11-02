#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define modVal 10e9
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

int AB(string &s , string &s2){

    unordered_map<char , int> m;

    if(s2.length() == 1){
        return 0;
    }   
    int ans =0;
    for(int i = 0 ; i < s.length() ;i++ ){
       m.insert(make_pair(s[i],i));
    }
    for(int i = 0 ; i < s2.length()-1 ;i++ ){
        ans+=abs(m[s2[i]]-m[s2[i+1]]);
    }
    return ans;

}



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
        
        string s;
        string s2;
        cin>>s;
        cin>>s2;
        cout<<AB(s , s2)<<"\n";
    }
   
}