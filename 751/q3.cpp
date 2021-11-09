#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define modVal 10e9
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

void solve(long long*arr , int n){

    vector<int>  bits(33,0);
    for(int i = 0 ; i < n ;i++){
        
        long long a = arr[i];
        int k = 0;
        while(a>0){
            if((a&1LL) == 1){
                bits[k]++;
            }
            k++;
            a=a>>1;
        }

    }
    for(int i = 1 ; i <= n ; i++ ){
        bool print_i = true;
        for(int j=0;j<32 ;j++){
            if(bits[j]%i!=0){
                print_i = false;
                break;
            }
        }
        if(print_i){
              cout<<i<<" ";
        }
      
    } 
    cout<<'\n';

}

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
        // cout<<T<<" ";
        int  n = 0 ;    
        cin>>n;
        long long*arr = new long long[n];
        for(int i = 0 ;i< n ; i++)
        {
            cin>>arr[i];
        }  
        solve(arr,n);
        delete [] arr;

    }
   return 0;
}