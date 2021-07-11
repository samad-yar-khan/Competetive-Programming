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

        ll n {0} , k{0};
        cin>>n>>k;

        ll m = 0 ;
        ll temp =0;
        temp = k ;
        if(n>k){

            m = n/k;
            if(n%k != 0){
                m++;
            }

            temp = k*m;
        }

        ll answer = temp/n;

        if(temp%n!=0){
            answer++;
        }

        cout<<answer<<"\n";

       T--; 
    }


 
    return 0;
}