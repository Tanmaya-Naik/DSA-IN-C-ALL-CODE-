#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

public:
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

int main()
{
    vector<int> arr = {2, 5, 8, 9};
    Node *y = new Node(arr[2]);
    cout << y->data;
    return 0;
}