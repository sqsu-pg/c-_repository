#include <iostream>
#include <string>
#include <fstream>
#include <dirent.h>  

using namespace std;

int main()
{
    std::string path;
    path = "/home/walle/pcl_lab/lab/test_mkdir";

    DIR* d;

    if ((d = opendir(path.c_str())) == NULL)
    {
        cout << "文件夹路径不存在" << endl;
        cout << "创建文件夹" << endl;
        std::string mk = "mkdir -p " + path;
        system(mk.c_str());
    }


    return 0;
}