#include<bits/stdc++.h>
using namespace std;
#define ll long long 
// #define modVal 10e9+7
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
long long const modVal = 1000000007;

// int binarySearch(vector<ll> vec,ll si , ll ei ,  ll t){

//     while(si<=ei){

//         ll mid = (si+ei)/2;
//         if(vec[mid] == t){
//             return mid;
//         }else{
//             if(vec[mid] > t){
//                 ei=mid-1;
//             }else
//             {
//                 si=mid+1;
//             }
//         }

//     }

//     return -1;

// }

// int power( int n , int k){

//     int a = n;
//     int ans = 1;
//     while(k>0){
//         if(k&1 == 1){
//             ans*=a;
//         }
//         k=k>>1;
//         a=a*a;
//     }

//     return ans;

// }

// int KthRoot(int n , int k){
//     int si = 1;
//     int ei = n;
//     int ans = 0;
//     while(si<=ei){
//         int mid = si+ ((ei-si)/2);
      
//         int value = power(mid , k);
//         if(value <= 0){
//             ei=mid-1;
//             continue;
//         }
//         if( value == n){
//             return mid;
//         }

//         if(value<=n ){
//             si=mid+1;
//             ans=max(mid,ans);
//         }else{
//             ei=mid-1;
//         }
//     }
//     return ans;
// }
// void makeSeive(vector<bool>&seive , int range , vector<int>& primes ){

//     seive[0] = 0 ;//np
//     seive[1] = 0 ;//np
//     seive[2] = 1 ;//pr

//     for(long long i=2 ; i <= range ; i++){
//         if(seive[i]){
//             primes.push_back(i);
//             for(long long j = i*i ; j <= range ; j+=i){
//                 seive.at(j)=false;
//             }
//         }
//     }
// }
// ll gcd(ll a, ll b)
// {
//     if (a == 0)
//         return b;
//     return gcd(b % a, a);
// }

// void print(vector<ll>&vec){
//     for(auto i:vec) cout<<i<<" ";
//     cout<<"\n";
// }
// void print(vector<int>&vec){
//     for(auto i:vec) cout<<i<<" ";
//     cout<<"\n";
// }
// void print(vector<string>&vec){
//     for(auto i:vec) cout<<i<<" ";
//     cout<<"\n";
// }
// void print(vector<vector<int>>&vec){
//     for(int i =0;i<vec.size();i++){
//         for(int j =0;j<vec[i].size();j++){
//             cout<<vec[i][j]<<" ";
//         }
//         cout<<"\n";
//     }
// }
void print(vector<vector<int>>&vec){
    for(int i =0;i<vec.size();i++){
        for(int j =0;j<vec[i].size();j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<"\n";
    }
}
// void print(vector<vector<string>>&vec){
//     for(int i =0;i<vec.size();i++){
//         for(int j =0;j<vec[i].size();j++){
//             cout<<vec[i][j]<<" ";
//         }
//         cout<<"\n";
//     }
// }


// bool isPal(string &s){

//     int si=0;int ei=s.length()-1;
//     while(si<ei){
//         if(s[si]!=s[ei]){
//             return false;
//         }
//         si++;ei--;
//     }

//     return true;


// }

ll q(int i , int j , int k){

    cout<<"? "<<i<<" "<<j<<" "<<k<<endl;
    ll res=0;cin>>res;
    return res;

}

int main(){
     
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    fflush(stdout);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r" , stdin);
        freopen("../output.txt", "w", stdout);
    #endif
 
    int T=0;cin>>T;
 
    while(T--){
        
        
        int n =0,m=0;cin>>n>>m;
        vector<vector<int>>mat(n,vector<int>(m,0));
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                cin>>mat[i][j];
            }
        }
 
        vector<int>cols(m,0);
        int fualts=0;
        for(int i =0;i<n;i++){
            for(int j =1;j<m;j++){
                if(mat[i][j]<mat[i][j-1]){
                    fualts++;
                    cols[j]++;
                    cols[j-1]++;
                }
            }
        }
        if(fualts == 0){
            cout<<1<<" "<<1<<"\n";
            continue;
        }
 
       
        vector<pair<int,int>>p(m,make_pair(0,0));
        for(int i =0;i<m;i++){
            p[i] = make_pair(cols[i],i);
        }
        bool w=false;
        vector<vector<int>>temp = mat;
        sort(p.begin(),p.end(),greater<pair<int,int>>());
        for(int i =0 ;i<6 && i<m;i++){
            for(int j =i+1;j<6 && j<m;j++){
              
                for(int x =0;x<n;x++){
                    swap(temp[x][p[i].second],temp[x][p[j].second]);
                }
                 fualts=0;
                for(int ii =0;ii<n;ii++){
                    for(int jj =1;jj<m;jj++){
                        if(temp[ii][jj]<temp[ii][jj-1]){
                            fualts++;
                        }
                    }
                }
                if(fualts ==0){
                   cout<<min(p[i].second,p[j].second)+1<<" "<<max(p[i].second,p[j].second)+1<<"\n";
                   w=true;
                   break;
                }
                for(int x =0;x<n;x++){
                    swap(temp[x][p[i].second],temp[x][p[j].second]);
                }
 
            }
            if(w){
                break;
            }
        }
        if(!w){
            cout<<-1<<"\n";
        }
       
 
 
        
      
    }
}

// int main(){
     
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);cout.tie(NULL);
//     fflush(stdout);
//     #ifndef ONLINE_JUDGE
//         freopen("../input.txt", "r" , stdin);
//         freopen("../output.txt", "w", stdout);
//     #endif

//     int T=0;cin>>T;

//     while(T--){
        
        
//         int n =0,m=0;cin>>n>>m;
//         vector<vector<int>>mat(n,vector<int>(m,0));
//           vector<vector<pair<int,int>>>pm(n,vector<pair<int,int>>(m,{0,0}));
//         for(int i =0;i<n;i++){
//             for(int j =0;j<m;j++){
//                 cin>>mat[i][j];
//                 pm[i][j] = make_pair(mat[i][j],j);
//             }
//         }
//         for(int i =0;i<n;i++){
//             stable_sort(pm[i].begin(),pm[i].end());
//         }

      

//         vector<int>cols(m,0);
//         int fualts=0;
//         for(int i =0;i<n;i++){
//             for(int j =1;j<m;j++){
//                 if(mat[i][j]<mat[i][j-1]){
//                     fualts++;
//                     cols[j]++;
//                     cols[j-1]++;
//                 }
//             }
//         }
//         if(fualts == 0){
//             cout<<1<<" "<<1<<"\n";
//             continue;
//         }
//         for(int i =0;i<n;i++){
//             for(int j=0;j<m;j++){

//             }
//         }

       
        
//         bool w=false;
      
        
//         if(!w){
//             cout<<-1<<"\n";
//         }

 
        
      
//     }
// }
/*
7 111
2 010

10 1010
12 1100
8 1000

9 1001
5 0101




*/