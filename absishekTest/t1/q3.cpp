#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define modVal 10e9
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

class Btree{

    public:
    int data;
    Btree*left;
    Btree*right;
};

Btree* solve(Btree*root){
    if(root==NULL){
        return NULL;
    }

    queue<Btree*> pn;
    Btree*head =NULL;
    Btree*tail=NULL;
    int lm =INT_MIN;
    pn.push(root);
    pn.push(NULL);
    while(!pn.empty()){

        Btree*tn=pn.front();pn.pop();

        if(tn==NULL){
            if(!pn.empty()){
                pn.push(NULL);
            }
            Btree*nn = new Btree;
            nn->data=lm;
            if(head==NULL){
                head =nn;
                tail=nn;
            }else{
                tail->right=nn;
                tail=tail->right;
            }
            lm=INT_MIN;
        }else{

            lm=max(lm , tn->data);
            if(tn->left){
                pn.push(tn->left);
            }
            if(tn->right){
                pn.push(tn->right);
            }
        }

    }
    return head;
}



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
        
    }
   
}