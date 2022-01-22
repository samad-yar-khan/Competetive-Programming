#include<bits/stdc++.h>
using namespace std;
#define ll long long 
// #define modVal 10e9+7
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
long long const modVal = 1000000007;


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

    // vector<bool >seive(100001, true);    
    // vector<int> primes;
    // makeSeive(seive , 100000, primes);
    while(T--){
        ll n =0 ;  

        cin>>n;
        vector<int> odds , evens;

        for(int i =0;i<n;i++){
            int a =0;cin>>a;
            if(a%2==0){
                evens.push_back(a);
            }else{
                odds.push_back(a);
            }
        }

        if(evens.size()%2 == 0 && odds.size()%2==0){
            cout<<"YES\n";
        }else{
            sort(evens.begin(),evens.end());
            sort(odds.begin(),odds.end());

            vector<int> small; 
            vector<int> large; 

            if(evens.size()<odds.size()){
                small=evens;
                large = odds;
            }else{
                small=odds;
                large = evens;
            }
            int ss = small.size();
            int ls = large.size();
            
            int sst=ss;
            int lst=ls;
            int i =0;
            int j =0;
            while(i<ss && (sst%2!=0 || lst%2!=0)){
                
                int jt = j;
                bool f =false;
                while(jt < ls ){
                    // cout<<small[i]<<" "<<large[jt]<<"\n";
                    if(abs(large[jt]-small[i])==1){
                        f=true;
                        break;  
                    }
                    jt++;
                }
                if(f){
                   
                    j=jt;
                    sst+=1;
                    lst-=1;
                    j++;
                }
             
                i++;
            }
           
            if(sst%2!=0 || lst%2!=0){
                cout<<"NO\n";
            }else{
                cout<<"YES\n";
            }
        }


    }
}