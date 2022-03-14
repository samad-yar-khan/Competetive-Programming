#include<bits/stdc++.h>
using namespace std;

  int minimumOperations(vector<int>& nums) {
        unordered_map<int,int> m1;
        unordered_map<int,int> m2;
        
        for(int i =0;i<nums.size(); i++){
            if(i%2){
                m1[nums[i]]++;
            }else{
                m2[nums[i]]++;
            }
        }
        
        int f1=0,f2=0,n1=0,n2=0;
        
        for(auto i=m1.begin();i!=m1.end();i++){
            if(i->second > f1){
                f1= i->second;
                n1 = i->first;
            }
        }
        for(auto i=m2.begin();i!=m2.end();i++){
            if(i->second > f2){
                f2= i->second;
                n2 = i->first;
            }
        }
        
        int s1 = nums.size()/2;
        int s2 =s1;
        if(nums.size()%2==1){
            s1++;
        }
        
        if(n1 != n2){
            return (s1-f1) + (s2-f2);    
        }
        
        int f3 =0,n3=0,f4 =0,n4=0;
        for(auto i=m2.begin();i!=m2.end();i++){
            if(i->second > f4 && i->first!=n2){
                f4= i->second;
                n4 = i->first;
            }
        }
        for(auto i=m1.begin();i!=m1.end();i++){
            if(i->second > f3 && i->first!=n1){
                f3= i->second;
                n3 = i->first;
            }
        }
                
        return min(s1-f3+s2-f2 , s1-f1 + s2-f4);
    }