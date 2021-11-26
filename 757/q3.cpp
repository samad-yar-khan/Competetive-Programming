#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define modVal 10e9+7
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

class trip
{

    public :
        ll l;
        ll r;
        ll x;
};

bool comp(trip a , trip b){
    if(a.r!=b.r){
        return a.r<b.r;
    } 
    return a.l<b.l;
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

        ll n =0 , m=0;
        cin>>n>>m;
        vector<trip> vec;
        for(int i =0;i< m ;i++){
            ll l=0,r=0,x=0;
            cin>>l>>r>>x;
            trip t;
            t.l=l;
            t.r=r;
            t.x=x;
            vec.push_back(t);
        }
        sort(vec.begin(),vec.end(),comp);
        for(int i =0;i< m ;i++){
            cout<<vec[i].l<<" "<<vec[i].r<<" "<<vec[i].x<<"\n";
        }
       
    }
   
}