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
        
        int N=0;
        cin>>N;
        char L='(';
        char R=')';
        string s(N,L);
        string s2(N,R);
        string S=s+s2;
        int i = 1 ;
        int j = (2*N)-2 ;
 
        cout<<S<<'\n';
        while(i<j){
            string S2 = S;
            S2[i]=')';
            S2[j]='(';
            cout<<S2<<'\n';
            i++;j--;
        }
    }
  
 
 
}