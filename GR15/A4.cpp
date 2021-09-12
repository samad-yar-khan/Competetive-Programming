#include <bits/stdc++.h>
using namespace std;
#define modVal 1000000007
#define ll long long


bool comp(pair<int,int> a , pair<int , int> b){
    if(a.first==b.first){
        return a.second>b.second;
    }
    return a.first<b.first;
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r" , stdin);
        freopen("output.txt", "w", stdout);
    #endif
   
    

    int T= 0 ;
    cin>>T;


    while(T--){

        int arr[301] = {0};
        int n= 0, m =0;
        cin>>n>>m;
        for(int i = 0 ; i < m  ; i++){
            cin>>arr[i];
        }

        vector<pair<int,int>> seats;
        for(int i =0;i<m ; i++){
            seats.push_back(make_pair(arr[i] , i));
        }

        sort(seats.begin(),seats.end() , comp);

        bool seat_tak[301];
        for(int itr = 0 ; itr<m ; itr++){
            seat_tak[itr] =false;
        }
        ll count =0;
        for(int i =0 ; i < m ;i++ ){
            int mark=0;
            for(int j= 0 ; j < m ; j++){
                if(seats[j].second==i){
                    mark=j;
                    break;
                }
            }
            for(int k = 0 ; k <= mark ; k++){
                if(k==mark){
                    seat_tak[k]=true;
                    break;
                }

                if(k<mark && seat_tak[k]){
                    count++;
                }
            }
        }

        cout<<count<<'\n';
       
    }
   
}

