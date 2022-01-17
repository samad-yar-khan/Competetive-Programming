#include<iostream>
#include<string>
using namespace std;

//this function return the maximum value of M required to form a valid string using the range 1 to M
int getRange(string &s){

    //count of maximum number of consecutive '<' signs
    int count_less_than_sign =0;

    //count of maximum number of consecutive '>' sign
    int count_more_than_sign=0;

    //this will hold the current symbol
    char currSymbol= s[0];

    //this will hold count of current consecutive signs 
    int currCount =1;
    int si=0;
    for(int i =1;i<s.length();i++){

        if(s[i] == currSymbol || s[i]=='='){

            //if its the same symbol and not the '=' sign, we incremnet the count
            if(s[i]!='='){
                currCount++;
            }

        }else{
            
            //if the symbol changes then we need to identify the symbol and reset the maxum count of the symbol if needed
            switch (currSymbol){
                case '<':{
                    count_less_than_sign=max(count_less_than_sign,currCount);
                    break;
                }
                case '>':{
                    count_more_than_sign=max(count_more_than_sign,currCount);
                    break;

                }
                default:
                    break;
            }

            //reset the counter
            currCount=1;
            currSymbol=s[i];
            si=i;
        }

    }

    //we need to set values of maximum symbol once again when the strings ends
    switch (currSymbol){
        case '<':{
            count_less_than_sign=max(count_less_than_sign,currCount);
            break;
        }
        case '>':{
            count_more_than_sign=max(count_more_than_sign,currCount);
            break;
        }
        default:
            break;
    }
    
    //we return the maximum of the two values incremented by 1 
    return max(count_more_than_sign,count_less_than_sign)+1;

}


int main(){
  
    cout<<"Enter the number of Test Cases : ";
    int T= 0 ;
    cin>>T;
    int counter = 1 ;
  
    while(counter <= T){     
        
        cout<<"Enter the string for case "<<counter<<" : ";
        string s;
        cin>>s;
        int rangeValue = getRange(s);
        cout<<"Minimum value of M required to form the sequence is "<<rangeValue<<" and the range of numbers is : ";
        cout<<"[1"<<","<<rangeValue<<"]\n";
        counter ++;
        cout<<"\n";
    }
    return 0;
}