#include<bits/stdc++.h>
using namespace std;
#define ll long long 
// #define modVal 10e9+7
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
long long const modVal = 1000000007;

ll exp(ll m , ll n){    //m^n

    ll number = m ;
    ll power = n ;
    ll answer = 1;
    while( power > 0){
        if((power & 1 ) > 0){
            answer *= number ;
            answer%=modVal;
        } 
        //square the number 
        number*=number;
        number%=modVal;
        //right shift power
        power = power>>1;
    }
    return answer;
}


int main(){
    
   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r" , stdin);
        freopen("../output.txt", "w", stdout);
    #endif
   
    long long T= 0 ;
    cin>>T;
    
    while(T--){
        
        int n =0;
        cin>>n;
        int a_ =-1;
        bool diff=false;
        vector<pair<int,int>> city;
        vector<int> dis(n+1 , 0);
        vector<pair<int,int>>ans;
        for(int i=0;i<n ;i++){
            cin>>dis[i];
            if(i==0){
                a_=dis[i];
            }else{
                if(a_!=dis[i]){
                    diff=true;
                }
            }
            city.push_back({dis[i],i+1});

        }
        if(!diff){
            cout<<"NO\n";continue;
        
        }
        sort(city.begin(),city.end());

        int i =0;
        int j =0;

        int a =city[0].first;
        int b=0;

        while(i<n && city[i].first==a){
            i++;

        }
        j=i;
        i=0;
        b =city[j].first;
        int k =1;
        while(k<n && city[k].first==a){

            ans.push_back({city[k].second,city[j].second});
            k++;

        }

        while(i<n & j<n){

            int k =j;

            while(k<n && city[k].first==city[j].first){
                ans.push_back(make_pair(city[k].second,city[i].second));
                k++;
            }
            i=j;
            j=k;

        }
        cout<<"YES\n";
        for(int i =0;i<n-1 ;i++){
            cout<<ans[i].first<<" "<<ans[i].second<<"\n";
        }

       
        
    }

    
}