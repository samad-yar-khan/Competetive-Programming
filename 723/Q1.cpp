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
    while(T--){

        int n{0};
        ll arr[51];
        cin>>n;

        for(int i = 0 ; i < 2*n ; i++)
        {
            cin>>arr[i];
        }

        sort(arr , arr+2*n);

        int i= 0 , j = (2*n)-1;
        while(i < j){
            cout<<arr[i]<<" ";
            cout<<arr[j]<<" ";
            i++;j--;
        }
        cout<<"\n";
    }

}