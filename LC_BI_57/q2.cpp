#include <bits/stdc++.h>
using namespace std;
#define modVal 1000000007
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
 
    cin.tie(NULL);
 

    ll T{0};
    cin>>T;
    while(T > 0){
        
        int size_arr = 0 ;
        cin>>size_arr;

        int a[101] = {0} ;
        int b[101] = {0};

        int s = 0 ;
        
        for(int i = 0 ; i < size_arr ; i++){
            cin>>a[i];
            s+=a[i];
        }

        for(int i = 0 ; i < size_arr ; i++){
            cin>>b[i];
            s-=b[i];
        }

        if(s!=0){
            cout<<-1<<"\n";
            T--;
            continue;
        }

        vector<int> smaller ;
        vector<int> larger ;

        for(int i = 0 ; i < size_arr ; i++){

            if(a[i] < b[i]){
                smaller.push_back(i);
            }else if(a[i] > b[i]){
                larger.push_back(i);
            }

        }

        s = 0 ;
        int l = 0;

        vector<pair<int,int>> ans;

        while(s < smaller.size() && l< larger.size()){

           a[smaller[s]]+=1;
           a[larger[l]]-=1 ;

           pair<int,int> p(larger[l],smaller[s]);
           ans.push_back(p);
           if(a[smaller[s]] == b[smaller[s]]){
               s++;
           }
           if(a[larger[l]] == b[larger[l]]) {
               l++;
           }

        }

        cout<<ans.size()<<"\n";
        for(int i = 0 ;  i < ans.size() ; i++){
            cout<<ans[i].first+1<<" "<<ans[i].second+1<<"\n";
        }

        T--;
    }

}