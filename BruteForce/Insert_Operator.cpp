#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
int main()
{
    int n,k,i;
    int sum = 0;
    int max_sum = INT_MIN;
    int min_sum = INT_MAX;
    cin >> n;
    int oper_num[4];
    int *number = new int[n];
    int *oper = new int[n-1];
    for(int i = 0; i < n; i++)
        cin >> number[i];
    for(int i = 0; i < 4; i++)
        cin >> oper_num[i];
    k = 0;
    i = 0;
    while(k != 4){

        if(oper_num[k]==0){

            k++;
        }
        else
        {
            oper[i] = k;
            oper_num[k]--;
            i++;
        }
         
    }
    // for(int i=0; i < n - 1; i++){
    //     printf("%d\n",oper[i]);
    // }

    do{
        sum = number[0];
        for(int i = 0; i < n - 1; i++)
        {
            switch(oper[i])
            {
                case 0:
                    sum += number[i+1];
                    break;
                case 1:
                    sum -= number[i+1];
                    break;
                case 2:
                    sum *= number[i+1];
                    break;
                case 3:
                    sum /= number[i+1];
                    break;
            }
        }
        max_sum = max(max_sum, sum);
        min_sum = min(min_sum, sum);
    }while(next_permutation(oper, oper+(n - 1)));
    printf("%d\n", max_sum);
    printf("%d\n", min_sum);

}