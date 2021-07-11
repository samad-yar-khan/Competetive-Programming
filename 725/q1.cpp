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
       
           
        int n = 0 ;
        int arr[101] = {};
        cin>>n ;
        for(int i = 0 ; i < n ; i++)
        {
            cin>>arr[i];    
        }

        int m = INT_MAX , M = INT_MIN;
        int mi = -1 , Mi = -1;
        
        for(int i = 0 ; i < n ; i++){
            if(m > arr[i]){
                m = arr[i];
                mi = i;
            }
            if(M < arr[i]){
                M = arr[i];
                Mi = i ;
            }
        }

        int sI = min(mi , Mi);
        int lI = max(mi , Mi);

        int a1 = lI+1 ;
        int a2 = n - sI;
        int a3 = sI+1 + n -lI;

        cout<<min(a1 , min(a2,a3))<<"\n";




    }

}