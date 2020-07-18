#include <iostream>
#include <algorithm>
using namespace std;
char arr_c[15];
char temp[15];
int combi[15]={0,};
int ja=0;
int mo=0;
int main()
{
    int L,C;
    cin >> L >> C;
    for(int i = 0; i < C; i++)
        cin >> arr_c[i];
    sort(arr_c, arr_c + C);

    for(int i = 0; i < L; i++)
        combi[i] = 1;
    
    do{
        mo = 0;
        ja = 0;
        int t = 0;
        for(int i = 0; i < C; i++){
            if(combi[i]==1){
                temp[t] = arr_c[i];
                if(temp[t] == 'a' ||temp[t] == 'e' ||temp[t] == 'i' ||temp[t] == 'o' ||temp[t] == 'u')
                        mo++;
                else
                {
                    ja++;
                }
                t++;
            }
        }
        if(mo >= 1 && ja >= 2){
            for(int i = 0; i < L; i++)
                cout << temp[i];
            cout << "\n";
        }
        // else{
        //     cout << "wrong :" << mo << " " << ja;
        //     for(int i = 0; i < L; i++)
        //         cout << temp[i];
        // }

    }while(prev_permutation(combi, combi + C));
    
}