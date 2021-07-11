#include <bits/stdc++.h>
using namespace std;
#define modVal 1000000007
#define ll long long
#define MAXN   1000000000


ll GCD(ll A, ll B)
{
    if (B == 0){
        return A;
    }
    return GCD(B, A % B);
     
}
  

int main()
{
    ios_base::sync_with_stdio(false);
 
    cin.tie(NULL);
 

    int T{0};
    cin>>T;
    while(T){

    

        ll a= 0 , b = 0 , k = 0 ;
        cin>>a>>b>>k;

        ll A = max(a,b);
        ll B = min(a,b);
        ll G = GCD(A,B);

        ll pfA = 


        T--;
    }

}