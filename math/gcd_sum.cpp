#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    if(b==0)
        return a;
    
    return gcd(b, a%b);
}

int main()
{
    int test_n;
    int case_n;
    long long int sum = 0;
    cin >> test_n;
    int **arr = new int*[test_n];
    if(test_n > 100 && test_n < 1){cout << "Error"<< endl; return -1;}

    for(int i = 0; i < test_n; i++)
    {
        cin >> case_n;
        arr[i] = new int[case_n];
        for(int j=0; j < case_n; j++)
            cin >> arr[i][j];

        for(int k=0; k < case_n-1; k++)
            for(int t=k+1; t < case_n; t++)
                sum+=gcd(arr[i][k],arr[i][t]);

        cout << sum << endl;
        sum = 0;
    }
    return 0;
}