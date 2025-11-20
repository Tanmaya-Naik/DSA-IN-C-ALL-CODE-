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

Node *convertoLL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *move = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        move->next = temp;
        move = temp;
    }

    return head;
}

int main()
{
    vector<int> arr = {18, 14, 8, 9};
    Node *Head = convertoLL(arr);
    cout << Head->data;
    return 0;
}