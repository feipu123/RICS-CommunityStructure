/*
Input :
Line 1: the number of vertice n, the number of communities in the first structure m1, the number of communities in the second structure m2 
Line 2: n numbers. The i-th number means which community the i-th vertex belongs to in the first structure. (The numbers are between 0 and n-1)
Line 3: n numbers. The i-th number means which community the i-th vertex belongs to in the second structure. (The numbers are between 0 and n-1)

Output :
Line 1: If the two structures are too different, output "Too Different"; Otherwise, output the value of difference.

Time :
O(n + m1 * m2)
 */


#include <iostream>
#include <cstdio>
using namespace std;
int const MAXCOMMUNITY = 1000, MAXVERTEX = 1000;
int n, m1, m2, ans, com1[MAXVERTEX], com2[MAXVERTEX], num1[MAXCOMMUNITY], num2[MAXCOMMUNITY], g[MAXCOMMUNITY][MAXCOMMUNITY];
bool f;
int main()
{
  scanf("%d%d%d", &n, &m1, &m2);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &com1[i]);
    ++num1[com1[i]];
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &com2[i]);
    ++num2[com2[i]];
  }
  for (int i = 0; i < n; ++i) 
      ++g[com1[i]][com2[i]];
  for (int i = 0; i < m1; ++i) {
    f = true;
    for (int j = 0; j < m2; ++j)
      if (g[i][j] * 2 >= num1[i]) {
	ans += num1[i] - g[i][j];
	f = false;
	break;
      }
    if (f) {
      printf("Too Different\n");
      return 0;
    }
  }
  for (int i = 0; i < m2; ++i) {
    f = true;
    for (int j = 0; j < m1; ++j)
      if (g[j][i] * 2 >= num2[i]) {
	ans += num2[i] - g[j][i];
	f = false;
	break;
      }
    if (f) {
      printf("Too Different\n");
      return 0;
    }
  }
  printf("The value of difference is %d", ans);
  return 0;
};
