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
    while(T--){

        int n=0;
        cin>>n;
        string s{""};
        cin>>s;

        int wins[51] = {0};
        char mat[51][51];
        vector<int> ones;

        for(int i = 0 ; i < n ; i++){
            if(s[i] == '2'){
                ones.push_back(i);
            }
            for(int j = i ; j < n ; j++){
                if(i==j){
                    mat[i][j] = 'X';
                }
                if(j>i){
                    if(s[i] == '1'){
                        mat[i][j] = '=';
                        mat[j][i] = '=';
                    }else if(s[i]=='2' && s[j]=='2') {
                        mat[i][j] = '+';
                        mat[j][i] = '-';
                        wins[i]++;
                    }else if(s[i]=='2' && s[j] == '1'){
                        mat[i][j] = '=';
                        mat[j][i] = '=';
                    }
                }
                
            }
        }

        int i = 0 , j = ones.size()-1;
        while(i < j && i < n && j>=0){

            int countL=wins[ones[i]];
            int countR = wins[ones[j]];

            if(countL > 1){
                wins[ones[i]]--;
                wins[ones[j]]++;
                mat[ones[i]][ones[j]] = '-';
                mat[ones[j]][ones[i]]= '+';
                j--;
            }
            if(countL<=1){
                i++;
            }
        }   
        bool nw =false;
        for(int i = 0 ; i< ones.size() ; i++){
            if(wins[ones[i]]<1){
                cout<<"NO"<<"\n";
                nw=true;
                break;
            }
        }

    if(!nw){
        cout<<"YES\n";
          for( int i = 0; i< n ; i++){
            for(int j = 0 ;j< n ; j++){
                cout<<mat[i][j];
            }
            cout<<"\n";
        }
    }

    
      
       
    }
   
}

