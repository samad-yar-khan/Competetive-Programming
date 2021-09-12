#include <bits/stdc++.h>
using namespace std;
#define modVal 1000000007
#define ll long long


ll dfs (int path[51][51] , int gold[] , int N , int currMine , bool visited[]){

    visited[currMine] = true;

    ll maxPath = gold[currMine] ;
    for(int i = 1 ; i <= N ; i++ ){
        
        if(visited[i]||i==currMine){
            continue;
        }
        ll temp = 0 ;
        if(path[currMine][i] == 1){
            temp = gold[currMine] + dfs(path , gold , N , i,visited);
            maxPath=max(maxPath,temp);
        }
   
    }

    return maxPath;

}

ll solve(int path[51][51] , int gold[] , int N){

    vector<ll> paths;

    bool visited[51] = {false};
    visited[1] = true;
    for(int i = 2 ; i <=N ; i++ ){
        if(!visited[i] && path[1][i] == 1){
            ll pathsDown = dfs(path , gold  , N , i , visited);
            paths.push_back(pathsDown);
        }
    }

    if(paths.size() == 1){
        return paths[0]+gold[1]; 
    }

    sort(paths.begin() , paths.end());


    return paths[paths.size()-1] + paths[paths.size()-2] + gold[1];

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("gold_mine_chapter_1_input.txt", "r" , stdin);
        freopen("output.txt", "w", stdout);
    #endif
    

    int T= 0 ;
    cin>>T;
    for(int i = 1 ; i <= T ; i++){
        
        int N=0;
        cin>>N;
        if(N==0){
            cout<<"Case #"<<i<<": "<<0<<"\n";
            continue;
        }
        int gold[51] = {0};
        for(int i = 1 ; i <= N ; i++){
            cin>>gold[i];
        }
        if(N==1){
            cout<<"Case #"<<i<<": "<<gold[1]<<"\n";
            continue;
        }
        int mines[51][51] ;
        for(int i =  0 ; i<= N ;i++){
            for(int j = 0 ; j <= N ; j++){
                mines[i][j] = 0;
            }
        }

        for(int i = 0 ; i < N-1 ; i++){
            int x=0;
            int y =0;
            cin>>x>>y;

            mines[x][y] = 1;
            mines[y][x] = 1;
        }
        

          cout<<"Case #"<<i<<": "<<solve(mines , gold , N)<<"\n";
    }


}

