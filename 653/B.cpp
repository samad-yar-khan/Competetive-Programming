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


        int n =0;cin>>n;
        long long N=n;

        int twos =0;
        int threes=0;
        while(n%2==0){
            n/=2;
            twos++;
        }
        while(n%3==0){
            n/=3;
            threes++;
        }   
        if(n>1 || threes<twos){
            cout<<-1<<"\n";
            continue;
        }
        
        N=N*pow(2,threes-twos);
        int ans =threes-twos;
        while(N>1){
            N/=6;
            ans++;
        }
        cout<<ans<<"\n";



    }
  
 
 
}