/*
 * @Author: your name
 * @Date: 2021-05-30 22:01:17
 * @LastEditTime: 2021-05-30 22:45:29
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /c++_core/smart_ptr.cpp
 */

#include <iostream>
#include <memory>
#include <string>

using namespace std;


void print_unique_int(int* ptr)
{
    cout << *ptr << endl;
}

void move_unique_ptr(unique_ptr<int> data)
{
    cout << *data << endl;
    
}

int main()
{
    //*1.unique_ptrs 智能指针，具有”唯一的所有权“的智能指针
    unique_ptr<int> uq1 = make_unique<int>(5);
    cout << *uq1 << endl;
    //*get()方法可用于直接访问底层指针，这可以将指针传递给需要普通指针的函数，例如以下调用
    print_unique_int(uq1.get());

    //*可以释放unique_ptr的底层指针，并且使用reset()根据需要将其改成另一个指针
    unique_ptr<int> uq2 = nullptr;//*直接赋值为nullptr空指针不会报错
    uq2.reset();//重置为空指针
    uq2.reset(new int(50));//*重置成为Int为50的指针
    cout << *uq2 << endl;

    //*可以使用release()断开unique_ptr与底层指针的连接。release()方法返回资源的底层指针，然后将底层指针设置为nullptr
    int *ptr1 = uq2.release();//*智能指针不再负责内存空间的释放
    cout << *ptr1 << endl;
    delete ptr1;

    //*由于unique_ptr具有唯一所有权， 因此无法复制他，使用std::move()方法，将unique_ptr移动到另一个
    unique_ptr<int> uq3 = make_unique<int>(30);
    unique_ptr<int> uq4 = std::move(uq3);
    cout << *uq4 << endl;
    move_unique_ptr(std::move(uq4));


    //*shared_ptr
    //*shared_ptr容易产生双重删除的问题，也就是一个指针，绑定到了两个shared_ptr上导致的
    int* ptr2 = new int(10);
    //*以下这样就会导致双重析构，出问题
    /* shared_ptr<int> sp1(ptr2);
    shared_ptr<int> sp2(ptr2); */

    shared_ptr<int> sp3;
    sp3.reset(ptr2);//*这样使用reset是正确的

    //shared_ptr<int> sp4;
    //sp4.reset(sp3);//*这样使用reset是不正确的，智能指针不能reset为指向智能指针
    cout << *sp3 << endl;

    shared_ptr<int> sp5(sp3);//*支持使用另一个shared_ptr初始化一个shared_ptr指针
    cout << *sp5 << endl;

    shared_ptr<int> sp6 = sp3;//*shared_ptr可以直接进行赋值 
    cout << *sp6 << endl;

    return 0;
}
