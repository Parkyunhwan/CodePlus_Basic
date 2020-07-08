/*
    9명의 난쟁이 중 7명의 합이 100이면 그 7명이 진짜 난쟁이다.
    7 -> 100
    배열을 통한 검사
*/
#include <iostream>
#include <algorithm>
using namespace std;
int shortman[9]={0,};
int finalman[7]={0,};
int sum=0;
int one,two;
int main()
{
    for(int i=0; i<9; i++)
        cin >> shortman[i];
    for(int i=0; i<9; i++)
        sum+=shortman[i];
    
    for(int i=0; i<9; i++){
        for(int j=i+1; j<9; j++){
            int twoman = shortman[i] + shortman[j];
           // cout << "sum" << sum << endl;
           // cout << "twoman" << twoman << endl;
            if((sum-twoman)==100){
                one=i;
                two=j;
               // cout << "o t" << one << two << endl;
                i=10;
                break;
            }
        }
    }
    int f=0;
    for(int i=0; i<9; i++){
        if(i!=one && i!=two){
            finalman[f]=shortman[i];
           // cout << "i" << i << endl;
           // cout << finalman[f] << endl;
            f++;
        }
    }
    //20cout << one << " " << two << "ok\n";
    sort(finalman,finalman+7);
    for(int i=0; i<7; i++)
        cout << "\n" <<finalman[i] << "\n";
}
