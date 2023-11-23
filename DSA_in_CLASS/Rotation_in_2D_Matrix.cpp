#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

struct node
{
    int data;
    node *next;
};
node *head = NULL;
node *temp = NULL;
node *newnode = NULL;
void creation(int n, int index[])
{
    for (int i = 0; i < n; i++)
    {
        newnode = new node();
        newnode->data = index[i];
        newnode->next = head;
        if (head == nullptr)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }

    return;
}
void display()
{
    temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
}

int **rotation(int **arr, int n = 4)
{
    head = head->next;
    temp = head;
    do
    {
        for (int i = 0; i < n; i++)
        {
            arr[0][i] = temp->data;
            temp = temp->next;
        }

        for (int i = 1; i < n; i++)
        {
            arr[i][3] = temp->data;
            temp = temp->next;
        }

        for (int i = n - 2; i > -1; --i)
        {
            arr[3][i] = temp->data;
            temp = temp->next;
        }

        for (int i = n - 2; i > 0; --i)
        {
            arr[i][0] = temp->data;
            temp = temp->next;
        }

    } while (temp != head);
    return arr;
}
void pos(int index[], int **arr, int n)
{
    int p = 0;

    // cout<<"arr: "<<arr[3][3];
    for (int i = 0; i < n; i++)
        index[p++] = arr[0][i];

    for (int i = 1; i < n; i++)
        index[p++] = arr[i][3];

    for (int i = n - 2; i > -1; --i)
        index[p++] = arr[3][i];

    for (int i = n - 2; i > 0; --i)
        index[p++] = arr[i][0];
    creation(p, index);
}

void print(int **arr)
{
    for (int i = 0; i < 4; i++)
    {
        for (int k = 0; k < 4; k++)
        {
            cout << arr[i][k] << "   ";
        }
        cout << endl;
    }
}

int main()
{
    int **arr;
    int data = 0;
    int index[4 * 4];
    arr = new int *[4];

    for (int i = 0; i < 4; i++)
    {
        arr[i] = new int[4];
        for (int k = 0; k < 4; k++)
        {
            if (k == 3 || i == 0 || i == 3 || k == 0)
                arr[i][k] = ++data;
            else
                arr[i][k] = 0;
        }
    }
    print(arr);

    pos(index, arr, 4);
    cout << endl;
    cout << endl;

    while (true)
    {
        arr = rotation(arr);
        cout << endl;
        print(arr);

        Sleep(1000*6);
    }
}
