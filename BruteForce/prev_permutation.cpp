#include <iostream>
#include <algorithm>

using namespace std;
const int N=10000;
bool prev_permutation(int *per, int n)
{
    int i = n - 1;
    while(i > 0 && per[i] > per[i-1])
        i--;
    if(i==0)
        return false;
    int j = n - 1;
    while(per[i-1] <= per[j])
        j--;
    swap(per[i-1], per[j]);
    j = n - 1;
    while(i < j)
    {
        swap(per[i], per[j]);
        i++;
        j--;
    }
    return true;
}
int main()
{
    int n;
    cin >> n;
    int *per = new int[n];
    for(int i=0; i<n; i++)
        cin >>  per[i];
    
    if(prev_permutation(per,n)){
        for(int i=0; i < n; i++)
            cout << per[i] << " ";
    }
    else{
        cout << "-1" << endl;
    }
    
}