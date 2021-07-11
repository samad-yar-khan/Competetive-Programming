//https://codeforces.com/contest/1509/problem/C
#include <bits/stdc++.h>
using namespace std;
#define ll long long

//recursion
ll solve_rec(ll* arr , int si , int ei , int size){

    //base case
    if(size == 2){
        return arr[ei] - arr[si];
    }

    //ih
    //assume it will work
    ll c1 = solve_rec(arr,si+1,ei,size-1);
    ll c2 = solve_rec(arr , si , ei-1 , size-1 );

    //now we take the min of those two and return my ans
    ll my_d = arr[ei] - arr[si];
    return min(c1,c2) + my_d;
}


//memoization
ll solve_memos_ans(ll* arr , int si , int ei , int size , ll**ans){

    //bc
    if(size == 2){
        return arr[ei] -  arr[si];
    }
    //check if ans already exists
    if(ans[si][ei] != -1){
        return ans[si][ei];
    }
    //else calculate the ans
     //ih
    //assume it will work
    ll c1 = solve_memos_ans(arr,si+1,ei,size-1 , ans);
    ll c2 = solve_memos_ans(arr , si , ei-1 , size-1 ,ans);

    //now we take the min of those two and return my ans
    ll my_d = arr[ei] - arr[si];
    //save the ans
    ans[si][ei] = min(c1,c2) + my_d;
    return ans[si][ei];

}

ll solve_memo(ll* arr , int si , int ei , int size){


    if(size == 1)
    {
        return 0;
    }
    //ans i,j will have the ans for sub array (i,j)
    ll**ans= new ll*[size];
    for(int i{0} ; i < size ; i++){

        ans[i] = new ll[size];
        for(int j = 0 ; j < size ; j++){
            ans[i][j] = -1;
        }

    }

    ll ANS = solve_memos_ans(arr,si,ei,size,ans);

     for(int i{0} ; i < size ; i++){

        delete [] ans[i];

    }
    delete[] ans;

    return ANS;

}
//DP
ll solve_dp(ll* arr , int si , int ei , int size){


    if(size == 1)
    {
        return 0;
    }
    //ans i,j will have the ans for sub array (i,j)
    ll**ans= new ll*[size];
    for(int i{0} ; i < size ; i++){

        ans[i] = new ll[size];
        for(int j = 0 ; j < size ; j++){
            ans[i][j] = -1;
            if(i==j){
                ans[i][j] = 0;
            }
        }

    }
    //fill for pairs of two
    for(int i{0} ; i < size-1 ; i++){
        
        ans[i][i+1] = arr[i+1]-arr[i]; //taking pairs of two

    }

    int gap = 2;
    while(gap<size){
        for(int i = 0 ; i < size-gap ; i++){
            ans[i][i+gap] = min(ans[i+1][i+gap] , ans[i][i+gap-1]) + arr[i+gap]-arr[i];
        }
        gap++;
    }
    ll ANS = ans[0][size-1];


  //we need to prefill the values which we can


     for(int i{0} ; i < size ; i++){

        delete [] ans[i];

    }
    delete[] ans;

    return ANS;

}

int main()
{
    ios_base::sync_with_stdio(false);
 
    cin.tie(NULL);
 

    ll n{0};
    cin>>n;

    ll*arr = new ll[n];
    for(int i = 0 ; i < n ;  i++){
        cin>>arr[i];
    }
    sort(arr , arr+n);
    ll val = solve_dp(arr,0,n-1,n);

    cout<<val<<"\n";
       
    delete[] arr;
        


 
    return 0;
}