#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define modVal 10e9
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;


 bool comp(pair<int,pair<int,int>>p1 , pair<int,pair<int,int>>p2){

     if(p1.second.first+p1.second.second != p2.second.first+p2.second.second){
         return p1.second.first+p1.second.second >p2.second.first+p2.second.second ;
     }
    return p1.first< p2.first;
 }

int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r" , stdin);
        freopen("../output.txt", "w", stdout);
    #endif
   
    // int T= 0 ;
    // cin>>T;
 
    // while(T--){ 

        int n=0,k=0;cin>>n>>k;
        vector<pair<int,pair<int,int>>>both;
        vector<int> alice;
        vector<int>bob;


        for(int i =0;i<n;i++){
            int time =0,a=0,b=0;
            cin>>time>>a>>b;
            if(a==1 && b==1){
                both.push_back(make_pair(time,make_pair(1,1)));
            }else if( a==0 && b==1 ){
                bob.push_back(time);
            }else if(a==1 && b==0){
                alice.push_back(time);
            }
        }


        sort(alice.begin(),alice.end());
        sort(bob.begin(),bob.end());

        int aa=0;int ak=0;
        int i=0;int j=0;;
        while(i<alice.size()&&j<bob.size()){
            both.push_back(make_pair(alice[i]+bob[j],make_pair(1,1)));
            i++;j++;
        }
        while(i<alice.size()){
            both.push_back(make_pair(alice[i++],make_pair(1,0)));
        }
        while(j<bob.size()){
             both.push_back(make_pair(bob[j++],make_pair(0,1)));
        }

        sort(both.begin(),both.end(),comp);

        int c1 =0,c2=0;
        i=0;
        int t=0;
        while((c1<k || c2<k) && i<both.size()){
            // cout<<both[i].first<<" "<<both[i].second.first<<" "<<both[i].second.second<<"\n";
            if(both[i].second.first){
                c1+=1;
            }
            if(both[i].second.second){
                c2+=1;
            }
            t+=both[i].first;
            i++;
        }
        if(c1 <k || c2<k ){
            cout<<-1<<"\n";
        }else{
            cout<<t<<"\n";
        }

}