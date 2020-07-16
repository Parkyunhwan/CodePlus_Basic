/*
    생각
    1. 주어진 k개에서 6개를 뽑아 정렬할 수 있는 개수
    2. 순열을 통해 구할 수 있다. (순서 상관없이 사용 했으므로 조합) !!
    3. 사전 순 출력이 되어야 한다.
*/
#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int i, k;

  while (1) {
    scanf("%d", &k);
    if (k == 0) break;

    int choose[12] = { 0, };
    int arr[12];
    for (i = 0; i < 6; i++) choose[i] = 1;
    for (i = 0; i < k; i++) scanf("%d", &arr[i]);

    do {
      for (i = 0; i < k; i++) {
        if (choose[i] == 1) printf("%d ", arr[i]);
      }
      printf("\n");
    } while(prev_permutation(choose, choose+k));

    printf("\n");
  }

}