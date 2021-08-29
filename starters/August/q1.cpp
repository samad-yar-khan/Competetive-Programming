#include <bits/stdc++.h>
using namespace std;
#define modVal 1000000007
#define ll long long


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r" , stdin);
        freopen("output.txt", "w", stdout);
    #endif
    

    int T= 0 ;
    cin>>T;
    for(int i = 1 ; i <= T ; i++){

        int n= 0 ;
        int k = 0;
        int arr[100000] ={0};

        cin>>n>>k;
        for(int j = 0 ; j <n ; j++){
            cin>>arr[j];
        }

        sort(arr , arr+n);  
        ll s1 =0;
        for(int i = 0 ; i < n && i < k && arr[i]<0 ; i++  ){
            arr[i]=(-1*(arr[i]));

        }
        sort(arr , arr+n);  

        int c = 0 ;
        for(int i = n-1 ; i >=0 && arr[i]>0 ; i--  ){
            s1+=(arr[i]);
        }
        cout<<s1<<"\n";
    }




}

