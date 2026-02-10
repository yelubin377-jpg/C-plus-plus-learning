// 函数重载 就是同名函数参数不一样 编译器自动选
// C语言不支持这个 C++才有 感觉挺方便的

#include <iostream>
using namespace std;


// 同名函数 参数类型不一样
// 编译器看你传的是啥类型 就调哪个版本

void XianShi(int ZhengShu)
{
    cout << "  [int Ban] ZhengShu: " << ZhengShu << endl;
}

void XianShi(double XiaoShu)
{
    cout << "  [double Ban] XiaoShu: " << XiaoShu << endl;
}

void XianShi(const char *ZiFuChuan)
{
    cout << "  [char* Ban] ZiFuChuan: " << ZiFuChuan << endl;
}

void XianShi(char DanZiFu)
{
    cout << "  [char Ban] DanZiFu: " << DanZiFu << endl;
}


// 参数个数不同也算重载

int QiuHe(int A)
{
    cout << "  1Ge CanShu: " << A << endl;
    return A;
}

int QiuHe(int A, int B)
{
    int JieGuo = A + B;
    cout << "  2Ge CanShu: " << A << "+" << B << "=" << JieGuo << endl;
    return JieGuo;
}

int QiuHe(int A, int B, int C)
{
    int JieGuo = A + B + C;
    cout << "  3Ge CanShu: " << A << "+" << B << "+" << C << "=" << JieGuo << endl;
    return JieGuo;
}


// 用面积计算来试试 类型和个数一起变的情况

double MianJi(double BanJing)   // 圆
{
    double JieGuo = 3.14159 * BanJing * BanJing;
    cout << "  Yuan(r=" << BanJing << "): " << JieGuo << endl;
    return JieGuo;
}

double MianJi(double Chang, double Kuan)   // 矩形
{
    double JieGuo = Chang * Kuan;
    cout << "  JuXing(" << Chang << "x" << Kuan << "): " << JieGuo << endl;
    return JieGuo;
}

// 注意这里参数是int 不是double 所以和上面那个(double,double)不冲突
double MianJi(int Di, int Gao)   // 三角形
{
    double JieGuo = Di * Gao / 2.0;
    cout << "  SanJiao(Di=" << Di << ",Gao=" << Gao << "): " << JieGuo << endl;
    return JieGuo;
}


int main()
{
    // 先试类型不同的
    cout << "LeiXing BuTong:" << endl;
    XianShi(42);        // 传int -> 调int版
    XianShi(3.14);      // 传double -> 调double版
    XianShi("hello");   // 传字符串 -> 调char*版
    XianShi('A');        // 传字符 -> 调char版
    // 关键点: 编译器靠 函数名+参数列表 来区分 这叫函数签名
    // 返回值不算！ 光返回值不同不能重载

    cout << endl;

    // 个数不同
    cout << "GeShu BuTong:" << endl;
    QiuHe(5);
    QiuHe(3, 7);
    QiuHe(1, 2, 3);
    // 传几个参数就调几个参数的版本 很直观

    cout << endl;

    // 面积 类型+个数组合
    cout << "MianJi JiSuan:" << endl;
    MianJi(5.0);        // 1个double -> 圆
    MianJi(4.0, 6.0);   // 2个double -> 矩形
    MianJi(3, 8);        // 2个int -> 三角形
    // MianJi(3, 8)走的是int版 不是double版
    // 如果写MianJi(3.0, 8.0)就走double版了 这个要注意

    cout << endl;

    // 还有个坑: 隐式类型转换
    cout << "YinShi ZhuanHuan:" << endl;
    float XiaoShuF = 2.5f;
    XianShi(XiaoShuF);
    // float没有对应的重载版本 编译器把它转成double了
    // 一开始还以为会报错 结果不会 编译器自己转了
    cout << "  (float MeiYou DuiYingBanBen, BeiZhuanCheng double Le)" << endl;

    // XianShi(42L);  // long也没有对应版本 会转成int还是double?
    // 试了下 long -> int  但如果有歧义编译器会报错

    return 0;
}
