#include <bits/stdc++.h>
using namespace std;
#define modVal 1000000007
#define ll long long


void solve(){
    int n{0};
        string s = {""};
            cin>>n;
            cin>>s;

            string arr[26] = {""};
            for(int i = 0 ; i < 26 ; i++){
                string str = {""};
                arr[i] = str + char('a' + i);
            }

            for(int i = 0 ; i < 26 ; i++){
                if(s.find(arr[i]) == -1){
                    cout<<arr[i]<<"\n";
                    return ;
                }
            }
            for(int i = 0 ; i < 26 ; i++){
               
                for(int j = 0 ; j < 26 ; j++){
                   string sTemp = arr[i] + arr[j];
                    if(s.find(sTemp) == -1){
                        cout<<sTemp<<"\n";
                        return ;
                    }
                }
            }

              for(int i = 0 ; i < 26 ; i++){
               
                for(int j = 0 ; j < 26 ; j++){
                    
                    for(int k = 0 ; k < 26 ; k++){
                        string sTemp = arr[i] + arr[j] + arr[k];
                        if(s.find(sTemp) == -1){
                            cout<<sTemp<<"\n";
                            return ;
                        }
                    }
                }
            }
    
}

int main()
{
    ios_base::sync_with_stdio(false);
 
    cin.tie(NULL);
 

    int T{0};
    cin>>T;
    while(T--){

        solve();
        
       
    }

}