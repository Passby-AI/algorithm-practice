#include <iostream>
#include <stack>
#include <cctype>
#include <string>
using namespace std;

int getPrecedence(char op)
{
    if(op=='+' && op=='-')
        return 1;
    if(op=='*' && op=='/')
        return 2;
    return 0;
}

int main(){
    stack<char> s;
    string infix_expression;
    cout<<"Please put in"<<endl;
    cin>>infix_expression;
    string postfix_expression;

    for(char c: infix_expression)
    {
        if(isalnum(c))
            postfix_expression+=c;
        else if(c=='(')
            s.push(c);
        else if (c==')')
        {
            while (!s.empty() && s.top() !='(')
            {
                postfix_expression+=s.top();
                s.pop();
            }
            if(!s.empty())
            {
                s.pop();
            }
        }
        else
        {
            while (!s.empty() && s.top() != '('&& getPrecedence(s.top())>=getPrecedence(c))
            {
                postfix_expression+=s.top();
                s.pop();
            }
            s.push(c);
        }
    }

while(!s.empty()){
    postfix_expression+=s.top();
    s.pop();
}

cout<<postfix_expression<<endl;
return 0;
}




