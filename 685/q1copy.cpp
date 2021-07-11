#include <bits/stdc++.h>
using namespace std;
#define ll long long


void check_sub(string s , int q , int n){

    int Q= q;
    while(Q>0){

        int l{0} , r{0};
        cin>>l>>r;

        --l;//maed them indexes
        --r;
        int starting = l ;
        int ending = r;

        int i = 0;
        bool entered=false;
        bool case1=false  , case2 =false;
        while(i < n && l<=r){

            if(!entered){

                if(s.at(i) == s.at(l) && i!=l){
                    entered=true;
                    l++;
                    i++;
                
                }else{
                    i++;
                }

            }else{
                if(s.at(i) == s.at(l)){
                    i++;
                    l++;
                }else{
                    i++;
                }
            }
        }

        if(l>r){
                case1 = true;
        }
        l=starting;
        i=0;
         while(i < n && l<=r){
            
            if(l==r){//last ellement

                 if(s.at(i) == s.at(l) && i!=r){
                        i++;
                        l++;
                        break;
                 }

            }
            else{
                if(s.at(i) == s.at(l)){
                        i++;
                        l++;
                }else{
                        i++;
                    }
                
             }
        }
         if(l>r){
                case2 = true;
        }

        if(case1 || case2){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
        

        Q--;
    }
    

}

int main()
{
    ios_base::sync_with_stdio(false);
 
    cin.tie(NULL);
 

    int T{0};
    cin>>T;



    while(T>0){

        int n{0} ,  q{0};
        cin>>n>>q;

        string s ;
        cin>>s;
        
        check_sub(s , q , n);
       
        T--;
    }


 
    return 0;
}