#include <bits/stdc++.h>
using namespace std;
#define modVal 1000000007
#define ll unsigned long long


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r" , stdin);
        freopen("output.txt", "w", stdout);
    #endif
    

    int T= 0 ;
    cin>>T;
    for(int i = 1 ; i <= T ; i++){

        int n = 0 ;
        cin>>n;
        ll Zero = 0;
        ll*A = new ll[n]{Zero};
        ll*B = new ll[n]{Zero};

        for(int i =  0 ;i <n ; i++){
            cin>>A[i];
        }
        for(int i = 0 ; i < n ; i++){
            cin>>B[i];
        }
        Zero=~Zero;

        int vals [32] = {0};

        for(int i  = 0  ; i< n ; i++){

            int c = 0 ;
            ll one = 1 ;
            ll x = A[i];

            while(x>0){
                if(x&one == one){
                    vals[c]++;
                }
                c++;
                x=x>>one;
            }
            c=0;
            x=B[i];
            while(x>0){
                if(x&one == one){
                    vals[c]++;
                }
                c++;
                x=x>>one;
            }
        }
        
        int f =0;
        int AAns[100000] = {0};
        for(int i  = 0  ; i< n ; i++){

            ll a=A[i];
            ll b=B[i];

            int AVals[32] = {0};
            ll one = 1 ;
            int c =0;
            while(a>0){
                if(a&one == one){
                    AVals[c]++;
                }
                c++;
                a=a>>1;
            }


            int BVals[32] = {0};
            
             c =0;
            while(b>0){
                if(b&one == one){
                    BVals[c]++;
                }
                c++;
                b=b>>1;
            }      

            int pa =0;
            int pb=0;

            int TempVal[32]={0};

            for(int j =0;j<32 ; j++){
                TempVal[j] = vals[j]-AVals[j]-BVals[j];
            }
            for(int i = 0 ;  i  < 10 ; i++){
            // cout<<TempVal[i]<<" ";;
            }


            for(int j = 0 ;j < 32 ; j++){
                if(AVals[j] == 1){
                    pa+=TempVal[j];
                }
                if(BVals[j] == 1){
                    pb+=TempVal[j];
                }
            }

            if(pa>pb){
                for(int j = 0 ;j < 32 ; j++){
                   vals[j] -= BVals[j];
                 }

            }else if(pa<pb){
                 for(int j = 0 ;j < 32 ; j++){
                   vals[j] -= AVals[j];
                 }
                 AAns[i] = 1;
                 f++;
            }else if(pa == pb){
                if(A[i] > B[i]){
                    for(int j = 0 ;j < 32 ; j++){
                   vals[j] -= BVals[j];
                   
                 }
                }else{
                    for(int j = 0 ;j < 32 ; j++){
                        vals[j] -= AVals[j];
                    }
                    f++;
                     AAns[i] = 1;
                }
            }
          
        }

        
        ll ans = A[0];
        if(AAns[0]==1){
            ans =B[0];
        }
        ll on = 1;
        for(int  i =1 ; i <n ; i++){
            if(AAns[i]==0){
                ans = (ans&A[i]);
            }else{
                ans =(ans&B[i]);
            }
        }
        for(int i = 0 ; i < n ; i++)
        {
            if(AAns[i] == 1){
                ll temp = ans;
                temp = temp&A[i];
                if(ans == temp){
                    f--;
                }

            }
        }
        cout<<ans<<" "<<f<<"\n";
        delete [] B;
        delete [] A;
    }




}

