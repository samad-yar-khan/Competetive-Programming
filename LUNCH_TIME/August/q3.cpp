#include <bits/stdc++.h>
using namespace std;
#define modVal 1000000007
#define ll long long


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r" , stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    

    int T= 0 ;
    cin>>T;
    for(int i = 1 ; i <= T ; i++){

        int n = 0 ;
        int k = 0 ;
        cin>>n>>k;

        int arr[200001] = {0};
        int maxVal = INT_MIN;
        for(int j = 0 ; j< n ; j++){
            cin>>arr[j];
            maxVal = max(maxVal , arr[j]);
        }
        vector<int> ind;
        for(int itr = 0 ; itr <n ;  itr++){
            if(arr[itr] == maxVal){
                ind.push_back(itr);
            }
        }
        ll count =0;
        for(int i = 0;i<ind.size() ; i++){
            // if(i==ind.size()-1){
                int x = ind[i];
                if(x+1 >= k){
                    count+=(n-x);
                }
            // }else{
            //     int x = ind[i];
            //     int y = ind[i+1];
            //     if(x+1 >= k){
            //         count+=(y-x);
            //     }
            // }
        }
        // priority_queue<pair<int,int>> nodes ;

        // int L = 0;
        // int R = 0;
        // while(R<k){
        //     nodes.push(make_pair(arr[R] ,R ));
        //     R++;
        // }

        // int count = 0 ;
        // while(R <= n){
            
        //     if(R-L>=k){

        //         pair<int , int> tNode = nodes.top();
        //         int ind = tNode.second;

        //         if(ind < L){
        //             nodes.pop();
        //             continue;
        //         }

        //         if(ind == L+k-1 && maxVal ==arr[ind]){
                   
        //             count++;
        //             if(R<n){
        //                 nodes.push(make_pair(arr[R] ,R ));
        //             }
        //            R++;
        //         }else{
        //             L++;
        //         }

        //     }else{
        //         if(R==n){
        //             break;
        //         }else{
        //             nodes.push(make_pair(arr[R] , R));
        //             R++;
        //         }
        //     }
        // }

        cout<<count<<"\n";
       

    }




}

