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

int dfs(vector<vector<pair<int,int>>> &g , vector<int> &vis , int ind,vector<vector<int>>&dp ,int type,vector<int>& classE){

    vis[ind] = true;
    classE[ind] = type;

    if(dp[ind][type] != -1){
        return dp[ind][type];
    }    
    int ans = 0;
    if(type == 0){
        ans++;
    }

    for(int i =0;i<g[ind].size() ;i++){
        int indc = g[ind][i].first;
        int bond = g[ind][i].second;

        if(type == 0){
            if(bond == 0){
                bond =1 ;
            }else{
                bond =0;
            }
        }

        int sa =dfs(g,vis,indc,dp,bond,classE);
        ans+=sa;
    }

    return ans;

}

//detectibg cycle
bool downCycle(vector<vector<pair<int ,int>>>&g,vector<bool>&downV,vector<bool>&visited , int si){

    visited[si] = true;
    downV[si] = true;
    for(int i =0;i<g[si].size();i++){
        int ind = g[si][i].first;
        if(ind == si){
            continue;
        }
        if(downV[ind]){
            downV[si] = false;
            return true;
        }
        if(visited[ind]){
            continue;
        }
        bool sa=downCycle(g,downV,visited,ind);
        if(sa){
            downV[si]=false;
            return true;
        }

    }
     downV[si] = false;
    return false;

}

bool dagCycle(vector<vector<pair<int ,int>>>&g){

    vector<bool> downV(g.size() ,false);
    vector<bool> visited(g.size() ,false);
    set<pair<int,int>> s;
    for(int i =1;i<=g.size();i++){
        if(!visited[i]){
            bool vis=downCycle(g,downV,visited,i);
            if(vis){
                return true;
            }
        }
    }
    return false;

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

        vector<vector<pair<int ,int>>>g(n+1,vector<pair<int,int>>(0));
        vector<bool> noParent(n+1,true);
        for(int i = 0 ; i < m ;i++){

            int a =0,b=0;
            string s;


            cin>>a>>b>>s;
            noParent[b] = false;
            int num = -1;     
            if(s==I){
                num = 0 ;
            }else{
                num = 1 ;
            }

            g[a].push_back(make_pair(b,num));
        }
      
        if(dagCycle(g)){
            cout<<-1<<"\n";
            continue;
        }

        vector<int> sps;
        for(int i =1;i<=n ;i++)
        {
            if(noParent[i]){
                sps.push_back(i);
            }
        }
        if(sps.size() == 0){
            cout<<-1<<"\n";
        }
        vector<int> vis(n+1,false);
        vector<vector<int>>dp(n+1 , vector<int>(2,-1));

        for(int i =0;i<sps.size() ;i++)
        {
            int sp = sps[i];
            
        }

    }

}