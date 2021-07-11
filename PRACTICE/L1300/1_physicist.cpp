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
    int x = 0 , y=0 , z=0  ;

    while(T--){
        int xi=0 , yi=0 , zi=0;
        cin>>xi>>yi>>zi;
        x+=xi;
        y+=yi;
        z+=yi;

    }
    if(x==0 && y==0 &&z==0){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
    }

}