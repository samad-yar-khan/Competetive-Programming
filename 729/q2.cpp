#include <bits/stdc++.h>
using namespace std;
#define modVal 1000000007
#define ll long long


bool solve(ll n , ll a , ll b ){
    
    if( a == 1){
        int A = n - 1;
        if(A%b == 0){
            return true;
        }else{
            return false;
        }
    }

    if(b == 1){
        return true;
    }
    if(n == 1){
        return true;
    }
    
    ll N = n;
    ll A = 1;
    while(A <= N){
    
        ll n2 = N-A;

        if(n2%b == 0){      
            return true;
        }
        A*=a;
    }
    return false;

}

int main()
{
    ios_base::sync_with_stdio(false);
 
    cin.tie(NULL);
 

    ll T{0};
    cin>>T;

    while(T--){
        
        ll a = 0 , b = 0 , n = 0 ;
        cin>>n>>a>>b;

       
        
             if(solve(n,a,b)){
            cout<<"Yes\n";
            }else{
                cout<<"No\n";
            }
        
       
    }

}