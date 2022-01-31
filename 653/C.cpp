#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define modVal 10e9
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;


//gives bit rep
vector<int> getBits(ll n){    
    vector<int> ans(64,0);
    ll n_=n;
    int pos = 0 ;
    while(n_>0){
        if(n_&1){
            ans[pos]++;
        }
        n_=n_>>1;
        pos++;
    }
    return ans;
}

//vector<int> getBits(int n){    
ll getNumFromBits(vector<int>& bits){
    int curr = 1;
    ll ans=0;
    for(int i =0;i<32;i++){
        if(bits[i]){
            ans+=(curr);
        }
        curr = curr<<1;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r" , stdin);
        freopen("../output.txt", "w", stdout);
    #endif
    int T=0 ;
    cin>>T;
    while(T--){ 
        ll a=0,b=0;
        cin>>a>>b;
        if(a>=b){
            cout<<a-b<<"\n";
        }else{
            ll ans=(b-a);
            for(int i =0;a+i<=b;i++){
                ll a_ = a+i;
                vector<int>A = getBits(a_);
                vector<int>B= getBits(b);  
                vector<int>B_(64,0);             
                for( int j=31; j>=0 ; j--){
                    if(A[j] == 1 && B[j]== 0){
                        B_[j] = 1;
                        break;
                    }else{
                        B_[j] = B[j];
                    }
                }
                ll b_ = getNumFromBits(B_);
                ll ansTemp = i+ (-b) +1 + (a_|b_) ;
                ans = min(ans,ansTemp);
            }
            cout<<ans<<"\n";
        }
    }
}