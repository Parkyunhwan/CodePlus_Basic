#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int combi[20]={0,};

int main()
{
    int N, S, k,sum;
    int result = 0;
    cin >> N >> S;
    vector<int> v(N);
    for(int i = 0; i < N; i++)
        cin >> v[i];
    
    for(int x=0; x < N; x++){
        combi[x]=1;
        do{
            sum = 0;
            for(int i = 0; i < N; i++){
                if(combi[i]==1)
                    sum += v[i];
            }
            if(sum == S){
                // cout << N << "\n";
                // for(int i = 0; i < N; i++){
                //     if(combi[i]==1)
                //         cout <<v[i] << " ";
                // }
                // cout << "\n";    
                result++;
            }
        }while(prev_permutation(combi, combi+N));
    }
    cout << result << "\n";
}