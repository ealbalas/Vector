#include <iostream>
#include "MyVector.hpp"

using namespace std;

int main()
{
    MyVector<int> v1;
    auto cap = v1.capacity();
    cout << cap << endl;
    cout << v1.size() << endl;
    return 0;
}