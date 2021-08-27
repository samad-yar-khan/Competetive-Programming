#include <bits/stdc++.h>
using namespace std;
#define modVal 1000000007
#define ll long long

 
int main()
{
    ios_base::sync_with_stdio(false);
 
    cin.tie(NULL);
 
 
    ll T{0};
    cin>>T;
    int A= 'a';
 
    while(T--){
 
      
 
        int N = 0 , M = 0 ;
        long long freq[100001] = {0};
        cin>>N>>M;
        vector<string> vec;
        vector<string> vec2;
 
        for(int i = 0 ; i < N ; i++){
            string s{""};
            cin>>s;
           
            for(int j = 0 ; j < M ; j++){
                int a=0;
                 a = int(s[j] - A);
                freq[j] += a;
            }
         
            vec.push_back(s);
        }
     
        for(int i = 0 ; i < N-1 ; i++){
            string s{""};
            cin>>s;
         
            for(int j = 0 ; j < M ; j++){
                 int a=0;
                 a = int(s[j] - A);
               freq[j] -= a;
            }
          
        }
        
        string ans {""};
        for(int i = 0 ; i < M ; i++){
            int a = freq[i];
            char c = a + 'a';
            ans = ans + c;
        }
      
 
 
        // string ans ={""};
        // for(int i = 0 ; i < N ; i++){
        //     // long long  temp[27] = {0};
        //     // string s = vec[i];
        //     // for(int j  = 0 ; j < M ; j++){
        //     //      int a=0;
        //     //      a = int(s[j] - A);
        //     //     temp[a]+=1;
        //     // }
        //     // bool c = true;
        //     // for(int k = 0 ; k < 27 ; k++){
        //     //     if(freq[k] != temp[k]){
        //     //         c=false;
        //     //         break;
        //     //     }
        //     // }
 
        //     // if( c == true){
        //     //     ans = s;
        //     //     break;
        //     // }
            
 
        // }
 
        cout<<ans<<endl;
        // fflush(stdout);
 
    }
 
}