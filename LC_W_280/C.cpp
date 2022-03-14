#include<bits/stdc++.h>
using namespace std;

 long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(),beans.end());
        vector<long long>f (beans.size(),0);
        vector<long long>b(beans.size(),0);
        long long cs =0;
        for(int i =0;i<beans.size();i++){
            cs = cs + beans[i];
            f[i] = cs;
        }
        cs =0;
        for(int i = beans.size()-1 ;i>=0;i--){
            cs = cs+beans[i];
            b[i] = cs;
        }
        
        
        int i =0;
        long long ans = numeric_limits<long long>::max();
        while(i<beans.size()){
            int j =i;
            while(j<beans.size()  && beans[j] == beans[i]){
                j++;
                
            }
            long long ms =0;
            if(j<beans.size()){
                ms+=(b[j]-(beans.size()-j)*(beans[i]));
            }
            if(i>0){
                ms+=(f[i-1]);
            }
            i=j;
            ans = min(ans,ms);
            
        }
        return ans;
    }