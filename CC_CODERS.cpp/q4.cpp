#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define modVal 10e9+7
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;



int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r" , stdin);
        freopen("../output.txt", "w", stdout);
    #endif
   
    int T= 0 ;
    cin>>T;
    
    while(T--){ 

        ll N=0,K=0;

        cin>>N>>K;

        vector<int> vec;
        ll x=N;
        ll p=1;
        priority_queue<ll , vector<ll>,greater<ll>>pq;
        while(x>0){
            vec.push_back(x%10);
            p=p*(x%10);
            pq.push(x%10);
            x/=10;
        }
        int i =0;
        while(i<K && pq.size() >0&&pq.top()<9){

            ll y = pq.top();
            pq.pop();
            y+=1;
            pq.push(y);
            i++;

        }
        ll ans =1;
        while(pq.size()>0){
            ans=ans*(pq.top());
            pq.pop();
        }
        cout<<ans<<"\n";
    }
   
}