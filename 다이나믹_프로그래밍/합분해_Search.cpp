#include <iostream>

using namespace std;

int d[201][201];
const int mod = 1000000000;
int main()
{
    int n,k;
    cin >> n >> k;

    for(int i=0; i<=n; i++){
        d[1][i] = 1;
    }


    for(int i=2; i<=k; i++){
        for(int j=0; j<=n; j++){
            for(int l=0; l<=j; l++){
                d[i][j] = (d[i][j] + d[i-1][j-l])%mod;
                //cout << d[i][j] << "\n";
            }
        }
    }
    cout << d[k][n] << "\n";
}