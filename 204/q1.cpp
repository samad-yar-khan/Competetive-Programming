#include<bits/stdc++.h>
#define ll long long
using namespace std;



int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r" , stdin);
        freopen("../output.txt", "w", stdout);
    #endif



    

      
        int n = 0 ;
        int count5 = 0;
        int count0 = 0 ;
        cin>>n;
        for(int i =0;i<n ; i++){
            int a =0;
            cin>>a;
            if(a==5){
               count5++; 
            }else{
                count0++;
            }
        }

        if(count0 ==0){
            cout<<-1<<"\n";
        }else if (count5 < 9){
            cout<<0<<"\n";
        }else{
            count5 = count5 - (count5%9);
            while(count5--){
                cout<<5;
            }
            while(count0--){
                cout<<0;
            }
            cout<<"\n";
        }




    return 0;
   


}