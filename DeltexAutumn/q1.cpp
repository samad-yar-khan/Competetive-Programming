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
        
        int n =0;
        cin>>n;
        vector<long long>arr;
        ll pows =0;
        ll sum=0;
        ll sum2=0;
        for(int i =0;i<n ;i++){
            long long a =0;cin>>a;
            sum2+=a;
            while(a>1 && a%2==0){  
                pows++;
                a/=2;
            }
            arr.push_back(a);
            sum+=a;
        }
        ll one =1 ;
        ll s3=sum;
        for(int i =0;i<n;i++){
            ll sum3 = sum+((one<<pows)*arr[i])-arr[i];
            s3 = max(s3,max(sum3,sum));
        }
        cout<<s3<<"\n";
      
     
       

    }

    return 0;
   
}