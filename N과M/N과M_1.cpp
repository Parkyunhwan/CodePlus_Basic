/*
    https://www.acmicpc.net/submit/15649
    
    나는 permuation을 활용하여 풀이했다.

    순열과 조합이 필요한 문제는 STL을 사용해서 풀어도 되지만
    많은 사람들이 재귀를 통해 푸는 것 같다.

*/
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;
    int per[8];
    int prev_per[8]={0,};
    cin >> n >> m;

    for(int i=0; i < n; i++){
        per[i] = i+1;
    }
    bool flag = true;
    do{
        flag = true;
        for(int i=0; i < m; i++)
            if(prev_per[i]!=per[i])
                flag = false;
        if(flag==false){
            for(int i=0; i < m; i++){
                cout << per[i] << " ";
                prev_per[i] = per[i];
            }
            cout << "\n";
        }
    }while(next_permutation(per,per+n));
}