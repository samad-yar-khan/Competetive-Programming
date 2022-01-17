#include <bits/stdc++.h>
using namespace std;
#define modVal 1000000007
#define numMax 1000000001
#define ll long long


ll power(ll x, ll y)
{
    ll temp;
    if(y == 0)
        return 1;
    temp = power(x, y / 2);
    if (y % 2 == 0)
        return temp * temp;
    else
    {
        if(y > 0)
            return x * temp * temp;
        else
            return (temp * temp) / x;
    }
}

void fillVec (ll num1 , ll r1 , ll num2 , ll r2 , vector<ll>& v){
    for(int i = 1 ; i < r1 ; i++){
        for(int j = 1 ; j < r2 ; j++){
            ll s = power(num1 , i) + power(num2 , j);
            if( s > numMax){
                break;
            }
            v.push_back(s);
        }
    }
}



ll SpecialNumbers(ll number ,ll inrease_cost,ll dc){

    vector <ll> v;

    ll t = 3;
    ll f = 5;
    ll s = 7;

    fillVec(3 , 18 , 5 , 13 , v);
    fillVec(3 , 18 , 7 , 11 , v);    
    fillVec(7 , 11 , 5 , 13 , v);

    sort(v.begin() , v.end());

    
    ll ub=0, lb=0;
    for(int i = 0 ; i < v.size() ; i++){
        if(number == v.at(i)){ 
            return 0;
        }   
        if(number < v.at(i)){
            ub = v.at(i);
            if(i-1>0){
                lb = v.at(i-1);
            }else{
                lb = 0;
            }  
            break;
        }
    }

 
    ll c1 = inrease_cost*(ub-number);
    if(lb == 0){
        return c1;
    }
    ll c2 = dc*(number-lb);
    return min(c1,c2);

}

int main()
{
    ios_base::sync_with_stdio(false);
 
    cin.tie(NULL);
    
    int T{0};
    cin>>T;
    while(T--){
      
      ll number{0} , inrease_cost{0} , dicease_cost{0};

    cin>>number>>inrease_cost>>dicease_cost;

        cout<<SpecialNumbers(number , inrease_cost , dicease_cost)<<"\n";

    }

}