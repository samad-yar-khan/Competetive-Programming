#include <bits/stdc++.h>
using namespace std;
#define modVal 1000000007
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
 
    cin.tie(NULL);
 

    ll T{0};
    cin>>T;
    while(T--){
        
        ll n = 0 ;
        cin>>n;
        int*arr = new int[n]{0};
        int nums = 0 ;
        for(int i = 0 ;  i< 2*n ; i++){
            cin>>arr[i];
            if(arr[i]&1 > 0){
                nums++;
            }
        }


        if(nums == n ){
            cout<<"Yes\n";
        }else{
            cout<<"No\n";
        }

        delete [] arr;
       
    }

}