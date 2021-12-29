#include<bits/stdc++.h>
using namespace std;
#define ll long long 
// #define modVal 10e9+7
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
long long const modVal = 1000000007;

ll exp(ll m , ll n){    //m^n

    ll number = m ;
    ll power = n ;
    ll answer = 1;
    while( power > 0){
        if((power & 1 ) > 0){
            answer *= number ;
            answer%=modVal;
        } 
        //square the number 
        number*=number;
        number%=modVal;
        //right shift power
        power = power>>1;
    }
    return answer;
}


int main(){
    
   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r" , stdin);
        freopen("../output.txt", "w", stdout);
    #endif
   
    long long T= 0 ;
    cin>>T;

    while(T--){
        ll N = 0 ;cin>>N;
        char c ;cin>>c;
        string s;
        cin>>s;
        vector<bool>check(N+1,false);
        vector<int> indexes;

        for(int i =0;i<N ;i++){
            if(s[i]!=c){
                check[i+1]=true;
                indexes.push_back(i+1);
            }
        }

        if(indexes.size() == 0){
            cout<<0<<"\n";
            continue;
        }
        int count =indexes.size()-1;
     int ans=-1;
        for(int i =1 ;i<=N;i++){

            int X=i;
            if(check[i] == true){
                continue;
            }
            int c2 =0;
            while(X<=N){
                if(check[X]==true){
                    c2++;
                    break;
                }
                X+=i;
            }
            if(c2==0){
                ans=i;
                break;
            }
        }
        if(ans !=-1){
            cout<<1<<"\n";
            cout<<ans<<"\n";
        }else{
            cout<<2<<"\n";
            cout<<N<<" "<<N-1<<"\n";
        }

    //     bool allEven = true;
    //     bool allOdd = true;
    //     for(int i =0;i<indexes.size();i++){
    //         if(indexes[i]%2==0){
    //             allEven=false;
    //         }else{
    //             allOdd=false;
    //         }
    //     }

        

    //     if(indexes.size() > 1){
            
           

    //         if(indexes[indexes.size()-1]!=N){
    //             cout<<1<<"\n";
    //             cout<<N<<"\n";
    //             continue;
    //         }else{
    //             cout<<2<<"\n";
    //         cout<<indexes[indexes.size()-1]<<" ";
    //          for(int i =1 ;i<=N;i++){
    //             if(indexes[0]%i!=0){
    //                 cout<<i<<"\n";
    //                 break;
    //             }
    //         }
    //         }

            

    //     }else{
    //         cout<<1<<"\n";
    //         for(int i =1 ;i<=N;i++){
    //             if(indexes[0]%i!=0){
    //                 cout<<i<<"\n";
    //                 break;
    //             }
    //         }
    //     }


    }


}