#include<bits/stdc++.h>
using namespace std;
#define ll long long 
// #define modVal 10e9+7
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
long long const modVal = 1000000007;


ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
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

        int n =0, w=0;
        cin>>n>>w;

        vector<int> vec(n,0);
        vector<int> bitF(33,0);
        for(int i =0;i<n;i++){
            cin>>vec[i];
            int j =0;
            int a = vec[i];
            while(a>1){
                j++;
                a/=2;
            }
            bitF[j]++;
        }
        int N=n;
        int level=0;
        while(N>0){

            int WT=w;
            for(int i=32 ;i>=0 ;i--){
                
                if(bitF[i]>0){
                    ll number = 1<<i;
                    while(bitF[i]>0 && WT>=number){
                        WT-=number;
                        N--;
                        bitF[i]--;
                    }
                    

                }else{
                    continue;
                }

            }
            level++;

        }
        cout<<level<<"\n";
        

      
    }
    
   
 
    
}