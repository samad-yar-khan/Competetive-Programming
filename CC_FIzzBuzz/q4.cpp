#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define modVal 10e9+7
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

        ll N=0 , K=0;
        cin>>N>>K;

        if(N==0){
            cout<<0<<"\n";
            continue;
        }
        vector<int>vec(N,0);
        for(int i=0;i<N;i++){
            cin>>vec[i];
        }

        vector<vector<int>> dp(K+1 , vector<int>(2,0));
        int total =0;
        int prev =0;
        int curr =vec[0];
        for(int i =1;i<N;i++){
            if(vec[i]!=curr)
            {
                int num = vec[i];
                dp[num][0]++;
                total++;
                if(prev == 0 || prev==num){
                    dp[curr][1]++;
                }
                prev = curr;
                curr=vec[i];
            }
        }

        for(int i =1;i<=K ;i++){
            cout<<total -dp[i][0]-dp[i][1]<<" ";
        }
        cout<<"\n";

    }
   
}