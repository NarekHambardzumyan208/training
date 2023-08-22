#include <iostream>
#include <vector>
#include <set>
using namespace std;

template<typename T>
void unique(vector<T>& obj)
{
    if (obj.size() == 0 || obj.size() == 1)
    {
        return;
    }

    set<T> temp;
    for (int i = 0; i < obj.size(); i++)
    {
        temp.insert(obj[i]);
    }

    obj.clear();
    for (const T& element : temp)
    {
        obj.push_back(element);
    }
}

template<typename T>
void odd(vector<T>& obj)
{
    set<T> temp;
    for (int i = 0; i < obj.size(); i++)
    {
        temp.insert(obj[i]);
    }

    obj.clear();
    for (const T& element : temp)
    {
        if (element % 2 != 0)
        {
            obj.push_back(element);
        }
    }
}

template<typename T>
void display(const vector<T>& a)
{
    for (const T& element : a)
    {
        cout << element << endl;
    }
}

int main() {
    vector<int> a;
    a.push_back(4);
    a.push_back(6);
    a.push_back(9);
    a.push_back(10);
    a.push_back(6);

    cout << "Original Vector:" << endl;
    display(a);

    unique(a);
    cout << "After unique function:" << endl;
    display(a);

    odd(a);
    cout << "After odd function:" << endl;
    display(a);

    return 0;
}
