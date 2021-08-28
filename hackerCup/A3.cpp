#include <bits/stdc++.h>
using namespace std;
#define modVal 1000000007
#define ll long long




pair<int,int> solve(vector<string> &board, int n){

    pair<int , int > a = make_pair(0,0);
    pair<int , int> rows[50] = {a} ; 
    pair<int , int > cols[50] = {a};

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(board[i][j] == 'X'){
                rows[i].first++;
            }else if(board[i][j] == 'O'){
                rows[i].second++;
            }
        }
    }

    for(int j = 0 ; j < n ; j++){
        for(int i = 0 ; i < n ; i++){
            if(board[i][j] == 'X'){
                cols[j].first++;
            }else if(board[i][j] == 'O'){
                cols[j].second++;
            }
        }
    }

    bool noZeros = true; //no row with no zerows
    for(int i =  0 ; i < n ; i++){
        if(rows[i].second == 0 || cols[i].second==0){
            noZeros=false;
            break;
        }
    }

    //no rows or cols with no zerows
    if(noZeros){
        return make_pair(-1,-1);
    }

    int minXRows = INT_MAX;
    int minXCols = INT_MAX;

    vector<int> rowsCon;
    vector<int> colCon;

    for(int i = 0 ; i < n ; i++){
        if(rows[i].second==0){
            int xSNeeded = n-rows[i].first;
            
            if(xSNeeded < minXRows){
                rowsCon.clear();
                rowsCon.push_back(i);
                minXRows = xSNeeded;
            }else if(xSNeeded == minXRows){
                rowsCon.push_back(i);
            }
        }
    }

    for(int i = 0 ; i < n ; i++){
        if(cols[i].second==0){
            int xSNeeded = n-cols[i].first;
            
            if(xSNeeded < minXCols){
                colCon.clear();
                colCon.push_back(i);
                minXCols = xSNeeded;
            }else if(xSNeeded == minXCols){
                colCon.push_back(i);
            }
        }
    }

    if(minXCols<minXRows){
        return make_pair(minXCols , colCon.size());
    }else if(minXCols>minXRows){
         return make_pair(minXRows ,  rowsCon.size());
    }else if(minXCols == minXRows && minXCols!=1){
        return make_pair(minXCols , rowsCon.size() + colCon.size());
    }


    //now here we have that we need toplace 1 x to make the row and cols win 
    // so wenjust mark these poits and the numb od points will be the ans
    int arr[50][50];
    for(int i =  0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            arr[i][j] = 0 ;
        }
    }

    for(int i = 0 ; i < rowsCon.size() ; i++){

        int r = rowsCon[i];
        for(int j = 0 ; j < n ; j++){
            if(board[r][j] == '.'){
                arr[r][j] = 1;
            }
        }

    }

    for(int j = 0 ; j < colCon.size() ; j++){

        int c = colCon[j];
        for(int i = 0 ; i < n ; i++){
            if(board[i][c] == '.'){
                arr[i][c] = 1;
            }
        }

    }
    int ans=0;
    for(int i = 0 ; i < n ; i++ ){
        for(int j = 0 ; j <n ; j++){
            ans += arr[i][j];
        }
    }

    return make_pair(1 , ans);



}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("xs_and_os_input.txt", "r" , stdin);
        freopen("output.txt", "w", stdout);
    #endif
    

    int T= 0 ;
    cin>>T;
    for(int i = 1 ; i <= T ; i++){
        
        string nullStr {""};
        vector<string>  board(50,nullStr);

        int n = 0;
        cin>>n;
        for(int i = 0 ; i < n ;i++){
            cin>>board[i];
        }
        pair<int,int> ans = solve(board , n);
        if(ans.first==-1){
            cout<<"Case #"<<i<<": "<<"Impossible"<<"\n";
        }else{
            cout<<"Case #"<<i<<": "<<ans.first<<" "<<ans.second<<"\n";
        }
        
    }


}

