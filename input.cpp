/*
 * @Author: your name
 * @Date: 2021-06-20 14:25:21
 * @LastEditTime: 2021-06-20 16:10:55
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /c++_core/input.cpp
 */
#include <iostream>
#include <string>
#include <limits>
#include <climits>
#include <stdio.h>
#include <cstdio>
#include <glog/logging.h>
#include <gflags/gflags.h>

using namespace std;

//doing 详解地址 https://blog.csdn.net/K346K346/article/details/48213811

//doing 当我们从键盘输入字符串的时候需要敲一下回车键才能够将这个字符串送入到缓冲区中，那么敲入的这个回车键（\r）会被转换为一个换行符（\n），
//doing 这个换行符也会被存储在 cin 的缓冲区中并且被当成一个字符来计算！比如我们在键盘上敲下了 123456 这个字符串，然后敲一下回车键（\r）将这个字符串送入了缓冲区中，
//doing 那么此时缓冲区中的字节个数是 7 ，而不是 6。


//doing cin 可以连续从键盘读取想要的数据，以空格、tab 或换行作为分隔符
//doing 当 cin>> 从缓冲区中读取数据时，若缓冲区中第一个字符是空格、tab或换行这些分隔符时，cin>> 会将其忽略并清除，继续读取下一个字符，若缓冲区为空，则继续等待。
//! 但是如果读取成功，字符后面的分隔符是残留在缓冲区的，cin>> 不做处理。
void cin_input()
{
    int a;
    char b;
    double c;
    
    std::cin >> a;
    std::cin >> b;
    std::cin >> c;
    LOG(INFO) << "a is : " << a << " " << "b is : " << b << " " << "c is : " << c;

    //!从结果可以看出，cin>> 对缓冲区中的第一个换行符视而不见，采取的措施是忽略清除，继续阻塞等待缓冲区有效数据的到来。
    //!但是，getline() 读取数据时，并非像 cin>> 那样忽略第一个换行符，getline() 发现 cin 的缓冲区中有一个残留的换行符，
    //!不阻塞请求键盘输入，直接读取，送入目标字符串后，因为读取的内容为空，所以程序中的变量 test 为空串。
    //doing 这里不阻塞的原因是，cin 会把最后一个\n换行字符留在缓冲区中，getline读到\n所以直接不阻塞
    string test;
	getline(cin,test);	//不阻塞
	cout<<"test:"<<test<<endl;
}

//!cin.get() 从输入缓冲区读取单个字符时不忽略分隔符，直接将其读取，就出现了如上情况，将换行符读入变量 b，输出时换行两次，一次是变量 b，一次是 endl
//!cin.get() 的返回值是 int 类型，成功则返回读取字符的 ASCII 码值。
//!cin.get(char var) 如果成功返回的是 cin 对象，因此支持链式操作，如cin.get(b).get(c)
void cin_get_input()
{
    char a;
	char b;
	a=cin.get();
	cin.get(b);
	cout << "a is : " << a << endl; 
    cout << "b is : " << b << endl;

    //!cin.get(array,20); 读取一行时，遇到换行符时结束读取，但是不对换行符进行处理，换行符仍然残留在输入缓冲区
    //!第二次由 cin.get(a2) 将换行符读入变量 a2，打印输入换行符的 ASCII 码值 10。
    //!这也是 cin.get() 读取一行与使用 cin.getline 读取一行的区别所在.
    //!cin.getline 读取一行字符时，默认遇到 ‘\n’ 时终止，并且将 ‘\n’ 直接从输入缓冲区中删除掉，不会影响下面的输入处理。
    cout << "使用cin.get()读取一行: " << endl;
    char a2;
	char array[20]={NULL}; 
	cin.get(array,20);
	cin.get(a2);
	cout<<array<<" "<< a2 << " " << (int)a2 << endl;
}

//?注意，cin.getline() 与 cin.get() 的区别是，cin.getline() 不会将行结束符（如换行符）残留在输入缓冲区中。

