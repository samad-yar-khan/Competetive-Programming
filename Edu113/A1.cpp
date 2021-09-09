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
    while(T--){

        int n = 0 ;
        cin>>n;
        string s{""};
        cin>>s;
        int arr[51] = {0};

        for(int i = 0 ; i < n ; i++){
            if(s[i] == 'a'){
                arr[i] = 1 ;
            }else{
                arr[i] = -1;
            }
        }

        int sum[100] = {0};
        sum[0] = arr[0];
        bool f=false;
        int a = -1 ;
        int b = -1;
        for(int i = 1;i<n ; i++)
        {
            sum[i] = sum[i-1]+arr[i];
            if(sum[i] == 0){
                a = 1 ;
                b = i+1;
                f=true;
                break;
            }
        }
        if(!f){
             for(int i = 0 ; i < n ; i++){
                for(int j = i+1 ; j < n ; j++ ){
                    if(sum[j]-sum[i] == 0){
                        a = i+2 ;
                        b = j+1;
                        f=true;
                    }
                    if(f){
                        break;
                    }
                }
            }

        }
       
        cout<<a<<" "<<b<<"\n";
    }




}

