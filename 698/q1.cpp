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

        ll n=0;
        cin>>n;
        if(n==1){
            cout<<1<<"\n";
        }else{
            ll max_rep = 1;
            ll reps= 1 ;
            ll prev = 0 ;
            ll curr = 0 ;
            bool repeating = false;
            
            cin>>prev;

            for(int i = 0 ; i < n-1 ; i++)
            {

                cin>>curr;
                if(!repeating){

                    if(curr == prev ){
                        reps++;
                        repeating = true;
                    } 

                    prev = curr;

                }else{

                    if(curr == prev){
                        reps++;
                        prev = curr;
                        
                    }else{
                        max_rep = max(max_rep , reps);
                        prev= curr;
                        reps = 1;
                    }

                }

            }
            if(repeating){
                max_rep=max(max_rep,reps);
            }
            
            cout<<max_rep<<"\n";

        }

        
       T--; 
    }


 
    return 0;
}