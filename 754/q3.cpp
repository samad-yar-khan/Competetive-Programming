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
        
        int a1 = 0 ,a2=0,a3=0;
        cin>>a1>>a2>>a3;

        int d=abs(a1+a3 - 2*a2);

        if(d==0){
            cout<<0<<"\n";
            continue;
        }
        // int minVal = d;
        // int tempD =d;
        // bool op1=false;
        // if(a1+a3 > 2*a2){
        //     op1=true;
        // }
        // while(tempD<=d){
        //     if(op1){
        //         a1--;
        //         a2++;
        //         tempD=abs(a1+a3 - 2*a2);
        //         d=min(d,tempD);
        //     }else{
        //         a1++;
        //         a2--;
        //         tempD=abs(a1+a3 - 2*a2);
        //         d=min(d,tempD);
        //     }
        // }

        // cout<<d<<"\n";
        int ans = d%3;
        if(ans ==2 ){
            ans =1 ;
        }
        cout<<ans<<"\n";
        
    }
   
}