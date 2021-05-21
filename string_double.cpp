/*
 * @Author: your name
 * @Date: 2021-04-25 21:00:54
 * @LastEditTime: 2021-04-25 21:23:48
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit#i
 * @FilePath: /leran_algorithms/leetCode/string_double.cpp
 */
#include <iostream>
#include <vector>
#include <string>



using namespace std;

//*将一个字符串中的double分为多个字符串
void string_to_vec(string &num_str, vector<string>& num_vec)
{
    int left = 0; 
    int right = 0;
    int valid = 0;

    while (right < num_str.size())
    {
        /* code */
        if (num_str[right] == '-' || (num_str[right] >= '0' && num_str[right] <= '9') || num_str[right] == '.')
        {
            right++;
            if (right == num_str.size())
            {
                num_vec.push_back(num_str.substr(left, right - left));
            }
        }
        else
        {
            num_vec.push_back(num_str.substr(left, right - left));
            left = right;
            while (left < num_str.size() && num_str[left] != '-' && (num_str[left] < '0' || num_str[left] > '9'))
            {
                /* code */
                left++;
                right = left;
            }
        }
        
    }
    
}

int main()
{
    string num_str = "-1.2,  3.5,  56.4  ";
    vector<string> num_vec;

    string_to_vec(num_str, num_vec);


    cout << num_vec.size() << endl;
    for (int i = 0; i < num_vec.size(); i++)
    {
        double b = stod(num_vec[i]);
        cout << b << " ";
    }
    cout << endl;
    

    return 0;
}
