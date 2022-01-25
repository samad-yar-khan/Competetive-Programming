#include<bits/stdc++.h>
using namespace std;
#define ll long long 
// #define modVal 10e9+7
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
long long const modVal = 1000000007;

int binarySearch(vector<ll> vec,ll si , ll ei ,  ll t){

    while(si<=ei){

        ll mid = (si+ei)/2;
        if(vec[mid] == t){
            return mid;
        }else{
            if(vec[mid] > t){
                ei=mid-1;
            }else
            {
                si=mid+1;
            }
        }

    }

    return -1;

}

int power( int n , int k){

    int a = n;
    int ans = 1;
    while(k>0){
        if(k&1 == 1){
            ans*=a;
        }
        k=k>>1;
        a=a*a;
    }

    return ans;

}

int KthRoot(int n , int k){
    int si = 1;
    int ei = n;
    int ans = 0;
    while(si<=ei){
        int mid = si+ ((ei-si)/2);
      
        int value = power(mid , k);
        if(value <= 0){
            ei=mid-1;
            continue;
        }
        if( value == n){
            return mid;
        }

        if(value<=n ){
            si=mid+1;
            ans=max(mid,ans);
        }else{
            ei=mid-1;
        }
    }
    return ans;
}


void makeSeive(vector<bool>&seive , int range , vector<int>& primes ){

    seive[0] = 0 ;//np
    seive[1] = 0 ;//np
    seive[2] = 1 ;//pr

    for(long long i=2 ; i <= range ; i++){
        if(seive[i]){
            primes.push_back(i);
            for(long long j = i*i ; j <= range ; j+=i){
                seive.at(j)=false;
            }
        }
    }
}

ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

ll sd(ll n){
    ll a=0;
    while (n>0)
    {
        a+=(n%10);
        n/=10;
    }
    
    return a;
}

pair<int,int> maxMUX(vector<int>&  vec,int si , int ei,vector<int>&maxDp){
    if(si==ei){
        for(int i =0;i<=vec[ei];i++){
            if(i<vec[ei]){
                return make_pair(i,ei+1);
            }
        }
    }
    int m =maxDp[si];
   

    vector<int>vis(m+2,0);
    int cm=0;
    int maxMux=0;
    int mmi=0;
    for(int  i=si;i<=ei;i++){
        if(vec[i]==cm){
            vis[cm]=1;
           while(cm<=m+1 && vis[cm]==1){
               cm++;
           }
        }
        vis[vec[i]]=1;
        if(cm>maxMux){
            maxMux=cm;
            mmi=i;
            if(maxMux>=m){
                break;
            }
        }
        
      
    }

    return make_pair(maxMux,mmi);
}



int main(){
     
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r" , stdin);
        freopen("../output.txt", "w", stdout);
    #endif

    int T=0;cin>>T;

   
    while(T--){

        int n =0;cin>>n;
        vector<int>arr(n,0);
        int maxVal=0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            maxVal = max(maxVal,arr[i]);
        }
      
        vector<int>vis(maxVal+2,0);
        int cm=0;
        int maxMux=0;
        vector<int>muxx(n,0);
        int mmi=0;
        vector<int>maxx(n,0);
        int maxV=0;
        for(int  i=n-1;i>=0;i--){
            if(arr[i]==cm){
                vis[cm]=1;
            while(cm<=maxVal+1 && vis[cm]==1){
                cm++;
            }
            }
            vis[arr[i]]=1;
            if(cm>maxMux){
                maxMux=cm;
                mmi=i;
            }
            if(arr[i]>maxV){
                maxV=arr[i];
            }

            maxx[i] = maxV;
            muxx[i] = cm;
            
        
        }
        int ind =0;
        vector<int> ans;
        while(ind <n){
            int mms = muxx[ind];
            vector<int>vis(maxx[ind]+2,0);
            int cm=0;

            int j =ind;
            bool f=false;
            while(j<n && cm!=mms){
                if(arr[j]==cm){
                    vis[arr[j]]=1;
                    while(cm<=maxVal+1 && vis[cm]==1){
                        cm++;
                    }
                }
                vis[arr[j]]=1;
                j++;
                if(j>=n || cm==mms){
                    f=true;
                }
            }
            if(!f){
                j++;
            }
            ans.push_back(mms);
            ind =j;
            
        }

        cout<<ans.size()<<"\n";

        for(int i =0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }

        cout<<"\n";
    }
}