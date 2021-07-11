#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll moving(ll pos , ll step , ll des , ll maxp){

    if(pos == des){
        return  step - 1;
    }

    if(pos > des){
        return step - 1 + des- pos;
    }

    if(step > maxp)
    {
        return maxp;
    }

    //
    ll so1 = moving(pos+step , step+1,des,maxp);
    ll so2 = moving(pos-1 , step+1 ,des , maxp );
    
    //is
    return min(so1 , so2);


}

void solution(ll n){

    ll p = 0 ;
    ll i = 1 ;
    while(p < n){
        p+=i;
        i++;
    }

    if(n-p == 0){
        cout<<i-1<<"\n";
        return;
    }
    ll maxp = n-p + i-1;

    ll ans = moving(0 ,1 ,n, maxp);
    
    cout<<ans<<"\n";
}



int main()
{
    ios_base::sync_with_stdio(false);
 
    cin.tie(NULL);
 

    int T{0};
    cin>>T;



    while(T>0){

        ll n{0};

        cin>>n;
        
        solution(n);
       T--; 
    }


 
    return 0;
}