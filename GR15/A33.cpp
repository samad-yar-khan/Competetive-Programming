#include <bits/stdc++.h>
using namespace std;
#define modVal 1000000007
#define ll long long


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r" , stdin);
        freopen("output.txt", "w", stdout);
    #endif
   
    

    int T= 0 ;
    cin>>T;


    while(T--){

        ll N=0;
        cin>>N;
        string t{""};
        cin>>t;
        string b{""};
        cin>>b; 

        int i = 0 ;
        int j = 0 ;
    
        bool zeros =false;
        bool ones = false;
        ll ans =0;
        int n = t.length();

        while(i < n){
            j=i;
            while(j < n ){
                
                if(((t[j]=='1' && b[j] =='0') || (t[j]=='0' && b[j] =='1')) && zeros){
                    ans += (j-i+2);
                    j++;
                    zeros=false;
                    ones=false;
                    break;
                }

                if(((t[j]=='1' && b[j] =='1')) && zeros){
                    ans += (j-i+1);
                    j++;
                    zeros=false;
                    ones=false;
                    break;
                }


                if(t[j]=='1' || b[j] == '1'){
                    ones=true;
                }
                if(t[j] == '0' || b[j] =='0'){
                    zeros=true;
                }
                j++;
                if(zeros && ones){
                    ans+=2;
                    zeros=false;
                    ones=false;
                    break;
                }

                // if(j-i >1 && zeros){
                //     ans+=2;
                //     zeros=false;
                //     ones=false;
                //     break;
                // }

            }

            if(j==n && zeros){
                ans+=(j-i);
            }
            i=j;

        }

        cout<<ans<<"\n";

      
    }
   
}

