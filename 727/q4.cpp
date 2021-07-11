#include <bits/stdc++.h>
using namespace std;
#define modVal 1000000007
#define ll  unsigned long long


bool sortbysec(const pair<ll,ll> &a,const pair<ll,ll> &b)
{
    if( a.second != b.second){
        return a.second > b.second;
    }else{
        return a.first <= b.first;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
 
    cin.tie(NULL);
 
   ll n = 0 ;
   vector<pair<ll,ll>> CP;
   cin>>n;
   for(int i = 0 ; i < n ; i++){
       ll x = 0 ,  q = 0 ;
       cin>>x>>q;
       pair<ll , ll> a(x,q);
       CP.push_back(a);
   }

   sort(CP.begin() , CP.end() , sortbysec);

   ll s= 0 ;
   ll  e = CP.size() -1;
    ll Q = 0 , C= 0;
   while(s<=e && e>=0 &&s <CP.size()){

       //edge 
      


       if(CP.at(e).second <= Q && CP.at(e).first > 0){
           C+= CP.at(e).first;
           Q+= CP.at(e).first;
           CP.at(e).first = 0;
           if(e==0){
               break;
           }
            e--;
     
       }else{
          pair<ll,ll> myItem = CP.at(s);
            ll cq = myItem.first;//kitna lena hai
            ll cb = myItem.second;//kitne ke bad kam hoga


            if(cq+Q >= CP.at(e).second){
                ll diff = CP.at(e).second - Q;
                C+=(diff*2);
                CP.at(s).first-=diff;
                Q+=diff;
                if(CP.at(s).first  ==  0){
                    s++;
                }
            }else if(cq+Q >= cb){//mai kuch lelung to iske bad mujhe j tak sab half mai milega //edge casse
                ll dp = cb-Q;
                C+=dp*2;
                C+=(cq-dp)*1;
                s++;
                Q+=cq;
                while(s<=e && s<CP.size()){
                    C+=CP.at(s).first;
                    s++;
                }
                break;
            }else {
                C+= cq*2;
                Q+=cq;
                CP.at(s).first=0;
                s++;
            }
          

       }

   }
   cout<<C<<"\n";

   



}