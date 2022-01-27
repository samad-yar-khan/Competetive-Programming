#include<bits/stdc++.h>
using namespace std;
#define ll long long 
// #define modVal 10e9+7
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
long long const modVal = 1000000007;



int main(){
     
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r" , stdin);
        freopen("../output.txt", "w", stdout);
    #endif

    // int T=0;cin>>T;

    // vector<bool >seive(100001, true);    
    // vector<int> primes;
    // makeSeive(seive , 100000, primes);

    int n =0;int q=0;
    cin>>n>>q;
    vector<int>pos(51,INT_MAX);
    for(int i =0;i<n;i++){
        int a =0;
        cin>>a;
        pos[a] = min(pos[a],i+1);
    }

    vector<int>ans(q,0);

    for(int i =0;i<q;i++){
        int qi=0;cin>>qi;
            ans[i]=pos[qi];
            for(int j=1;j<=50;j++){
                if(pos[qi] > pos[j]){
                    pos[j]++;
                }
            }
            pos[qi] =1;
        
    }
    for(int x:ans){
        cout<<x<<' ';
    }
    cout<<'\n';




}