#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define modVal 10e9
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
      
        // vector<pair<int,int>> arr2;
        // vector<int> arr1;
        int N = 0 ;
        cin>>N;
        map<int,int> arr1;
        map<int,int> arr2;

        for(int i = 0 ;i< N ;  i++){
            int a =0;
            cin>>a;
            arr1[a] = i;

        }
        for(int j =0 ;j <N ;j++){
            int a =0;
            cin>>a;
            arr2[a] = j;
        }
        priority_queue<int , vector<int> , greater<int>> pq;
         int ans=INT_MAX; 
        for(int i =(2*N)-1 ; i>=1 ; i-=2){

            int num = arr1[i];
            pq.push(arr2[i+1]);
            int dis = pq.top();
            ans=min(ans , dis+num);

        }
    cout<<ans<<"\n";
    }
  


}