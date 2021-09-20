#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define modVal 10e9

//os Tree
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r" , stdin);
        freopen("../output.txt", "w", stdout);
    #endif
   
    int T= 0 ;
    cin>>T;

    while(T--){ 
      
        //the logic is that we procceed with a bfs of the whole thing 
        //the accessible node willl be put in a queue    
        int N = 0 ;
        cin>>N;
        queue<int> readable_books;
        vector<int> numParentNodes(N+1,0);
        vector<vector<int>> edges(N+1,vector<int>(0));
        for(int i =1 ;i<=N ; i++){
            int K =0;
            cin>>K;
            if(K==0){
                readable_books.push(i);
            }
            numParentNodes[i] = K;//isko itni parens chahiye tobe acceses
            for(int  j =0  ; j < K ; j++){
                int parent=0;
                cin>>parent;
                edges[parent].push_back(i);
            }

        }

        vector<int> levels(N+1 ,1 );//so level refers too the stage at wihic the ith the book will be read
        int readBooks =0;

        while(!readable_books.empty()){

            int myBook = readable_books.front();
            readable_books.pop();
            readBooks++;
            //go throuugh the childred
            for(int i = 0 ; i < edges[myBook].size() ;i++)
            {
                int child = edges[myBook][i];
                //apne child ke req parents kam kardo because you have alreaady read this patets book;
                numParentNodes[child]--;
                //now decide the level for you child
                if(myBook < child){
                    levels[child] = max(levels[child] , levels[myBook]);
                }else{
                    levels[child] = max(levels[child] , levels[myBook]+1);
                }

                if(numParentNodes[child]==0){
                    readable_books.push(child);
                } 
            }
        }
        int ans =0;
        for(int i =1 ;i <= N ; i++ ){
            ans =max(ans , levels[i]);
        }
        if(readBooks == N){
            cout<<ans<<'\n';
        }else{
            cout<<-1<<"\n";
        }
    }
}
