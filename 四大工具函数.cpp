//蓝桥杯基础复盘

//闰年判断函数
// bool IsRunNian(int year)
// {
//     if((year % 4 == 0&&year % 100 != 0)||(year % 400 == 0 )) return true;
//     else return false;
// }


//MaxGongYue && MinGongBei
// long long MaxGongYue(long long a,long long b)
// {
//     while(b != 0)
//     {
//         int temp = b;
//         b = a % b;
//         a = temp;
//     }
//     return a;
// }

// long long MinGongBei(long long a,long long b)
// {
//     int result = (a / MaxGongYue(a,b)) * b;
//     return result;  
// }


//进制转换模板

//Level 1

// #include <bits/stdc++.h>
// using namespace std;
// string TenToAny(long long Former, int TargetNum)
// {
//     if(Former == 0) return "0";
//     string chars = "0123456789ABCDEF";
//     string result;
//     while(Former > 0)
//     {
//         int remainder = Former % TargetNum;
//         result += chars[remainder];
//         Former = Former / TargetNum;
//     }
//     reverse(result.begin(),result.end());
//     return result;
// }
// int main()
// {
//     long long a = 0;
//     int b = 0;
//     cin >> a;
//     cin >> b;
//     string result = TenToAny(a,b);
//     while(result.length() < 8)
//     {
//         result = "0" + result;
//     } 
//     cout << result << endl;
// }

//Level 2

// long long AnyToTen(string numStr,int sourceBase)
// {
//     long long result = 0;
//     string chars = "0123456789ABCDEF";
//     for(int i = 0;i < numStr.size();i++)
//     {
//         char c = numStr[i];
//         int num = chars.find(toupper(c));
//         result = result * sourceBase + num;
//     }
//     return result;
// }

#include<bits/stdc++.h>
using namespace std;
long long AnyToTen(string Former,int FormerNum)
{
    long long result = 0;
    string chars = "0123456789ABCDEF";
    for(int i = 0;i < Former.size();i++)
    {
        char c = Former[i];
        int num = chars.find(toupper(c));
        result = result * FormerNum + num;
    }
    return result;

}
int main()
{
    string a;
    int b;
    cin >> a;
    cin >> b;
    long long result = AnyToTen(a,b);
    cout << result << endl;
}




