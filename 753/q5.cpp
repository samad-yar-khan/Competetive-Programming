#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define modVal 10e9
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

void getPoint(int rows, int cols , string S){

    int SP = 0 ;
    int i =1,j =1;
    int minR = 1,maxC=1 , minC=1,maxR=1;
    int I=1,J=1;
    
    for(int itr =0 ; itr < S.length() ; itr++){

        if(S[itr] == 'U'){
            i--;
        }else if(S[itr] == 'D'){
            i++;
        }else if(S[itr] == 'L'){
            j--;
        }else{
            j++;
        }

        if( i <= 0 || i > rows){
            if(i<=0){
                if(maxR+1 <= rows){
                    i++;
                    maxR++;
                    I++;
                }else{
                    break;
                }
            }else{
                if(minR-1 >= 1){
                    i--;
                    maxR--;
                    minR--;
                    I--;
                }else{
                    break;
                }
            }
        }else if(j <=0 || j > cols){
            if(j<=0){
                if(maxC+1 <= cols){
                    j++;
                    maxC++;
                    J++;
                }else{
                    break;
                }
            }else{
                if(minC-1 >= 1){
                    j--;
                    maxC--;
                    minC--;
                    J--;
                }else{
                    break;
                }
            }
        }

        minR=min(minR,i);
        maxR=max(maxR,i);
        minC=min(minC,j);
        maxC=max(maxC,j);
         

    }

    cout<<I<<" "<<J<<"\n";

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

        int n =0 , m =0;
        cin>>n>>m;
        string S;
        cin>>S;
        getPoint(n ,  m , S);
        
    }
   return 0;
}