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
        
        string S;cin>>S;
        int W=0;cin>>W;

        vector<string> vec(W+1);
        for(int i =0;i<=W;i++){
            cin>>vec[i];
        }
        vector<pair<char,int>>wl;
        int si=0;
        while(si<S.length()){
            int ci=si;
            char cc  =S[ci];
            int c=0;
            while (ci<S.length() && S[ci] == cc)
            {
                c++;
                ci++;
            }
            wl.push_back({cc,c});
            si=ci;    
        }
        int ans=0;
        for(int i =0;i<=W;i++){
          
            string T=vec[i];
            int si=0;
            vector<pair<char,int>>wl2;
            while(si<T.length()){
                int ci=si;
                char cc  =T[ci];
                int c=0;
                while (ci<T.length() && T[ci] == cc)
                {
                    c++;
                    ci++;
                }
                wl2.push_back({cc,c});
                si=ci;    
            }

            if(wl.size()!=wl2.size()){
                continue;
            }   

            bool na=true;

            for(int j =0;j<wl.size() ;j++){
                if(wl[j].first!=wl2[j].first){
                   
                    na=false;break;
                }

                if(wl[j].second < wl2[j].second || (wl[j].second>wl2[j].second && wl[j].second<3)){
                   
                    na=false;break;
                    
                }
            }
              if(na){
                //   cout<<i<<"\n";
               
                ans++;
            }
          

        }
        cout<<ans<<"\n";
        
    }
   
}