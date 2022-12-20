#include <iostream>
#include "MyVector.hpp"

using namespace std;

int main()
{
    MyVector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    MyVector<int> v2(v1);
    v1.insert(1, 5);
    v2.push_back(10);
    v1.pop_back();
    v1.erase(1);
    MyVector<int> v3 = v1;
    v1.push_back(8);
    MyVector<int> v4;
    for (int i = 1; i < 100; i++)
    {
        v4.push_back(i);
    }
    cout << v4.size() << endl;
    cout << v4.capacity() << endl;
    v4.shrink_to_fit();
    cout << v4.size() << endl;
    cout << v4.capacity() << endl;
    

    
    // cout << v1.capacity() << endl;
    // cout << v1.size() << endl;
    // for (int i = 0; i < v1.size(); i++)
    // {
    //     cout << v1[i] << endl;
    // }
    // cout << v2.capacity() << endl;
    // cout << v2.size() << endl;
    // for (int i = 0; i < v2.size(); i++)
    // {
    //     cout << v2[i] << endl;
    // }
    // cout << v3.capacity() << endl;
    // cout << v3.size() << endl;
    // for (int i = 0; i < v3.size(); i++)
    // {
    //     cout << v3[i] << endl;
    // }


    // v1.swap(0, v1.size() - 1);
    // cout << v1.front() << endl;
    // cout << v1.end() << endl;


    return 0;
}