//!cin.getline 读取一行字符时，默认遇到 ‘\n’ 时终止，并且将 ‘\n’ 直接从输入缓冲区中删除掉，不会影响下面的输入处理。
//!遇到'\n'换行符的时候，和cin.get()一样，不忽略分隔符
void my_cin_getline_input()
{
    char s1[20]={NULL};
    char s2[20]={NULL};
    cin.getline(s1, 12);
    cin.getline(s2, 10);
    cout << "s1 is : " << s1 << endl;
    cout << "s2 is : " << s2 << endl;
}


//doing cin state
void cin_state()
{
    char ch, str[20]; 
	cin.getline(str, 5);
	cout<<"goodbit:"<<cin.good()<<endl;    // 查看goodbit状态，即是否有异常
	cin.clear();                         // 清除错误标志
	cout<<"goodbit:"<<cin.good()<<endl;    // 清除标志后再查看异常状态
	//cin>>ch; 
    cin.get(ch);
    char ch2;
    //cin.get(ch2);
	cout<<"str:"<<str<<endl;
	cout<<"ch:"<<ch<<endl;
    //cout << "ch2 is : " << ch2 << endl;
    cout<<"goodbit:"<<cin.good()<<endl; 

    char str1[20]={NULL},str2[20]={NULL};
    cin.getline(str1,5);
    cin.clear();  // 清除错误标志
	cin.ignore(numeric_limits<std::streamsize>::max(),'\n'); // 清除缓冲区的当前行
	cin.getline(str2,20);
	cout<<"str1:"<<str1<<endl;
	cout<<"str2:"<<str2<<endl;
}

//doing C++ 中定义了一个在 std 名字空间的全局函数 getline()，因为这个 getline() 函数的参数使用了 string 字符串，所以声明在了<string>头文件中了。
//todo getline() 利用 cin 可以从标准输入设备键盘读取一行，当遇到如下三种情况会结束读操作：文件结束； 遇到行分隔符； 输入达到最大限度。
//?两个重点关注的点：1. 开头不会不像cin一样忽略结束符(不会忽略)　2. 结尾会不会删除'\n'(会删除)
//doing getline() 遇到结束符时，会将结束符一并读入指定的 string 中，再将结束符替换为空字符。
//doing 因此，进行从键盘读取一行字符时，建议使用 getline，较为安全。但是，最好还是要进行标准输入的安全检查，提高程序容错能力。
//doing cin.getline() 与 getline() 类似，但是因为 cin.getline() 的输出是char*，getline() 的输出是 string，
//doing 所以 cin.getline() 属于 istream 流，而 getline() 属于 string 流，二者是不一样的函数。

void my_getline()
{
    string str;
	getline(cin,str);
	cout << str << endl;
    char ch;
    cin.get(ch);
    cout << "getline 读入结束后，会不会删除最后的字符: " << endl;
    cout << "ch 也就是最后的字符为 : " << ch << endl;
    
}

//doing gets() 是 C 中的库函数，在头文件 <stdio.h> 申明，从标准输入设备读字符串，
//doing 可以无限读取，不会判断上限，以回车或者文件结束符 EOF（ 即 -1） 结束，所以程序员应该确保 buffer 的空间足够大，以便在执行读操作时不发生溢出。
void my_gets()
{
    char array[20]={NULL};
	gets(array);
	cout << array << endl;
}

int main(int argc, char** argv)
{
    /* FLAGS_logtostderr = 0;
    FLAGS_stderrthreshold = 1;
    LOG(INFO) << "USING LOG";
    LOG(WARNING) << "WARING";
    LOG(ERROR) << "ERROR";
    LOG(FATAL) << "FATAL";
    google::InitGoogleLogging(argv[0]); */
    
    //doing learn_cin
    /* cin_input();
    char c1;
    std::cin >> c1;
    std::cout << "c1 s is : " << c1 << std::endl; */

    //doing learn cin.get()
    //cin_get_input();

    //doing learn cin.getline();
    //my_cin_getline_input();

    //doing learn cin state
    //cin_state();

    //doing learn getline
    //my_getline();

    //doing learn get
    my_get();
    

    return 0;
}