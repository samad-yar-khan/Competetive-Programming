#include<bits/stdc++.h>
using namespace std;
#define ll long long 
// #define modVal 10e9+7
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
long long const modVal = 1000000007;

//the crux of the problm is to make unique substrings  of lkength 2
// this can be achived by actually making a dfs 
//provided k = 3
//for a , we try to add , a , b , c
//for b we add b ,c
//for c we add c
//wehenver we return from a dfs call
//we need to add revrse , so if the index is diiff we add our char to the end
//we should initially have a , inoiut string already
//a 
// aa 
//we from aab
//we call dfs on b
//we append b aabb
//we  itertate to see c , append c and as c is not vis, call on c
// call c-> aabbc
//np we go back, to b's call
//we need to form reversed ,
//append b at end and ind of b is 2 and c is 3
// aabbcb
//we go back to a's call
// we see diff idices upon bac=ktracking
//we appejnd at edn
// aabbcba
//we are on as loop and we add c
//aabbcbac
//we cant call dfs on c as it has been visited
//apppend a at end as index is diff
//aabbcbaca
//no of len of this unique string is less than n
//we print a sus strings
//but if the length of this staring is kless than n, we keep printing the sam estring till we reach length n , ignore last char as it leads to a worst caasr


void dfs(int i,int k,vector<bool> &vis,string &s,int n){

    if(n==0){
        return ;
    }
    vis[i] = true;

    // cout<<i<<" "<<k<<"\n";
    for(int ind =i ;ind<k && n>0;ind++){

        char ins='a'+ind;
        s+=(ins);
        if(!vis[ind]){
            dfs(ind,k,vis,s,n);
        }   
        if(n==0){
            break;
        }
        if(ind!=i){
              char ins='a'+i;
              s+=ins;
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

    // int T=0;cin>>T;

    // vector<bool >seive(100001, true);    
    // vector<int> primes;
    // makeSeive(seive , 100000, primes);


    int  n=0,k=0;
    cin>>n>>k;
    string s{"a"};
    if(n==1){
        cout<<s<<"\n";return 0;
    }
    vector<bool> vis(26,false);
    dfs(0,k,vis,s,n);
    // cout<<s<<" ";
    if(s.length()>n){
        for(int i =0;i<n;i++){
            cout<<s[i%s.size()];
        }
    }else{
         for(int i =0;i<n;i++){
            cout<<s[i%(s.size()-1)];
        }
    }
    cout<<'\n';
  
  
}