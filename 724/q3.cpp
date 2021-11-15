#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define modVal 10e9
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;



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
        
        int n =0;string s;
        cin>>n;
        cin>>s;

        vector<int>ans(n,1);

        vector<pair<int,int>> preCount(n,{0,0});
        if(s.length()<=1){
            cout<<1<<'\n';
            continue;
        }

        if(s[0] =='D'){
            preCount[0].first++;
        }else{
            preCount[0].second++;
        }

        for(int i =1;i < n ; i++){
            preCount[i].first=preCount[i-1].first;
            preCount[i].second=preCount[i-1].second;
            if(s[i] =='D'){
                preCount[i].first++;
            }else{
                preCount[i].second++;
            }
        }

        char startingChar = s[0];
        int i =1;
        int c=2;
        while(s[i]==startingChar){
            ans[i] = c;
            i++;c++;
        }

       
        
        unordered_map<double,int>f;
        for( ; i < n ;i++)
        {
            int c= 1;
            int  si=i;
            double r=(double)preCount[i].first/preCount[i].second;
            f[r]++;
            ans[i]=max(f[r],ans[i]);
        }

        for(int i =0;i<n ;i++){
            cout<<ans[i]<<" ";
        }cout<<"\n";


    }
   
}