#include <bits/stdc++.h>
using namespace std;

int main()
{
  int a[1001] = {0};
  int n = 0;//输入的数字

  scanf("%d",&n);
  for(int i = 1; i<=n; i++)
  {
    a[i] = 1;
    for( int j = 1;j<= i/2;j++)
    { 
      a[i] = a[i]+a[j];
    }
  }
  printf("%d\n",a[n]);
}