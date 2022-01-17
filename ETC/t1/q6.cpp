#include<bits/stdc++.h>
using namespace std;
#define ll long long

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

ll modVal = 1000000009;

ll solve(vector<ll> &arr , int n ){

    vector<ll> temp  = arr;
    ll ca =0;
    while(temp.size()>2){
        
        int mindIndex =0;
        ll minEl=INT_MAX;
        for(int i =0;i<temp.size();i++){
            if(temp[i]<minEl){
                minEl=temp[i];
                mindIndex=i;
            }
        }

        ll l1=1,lc1=1,cc1=1,rc1=1;

        if(mindIndex-1 >=0 ){
            lc1=temp[mindIndex-1 ];
        }
        if(mindIndex-2 >=0 ){
             l1=temp[mindIndex-2 ];
        }
        cc1=temp[mindIndex];
        if(mindIndex+1 < temp.size()){
            rc1=temp[mindIndex+1];
        }
        ll rc2 =1;
        if(mindIndex+2 < temp.size()){
            rc2=temp[mindIndex+2];
        }

        ll op1 = (l1*lc1*cc1*rc1)%modVal;
        ll op2 = (lc1*cc1*rc1*rc2)%modVal;
        ll ma=0;
        int x=0,y=0;
        if(op1 > op2){
            x=mindIndex-1;
            y=mindIndex;
        }else{
             x=mindIndex;
            y=mindIndex+1;
        }
        ma= max(op1,op2);

        ca = (ca%modVal + ma%modVal)%modVal;vector<ll>t2;
        for(int i =0;i<temp.size();i++){
            if(i != x && i != y){
                t2.push_back(temp[i]);
            }
        }
        temp=t2;
    }
    ca =( ca%modVal + (temp[0]*temp[1])%modVal)%modVal;
    return ca;
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
        
        int n =0;cin>>n;
        vector<ll>arr( n , 0);
        for(int i =0;i<n ;i++){
            cin>>arr[i];
        }
    cout<<solve(arr , n)<<"\n";

    }
   
}