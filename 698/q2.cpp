#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
 
    cin.tie(NULL);
 

    int T{1};
    cin>>T;



    while(T>0){

        ll q = 0 ;
        int d = 0;

        cin>>q>>d;

        for(ll i = 0 ; i < q ; i ++ ){

            ll x = 0 ;
            cin >> x;

            
            int temp= 0 ;
            ll x2 = x;

            int i = 0 ;
            while(x2!=0){

                ll r = x2%10;
                if(r==d){
                    cout<<"YES\n";
                    break;
                }
                x2/=10;
                i++;

            }




        }




    }


 
    return 0;
}