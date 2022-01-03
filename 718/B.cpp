#include<bits/stdc++.h>
using namespace std;
#define ll long long 
// #define modVal 10e9+7
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
long long const modVal = 1000000007;


class comp{
    public:
    bool operator()(pair<int,pair<int,int>>p1,pair<int,pair<int,int>>p2){
        return p1.first>p2.first;
    }
};

int main(){
    
   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r" , stdin);
        freopen("../output.txt", "w", stdout);
    #endif
   
    int T =0;cin>>T;
    vector<vector<int>>p(101,vector<int>(101,0));
    while(T--){
        int n =0;int m =0;
        cin>>n>>m;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,comp>pq;
        for(int i =0;i<n ;i++){
            for(int j =0;j<m ;j++){
                cin>>p[i][j];
                pq.push(make_pair(p[i][j],make_pair(i,j)));
            }
        }

        vector<pair<int,pair<int,int>>>vec;
        int k =0;
        while(k<m){
            k++;
            vec.push_back(pq.top());pq.pop();
        }
        queue<pair<int,int>>qqq;
        vector<queue<pair<int,int>>>qq(m,qqq);

        vector<int>f(m,0);
        for(int i =0;i<m;i++){
            f[vec[i].second.second]++;
            qq[vec[i].second.second].push(vec[i].second);
        }
        vector<pair<int,int>>vv;
        for(int i =0;i<m ;i++){
            vv.push_back(make_pair(f[i],i));
        }
        sort(vv.begin(),vv.end());
        int si=0,ei=m-1;
        
        while(si<ei){
        
            if(vv[si].first>=1){
                si++;continue;
            }
              
           if(vv[si].first==0){       
               int col1=vv[ei].second;
               int col2=vv[si].second;
                 pair<int,int> cor = qq[col1].front();
                        qq[col1].pop();
                        swap(p[cor.first][cor.second],p[cor.first][col2]);
                        f[col2]++;f[col1]--;
                        vv[ei].first--;
                        vv[si].first++;
                        si++;
           }
           if(vv[ei].first==1){
               ei--;
           }
        }       
         for(int i =0;i<n ;i++){
            for(int j =0;j<m ;j++){
                cout<<p[i][j]<<" ";
            }
            cout<<"\n";
        }
    }    
}