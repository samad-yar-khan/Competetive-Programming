#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define modVal 10e9+7
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

        ll N=0 , K=0;
        cin>>N>>K;

        string s;
        cin>>s;

        set<char> s2;

        for(int i =0;i<N;i++){
            s2.insert(s[i]);    
        }

        if(s2.size()>1 && K==0){
            cout<<-1<<"\n";
            continue;
        }

        vector<char>c;
        char A='A';
        for(int i =0;i<26 ;i++){
            char N=A+i;
            c.push_back(N);
        }

        ll ans =0;
        for(int i =0 ;i<26 ;i++){
            int KT=K;
            char curr = c[i];

            int lenP =0;
            while(lenP<N && s[lenP]==curr){   
                lenP++;
            }
            int lenS =0;
            int j = N-1;
            while(j>=0 && s[j]==curr){   
                lenS++;
                j--;
            }


            int k = lenP;
            priority_queue<int>pq;
            while(k <= j){
              
                if(s[k] == curr){
                    int x = k; 
                    int c2=0;
                    while(s[x] == curr){
                        c2++;x++;
                    }
                    k=x;
                    pq.push(c2);
                }else{
                    k++;
                }
            }

            int mids =0;
            // cout<<pq.size()<<","<<K<<" \n";
           KT--;
            while(KT>0 && pq.size() >0){
                mids+=pq.top();
                pq.pop();
                KT--;
            }
            ll a2 =lenP+lenS+mids;
            ll an =  min(N , a2);
            ans = max(an , ans);
         


        }

        cout<<ans<<"\n";

    }
   
}

