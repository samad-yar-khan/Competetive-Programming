#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
 
    cin.tie(NULL);
 

    int T{1};
    cin>>T;
    while(T--){

        int n{0} ;
        cin>>n;
        int arr[101];
        int freq[101]{0};
        int min_num=INT_MAX;
        for(int i = 0 ; i < n ; i++){
            cin>>arr[i];
            min_num = min(min_num,arr[i]);
            freq[arr[i]]++;
        }

        int ans{0};

        for(int i = min_num+1 ; i < 101 ; i++ ){
            ans+=freq[i];
        }

        cout<<ans<<"\n";

    }

}