#include <iostream>
using namespace std;

// C++对象生命周期实验 


class YanShi
{
public:
    string MingCheng;  // 用个名字区分不同的对象
    
    // 构造函数
    // 对象诞生的时候调用
    YanShi(string m) : MingCheng(m)
    {
        cout << "[构造] " << MingCheng << endl;
    }
    
    // 拷贝构造函数
    // 防背刺：传值的时候会调用！
    // 这个我一开始不知道 结果传参的时候踩坑了
    YanShi(const YanShi &QiTa) : MingCheng(QiTa.MingCheng + "_copy")
    {
        cout << "[拷贝构造] " << MingCheng << endl;
    }
    
    // 析构函数
    // 对象死亡的时候调用，释放资源用的
    ~YanShi()
    {
        cout << "[析构] " << MingCheng << endl;
    }
};

// 传值（会调用拷贝构造）
// 坑！！参数是值传递，会复制一份，函数结束就销毁
// 所以传大对象的时候尽量用引用
void ChuanZhi(YanShi dx)
{
    cout << "  传值函数内: " << dx.MingCheng << endl;
    // 函数结束，dx会被析构
}

// 传引用（不会拷贝）
// 推荐用这个，省内存省时间
// 而且不会多一次构造析构
void ChuanYinYong(YanShi &dx)     
{
    cout << "  传引用函数内: " << dx.MingCheng << endl;
    // dx是引用，不会析构
}

// 返回对象

YanShi FanHuiDuiXiang()
{
    YanShi JuBu("局部对象");
    return JuBu; 
}

int main()
{
    cout << "=== 1. 栈对象 ===" << endl;
    YanShi a("栈对象A");
    // 栈对象，函数结束自动析构，不用手动管
    // 这个最省心
    
    cout << "\n=== 2. 堆对象 ===" << endl;
    YanShi *b = new YanShi("堆对象B");
    delete b;  // 堆对象必须手动delete！！不然内存泄漏
  
    
    cout << "\n=== 3. 传值调用 ===" << endl;
    ChuanZhi(a);  // 会看到拷贝构造和析构
    // 这里会多一次拷贝 效率低
    
    cout << "\n=== 4. 传引用调用 ===" << endl;
    ChuanYinYong(a);  // 不会拷贝，效率高
    // 推荐用这个方式
    
    cout << "\n=== 5. 函数返回对象 ===" << endl;
    YanShi c = FanHuiDuiXiang();


    cout << "\n=== main结束,栈对象自动析构 ===" << endl;
    // a和c会按照构造的逆序析构（后构造的先析构）
    return 0;
}

// 重要结论：
// 1. 栈对象自动管理，离开作用域自动析构
// 2. 堆对象要手动delete，容易忘（所以有了智能指针）
// 3. 传值会拷贝，传引用不拷贝
// 4. 返回对象可能被RVO优化
//


