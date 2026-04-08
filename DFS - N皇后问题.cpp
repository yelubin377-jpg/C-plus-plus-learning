//解法1:
// #include<bits/stdc++.h>
// using namespace std;
// int x[15] = {0};//N皇后中N是小于10的
// int sum,n;
// int PD(int k)//判定是否符合标准
// {
//     for(int i = 1;i<k;i++)
//     {
//         if(abs(k-i)==abs(x[k]-x[i]))    return 0;//这个表示不在同一斜线上
//         else if(x[k] == x[i])  return 0;  //这个表示不再同一列
//         //行数无需判断，本身i就代表行数，不可能相同
//     }
//     return 1;
// }


// bool check(int a)//a表示当前放到的行数
// {
//     if(a>n) sum++;
//     else 
//     {
//         return 0;
//     }
//     return 1;
// }


// void DFS(int a)
// {
//     if(check(a)) return;//检查放完了没有，如果没有，继续放                  ！！//如果放完了，return 1 截断,进入36行之后，继续佛人循环继续找
//     else
//         for(int i = 1;i<=n;i++)
//         {
//             x[a]=i;
//             if(PD(a))
//                 DFS(a+1);
//             else continue;
//         }

// }



// int main()
// {
//     cin >> n ;
//     DFS(1);
//     cout << sum <<endl;
//     return 0;
// }




//解法2    回溯DFS法尝试
#include <bits/stdc++.h>
using namespace std;
int ans = 0;
const int N = 15;
int n = 0;
bool Lie[N];
bool ZDJX[2*N];
bool FDJX[2*N];
void dfs(int row)
{
    if(row == n)
    {
        ans++;
        return;
    }
    for(int i = 0;i<n;i++)
    {
        if(!Lie[i] && !ZDJX[row + i] && !FDJX[row - i + n])
        {
            Lie[i] = ZDJX[row + i] = FDJX[row - i + n] = true;
            dfs(row + 1);
            Lie[i] = ZDJX[row + i] = FDJX[row - i + n] = false;
            
        }
    }
}
int main()
{
    scanf("%d",&n);
    dfs(0);
    cout << ans << endl;
    return 0;
}

