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
    int  T=0;cin>>T;
    while(T--){
        int n =0;cin>>n;
        int x=0; cin>>x;
        queue<pair<int ,int>> vals;
        vector<int> arr(n , 0);
        for(int i =0;i<n ;i++){
            cin>>arr[i];
            vals.push({arr[i],1});
        }
        
        ll ans =0;
        while(vals.size()>0){

            int topNum = vals.front().first;
            int topF = vals.front().second;
            vals.pop();
            ans+=topF*topNum;
            if(topNum%x !=0){
                break;
            }else{
                vals.push({topNum/x,topF*x});
            }

        }
         while(vals.size()>0){

            int topNum = vals.front().first;
            int topF = vals.front().second;
            vals.pop();
            ans+=topF*topNum;

        }

        cout<<ans<<'\n';
    }
    

}