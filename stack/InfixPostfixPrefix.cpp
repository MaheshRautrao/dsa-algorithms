#include <bits/stdc++.h>
using namespace std;

int precedence(char c)
{
    if (c == '^')
        return 3;
    if (c == '*' || c == '/')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    return 0;
}

bool isOperator(char c)
{
    return c == '*' || c == '/' || c == '+' || c == '-' || c == '^';
}

string infixToPostfix(string s)
{
    int n = s.length();
    string ans = "";
    stack<char> st;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '*' || s[i] == '/' || s[i] == '+' || s[i] == '-' || s[i] == '^')
        {

            while (!st.empty() && precedence(s[i]) <= precedence(st.top()))
            {
                ans.push_back(st.top());
                st.pop();
            }
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            while (st.top() != '(')
            {
                ans.push_back(st.top());
                st.pop();
            }
            st.pop();
        }
        else if (s[i] == '(')
            st.push(s[i]);
        else
        {
            ans.push_back(s[i]);
        }
    }

    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
}

string infixToPrefix(string s)
{
    int n = s.length();
    string ans = "";
    stack<char> st;

    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == '*' || s[i] == '/' || s[i] == '+' || s[i] == '-' || s[i] == '^')
        {

            while (!st.empty() && precedence(s[i]) < precedence(st.top()))
            {
                ans.push_back(st.top());
                st.pop();
            }
            st.push(s[i]);
        }
        else if (s[i] == '(')
        {
            while (st.top() != ')')
            {
                ans.push_back(st.top());
                st.pop();
            }
            st.pop();
        }
        else if (s[i] == ')')
            st.push(s[i]);
        else
        {
            ans.push_back(s[i]);
        }
    }

    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

string postfixToInfix(string s)
{
    int n = s.length();
    stack<string> st;

    for (int i = 0; i < n; i++)
    {
        if (!isOperator(s[i]))
        {
            st.push(string(1, s[i]));
        }
        else
        {
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();

            string t = "(" + op2 + s[i] + op1 + ")";
            st.push(t);
        }
    }
    return st.top();
}

string postfixToPrefix(string s)
{
    int n = s.length();
    stack<string> st;

    for (int i = 0; i < n; i++)
    {
        if (!isOperator(s[i]))
        {
            st.push(string(1, s[i]));
        }
        else
        {
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();

            string t = s[i] + op1 + op2;
            st.push(t);
        }
    }

    return st.top();
}

string prefixToInfix(string s)
{
    int n = s.length();
    stack<string> st;
    string temp = "";

    for (int i = n - 1; i >= 0; i--)
    {
        if (!isOperator(s[i]))
        {
            st.push(string(1, s[i]));
        }
        else
        {
            string op2 = st.top();
            st.pop();
            string op1 = st.top();
            st.pop();

            string t = "(" + op2 + s[i] + op1 + ")";
            st.push(t);
        }
    }

    return st.top();
}

string prefixToPostfix(string s)
{
    int n = s.length();
    stack<string> st;

    for (int i = n - 1; i >= 0; i--)
    {
        if (!isOperator(s[i]))
        {
            st.push(string(1, s[i]));
        }
        else
        {
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();
            string t = op1 + op2 + s[i];
            st.push(t);
        }
    }

    return st.top();
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string exp;
    cin >> exp;

    // string one = infixToPostfix(exp);
    string two = infixToPrefix(exp);
    //    string three = postfixToInfix(exp);
    //    string four = postfixToPrefix(exp);
    //    string fifth = prefixToInfix(exp);
    //    string sixth = prefixToPostfix(exp);

    // cout << one << endl;
    cout << two << endl;
    //    cout<<three<<endl;
    //    cout<<four<<endl;
    //    cout<<fifth<<endl;
    //    cout<<sixth<<endl;

    return 0;
}
