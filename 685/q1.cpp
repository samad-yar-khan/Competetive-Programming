#include <bits/stdc++.h>
using namespace std;
#define ll long long

// int solution(int n , int arr[]){

//     //base
//     if(n==1 ){
//         return 0;
//     }

//     if(arr[n] != -1){
//         return arr[n];
//     }

//     //IH
//    int x= n-1;

//     int ans = INT_MAX;
//     while(n%x != 0 && x > 1){
        
//     }

//     int ans = INT_MAX;
//     if(x == 1){
//        ans =  solution(n-1 , arr) + 1;
//     }else{
//       int so1 = solution(n/x , arr) + 1;
//     int so2 = solution(n-1 ,arr )+1;

//     ans = min(so1 , so2);

//     }

//     arr[n] = ans;
//     return arr[n];


// }

// int main()
// {
//     ios_base::sync_with_stdio(false);
 
//     cin.tie(NULL);
 

//     int T{0};
//     cin>>T;



//     while(T>0){

//         ll n{0};
//         cin>>n;
//         int *arr = new int[n+1];
//         for(int i = 0 ; i <= n ; i++ ){
//             arr[i] = -1;
//         }

//         int ans = solution(n , arr);

//         cout<<ans<<endl;
//         delete [] arr;
//         T--;
//     }


 
//     return 0;
// }

int main()
{
    ios_base::sync_with_stdio(false);
 
    cin.tie(NULL);
 

    int T{0};
    cin>>T;



    while(T>0){

        ll n{0};
        cin>>n;
        if(n==1){
            cout<<0<<"\n";
        }else if(n==2){
            cout<<1<<"\n";
        }
        else if(n%2 == 0 ||  n==3){
            cout<<2<<"\n";
        }else{
            cout<<3<<"\n";
        }
        T--;
    }


 
    return 0;
}