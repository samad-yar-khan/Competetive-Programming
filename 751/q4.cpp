#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define modVal 10e9
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

int minMoves(vector<int>&a ,vector<int>&b , int ci ,int n , bool slip,bool* visited){
    
    if(ci<0){
        return 0;
    }

    if(ci>=n || visited[ci]){
        return INT_MAX;
    }
    visited[ci] = true;
    if(slip){
        visited[ci]=false;
        return minMoves(a,b,ci+b[ci], n, false,visited);
    }
    int ans = INT_MAX;
    for(int i = 1 ; i <= a[ci] ; i++){
        int sa = minMoves(a,b,ci-i,n,true,visited);
        ans = min(sa,ans);
    }
    visited[ci]=false;
    if(ans==INT_MAX){
        return ans;
    }
    return ans+1;


}

void solve(vector<int>&a , vector<int>&b, int n){
    // cout<<n<<"\n";
    bool*visited = new bool[n];
    for(int i = 0;i<n ;i++){
        visited[i] = false;
    }
    // cout<<"N-1"<<n<<'\n';
    int ans = minMoves(a,b,n-1,n ,false,visited);
    if(ans==INT_MAX){
        cout<<-1;
    }else{
        cout<<ans;
    }
    cout<<'\n';
    delete [] visited;

}

int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r" , stdin);
        freopen("../output.txt", "w", stdout);
    #endif
   
   
    // while(T--){ 
        // cout<<T<<" ";
        int  n = 0 ;    
        cin>>n;
        vector<int>a(n,0);
        vector<int>b(n,0);
       for(int i = 0;i < n ; i++ ){
           cin>>a[i];
       }
       for(int j = 0 ; j < n ; j++){
           cin>>b[j];
       }
        solve(a,b,n);
    // }
   return 0;
}