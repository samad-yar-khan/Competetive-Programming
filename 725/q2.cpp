#include <bits/stdc++.h>
using namespace std;
#define modVal 1000000007
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
 
    cin.tie(NULL);
 

    int T{0};
    cin>>T;
    while(T){
       
           
        ll n = 0 ;
        cin>>n ;
        int *arr = new int[n];
        ll s = 0;
        for(int i = 0; i < n ;   i++){
            cin>>arr[i];
            s+=arr[i];
        }

        if(s%n != 0){
            cout<<-1<<"\n";
            T--;
            continue;
        }

    
        sort(arr , arr+n);
        ll fd = s/n;
        int a = n ;
        for(int i = 0 ; i < n ; i++){
            if(arr[i]>fd){
                a = i ;
                break;
            }
        }
       
        cout<<n-a<<"\n";
        T--;
    }

}