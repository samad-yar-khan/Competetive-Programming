#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define modVal 10e9
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

int AB(string &s , string &s2){

    unordered_map<char , int> m;

    if(s2.length() == 1){
        return 0;
    }   
    int ans =0;
    for(int i = 0 ; i < s.length() ;i++ ){
       m.insert(make_pair(s[i],i));
    }
    for(int i = 0 ; i < s2.length()-1 ;i++ ){
        ans+=abs(m[s2[i]]-m[s2[i+1]]);
    }
    return ans;

}



int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r" , stdin);
        freopen("../output.txt", "w", stdout);
    #endif
   
    int T= 0 ;
    cin>>T;
    int arr[1001];
    while(T--){ 
        int n =0;
        cin>>n;
       string s ;
       cin>>s;
       queue<int>ones;
        queue<int>zero;
        for(int i =0;i<n;i++){
            if(s[i] == '1'){
                ones.push(i+1);
            }
        }
        for(int i =s.length()-1;i>=0;i--){
            if(s[i] == '0'){
                zero.push(i+1);
            }
        }
        vector<int>v1;
        vector<int>v2;
        while(ones.size() >0 && zero.size()>0 &&ones.front() < zero.front()){
            v1.push_back(ones.front());ones.pop();
            v2.push_back(zero.front());zero.pop();
        }

        if(v1.size()==0){
            cout<<0<<"\n";
        }else{
            cout<<1<<"\n";
            cout<<v1.size()+v2.size()<<" ";
            for(auto i : v1 ){
                cout<<i<<" ";
            }
            reverse(v2.begin(),v2.end());
              for(auto i : v2 ){
                cout<<i<<" ";
            }cout<<"\n";
        } 


    }
   
}