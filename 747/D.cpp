#include<bits/stdc++.h>
using namespace std;
#define ll long long 
// #define modVal 10e9+7
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
long long const modVal = 1000000007;

ll exp(ll m , ll n){    //m^n

    ll number = m ;
    ll power = n ;
    ll answer = 1;
    while( power > 0){
        if((power & 1 ) > 0){
            answer *= number ;
            answer%=modVal;
        } 
        //square the number 
        number*=number;
        number%=modVal;
        //right shift power
        power = power>>1;
    }
    return answer;
}

int dfs(vector<vector<pair<int,int>>> &g , vector<int> &vis , int ind){
    
    if(vis[ind]!=-1){
        return 0;
    }



}

int main(){
    
   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r" , stdin);
        freopen("../output.txt", "w", stdout);
    #endif
   
    long long T= 0 ;
    cin>>T;
    string I{"imposter"};
    string C{"crewmate"};
    while(T--){
        
        ll m =0 , n =0;
        cin>>n>>m;

        vector<vector<pair<int ,int>>>g(n,vector<pair<int,int>>(0));

        for(int i = 0 ; i < m ;i++){

            int a =0,b=0;
            string s;
            cin>>a>>b>>s;

            int num = -1;     
            if(s==I){
                num = 0 ;
            }else{
                num = 1 ;
            }

            g[a].push_back({b,num});
        }
        vector<int>state1(n+1,0);
        vector<int>state2(n+1,0);

        for(int i =0;i<n ;i++){
            
        }


    }

}