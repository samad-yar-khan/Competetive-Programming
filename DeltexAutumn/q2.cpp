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
   
    // int T= 0 ;
    // cin>>T;
    // while(T--){ 

        int N=0,Q=0;
        cin>>N>>Q;

        string s;
        cin>>s;

        int numChanges=0;
        int i =0;
        if(N<=2){
            while(Q--){
                cout<<0<<"\n";
            }
           return 0;
        }

        vector<int> ss;
        while(i < N-2){
            if(s[i]=='a'){
                if(s[i+1] == 'b' && s[i+2] == 'c'){
                    numChanges++;
                    ss.push_back(i);
                    i+=2;
                }
            }
            i++;
        }

        for(int i =0;i<Q;i++){
            
            int ind=0;
            cin>>ind;
            ind--;

            char x{'\0'};
            cin>>x;

            if(x==s[ind]){
                cout<<numChanges<<"\n";continue;
            }

            if(s[ind]=='a'){
                
                if((ind+1<N && s[ind+1]=='b') &&(ind+2<N && s[ind+2]=='c')){
                    s[ind]=x;
                    numChanges--;
                }
                

            }else if(s[ind]=='b'){

                if((ind-1>=0 && s[ind-1]=='a') &&(ind+1<N && s[ind+1]=='c')){
                    s[ind]=x;
                    numChanges--;
                }

            }else{

                if((ind-2>=0 && s[ind-2]=='a') &&(ind-1>=0 && s[ind-1]=='b')){
                    s[ind]=x;
                    numChanges--;
                }

            }
            s[ind]=x;

           if(s[ind]=='a'){
                
                if((ind+1<N && s[ind+1]=='b') &&(ind+2<N && s[ind+2]=='c')){
               
                    numChanges++;
                }
                

            }else if(s[ind]=='b'){

                if((ind-1>=0 && s[ind-1]=='a') &&(ind+1<N && s[ind+1]=='c')){
                   
                    numChanges++;
                }

            }else{

                if((ind-2>=0 && s[ind-2]=='a') &&(ind-1>=0 && s[ind-1]=='b')){
                   
                    numChanges++;
                }

            }
            cout<<numChanges<<'\n';



        }

        
    // }
   
}