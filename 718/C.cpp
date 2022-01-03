#include<bits/stdc++.h>
using namespace std;
#define ll long long 
// #define modVal 10e9+7
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
long long const modVal = 1000000007;

ll exp(ll m , ll n){    //m^n

    ll number = m ;
    ll power = n ;
    ll answer = 1;
    while( power > 0){
        if((power & 1 ) > 0){
            answer *= number ;
            answer%=modVal;
        } 
        //square the number 
        number*=number;
        number%=modVal;
        //right shift power
        power = power>>1;
    }
    return answer;
}


int main(){
    
   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r" , stdin);
        freopen("../output.txt", "w", stdout);
    #endif
   
    int n=0;
    cin>>n;
    vector<vector<int>>vec(n+1 , vector<int>(n+1,0));

    for(int i =0;i<n;i++){
        cin>>vec.at(i).at(i);
    }

    for(int i =0 ;i<n ;i++){

        int num = vec.at(i).at(i);
        int k = num-1;
        int row = i;
        int col =i;
        while(k>0){
            if(vec.at(row).at(col) ==0){
                vec.at(row).at(col) = num;
                k--;
                 if(col >0 &&  vec.at(row).at(col-1) == 0 ){
                     col--;
               }else{
                   row++;
               }
            }else{

                if(col >0 &&  vec.at(row).at(col-1) == 0 ){
                     col--;
               }else{
                   row++;
               }

            }
            
           
            // }else if(vec.at(row).at(col)==0){
            //     vec.at(row).at(col) = num;
            //     row++;
            //     k--;
            // }else{
            //     row++;
            // }
        }

    }

    for(int i =0;i<n ;i++){
        for(int j=0;j<=i;j++){
            cout<<vec.at(i).at(j)<<" ";
        }
        cout<<"\n";
    }

    
}