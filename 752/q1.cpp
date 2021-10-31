#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define modVal 10e9
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

int AB(string &s){

    int ab=0;
    int n = s.length();
     if(n==1){
        return 0;
    }
    for(int i = 0 ; i < n-1 ; i++){
        if(s[i] == 'a' && s[i+1] =='b'){
            ab++;
        }
    }
    return ab;
}
int BA(string &s){
    
    int ab=0;
    int n = s.length();
    if(n==1){
        return 0;
    }
    for(int i = 0 ; i < n-1 ; i++){
        if(s[i] == 'b' && s[i+1] =='a'){
            ab++;
        }
    }
    return ab;
}

void minWays(string &s){

    int ab = AB(s);
    int ba = BA(s);

    if(ab == ba){
        cout<<s<<"\n";
        return;
    }

    if(ab > ba){
        if(s[0] == 'a'){
            s[0]='b';
        }else if(s[s.length()-1] == 'b'){
            s[0]='a';
        }
    }else{
          if(s[0] == 'b'){
            s[0]='a';
        }else if(s[s.length()-1] == 'a'){
            s[0]='b';
        }
    }
    cout<<s<<"\n";


}



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
        
        int n =0;
        cin>>n;
        vector<int> vec;

        for(int i =0 ; i < n ; i++){
            int a =0;
            cin>>a;
            vec.push_back(a);
        }
        int k =1;
        int ans =0;
        for(int i = 0 ; i < n ; i++){
            if(vec[i]>k){
                int diff = vec[i]-k;
                ans += diff;
                k+=diff;
                k++;
            }else{
                k++;
            }
        }
        cout<<ans<<"\n";


    }
  
 
 
}