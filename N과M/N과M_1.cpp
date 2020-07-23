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