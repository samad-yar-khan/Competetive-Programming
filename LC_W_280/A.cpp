#include<bits/stdc++.h>
using namespace std;

int countOperations(int num1, int num2) {
        int i =0;
        while(num1 > 0 &&  num2 > 0){
            if(num1>=num2){
                num1-=num2;
            }else{
                num2-=num1;
            }
            i++;
        }
        return i;
    }