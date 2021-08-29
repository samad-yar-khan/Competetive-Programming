#include <bits/stdc++.h>
using namespace std;
#define modVal 1000000007
#define ll long long



int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r" , stdin);
        freopen("output.txt", "w", stdout);
    #endif
    

    int T= 0 ;
    cin>>T;
    for(int i = 1 ; i <= T ; i++){

        int node[100000] =  {0};
        // int diff[100000] = {0};
        int n = 0 ;
        cin>>n;
        int diff = INT_MIN;
        int ans =n ;
        for(int i = 0 ; i < n ; i++){
            cin>>node[i];
        }

        diff=node[0]-0;
        for(int i = 1 ; i < n ; i++){
           
            if(node[i]-i != diff){
                ans =1;
                break;
            }
        }



      
      cout<<ans<<"\n";

    }




}

