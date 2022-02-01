#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define modVal 10e9
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

/*
//gives bit rep
vector<int> getBits(ll n){    
    vector<int> ans(64,0);
    ll n_=n;
    int pos = 0 ;
    while(n_>0){
        if(n_&1){
            ans[pos]++;
        }
        n_=n_>>1;
        pos++;
    }
    return ans;
}

//vector<int> getBits(int n){    
ll getNumFromBits(vector<int>& bits){
    int curr = 1;
    ll ans=0;
    for(int i =0;i<32;i++){
        if(bits[i]){
            ans+=(curr);
        }
        curr = curr<<1;
    }
    return ans;
}


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

*/


//logic -we have to deal with the last subsequnces made edning with 0 or 1 and formulate our answer=
int main(){
     
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r" , stdin);
        freopen("../output.txt", "w", stdout);
    #endif

    int T=0;cin>>T;
    while(T--){
        
        int n=0;cin>>n;
        string  s; cin>>s;
        vector<int> pos(n,0);
        int segmentsMade = 0 ;
        stack<int>end0;
        stack<int>end1; 
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                if(end1.size()!=0){
                    pos[i]=end1.top();
                    end0.push(end1.top());
                    end1.pop();
                }else{
                    segmentsMade+=1;
                    pos[i]=segmentsMade;
                    end0.push(segmentsMade);
                }
            }else{
                if(end0.size() != 0){
                    pos[i] = end0.top();
                    end1.push(end0.top());
                    end0.pop();
                }else{
                    segmentsMade+=1;
                    pos[i]=segmentsMade;
                    end1.push(segmentsMade);
                }
            }
        }
        cout<<segmentsMade<<"\n";
        for(int i =0;i<n;i++){
            cout<<pos[i]<<" ";
        }
        cout<<'\n';
    }
}