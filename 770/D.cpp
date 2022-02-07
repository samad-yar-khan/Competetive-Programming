#include<bits/stdc++.h>
using namespace std;
#define ll long long 
// #define modVal 10e9+7
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
long long const modVal = 1000000007;

// int binarySearch(vector<ll> vec,ll si , ll ei ,  ll t){

//     while(si<=ei){

//         ll mid = (si+ei)/2;
//         if(vec[mid] == t){
//             return mid;
//         }else{
//             if(vec[mid] > t){
//                 ei=mid-1;
//             }else
//             {
//                 si=mid+1;
//             }
//         }

//     }

//     return -1;

// }

// int power( int n , int k){

//     int a = n;
//     int ans = 1;
//     while(k>0){
//         if(k&1 == 1){
//             ans*=a;
//         }
//         k=k>>1;
//         a=a*a;
//     }

//     return ans;

// }

// int KthRoot(int n , int k){
//     int si = 1;
//     int ei = n;
//     int ans = 0;
//     while(si<=ei){
//         int mid = si+ ((ei-si)/2);
      
//         int value = power(mid , k);
//         if(value <= 0){
//             ei=mid-1;
//             continue;
//         }
//         if( value == n){
//             return mid;
//         }

//         if(value<=n ){
//             si=mid+1;
//             ans=max(mid,ans);
//         }else{
//             ei=mid-1;
//         }
//     }
//     return ans;
// }
// void makeSeive(vector<bool>&seive , int range , vector<int>& primes ){

//     seive[0] = 0 ;//np
//     seive[1] = 0 ;//np
//     seive[2] = 1 ;//pr

//     for(long long i=2 ; i <= range ; i++){
//         if(seive[i]){
//             primes.push_back(i);
//             for(long long j = i*i ; j <= range ; j+=i){
//                 seive.at(j)=false;
//             }
//         }
//     }
// }
// ll gcd(ll a, ll b)
// {
//     if (a == 0)
//         return b;
//     return gcd(b % a, a);
// }

// void print(vector<ll>&vec){
//     for(auto i:vec) cout<<i<<" ";
//     cout<<"\n";
// }
// void print(vector<int>&vec){
//     for(auto i:vec) cout<<i<<" ";
//     cout<<"\n";
// }
// void print(vector<string>&vec){
//     for(auto i:vec) cout<<i<<" ";
//     cout<<"\n";
// }
// void print(vector<vector<int>>&vec){
//     for(int i =0;i<vec.size();i++){
//         for(int j =0;j<vec[i].size();j++){
//             cout<<vec[i][j]<<" ";
//         }
//         cout<<"\n";
//     }
// }
void print(vector<vector<int>>&vec){
    for(int i =0;i<vec.size();i++){
        for(int j =0;j<vec[i].size();j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<"\n";
    }
}
// void print(vector<vector<string>>&vec){
//     for(int i =0;i<vec.size();i++){
//         for(int j =0;j<vec[i].size();j++){
//             cout<<vec[i][j]<<" ";
//         }
//         cout<<"\n";
//     }
// }


// bool isPal(string &s){

//     int si=0;int ei=s.length()-1;
//     while(si<ei){
//         if(s[si]!=s[ei]){
//             return false;
//         }
//         si++;ei--;
//     }

//     return true;


// }

ll q(int i , int j , int k){

    cout<<"? "<<i<<" "<<j<<" "<<k<<endl;
    ll res=0;cin>>res;
    return res;

}

int main(){
     
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    fflush(stdout);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r" , stdin);
        freopen("../output.txt", "w", stdout);
    #endif

    int T=0;cin>>T;

   /*
    logic yr tha ki ddo value pakadlo 
    a b , ye make sure karo ki ye dnone max and  min na ho
    iske liye hame do quey lagnege
    1,2,3 and 1,3,4 ,left q chota ho to 2,3 lo otherwoiswe
    3 4 , dono equal hongi to because of 1 and hame 1 ko le hi nahi rahe
    no hame maximum point dekhna hai
    a , b ko number line pe dallo 
    ....a....b....
    jo bhi ayega max quey value, wo ya to 0 se ayegha  ya max se
    ...0...a...b.. -> b-0
    ...a...b...max... -> max -a;
    ab, ek max point to mil gya, ab iska istimal karke dusara max queykaha araha hai iska index nikalo, because 
    dekho max qury min max ke sath se hi ayegi
    to same kam karo but b ki jhagah c se
    agar a already 0 ya max hua, to hart bar same max ayegfa and haare set mai bas
    ek hi value ayegi and set ka size 1 hoga, thats our ans
    otherwise ham d and c ko ans bolenge
    
   */
    while(T--){
        
        int N=0;cin>>N;
        int a=0,b=0,i=0,c=0,d=0;
        ll max1 = INT_MIN;
        ll max2 = INT_MIN;
        if(q(1,2,3)<=q(1,3,4)){
            a=2;
            b=3;
        }else{
            a=3;
            b=4;
        }

        for(int i =1;i<=N;i++){
            if(i==a||i==b){
                continue;
           }
            ll res=q(a,b,i);
            if(res > max1){
                max1=res;
                c=i;
            }  
        }

        set<ll> resVals;
        for(int i = 1;i<=N;i++){
            if(i==a||i==c){
                continue;
            }
            ll res=q(a,c,i);
            if(res > max2){
                max2=res;
                d=i;
            }  
            resVals.insert(res);
        }

        int A=0,B=0;
        if(resVals.size() == 1){
            A=a;
            B=c;
        }else{
            A=c;
            B=d;
        }

        cout<<"! "<<A<<" "<<B<<endl;
 
        
      
    }
}
/*
7 111
2 010

10 1010
12 1100
8 1000

9 1001
5 0101




*/