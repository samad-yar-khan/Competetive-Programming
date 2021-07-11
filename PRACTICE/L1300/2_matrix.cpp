#include <bits/stdc++.h>
using namespace std;
#define modVal 1000000007
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
 
    cin.tie(NULL);
 
    int arr[5][5] = {0};

    int x = 0 ;
    int y= 0;
    for(int i =  0 ; i < 5 ; i++){
        for(int j = 0 ; j < 5 ; j++){
            cin>>arr[i][j];
            if(arr[i][j]==1){
                x = i ;
                y = j;
            }
        }
    }

    cout<<abs(x-2)+abs(y-2)<<"\n";



}