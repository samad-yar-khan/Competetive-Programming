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

        if(s2.size()>0 && K==0){
            cout<<-1<<"\n";
            continue;
        }

        vector<char>c;
        char A='A';
        for(int i =0;i<26 ;i++){
            char N=A+i;
            c.push_back(N);
        }

        int ans =0;
        for(int i =0 ;i<26 ;i++){

            char curr = c[i];
            priority_queue<int>pn;
            int counts=0;
            for(int i=0;i<N;i++){
                if(s[i]==c[i]){
                    counts++;
                }
            }
            
            if(counts==0){
                continue;
            }

            int j=0;

            while(j<N && s[j]!=curr){
                j++;
            }   
            int k=K;
            if(j>0){
                k--;
            }
            j=N-1;
            while(j>=0 && s[j]!=curr){
                j--;
            }
            if(j<N-1){
                k--;
            }

            j=0;

            while(j<N){
                int k =j;
                int c2=0;
                if(s[j]==curr){
                    while(s[k]==curr){
                        k++;
                        c2++;
                    }
                    j=k;
                    pn.push(c2);
                }else{
                    j++;
                }
            }

            int temp =0;
            while(pn.size()>0 && k>0){
                temp+=(pn.top());
                pn.pop();
            }

            ans = max(ans,temp);

        }

        cout<<ans<<"\n";



    }
   
}