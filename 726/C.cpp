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

        int n=0;
        cin>>n;
        vector<int>arr(n,0);
        
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
       
        sort(arr.begin(),arr.end());
        int ind1=0;int ind2=0;
        int diff =INT_MAX;
        for(int i=0;i<n-1;i++){
            if(arr[i+1]-arr[i]<diff){
                ind1=i;ind2=i+1;
                diff=arr[i+1]-arr[i];
            }
        }
        if(arr[n-1]==arr[n-2]){
            ind1=n-2;
            ind2=n-1;    
        }
        if(n==2){
            cout<<arr[0]<<" "<<arr[1]<<"\n";continue;
        }
        for(int i=ind2;i<n;i++){
            cout<<arr[i]<<" ";
        }
        for(int i=0;i<ind2;i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
        
    }
   
}