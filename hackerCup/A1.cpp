#include <bits/stdc++.h>
using namespace std;
#define modVal 1000000007
#define ll long long


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("consistency_chapter_1_input.txt", "r" , stdin);
        freopen("output.txt", "w", stdout);
    #endif
    

    int T= 0 ;
    cin>>T;
    for(int i = 1 ; i <= T ; i++){

        int freq[26] = {0}; 
        string s{""};
        cin>>s;
        int maxVowel=-1;
        int v=-1;
        int maxCons=-1;
        int c= -1;
        if(s.length()==1){
           cout<<"Case #"<<i<<": "<<0<<"\n";
            continue;
        }
        for(int i =  0 ; i < s.length() ; i++){

            int f = s[i]-'A';
            freq[f]+=1;
            if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' ||s[i] == 'U' ){
               if(maxVowel < freq[f]){
                   maxVowel=freq[f];
                   v=f;
               }
            }else{
                if(maxCons < freq[f]){
                   maxCons=freq[f];
                   c=f;
               }
            }
        }

        if(maxCons == -1 || maxVowel == -1){
            cout<<"Case #"<<i<<": "<<s.length()<<"\n";
            continue;
        }   

        int ans1=0;
        int ans2=0;
        //change all to v
       
        for( int i  = 0 ; i < 26 ; i++){

            if(i==v || freq[i] == -1 || freq[i] == 0){
                continue;
            }
            if(i == 0 || i == 4 || i == 14 || i == 8 || i ==20){
               ans1+= (freq[i]*2);
            }else{
                ans1 += (freq[i]);
            }

        }
    


        for( int i  = 0 ; i < 26 ; i++){

            if(i==c || freq[i] == -1){
                continue;
            }
            if(i == 0 || i == 4 || i == 14 || i == 8 ||i ==20 ){
               ans2+= freq[i];
            }else{
                ans2+= (freq[i]*2);
            }
        
        }
    

        cout<<"Case #"<<i<<": "<<min(ans2,ans1)<<"\n";

    }




}

