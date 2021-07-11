#include <bits/stdc++.h>
using namespace std;
#define lld long double
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
 
    cin.tie(NULL);
 

    int T{1};
    cin>>T;



    while(T>0){

        int n = 0  ;
        lld k = 0;
    
        cin>>n>>k;
        lld z = k/100;
        vector<lld> arr;
        for(int i= 0; i < n  ; i++){
            lld temp=0;
            cin>>temp;
            arr.push_back(temp);
        }

        lld den = arr.at(0);
        lld adds = 0;
        for(int i = 1 ; i < n ; i++){

            lld dev = arr.at(i)/(den);
            if(dev <= z){
                den+=arr.at(i);
            }else{
                lld f = (arr.at(i)/z) - (lld)den;//f jitna add karna hai
                den+=arr.at(i);
                den+=f;
                adds+=f;
            }

        }
        ll ans = ceil(adds);
        cout<<ans<<"\n";



       T--; 
    }


 
    return 0;
}