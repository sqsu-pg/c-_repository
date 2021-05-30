/*
 * @Author: your name
 * @Date: 2021-05-30 13:07:16
 * @LastEditTime: 2021-05-30 18:11:40
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /c++_core/operator_and_return.cpp
 */
#include <iostream>
#include <string>

using namespace std;
class CMyString
{
    public:
        CMyString() = default;
        //*构造函数
        CMyString(const std::string& pData)
        {
            cout << "调用构造函数" << endl;
            m_pData = pData;
        }
        //*拷贝构造函数
        CMyString(const CMyString& str)
        {
            cout << "调用拷贝构造函数" << endl;
            m_pData = str.m_pData;
        }
        //*赋值函数
        CMyString& operator=(const CMyString& str)
        {
            cout << "调用赋值函数" << endl;
            //*一般写法，可能会由于分配空间不足导致异常
            /* if (this == &str)
            {
                return *this;
            }
            m_pData = str.m_pData;
            return *this; */
            //*高级写法，保证分配空间不足时，不会出错
            if (this != & str)
            {
                CMyString strTemp(str);
                string tmp = str.m_pData;
                strTemp.m_pData = m_pData;
                m_pData = tmp;
            }
            return *this;
        }

    private:
        std::string m_pData;

};

CMyString test1(const CMyString theCM)
{
    return theCM;
}

int main()
{
    CMyString cm1("james");
    CMyString cm2, cm3;
    cm3 = cm2 = cm1;

    cout << "C++ 拷贝函数和赋值函数的调用时机" << endl;
    cout << "调用拷贝构造函数的时机: " << endl;
    cout << "    1. 当用类的一个对象去初始化该类的另一个对象（或引用）时系统自动调用拷贝构造函数实现拷贝赋值" << endl;
    cout << "    2. 若函数的形参为类对象，调用函数时，实参赋值给形参，系统自动调用拷贝构造函数。" << endl;
    cout << "    3.当函数的返回值是类对象时，系统自动调用拷贝构造函数。" << endl;
    cout << "调用赋值函数的时机 : " << endl;
    cout << "    1.当用一个对象赋值给另一个对象时" << endl;
    CMyString cm4; 
    cm4 = test1(cm1);

    return 0;

}