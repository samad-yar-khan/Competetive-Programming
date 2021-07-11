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
        int n = 0;
        cin>>n ;
        int array[301] = {0};
        bool check[200]  = {false};
        for(int i = 0 ; i < n ; i++){
            cin>>array[i];
        }
        
        sort(array , array + n);
        if(array[0] < 0 ){
            cout<<"NO\n";
        }else{
           cout<<"YES\n";
           

           for(int i = 0 ; i < n ; i++){
               check[array[i]] = true;
           }

           for(int i = 0 ; i < n ; i++){
               for(int j = 0 ; j < n ; j++){
                   
                   int num = abs(array[j] - array[i]);
                   if(i!=j && !check[num]){
                       array[n++] = num;
                       check[num] = true;
                   }
               }
           }

           cout<<n<<"\n";

            for(int i = 0 ; i < n ; i++){
               cout<<array[i]<<" ";
           }
           cout<<'\n';
           

        }



    }

}