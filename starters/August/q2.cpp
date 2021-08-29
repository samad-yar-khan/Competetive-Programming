#include <bits/stdc++.h>
using namespace std;
#define modVal 1000000007
#define ll long long int


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
        int A[100000];
        int B[100000];
        
        ll s1 =0;
        for(int i = 0 ; i <  n; i++){
            cin>>A[i];
            // s1+=A[i];
        }
        ll s2 = 0;
        for(int i = 0 ; i <  n-1; i++){
            cin>>B[i];
            // s2+=B[i];
        }

        sort(A, A+n);
        sort(B ,B+n-1);

        unordered_map<int , int> m;

        for(int i = 0 ; i < n-1; i++){

            int x = - 1 , y = -1 , z= -1;

            if(i>0){
                x = B[i]-A[i-1];
            }
            y = B[i] - A[i];
            z=B[i]-A[i+1];

            if(x >0)
            {
                m[x]+=1;
            }
            if(y >0){
                m[y]+=1;
            }

            if(z>0){
                m[z]+=1;
            }
        }

        int maxF = -1;
        int ans =0;
        for(auto itr = m.begin() ; itr!= m.end() ; itr++){
            if(itr->second  > maxF ){
                ans = itr->first; 
                maxF = itr->second;
            }else if(itr->second == maxF){
                int t = itr->first;
                ans = min(t , ans);
            }
        }

        cout<<ans<<"\n";

    }

}

