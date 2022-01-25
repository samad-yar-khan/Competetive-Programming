#include<bits/stdc++.h>
using namespace std;
#define ll long long 
// #define modVal 10e9+7
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
long long const modVal = 1000000007;

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
        // cout<<value<<"\n";
        
        //overflow

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

ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

ll sd(ll n){
    ll a=0;
    while (n>0)
    {
        a+=(n%10);
        n/=10;
    }
    
    return a;
}



int main(){
     
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r" , stdin);
        freopen("../output.txt", "w", stdout);
    #endif

    int T=0;cin>>T;

    vector<bool >seive(100001, true);    
    vector<int> primes;
    makeSeive(seive , 100000, primes);
    while(T--){

        int n =0;cin>>n;
        string s(n,'0');
        vector<string> mat(n,s);
        for(int i =0;i<n;i++){
           cin>>mat[i];
        }

        bool lost = false;
        for(int i = n-2 ;i>=0 ;i--){
            for(int j = n-2 ;j>=0 ;j--){
                if(mat[i][j] =='1'){
                    if(!(mat[i][j+1]=='1' || mat[i+1][j]=='1')){
                        lost = true;break;
                    }
                }

            }
            if(lost){
                break;
            }
        }

        if(lost){
            cout<<"NO\n";
        }else{
            cout<<"YES\n";
        }
      
    }
}