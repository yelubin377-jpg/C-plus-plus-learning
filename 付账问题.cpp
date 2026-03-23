
#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main() 
{
    int n = 0;
    long long S = 0;
    scanf("%d %lld", &n, &S);
    
    double *a = (double*)malloc(sizeof(double) * n); // 开辟一个数组
    // a数组存储每个人所带的钱
    if (a == NULL) 
    {
        perror("malloc");
        return 1;
    }
    for (int i = 0; i < n; i++) 
    {
        long long eg = 0;
        scanf("%lld",&eg);
        a[i] = (double)eg;

    }
    sort(a, a + n);//从小到小大排列
    //for(int i = 0;i<n;i++)
    //{
    //    printf("%lf ",a[i]);
    //}
    double *b = (double*)malloc(sizeof(double)*n);//这个b数组用来存储每个人最终付的钱
    if(b == NULL)
    {
        perror("b malloc");
        return 1;
    }
    double sum = 0;//已经付的钱
    double aver_end = 0.0;
    int k = n;//记录从第看k个人开始钱完全够  //重点！！！假如没有找到足够的人，就是n个人全部付得起
    for(int i = 0;i<n;i++)
    {
        double aver = ((long double)S - sum) / (n - i);//现在 n - i的人的平均数
        if(a[i] <= aver)
        {
            b[i] = a[i];               
        }
        else
        {
            aver_end = ((double)S - sum) / ((double)n - i);
            k = i;
            break;
        }
        sum += a[i];
    }
    for(int i = k;i<n;i++)
    {
        b[i] = aver_end;
    }
    double *c = (double*)malloc(sizeof(double)*n);//这个c数组用来存储单数据－平均数  的平方
    if(c == NULL)
    {
        perror("c malloc");
        return 1;
    }
    for(int i = 0;i<n;i++)
    {
        c[i] = (b[i] - (double)((long double)S/n))*(b[i] - (double)((long double)S/n));
    }
    double result_begin = 0;
    double result_end = 0;
    for(int i = 0;i<n;i++)
    {
        result_begin += c[i];     
    }    
    result_begin = result_begin / (double)n;
    result_end = sqrt(result_begin);//sqrt 好用的平方根计算
    printf("%.4lf\n",result_end);
    free(a);
    free(b);
    free(c);
    
    
    
}
    