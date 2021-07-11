#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
 
    cin.tie(NULL);
 

    int T{1};
    cin>>T;



    while(T>0){
        
        int n{0};
        cin>>n;

        bool fault{false};

        char*str = new char[n+1];
        int CT{0}, CM{0};
        
        for(int i = 0 ; i < n ; i++){
            cin>>str[i];
            if(str[i] == 'T'){
                CT++;
            }else{
                CM++;
            }
        }

        if(CT%2!=0 ||CT/2 != CM){
            cout<<"NO\n";
            T--;
            continue;
        }

        bool f1{false},f2{false};

        int c1=0,c2=0;
        int itr = 0 ;
        while(itr<n){
            
            if(str[itr] == 'T'){
                c1++;
            }else{
                c2++;
            }
            if(c1-c2 < 0){
                f1 = true;
                break;
            }
            itr++;
        }
        itr = n-1;
        c1=0;
        c2=0;
         while(itr>=0){
            
            if(str[itr] == 'T'){
                c1++;
            }else{
                c2++;
            }
            if(c1-c2 < 0){
                f2 = true;
                break;
            }
            itr--;
        }

        if(f1||f2){
            cout<<"NO\n";
        }else{
            cout<<"YES\n";
        }

        delete [] str;
       T--; 
        
    }


 
    return 0;
}