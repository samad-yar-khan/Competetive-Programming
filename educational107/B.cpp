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

    int T=0;cin>>T;

    // vector<bool >seive(100001, true);    
    // vector<int> primes;
    // makeSeive(seive , 100000, primes);
    while(T--){

        int a =0,b=0,c=0;
        cin>>a>>b>>c;

        string X{"1"};
        string Y{"1"};
        string midX(a-c,'0');
        string midY(b-c,'1');
        string zeros(c-1,'0');
        
        X=X+midX+zeros;
        Y=Y+midY+zeros;
        cout<<X<<" "<<Y<<"\n";

    }
}