#include<bits/stdc++.h>
using namespace std;
#define ll long long 
// #define modVal 10e9+7
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
long long const modVal = 1000000007;

int binarySearch(vector<ll> vec,ll si , ll ei ,  ll t){
    while(si<=ei){
        ll mid = (si+ei)/2;
        if(vec[mid] == t){
            return mid;
        }else{
            if(vec[mid] > t){
                ei=mid-1;
            }else
            {
                si=mid+1;
            }
        }
    }
   return -1;
}

int power( int n , int k){
    int a = n;
    int ans = 1;
    while(k>0){
        if(k&1 == 1){
            ans*=a;
        }
        k=k>>1;
        a=a*a;
    }
    return ans;
}

int KthRoot(int n , int k){
    int si = 1;
    int ei = n;
    int ans = 0;
    while(si<=ei){
        int mid = si+ ((ei-si)/2);
      
        int value = power(mid , k);
        if(value <= 0){
            ei=mid-1;
            continue;
        }
        if( value == n){
            return mid;
        }

        if(value<=n ){
            si=mid+1;
            ans=max(mid,ans);
        }else{
            ei=mid-1;
        }
    }
    return ans;
}


void makeSeive(vector<bool>&seive , int range , vector<int>& primes ){
    seive[0] = 0 ;//np
    seive[1] = 0 ;//np
    seive[2] = 1 ;//pr
    for(long long i=2 ; i <= range ; i++){
        if(seive[i]){
            primes.push_back(i);
            for(long long j = i*i ; j <= range ; j+=i){
                seive.at(j)=false;
            }
        }
    }
}

ll gcd(ll a, ll b){
    if (a == 0)
        return b;
    return gcd(b % a, a);
}


void print(vector<ll>&vec){
    for(auto i:vec) cout<<i<<" ";
    cout<<"\n";
}
void print(vector<int>&vec){
    for(auto i:vec) cout<<i<<" ";
    cout<<"\n";
}
void print(vector<string>&vec){
    for(auto i:vec) cout<<i<<" ";
    cout<<"\n";
}
void print(vector<vector<int>>&vec){
    for(int i =0;i<vec.size();i++){
        for(int j =0;j<vec[i].size();j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<"\n";
    }
}
void print(vector<vector<ll>>&vec){
    for(int i =0;i<vec.size();i++){
        for(int j =0;j<vec[i].size();j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<"\n";
    }
}
void print(vector<vector<string>>&vec){
    for(int i =0;i<vec.size();i++){
        for(int j =0;j<vec[i].size();j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int X[4] = {0,0,-1,1};
int Y[4] = {1,-1,0,0};

void dfs(vector<vector<char>> &g ,vector<vector<bool>>&vis, int i , int j , int r,int c){

    vis[i][j]=true;
    int mA=0;
    for(int k=0;k<4;k++){
        int x=i+X[k];
        int y=j+Y[k];
        if(x<0 || y<0 || x>=r || y>=c )
        {
            continue;
        }
        if(vis[x][y]){
            continue;
        }
        if(g[x][y] == '#'){
            continue;
        }
       dfs(g,vis,x,y,r,c);
                       
    }

}

int main(){
     
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r" , stdin);
        freopen("../output.txt", "w", stdout);
    #endif

    int T=0;cin>>T;


   
    while(T--){


        int r=0,c=0;
        cin>>r>>c;
        int noG=0;
        vector<vector<char>> mat(r,vector<char>(c,0));
        for(int i =0;i<r;i++){
            for(int j =0;j<c;j++){
                cin>>mat[i][j];
                if(mat[i][j] == 'G'){
                    noG++;
                }
            }
        }
        // if(noG){
        //     cout<<"Yes\n";continue;
        // }
        bool lost=false;
        vector<vector<int>> canReach(r,vector<int>(c,-1));
        for(int i =0;i<r;i++){
            for(int j =0;j<c;j++){
                if(mat[i][j] == 'B'){
                    for(int k =0;k<4;k++){
                        int x=i+X[k];
                        int y=j+Y[k];
                        if(x<0 || y<0 || x>=r || y>=c)
                        {
                            continue;
                        }
                        if(mat[x][y] == 'G'){
                            lost =true;
                            break;
                        }
                        if(x==r-1 && y == c-1){
                            if(noG != 0){
                                lost =true;
                                break;
                            }
                        }
                        if(mat[x][y]== '.'){
                            mat[x][y] = '#';
                        }
                    }
                }
            }
            if(lost){
                break;
            }
        }  
        if(lost){
            cout<<"No\n";continue;
        }

      
        vector<vector<bool>>vis(r,vector<bool>(c,false));

        dfs(mat,vis,r-1,c-1,r,c);

        for(int i=0;i<r;i++){
            for(int j =0;j<c;j++){
                if(mat[i][j] == 'G'){
                    if(!vis[i][j]){
                        lost = true;
                    }
                }
            }
        }

        if(lost){
            cout<<"No\n";
        }else{
            cout<<"Yes\n";
        }


      
    }
}