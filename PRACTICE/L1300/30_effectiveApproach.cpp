#include <bits/stdc++.h>
using namespace std;
#define modVal 1000000007
#define ll long long


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../../input.txt", "r" , stdin);
        freopen("../../output.txt", "w", stdout);
    #endif
   
    int n = 0 ;
    cin>>n;
    vector<int> vec;
    vector<int> indexes(n+1 ,0);
    for(int i =0 ; i < n ; i++){
        int a = 0 ;
        cin>>a;
        vec.push_back(a);
        indexes[a] = i+1;
    }
    int m = 0 ;

    cin>>m;
    ll s = 0 , v=0;
    for(int i = 0;i<m;i++){
        int q=0;
        cin>>q;
        s= s+(indexes[q]);
        v=v+(n-indexes[q]+1);
        // indexes[q]=0;
        // indexes[n-q+1]=0;
    }
    cout<<s<<" "<<v<<"\n";

   
}

