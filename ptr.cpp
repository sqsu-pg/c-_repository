/*
 * @Author: your name
 * @Date: 2021-05-30 13:13:11
 * @LastEditTime: 2021-05-30 17:45:34
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /c++_core/ptr.cpp
 */
#include <iostream>
#include <string>
#include <stddef.h>

using namespace std;

void array_func()
{
    int myArray[5] = {1, 2, 3, 4, 5};
    int* myArrayPtr = myArray;
    //*可以用访问数组的方法访问指针
    for(int i = 0; i < 5; i++)
    {
        cout << myArrayPtr[i] << endl;
    }

    int* myNewArray = new int[5];
    for (int i = 0; i < 5; i++)
    {
        myNewArray[i] = i+1;
        cout << myNewArray[i] << endl;
    }
    delete []myNewArray;
    myNewArray = nullptr;

    int* myNewPtr = new int(5);
    cout << *myNewPtr << endl;
    cout << myNewPtr[0] << endl;
    myNewPtr[1] = 4;//*也可以用，但是可能容易出现访问越界
    cout << myNewPtr[1] << endl;
    delete []myNewPtr;
}

void char_array()
{
    char ch[10];
    for (int i = 0; i < 10; i++)
    {
        ch[i] = i;
    }
}

void func_with_array1(int* theArray, const int& size)
{
    for (int i = 0; i < size; i++)
    {
        cout << theArray[i] << endl;
    }
}
void func_with_array2(int theArray[], const int& size)
{
    for (int i = 0; i < size; i++)
    {
        cout << theArray[i] << endl;
    }
}
void func_with_array3(int theArray[5], const int& size)
{
    for (int i = 0; i < size; i++)
    {
        cout << theArray[i] << endl;
    }
}

void func_with_erwei_array(int theArray[][2], const int& rows,  const int& cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << theArray[i][j] << " ";
        }
        cout << endl;
    }
}

//*指针数组与数组指针，[]数组下标符(从左到右)优先级大于*指针云算法(从右到左)
//*指针数组 int* ptr_array[2] 注释：ptr_array先和[]数组下标符号结合，所以ptr_array是数组，然后再和*结合，所以是ptr_array数组中的元素都是指针;
//*数组指针 int(*array_ptr)[2] 注释：array_ptr是指向含有两个元素的数组的指针

int main()
{
    /* int myArray3[5] = {5, 4, 6, 3 , 1};
    func_with_array1(myArray3, 5);
    func_with_array2(myArray3, 5);
    func_with_array3(myArray3, 5); */

    int** erweiArray = nullptr;
    int erwei1[2][2];
    erwei1[0][0] = 0;
    erwei1[0][1] = 1;
    erwei1[1][0] = 1;
    erwei1[1][1] = 2;
    func_with_erwei_array(erwei1, 2, 2);

    //array_func();
    //char_array();

    //*指针既可以在堆栈中，也可以在堆中
    //*对于指针类型* 　*号前面是指针指向的类型，*号后面是指针
    /* int** handle = nullptr;
    cout << "二维指针的地址为: " << handle << endl;
    handle = new int*(nullptr);
    cout << "一维指针的地址为 : " << *handle << endl;
    *handle = new int(50);
    cout << "二维指针的地址为: " << handle << endl;
    cout << "一维指针的地址为 : " << *handle << endl;
    cout << "二维指针指向的数字为 : " << **handle << endl;

    delete *handle;
    delete handle;

    cout << "二维指针的地址为: " << handle << endl;
    cout << "一维指针的地址为 : " << *handle << endl;

    //*野指针和空指针
    int* ptr1 = nullptr;
    ptr1 = new int(20);
    cout << "指针地址为: " << ptr1 << endl;
    cout << "值为: " << *ptr1 << endl;

    delete ptr1;//delete之后，指针变成了野指针
    cout << "指针地址为: " << ptr1 << endl;
    ptr1 = nullptr;
    ptr1 = new int(50);
    cout << "值为: " << *ptr1 << endl;
    delete ptr1; */

    

    return 0;
}

