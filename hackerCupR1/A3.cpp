#include <bits/stdc++.h>
using namespace std;
#define modVal 1000000007
#define ll long long


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r" , stdin);
        freopen("output.txt", "w", stdout);
    #endif
    

    int T= 0 ;
    cin>>T;

   
    for(int i = 1 ; i <= T ; i++){
        ll count =0;
        ll N = 0;
        cin>>N;
        string S{""} ;
        cin>>S;
        ll j = 0 ; 
        char setChar = 'F';
        vector<int> si;
        vector<int> ei;
        //find first x or o
        while(j < N){
            if(S[j]=='X'||S[j] =='O'){
                setChar=S[j];
                j++;
                break;
            } 
           j++;
        }
        
        int starting = j-1;
        int k = j; 
        while(k < N){
            if(S[k]!='F' && S[k]!=setChar ){
                setChar = S[k];
                si.push_back(starting);
                ei.push_back(k);
                starting=k;
            }else if(S[k] == setChar){
                starting = k;
            }
            k++;
        }
        // for(int j = 0 ; j < si.size() ; j++){
        //     cout<<"("<<si[j]<<","<<ei[j]<<")"<<" ";
        // }
        
        if(si.size()==0||ei.size()==0){
            count=0;    
            cout<<"Case #"<<i<<": "<<count<<"\n";
            continue;
        }
        vector<ll> up;
        vector<ll> down;

        up.push_back(si[0]+1);
        for(int j = 1 ;j<si.size() ; j++ ){

            up.push_back(si[j]-si[j-1]);
            down.push_back(ei[j]-ei[j-1]);

        }
        down.push_back(((S.length()%modVal)-(ei[ei.size()-1]%modVal) + modVal)%modVal);

        //  for(int j = 0 ; j < down.size() ; j++){
        //     cout<<" "<<up[j]<<","<<down[j]<<" ";
        // }


        // cout<<"\n";

        vector<ll> presum;
        ll totalSum =0;
        ll sumVal =0;
        for(int i = 0 ; i < up.size() ; i++ ){
            sumVal = ((sumVal%modVal) + (up[i]%modVal))%modVal; 
            presum.push_back(sumVal);
            totalSum = (totalSum%modVal + sumVal%modVal)%modVal;
        }

        for(int j = down.size()-1 ; j>=0 ; j--){
            count = (count%modVal + (down[j]*totalSum)%modVal)%modVal;
            totalSum = totalSum-presum[j];
        }

         cout<<"Case #"<<i<<": "<<count<<"\n";

    }

}

