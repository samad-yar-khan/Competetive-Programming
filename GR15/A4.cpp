#include <bits/stdc++.h>
using namespace std;
#define modVal 1000000007
#define ll long long

ll mergeSorted(int *arr1 , int*arr2 ,int*arr3 , int si1 , int ei1 , int si2 , int ei2 ){

    int i =si1;
    int j =si2;
    int k =0;
    ll count =0;

    while(i<=ei1 && j<=ei2){
        if(arr2[j] > arr1[i]){
            arr3[k++]= arr2[j++];
            count += (ei1-i+1);

        }else{
            arr3[k++] = arr1[i++];
        }
    }   

    while(j<=ei2){
        arr3[k++] = arr2[j++];
    }

    while(i<=ei1){
         arr3[k++] = arr1[i++];
    }

    return count;

}

ll mergeSort(int*arr , int si , int ei){

    if(si>=ei){
        return 0;
    }
    int mid = (si+ei)/2;
    ll c1 = mergeSort(arr , si , mid );
    ll c2 = mergeSort(arr , mid+1 , ei);
    int*arr3 = new int[ei-si+2];
    ll count = mergeSorted(arr , arr , arr3 , si , mid, mid+1, ei);
    for(int i = 0 ;i<(ei-si+1) ; i++){
        arr[si+i] = arr3[i];
    }
    delete [] arr3;
    return count + c1 + c2;
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

    pair<int , int> arr[90001];
    int arr2[90001];
    while(T--){

        int n =0,m=0;
        cin>>n>>m;
        int N = n*m;

        for(int i = 0 ; i < N ; i++){
            int a_i =0;
            cin>>a_i;
            arr[i] = make_pair(a_i , i);
        }

        stable_sort(arr  , arr+N);

        //basically , unique elemnt to same hi chalenge , 
        //bas equals ke liye revesal karke we can lower the compelxiy

        int i = 0 ;
        while(i < N){

            int j = i ; 
            int num = arr[i].first;
            while (j<N && arr[j].first == num)
            {
                j++;
            }

            int starting =  i;
            //row wise reversing
            for(int k = i;k < j;k++){
                //row ke end mai agya
                if((k+1)%m == 0){
                    reverse(arr+starting , arr+k+1);
                    starting = k+1;
                }
            }
            //leftover
            if(starting!=j){
                reverse(arr+starting ,arr+j);
            }

            i=j;

        }

        for(int i =0  ; i < N ; i++){
            arr2[i] = arr[i].second;
        }
        //merge sort types , now for each m elemnts
        //we will see , how many smaller indexed elemts were on the left of it
        // https://www.geeksforgeeks.org/count-of-larger-elements-on-right-side-of-each-element-in-an-array/

        ll count =0;
        for(int i = 0 ;  i < N ; i+=m ){
            ll count_t = mergeSort(arr2 , i , i+m-1);
            count+=count_t;
        }

        cout<<count<<"\n";

    }
   
}

