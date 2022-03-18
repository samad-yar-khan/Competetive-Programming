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
        
        int n =0;
        cin>>n;
        int cn =1;
        vector<vector<int>>mat(n,vector<int>(n,0));
 
        for(int gap=0;gap<n && cn<= n*n ;gap++){
            int m =0;
            for(int i =0;i+gap<n && cn<=n*n;i++){
                mat[i][i+gap]=cn++;
                m = max(m,i+gap);
    
            }
          
            for(int i = m ;i-gap>=0 && cn <= n*n && gap!=0;i--){
                mat[i][i-gap]=cn++;
               
            }
          
            
        }

        int X[4] = {0,0,-1,1};
        int Y[4] = {1,-1,0,0};
        bool lost = false;
        for(int i =0;i<n;i++){
            for(int j =0;j<n;j++){
                for(int m = 0 ;m<4;m++){
                    int x = X[m] + i;
                    int y = Y[m] + j;
                    if(x<0 || x>=n || y>=n || y<0){
                        continue;;
                    }
                    if(abs(mat[x][y]-mat[i][j]) == 1){
                        lost = true;
                        break;
                    }
                }
                if(lost)
                {
                    break;
                }
            }
        }

          if(lost){
                cout<<-1<<"\n";
                continue;
            }else{
                 for(int i =0;i<n;i++){
                for(int j =0;j<n;j++){
                    cout<<mat[i][j]<<" ";
                }
                cout<<'\n';
            }
            }
    }
   
}