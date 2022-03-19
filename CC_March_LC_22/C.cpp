#include<bits/stdc++.h>
using namespace std;
#define ll long long 
// #define modVal 10e9+7
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
long long const modVal = 1000000007;

int main(){
     
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r" , stdin);
        freopen("../output.txt", "w", stdout);
    #endif
 
  
        
        int N =0 , M=0,Q=0;

        cin>>N>>M>>Q;
        vector<vector<int>>g(N+1,vector<int>(0));
        for(int i =0;i<M;i++){
            int a =0,b=0;cin>>a>>b;
            g[a].push_back(b);
            g[b].push_back(a);
        }

        int**qs = new int*[Q+1];
        for(int i =0;i<=Q;i++){
            qs[i] = new int[2];
            qs[i][0] = 0;
            qs[i][1] = 1;
        }
        for(int i =0;i<Q;i++)
        {
            cin>>qs[i][0];
            cin>>qs[i][1];
        }

        vector<bool>frozen(N+1,false);
        queue<int>newFrozen;
        int fc =0;
        for(int i =0;i<Q;i++){
           
            if(qs[i][0] == 1){

                int nn = qs[i][1];
                if(frozen[nn]){
                    continue;
                }else{
                    frozen[nn] = true;
                    fc++;
                    newFrozen.push(nn);
                }

            }else if(qs[i][0] == 2){

                newFrozen.push(-1);
                int time = qs[i][1];
                while(newFrozen.size()>0 && time>0 && fc<N){
                    int tn = newFrozen.front();
                    newFrozen.pop();
                    if(tn == -1){
                        time--;
                        if(time==0){
                            break;
                        }else{
                            newFrozen.push(-1);
                            continue;
                        }
                    }
        

                    for(int j =0;j<g[tn].size() && fc<N;j++){
                        int nb = g[tn][j];
                        if(frozen[nb])
                        {
                            continue;
                        }else{
                            frozen[nb] = true;
                            fc++;
                            newFrozen.push(nb);
                        }
                    }

                }


            }else{

                int nc = qs[i][1];
                if(frozen[nc]){
                    cout<<"YES\n";
                }else{
                    cout<<"NO\n";
                }

            }
        }

         for(int i =0;i<=Q;i++){
           delete [] qs[i];
        }
        delete [] qs;
  
}