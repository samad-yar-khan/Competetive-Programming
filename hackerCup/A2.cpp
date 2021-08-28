#include <bits/stdc++.h>
using namespace std;
#define modVal 1000000007
#define ll long long


void bfs(int mat[26][26] , int x , int cost[26][26]){

    queue<int> pendingNodes;
    pendingNodes.push(x);
    bool vis[26] = {false};

    int dis = 1 ;
    pendingNodes.push(-1);
    int z=x;
    while(!pendingNodes.empty()){

        int top = pendingNodes.front();
        pendingNodes.pop();
        if(top == -1){
            if(pendingNodes.size() > 0){
                pendingNodes.push(-1);
                dis++;
            }
            continue;
        }

        vis[top] = true;
        for(int i = 0; i < 26 ; i++){
            if(!vis[i] && i!=top && mat[top][i] == 1){
                cost[x][i] = min(cost[x][i] , dis) ;
                pendingNodes.push(i);
            }
        }
    }

}

int solve(string s , int mat[][26]){

    int cost[26][26];
     for(int i = 0 ; i < 26; i++){
        for(int j = 0 ; j < 26 ; j++){
             cost[i][j] = INT_MAX;
            if(i==j){
                cost[i][j] = 0 ;
            }
        }
    }

    bool done[26]= {false};
    
    for(int i=0 ; i < s.length() ; i++){

        int x = s[i] - 'A';
        if(done[x]){
            continue;
        }
        // cout<<x<<'\n';
        bfs(mat , x , cost);
     
        done[x] = true;
    }

    // for(int i = 0 ; i < 26 ; i++){
    //     for(int j = 0 ; j < 26 ; j++){
    //         cout<<cost[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }

    int totalCost = INT_MAX;
    for(int i = 0 ; i < 26 ; i++){
        int c = 0  ;
        bool t = false;
        for(int j = 0 ; j < s.length() ; j++){
            int x = s[j] - 'A';
            if(cost[x][i] == INT_MAX){
                t = true;
                break;
            }
            c+=cost[x][i];
        }

        if(!t){
            totalCost = min(totalCost,c);
        }
    }

    return (totalCost == INT_MAX) ?-1 : totalCost;

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("consistency_chapter_2_input.txt", "r" , stdin);
        freopen("output.txt", "w", stdout);
    #endif
    

    int T= 0 ;
    cin>>T;
    for(int i = 1 ; i <= T ; i++){
        string s{""};
        cin>>s;
        
        int n=0;
        cin>>n;
        int mat[26][26] ;
        for(int itr = 0 ; itr < 26 ; itr++){
            for(int j = 0 ; j<26 ; j++){
                mat[itr][j] = 0;
            }
        }

        //make a graph
        for(int j = 0 ; j < n ; j++){
            char x = '\0';
            char y = '\0';
            cin>>x>>y;

            int X = x  - 'A';
            
            int Y = y - 'A';
// cout<<X<<" "<<Y<<"\n";
            mat[X][Y] = 1;
        }

       cout<<"Case #"<<i<<": "<<solve(s , mat)<<"\n";

    }


}

