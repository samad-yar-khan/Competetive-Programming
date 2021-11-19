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
        
        ll n = 0 ; ll  s = 0 ;
        cin>>n>>s;

        vector<ll> vec;
        vector<ll> sum;
        ll N = n ;
        ll currSum =0;
        while(N>0){
            vec.push_back(N%10);
            N/=10;
        }   
        reverse(vec.begin(),vec.end());
        for(int i =0;i<vec.size();i++){
            currSum+=vec[i];
            sum.push_back(currSum);
        }
        reverse(sum.begin(),sum.end());
        reverse(vec.begin(),vec.end());

        sum.push_back(0);
        vec.push_back(0);
        int i = 0;
        // for(auto s:sum){
        //     cout<<s<<" ";
        // }
        // cout<<"\n";
        //  for(auto s:vec){
        //     cout<<s<<" ";
        // }
        while(sum[i]>s && i<vec.size()){
            sum[i]-=vec[i];
            vec[i]=0;
            ll carry = 1;
            while(carry){
                sum[i+1]=sum[i+1]-vec[i+1];
               vec[i+1]=vec[i+1]+carry;
                carry=vec[i+1]/10;
                vec[i+1]=vec[i+1]%10;
                sum[i+1]=sum[i+1]+vec[i+1];
                sum[i]=sum[i+1];
                i++;
            }
           
        }
        // cout<<"\n";
        // for(auto s:vec){
        //     cout<<s<<" ";
        // }
        //  cout<<"\n";
        reverse(vec.begin(),vec.end());
        ll final=0;
        ll ten =10;
        for(int i=0;i<vec.size();i++){
            final=final*ten + vec[i];
        }
        cout<<final-n<<"\n";



    }
    return 0;
}