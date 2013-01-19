#include <cstdio>
#include <cstdlib>
#include <cstring>
int xxx, n, c, ans;
float pin, pout;
char bufferx[10000], buffer[10000];
int main()
{
  xxx = 13195; // the number of data sets
  freopen("data.txt", "w", stdout);
  for (int xx = 0; xx < xxx; ++xx) {
    itoa(xx, buffer, 10);
	bufferx[0] = '\0';
    strcat(bufferx, buffer);
    strcat(bufferx, ".stg");
    freopen(bufferx, "r", stdin); // 0.stg
	scanf("%d%d%f%f", &n, &c, &pin, &pout);
	bufferx[0] = '\0';
    strcat(bufferx, buffer);
    strcat(bufferx, ".ans");
    freopen(bufferx, "r", stdin); // 0.ans
	scanf("%d", &ans);
	
    printf("%d %d %0.1f %0.1f %d\n", n, c, pin, pout, ans);
  }
}
