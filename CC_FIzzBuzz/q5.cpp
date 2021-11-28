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
        
        int N=0,M=0;
        cin>>N>>M;
        set<pair<int,int>>sets;
        vector<vector<int>> disc(N+1 , vector<int>(0));
        for( int i =0;i<M ; i++){
            int  a=0;
            int b =0;
            cin>>a>>b;
            if(a==b){
                continue;
            }
            pair<int,int>p(min(a,b),max(a,b));
            if(sets.count(p)){
                continue;
            }
            sets.insert(p);
            disc[a].push_back(b);
            disc[b].push_back(a);

        }

        vector<bool> vis(N+1,false);

        int comp=0;
        //BFS
        vector<vector<int>>comps;
        for(int i =1 ;i<=N;i++){
            if(!vis[i]){
                
                int z =0;
                queue<int>pn;
                vector<int>comp;
                pn.push(i);
                while(!pn.empty()){
                    int t=pn.front();
                    pn.pop();
                    z++;
                    vis[t]=true;
                    for(int j=0;j<disc[t].size();j++){
                        if(!vis[disc[t][j]]){
                            pn.push(disc[t][j]);
                            vis[disc[t][j]]=true;
                        }
                    }
                    comp.push_back(t);
                }
                comps.push_back(comp);
            }
        }
       int ways =0;
 
       if(comps.size()<=1){
           cout<<ways<<"\n";
           continue;
       }
       for(int i =0;i<comps.size();i++){
           int s = comps[i].size()-1;
       
           bool yes=true;
           for(int j=0;j<comps[i].size();j++){
               if(disc[comps[i][j]].size()!=s){
                   yes=false;
                   break;
               }
           }
           if(yes){
               ways++;
           }
       }
       cout<<ways<<"\n";
        


    }   
   
}