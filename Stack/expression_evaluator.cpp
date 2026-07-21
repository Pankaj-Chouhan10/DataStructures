// Expression Evaluator (Stack)

// Concepts used:
// * Stack
// * Infix → Postfix conversion
// * Parsing strings
// Features:
// * Take a mathematical expression from the user
// * Convert infix to postfix (using stack)
// * Evaluate postfix to produce result
// * Handle brackets and operator precedence
// * Display steps for learning purpose
// Example:
// Input: (3 + 4) * 2 → converts to 3 4 + 2 * → evaluates to 14

#include "iostream"
#include "stack"
#include "vector"
using namespace std;

class ExpressionSolver
{

public:
    int precedence(const string &op)
    {

        // Returns operator precedence for +, -, *, and /.

        if (op == "+" || op == "-")
            return 1;
        else if (op == "*" || op == "/")
            return 2;
        else
            return 0;
    }

    string charToString(char &ch)
    {
        string op(1, ch);
        return op;
    }

    bool isOperator(string ch)
    {
        return ch == "+" || ch == "*" || ch == "-" || ch == "/" || ch == "(" || ch == ")";
    }

    string extractNumber(string &str, int &start, int end = -1)
    {

        if (end == -1)
            end = str.size();
        string number = "";

        while (start < end && (str[start] >= '0' && str[start] <= '9'))
        {
            number += str[start++];
        }

        return number;
    }

    vector<string> tokenize(string &expression)
    {
        vector<string> tokens;
        int length = expression.size();
        for (int i = 0; i < length; i++)
        {

            if (expression[i] == ' ')
            {
                continue;
            }
            else if (isOperator(charToString(expression[i])))
            {
                tokens.push_back(charToString(expression[i]));
            }
            else
            {
                tokens.push_back(extractNumber(expression, i));
                i--;
            }
        }
        return tokens;

    }
    int applyOperation(int a, int b, string op)
    {
        char sym = op[0];
        switch (sym)
        {
        case '+':
            return a + b;
            break;
        case '-':
            return a - b;
            break;
        case '*':
            return (a * b);
            break;
        default:
            return (a / b);
            break;
        }
        return 0;
    }

    int parseInteger(string numberString)
    {
        int number = 0;
        for (char i : numberString)
        {
            number = number * 10 + (i - '0');
        }
        return number;
    }

    int evaluateExpression(string expression)
    {

        stack<int> st;
        string postfix = infixToPostfix(expression);

        vector<string> tokens = tokenize(postfix);

        for (string &token : tokens)
        {

            if (isOperator(token))
            {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();

                st.push(applyOperation(a, b, token));
            }
            else
            {
                st.push(parseInteger(token));
            }
        }

        return st.top();
    }

    string infixToPostfix(string expression)
    {
        stack<string> st;
        vector<string> tokens = tokenize(expression);

        string postfix = "";

        for (string &token : tokens)
        {

            if (isOperator(token))
            {
                if (token == "(")
                {
                    st.push(token);
                    continue;
                }
                else if (token == ")")
                {

                    while (!st.empty() && st.top() != "(")
                    {
                        postfix += (st.top() + ' ');
                        st.pop();
                    }
                    st.pop();
                }
                else
                {

                    if (!st.empty() && st.top() != "(" && precedence(st.top()) >= precedence(token))
                    {

                        while (!st.empty() && st.top() != "(" && precedence(st.top()) >= precedence(token))
                        {
                            postfix += (st.top() + ' ');
                            st.pop();
                        }
                    }
                    st.push(token);
                }
            }

            else
            {
                postfix += (token + ' ');
            }
        }

        while (!st.empty())
        {
            if (st.top() == "(")
                break;
            postfix += (st.top() + ' ');
            st.pop();
        }

        return postfix;
    }
};

int main()
{

    ExpressionSolver solver;
    string expression;
    
    cout<<"Enter the Expression : ";
    
    getline(cin,expression);


    cout<<"Given expression : "<<expression<<'\n';

    cout<<"Post Fix for the given expression : "<<solver.infixToPostfix(expression)<<'\n';

    cout << "Result of the given expression : " <<solver.evaluateExpression(expression)<<'\n';

    return 0;
}
