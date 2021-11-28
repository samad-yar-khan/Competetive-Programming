#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define modVal 10e9+7
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;


void prime_seive(int *arr , int n){

    //0 means non preime and 1 means prime
    //set all to prime except  even nos and on3
    arr[0] = 0;
    arr[1] = 0;
    arr[2] = 1;
    for(ll i =3 ; i<=n ; i+=1){
        if(i%2==0){
            arr[i] = 0;
        }else{
            arr[i] = 1;
        }
    }

    //now we mark mulriples 
    //bit onlu marks mulriple  of peimes and starting from theri squares
    //2 ke multiples even hia , wo already marks hogye
    for(ll i = 3 ; i<= n ; i++){
        if(arr[i] == 0){
            continue;
        }
        for(ll j = i*i ; j <= n ; j+=i){
            arr[j] = 0;
        }

    }

    return;

}


int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r" , stdin);
        freopen("../output.txt", "w", stdout);
    #endif
   
    int* arr=new int[1000001];
    
    prime_seive(arr , 1000000);
    int T= 0 ;
    cin>>T;
   
    while(T--){ 

        
        ll n =0,e=0;
        cin>>n>>e;
        vector<ll>vec;
        for(int i =0;i<n ;i++){
            ll el =0;cin>>el;
            vec.push_back(el);
        }
        ll ans=0;
        for(int i =0;i<n ;i++){

            if(arr[vec[i]]){
                ll j = i+e;
                ll r=0;
                ll l=0;
                while(j<n && vec[j] == 1){
                    j+=e;
                    r++;
                }

                j = i-e;
                while(j>=0 && vec[j] == 1){
                    j-=e;
                    l++;
                }
                ll comb = r*l;
                ans+=(l+r+comb);

            }

        }
        cout<<ans<<"\n";
        

       
    }
    delete [] arr;
   
}