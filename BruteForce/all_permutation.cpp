#include <iostream>
#include <algorithm>
using namespace std;
bool next_permutation(int *per, int n)
{
    int i = n - 1;
    while(i > 0 && per[i-1] >= per[i])
        i--;
    if(i<=0)
        return false;
    int j = n - 1;
    while(per[i-1] >= per[j])
        j--;
    swap(per[i-1],per[j]);
    j = n - 1;
    while(i < j)
    {
        swap(per[i],per[j]);
        i++;
        j--;
    }
    for(int i = 0; i < n; i++)
        cout << per[i] << " ";
    cout << "\n";
    return true;
}
void all_permutation(int n)
{
    int *per = new int[n];
    for(int i=0; i<n; i++){
        per[i]=i+1;
        cout << per[i] << " ";
    }
    cout << "\n";
    
    while(next_permutation(per,n));
    return;
}
int main()
{
    int n;
    cin >> n;
    all_permutation(n);
}