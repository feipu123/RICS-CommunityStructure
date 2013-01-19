/*
Input :
Line 1: the number of vertice n, the number of communities in the first structure m1, the number of communities in the second structure m2 
Line 2: n numbers. The i-th number means which community the i-th vertex belongs to in the first structure. (The numbers are between 0 and n-1)
Line 3: n numbers. The i-th number means which community the i-th vertex belongs to in the second structure. (The numbers are between 0 and n-1)

Output :
Line 1: If the two structures are too different, output "Too Different"; Otherwise, output the value of difference.

Time :
O(n+m1*m2)
 */


#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;
int const MAXCOMMUNITY = 1000, MAXVERTEX = 1000;
int n, m1, m2, ans, com1[MAXVERTEX], com2[MAXVERTEX], num1[MAXCOMMUNITY], num2[MAXCOMMUNITY], g[MAXCOMMUNITY][MAXCOMMUNITY];
bool f;
int xxx, xx;
char bufferx[1000], buffer[1000];

int main()
{
xxx = 2610; // the number of data sets
for (int xx = 0; xx < xxx; ++xx) {
  for (int i = 0; i < MAXCOMMUNITY; ++i) {
    num1[i] = 0;
	num2[i] = 0;
	for (int j = 0; j < MAXCOMMUNITY; ++j)
	  g[i][j] = 0;
  }
  m1 = 0;
  m2 = 0;
  ans = 0;
  itoa(xx, buffer, 10);
  bufferx[0] = '\0';
  strcat(bufferx, "fast_local.exe ");
  strcat(bufferx, buffer);
  strcat(bufferx, ".gph 0.5 10");
  system(bufferx); // fast_local.exe 0.gph 0.5 10
  

  
  bufferx[0] = '\0';
  strcat(bufferx, buffer);
  strcat(bufferx, ".stg");
  freopen(bufferx, "r", stdin); // 0.stg

  scanf("%d", &n);
  
  bufferx[0] = '\0';
  strcat(bufferx, buffer);
  strcat(bufferx, ".gph.singlemin_withoutTheta.partition");
  freopen(bufferx, "r", stdin);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &com1[i]);
    ++num1[com1[i]];
	if (com1[i] > m1) m1 = com1[i];
  }
  
  bufferx[0] = '\0';
  strcat(bufferx, buffer);
  strcat(bufferx, ".cmu");
  freopen(bufferx, "r", stdin); // 0.cmu
  for (int i = 0; i < n; ++i) {
    scanf("%d", &com2[i]);
    ++num2[com2[i]];
	if (com2[i] > m2) m2 = com2[i];
  }
  for (int i = 0; i < n; ++i) 
      ++g[com1[i]][com2[i]];
  ++m1;
  ++m2;
  for (int i = 0; i < m1; ++i) {
    f = true;
    for (int j = 0; j < m2; ++j)
      if (g[i][j] * 2 >= num1[i]) {
	    ans += num1[i] - g[i][j];
	    f = false;
	    break;
      }
    if (f) {
	  bufferx[0] = '\0';
      strcat(bufferx, buffer);
      strcat(bufferx, ".ans");
      freopen(bufferx, "w", stdout); // 0.ans
      printf("1000000\n");
	  fclose(stdout);
      break;
    }
  }
  if (f) continue;
  for (int i = 0; i < m2; ++i) {
    f = true;
    for (int j = 0; j < m1; ++j)
      if (g[j][i] * 2 >= num2[i]) {
	    ans += num2[i] - g[j][i];
	    f = false;
	    break;
      }
    if (f) {
	  bufferx[0] = '\0';
      strcat(bufferx, buffer);
      strcat(bufferx, ".ans");
      freopen(bufferx, "w", stdout); // 0.ans
      printf("1000000\n");
	  fclose(stdout);
      break;
    }
  }
  if (f) continue;
  bufferx[0] = '\0';
  strcat(bufferx, buffer);
  strcat(bufferx, ".ans");
  freopen(bufferx, "w", stdout); // 0.ans
  printf("%d", ans);
  fclose(stdout);
  }
};
