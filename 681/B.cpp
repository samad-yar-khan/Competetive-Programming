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
// void print(vector<vector<ll>>&vec){
//     for(int i =0;i<vec.size();i++){
//         for(int j =0;j<vec[i].size();j++){
//             cout<<vec[i][j]<<" ";
//         }
//         cout<<"\n";
//     }
// }
// void print(vector<vector<string>>&vec){
//     for(int i =0;i<vec.size();i++){
//         for(int j =0;j<vec[i].size();j++){
//             cout<<vec[i][j]<<" ";
//         }
//         cout<<"\n";
//     }
// }


int main(){
     
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r" , stdin);
        freopen("../output.txt", "w", stdout);
    #endif

    int T=0;cin>>T;

   
    while(T--){

        ll a =0,b=0;
        cin>>a>>b;
        string s;cin>>s;
        int i =0;
        while(i<s.length() && s[i]=='0'){
            i++;
        }
        int  j=s.length()-1;
        while (j>i && s[j]=='0')
        {
            j--;
        }

        int c1=0;
        vector<ll>vec;
        while(i<=j){
            if(s[i] == '1'){
                i++;
                c1++;
                continue;
            }
            int k=i;
            while(k<s.length() && s[k]=='0'){
                k++;
            }
            vec.push_back(k-i);
            i=k;
        }
        
        
        ll ans = 0;
        if(c1!=0){
            ans+=a;
        } 
        for(int i =0;i<vec.size();i++){
            ans+=(min(vec[i]*b,a));
            // cout<<vec[i]<<" ";
        }
        cout<<ans<<'\n';
      
    }
}