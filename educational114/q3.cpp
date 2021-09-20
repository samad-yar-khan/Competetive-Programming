#include<bits/stdc++.h>
using namespace std;
#define ll long long

#define modVal 10e9

//os tree
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r" , stdin);
        freopen("../output.txt", "w", stdout);
    #endif

    int N = 0 ;
    cin>>N;
    ll*heros = new ll[N+1];
    ll tp=0;
   
    for(int i =0; i <N ; i++){
        cin>>heros[i];
        tp+=heros[i];
    }   
    int D=0;
    cin>>D;
    pair<ll , ll>* dragons= new pair<ll , ll>[D];
    for(int j = 0 ; j<D ; j++){
        cin>>dragons[j].first;
        cin>>dragons[j].second;
    }
   
    sort(heros  , heros+N);

    for(int j = 0 ; j < D ; j++){

        ll x = dragons[j].first;
        ll y = dragons[j].second;

        if(heros[N-1] < x){
            ll c = x- heros[N-1];
            
            if(tp - heros[N-1] < y){
                c+= (y-(tp-heros[N-1]));
            }
            cout<<c<<"\n";
            continue;
        }

        int ind = lower_bound(heros , heros+N , x)-heros;
        
        ll h1 = heros[ind];
        ll c =0;
        if(h1 < x){
            c+=(x-h1);
        }

        if(tp - h1 < y){
            c+=(y-(tp-h1));
        }

        if(ind>0){
            ll h1 = heros[ind-1];
            ll c2 =0;
            if(h1 < x){
                c2+=(x-h1);
            }

            if(tp - h1 < y){
                c2+=(y-(tp-h1));
            }
            c=min(c,c2);
        }

        cout<<c<<'\n';
    }

    delete [] dragons;
    delete [] heros;
}