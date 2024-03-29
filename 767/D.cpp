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

// ll sd(ll n){
//     ll a=0;
//     while (n>0)
//     {
//         a+=(n%10);
//         n/=10;
//     }
    
//     return a;
// }


bool isPalindrome(string &a ){

    int i =0;
    int j =a.length()-1;

    while(i<=j){
        if(a[i]!=a[j]){
            return false;
        }
        i++;j--;
    }

    return true;
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
        vector<string> scenes(n+1);
        unordered_map<string,int>maps;
         unordered_map<string,int>len2;
        bool won =false;

        for(int i=0;i<n;i++){
            string a;cin>>a;
            scenes[i] =a;
            if(isPalindrome(a)){
                won = true;
            }
            reverse(a.begin(),a.end());
            // cout<<a<<"\n";
            if(maps.count(a)==0){
                maps.insert(make_pair(a,i));
            }else{
                maps[a] =i;
            }

            if(a.length() == 2){
                if(len2.count(a)==0){
                    len2.insert(make_pair(a,i));
                }else{
                    len2[a] =i;
                }
            }
           
            if(a.length()==3){
                if(maps.count(a.substr(0,2))==0){
                    maps.insert(make_pair(a.substr(0,2),i));
                }else{
                    maps[a.substr(0,2)] = i;
                }
            }
        }   

        if(won){
            cout<<"YES\n";continue;
        }

        // for(auto i =maps.begin();i!=maps.end();i++){
        //     cout<<i->first<<" "<<i->second<<"\n";
        // }
        for(int i =0;i<n;i++){
            if(maps.count(scenes[i]) == 1 && maps[scenes[i]] > i){
                won = true;
                break;
            }
            if(scenes[i].length()==3 && len2.count(scenes[i].substr(0,2)) == 1 && len2[scenes[i].substr(0,2)] > i){
                won = true;
                break;
            }
        }

        if(won){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }

      
    }
}


/*
YES
NO
NO
YES
NO
YES
YES
NO
YES
YES
YES
NO
NO
YES
NO
YES
YES
NO
YES
NO
YES
NO
NO
YES
YES
NO
YES
NO
NO
NO
NO
YES
YES
YES
NO
NO
YES
YES
YES
YES
NO
NO
YES
NO
NO
NO
NO
YES
YES
YES
NO
NO
YES
NO
YES
NO
YES
YES
YES
NO
YES
NO
NO
YES
NO
YES
YES
NO
NO
YES
NO
YES
NO
YES
NO
NO
NO
NO
NO
NO
YES
YES
NO
YES
YES
NO
NO
YES
NO
YES
YES
YES
NO
NO
NO
YES
NO
NO
NO
YES
*/