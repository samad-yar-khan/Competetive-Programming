#include<bits/stdc++.h>
#define ll long long int
using namespace std;



int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r" , stdin);
        freopen("../output.txt", "w", stdout);
    #endif


    int T =0;
    cin>>T;
    while(T--){
        ll a =0,b =0 , x=0,y=0,n=0;
        cin>>a>>b>>x>>y>>n;
        ll A=b;
        ll B=a;
        ll X=y;
        ll Y=x;
        ll N=n;

        //what we can do , is that we can either 
        //take the smaller numvber , drop it to its smalleer value , then drop the larget number to smaller valiue and get a ans
        //or we can choose the largeer numbe r, drop to its smalker value and gets the ans 
        //so in case 1 , we tak a, drop it to x , the drop b to y
        //then in case 2, a and b are swapped , so we drop b to y , then a to x and get the value
        //the ans can be only either of those two values
        
      
            //case1
            ll subMax = a-x;
            if(n<subMax){
                a-=n;
                n-=n;
            }else{
                a=x;
                n-=subMax;
                
                ll subB=b-y;
                if(n<subB){
                    b-=n;
                    n-=n;

                }else{
                    b-=subB;
                    n-=subB;
                }

            } 

     

           //case2
             subMax = A-X;
            if(N<subMax){
                A-=N;
                N-=N;
            }else{
                A=X;
                N-=subMax;
                
                ll subB=B-Y;
                if(N<subB){
                    B-=N;
                    N-=N;

                }else{
                    B-=subB;
                    N-=subB;
                }

            } 
        

        cout<<min(a*b,A*B)<<"\n";
        

    }
    return 0;
}