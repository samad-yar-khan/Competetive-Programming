#include<bits/stdc++.h>
using namespace std;
#define ll long long int
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
    vector<int>arr(2001,0);
    vector<int>qs(100001,0);
    while(T--){ 
        
        int  n = 0 ;
        cin>>n;
        
        for(int i = 0 ;i< n ; i++)
        {
            cin>>arr[i];
        }  
        int Q=0;
        cin>>Q;
        
        vector<pair<int , pair<int,int>>>queries;
        for( int i = 0 ; i < Q ; i++ ){
            int a =0;
            int b =0;
            cin>>a>>b;
            --a;
            queries.push_back(make_pair(b,make_pair(a,i)));
        }
        sort(queries.begin() , queries.end());
        int ct = 0;
        bool stop = false;
        for(int i = 0 ; i < Q ;i++){

            int k = queries[i].first;
            int ind = queries[i].second.first;
          
            while(ct < k && !stop ){
                ct++;
                vector<int> F(n+1,0);
                for(int j = 0 ;  j < n ; j++){
                    F[arr[j]]++;
                }
                stop = true;
                for(int j = 0; j<n ; j++){
                    if(F[arr[j]]!=arr[j]){
                        stop = false;
                    }
                    arr[j] = F[arr[j]];
                }
            
            }
           qs[queries[i].second.second]= arr[ind];
        }
        for(int  i=0 ; i< Q ;i++){
            cout<<qs[i]<<"\n";
        }
        

    }
   return 0;
}