/*
 * @Author: your name
 * @Date: 2021-06-06 15:04:41
 * @LastEditTime: 2021-06-06 15:36:13
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /c++_core/enum.cpp
 */
#include <iostream>
#include <string>

using namespace std;

enum DAY
{
    MONDAY = 6,
    TUESDAY = 5,
    WEDNESDAY = 4,
    THURSDAY = 7,
    FRIDAY = 9
};

//todo 只有使用强制枚举类型才可以拥有相同的枚举变量名称
enum class num1
{
    ONE,
    TWO,
    THREE
};

enum class num2
{
    ONE,
    TWO,
    THREE
};

int main(int argv, char** argc)
{
    DAY today;
    //today = 4; //doing 不能够使用 1 2 3 4 5 这样的数字给enum类型进行赋值
    today = MONDAY;
    int a = THURSDAY;//DOING 可以使用枚举类型给int类型数字进行赋值
    DAY today_2 = static_cast<DAY>(2);//doing 可以使用强制类型转换
    cout << "today is : " << today << endl;
    cout << a << endl;

    if (today == 0)
    {
        cout << "today is monday" << endl;
    }
    if (today == MONDAY)
    {
        cout << "today is monday" << endl;
    }

    switch(today)
    {
        case MONDAY :
            cout <<"Monday";
            break;
        case TUESDAY :
            cout <<"Tuesday";
            break;
        case WEDNESDAY:
            cout <<"Wednesday";
            break;
        case THURSDAY :
            cout <<"Thursday";
            break;
        case FRIDAY :
            cout <<"Friday";
            break;
    }

    for (DAY data = MONDAY; data <= FRIDAY; data = static_cast<DAY>(data + 1))
    {
        cout << data << endl;
    }
    for (int i = 0; i <= FRIDAY; i++)
    {
        cout << i << endl;
    }

    //doing c++11强制枚举类型
    num1 n1 = num1::ONE;
    num2 n2 = num2::ONE;
    cout << static_cast<int>(n1) << endl; //doing 强制枚举类型需要强制转换为int才能输出
    cout << static_cast<int>(n2) << endl;
    
}
