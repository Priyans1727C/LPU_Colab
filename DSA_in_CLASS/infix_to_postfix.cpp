#include <bits/stdc++.h>
#include <string>
#include <stack>
using namespace std;

int prec(char a)
{
    if (a == '^')
        return 3;
    else if (a == '/' || a == '*')
        return 2;
    else if (a == '-' || a == '+')
        return 1;
    else
        return -1;
}

void infix_to_postfix()
{

    string inp;
    string ans;

    stack<char> mstack;

    cin >> inp;

    for (int i = 0; i < inp.size(); i++)
    {
        if (inp[i] >= 'a' && inp[i] <= 'z')
        {
            ans += inp[i];
        }

        else if (inp[i] == '(')
            mstack.push(inp[i]);

        else if (inp[i] == ')')
        {
            while (mstack.top() != '(')
            {
                ans += mstack.top();
                mstack.pop();
            }
            mstack.pop();
        }

        else
        {
            while (!mstack.empty() && prec(inp[i]) <= prec(mstack.top()))
            {
                ans += mstack.top();
                mstack.pop();
            }

            mstack.push(inp[i]);
        }
    }
    while (!mstack.empty())
    {

        ans += mstack.top();
        mstack.pop();
    }

    cout << ans;
}

int main()
{

    infix_to_postfix();
}