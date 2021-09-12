#include <bits/stdc++.h>
using namespace std;
#define modVal 1000000007
#define ll long long


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("traffic_control_input.txt", "r" , stdin);
        freopen("output.txt", "w", stdout);
    #endif
    

    int T= 0 ;
    cin>>T;
    for(int i = 1 ; i <= T ; i++){
        
        int N = 0 , M=0,A=0,B=0;
        cin>>N>>M>>A>>B;
        

        if(N+M-1 > A || N+M -1 > B){
            cout<<"Case #"<<i<<": "<<"Impossible"<<"\n";
            continue;
        }

        int mat[50][50];
        for(int j=0;j<N ; j++){
            for(int k =0;k<M;k++){
                mat[j][k] = 1000;
            }
        }

    
        for(int j =0 ;j<N ; j++){
            mat[j][0] = 1;
            mat[j][M-1] = 1;
        }

        for(int j = 0 ; j < M ; j++){
            mat[N-1][j] = 1;
        }

        mat[0][0] = A-(N+M-2);
        mat[0][M-1] = B-(N+M-2);
        cout<<"Case #"<<i<<": "<<"Possible"<<"\n";

        for(int k = 0 ; k < N ; k++){
            for(int j = 0 ; j < M ;j++){
                cout<<mat[k][j]<<" ";
            }
            cout<<"\n";
        }

    }


}

