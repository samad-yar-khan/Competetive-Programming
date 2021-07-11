/*

B. Jumps
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are standing on the OX-axis at point 0 and you want to move to an integer point x>0.

You can make several jumps. Suppose you're currently at point y (y may be negative) and jump for the k-th time. You can:

either jump to the point y+k
or jump to the point y−1.
What is the minimum number of jumps you need to reach the point x?

Input
The first line contains a single integer t (1≤t≤1000) — the number of test cases.

The first and only line of each test case contains the single integer x (1≤x≤106) — the destination point.

Output
For each test case, print the single integer — the minimum number of jumps to reach x. It can be proved that we can reach any integer point x.

Example
inputCopy
5
1
2
3
4
5
outputCopy
1
3
2
3
4
Note
In the first test case x=1, so you need only one jump: the 1-st jump from 0 to 0+1=1.

In the second test case x=2. You need at least three jumps:

the 1-st jump from 0 to 0+1=1;
the 2-nd jump from 1 to 1+2=3;
the 3-rd jump from 3 to 3−1=2;
Two jumps are not enough because these are the only possible variants:

the 1-st jump as −1 and the 2-nd one as −1 — you'll reach 0−1−1=−2;
the 1-st jump as −1 and the 2-nd one as +2 — you'll reach 0−1+2=1;
the 1-st jump as +1 and the 2-nd one as −1 — you'll reach 0+1−1=0;
the 1-st jump as +1 and the 2-nd one as +2 — you'll reach 0+1+2=3;
In the third test case, you need two jumps: the 1-st one as +1 and the 2-nd one as +2, so 0+1+2=3.

In the fourth test case, you need three jumps: the 1-st one as −1, the 2-nd one as +2 and the 3-rd one as +3, so 0−1+2+3=4.

*/


#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T{0};
    cin>>T;

        while(T>0){

            ll x = 0 ;
            cin>>x;
            ll i = 1;
            ll sum = 0;
            while(sum < x){
                sum+=i;
                i++;
            }

            if(sum-x == 1 ){
                cout<<i<<"\n";
            }else{
                cout<<i-1<<"\n";
            }
            T--;
        }
    return 0;
}
