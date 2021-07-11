#include <bits/stdc++.h>
using namespace std;
#define modVal 1000000007
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
 
    cin.tie(NULL);
 

    int T{0};
    cin>>T;
    while(T--){

        ll n{0} , m{0};
        cin>>n>>m;

        string s;
        cin>>s;

        int arr[1001] = {0};
        int ld=INT_MAX;
       

        for(int i = 0 ; i < s.length() ; i ++){

            if(s.at(i) == '1'){
                    ld = 0;
            }else{
                
                if(ld!=INT_MAX){
                    ld++;
                }
                 int rd=INT_MAX;
                for(int j = i+1 ; j < s.length() ; j++ ){
                    if(s.at(j) == '1'){
                        rd = j-i;
                        break;
                    }
                }

                int md = min(rd,ld);
                if(md <= m && ld!=rd){
                    s.at(i) = '1';
                }
            }

        }

        cout<<s<<"\n";


    }

}