
// 引用与指针对比实验

#include <iostream>
using namespace std;

// 值传递
void ZhiChuanDi(int ShuZi)  // 数字
{
    ShuZi = 100;
}

//  指针传递
void ZhiZhenChuanDi(int *ZhiZhen)  // 指针
{
    *ZhiZhen = 200;
}

//  引用传递
void YinYongChuanDi(int &YinYong)  // 引用
{
    YinYong = 300;
}

//  返回引用
int ShuZu[5] = {1, 2, 3, 4, 5};  // 数组
int& HuoQuYuanSu(int SuoYin)    // 获取元素(索引)
{
    return ShuZu[SuoYin];
}

int main()
{
    //  基本用法
    int BianLiang = 10;           // 变量
    int *ZhiZhen = &BianLiang;    // 指针
    int &YinYong = BianLiang;     // 引用
    
    cout << "YuanShiZhi: " << BianLiang << endl;           // 原始值
    cout << "ZhiZhen FangWen: " << *ZhiZhen << endl;       // 指针访问
    cout << "YinYong FangWen: " << YinYong << endl;        // 引用访问
    
    //  修改测试
    *ZhiZhen = 50;
    cout << "TongGuo ZhiZhen XiuGaiHou: " << BianLiang << endl;  // 通过指针修改后
    YinYong = 80;
    cout << "TongGuo YinYong XiuGaiHou: " << BianLiang << endl;  // 通过引用修改后
    
    //  参数传递对比
    cout << "\nCanShu ChuanDi CeShi:" << endl;  // 参数传递测试
    int A = 1;
    ZhiChuanDi(A);
    cout << "ZhiChuanDi Hou: " << A << endl;  // 值传递后
    
    ZhiZhenChuanDi(&A);
    cout << "ZhiZhenChuanDi Hou: " << A << endl;  // 指针传递后
    
    YinYongChuanDi(A);
    cout << "YinYongChuanDi Hou: " << A << endl;  // 引用传递后
    
    //  引用返回值当左值
    cout << "\nYinYong FanHuiZhi:" << endl;  // 引用返回值
    cout << "ShuZu[2] = " << ShuZu[2] << endl;  // 数组
    HuoQuYuanSu(2) = 999;
    cout << "XiuGaiHou ShuZu[2] = " << ShuZu[2] << endl;  // 修改后数组
    
    // 引用不能重新绑定
    cout << "\nChongBangDing CeShi:" << endl;  // 重绑定测试
    int M = 111, N = 222;
    int &R = M;
    R = N;  // 这是赋值,不是重绑定
    cout << "M = " << M << ", N = " << N << endl;
    
    return 0;
}
