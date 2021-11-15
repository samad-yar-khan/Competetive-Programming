#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define modVal 10e9
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;



int main()
{
     ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r" , stdin);
        freopen("../output.txt", "w", stdout);
    #endif
 

    ll T{1};
    cin>>T;
    while(T--){

        ll n{0} ;
        cin>>n;
        ll arr[100000];
        for(ll i = 0 ; i < n ; i++){
            cin>>arr[i];
        }
         sort(arr , arr+n);
        if(n==1  || arr[0]>0){
            cout<<1<<"\n";
            continue;
        }

       
        int i =1;
        ll diff =INT_MAX;
        while (i<n && arr[i]<=0)
        {
            diff=min(abs(arr[i]-arr[i-1]),diff);
            i++;
        }
        
        if(i<n&&arr[i]>0 && arr[i]<=diff ){
            i++;
        }


        cout<<i<<"\n";

    }

}