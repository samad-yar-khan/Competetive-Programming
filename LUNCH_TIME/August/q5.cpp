#include <bits/stdc++.h>
using namespace std;
#define modVal 1000000007
#define ll long long


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE

        freopen("input.txt", "r" , stdin);
        freopen("output.txt", "w", stdout);
    #endif
    

    int T= 0 ;
    cin>>T;
    for(int i = 1 ; i <= T ; i++){

        int n = 0;
        cin>>n;
        int arr[100000] = {0};
        for(int j = 0 ; j < n ; j++){
            cin>>arr[j];
        }

        int x = n-1;
        int ans = 0 ;

        while(x>=0){

            int j = x-1;
            while(j >=0 && arr[x] >= arr[j]){
                j--;
                if(j<0 && arr[j+1] == arr[x]){
                    j=0;
                    break;
                }
            }
            x=j;
            ans++;
            if(x==0){
                break;
            }
        }

        if(x == 0){
            cout<<ans<<"\n";
        }else{
            cout<<-1<<"\n";
        }

    }




}

