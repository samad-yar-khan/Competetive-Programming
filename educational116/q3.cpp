#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
 
ull exp(ull m , ull n){    //m^n

    ull number = m ;
    ull power = n ;
    ull answer = 1;
    while( power > 0){
        if((power & 1 ) > 0){
            answer *= number ;
         
        } 
        //square the number 
        number*=number;
      
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
    
    int T= 0 ;
    cin>>T;

    while(T--){ 
        ull n =0;
        ull k =0;
        cin>>n>>k;
    
        vector<int> d;
    
        for(int i =0; i < n ; i++){
            int a = 0 ;cin>>a;
            d.push_back(a);
        }    
        if( k < 9){
            cout<<++k<<"\n";continue;
        }
        
        ull ans = 0;
        
        k++;
        int i  =0;
        while(i < d.size() && k > 0){
            
            if(i == d.size() - 1){
                ull t = k*(exp(10, d[i]));
                k=0;
                ans += t;
            }else{

                ull CanUse = exp(10 ,d[i+1]-d[i])-1;
                if(k < CanUse){
                    ans+=(exp(10 , d[i])*k);
                    k=0;
                }else{
                    k-=CanUse;
                    ans+=(exp(10 , d[i])*CanUse);
                }

            }
            i++;
        }
        cout<<ans<<"\n";

    }
}