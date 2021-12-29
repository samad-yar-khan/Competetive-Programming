#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define modVal 10e9+7
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;



int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r" , stdin);
        freopen("../output.txt", "w", stdout);
    #endif
   
    int T= 0 ;
    cin>>T;
    
    while(T--){ 

        int n =0;
        cin>>n;

        vector<int>vec(n+2 , 0);
        for(int i =0;i <= n+1 ;i++ )
        {
            cin>>vec[i];
        }

        sort(vec.begin(),vec.end());
        ll sum =0;
        for(int i =0;i<n;i++){
            sum+=vec[i];
        }

        if(sum == vec[n]){
            for(int i =0;i<n;i++){
                cout<<vec[i]<<" ";
            }
            cout<<'\n';
        }else{
            sum+=vec[n];
            int index = -1;
            for(int i =0;i<=n;i++){
                if(sum - vec[i] == vec[n+1]){
                    index =i;
                    break;
                }
            }

            if(index ==-1){
                cout<<-1<<"\n";
            }else{
                for(int i =0;i<=n;i++){
                    if(i == index){
                        continue;
                    }
                    cout<<vec[i]<<" ";
                }
                cout<<'\n';
            }
        }

        


    
    }

    return 0;
   
}