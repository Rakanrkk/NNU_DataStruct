//
// Created by Charm on 2022/10/8.
//

#ifndef EXP2_FIX_IPP
#define EXP2_FIX_IPP

#endif //EXP2_FIX_IPP

char infix::CompareOp(char preop, char op)
{
    switch (preop) {
        case '+': {
            switch (op) {
                case '+':
                    return '>';
                case '-':
                    return '>';
                case '*':
                    return '<';
                case '/':
                    return '<';
                case '=':
                    return '=';
                case ')':
                    return '>';
                case '@':
                    return '>';
            }
            break;
        }
        case '-': {
            switch (op) {
                case '+':
                    return '>';
                case '-':
                    return '>';
                case '*':
                    return '<';
                case '/':
                    return '<';
                case '(':
                    return '<';
                case ')':
                    return '>';
                case '@':
                    return '>';
            }
            break;
        }
        case '*': {
            switch (op) {
                case '+':
                    return '>';
                case '-':
                    return '>';
                case '*':
                    return '>';
                case '/':
                    return '>';
                case '(':
                    return '<';
                case ')':
                    return '>';
                case '@':
                    return '>';
            }
            break;
        }
        case '/': {
            switch (op) {
                case '+':
                    return '>';
                case '-':
                    return '>';
                case '*':
                    return '<';
                case '/':
                    return '<';
                case '(':
                    return '<';
                case ')':
                    return '>';
                case '@':
                    return '>';
            }
            break;
        }
        case '(': {
            switch (op) {
                case '+':
                    return '<';
                case '-':
                    return '<';
                case '*':
                    return '<';
                case '/':
                    return '<';
                case '(':
                    return '<';
                case ')':
                    return '=';
            }
            break;
        }
        case ')': {
            switch (op) {
                case '+':
                    return '>';
                case '-':
                    return '>';
                case '*':
                    return '>';
                case '/':
                    return '>';
                case ')':
                    return '>';
                case '@':
                    return '>';
            }
            break;
        }
        case '@': {
            switch (op) {
                case '+':
                    return '<';
                case '-':
                    return '<';
                case '*':
                    return '<';
                case '/':
                    return '<';
                case '(':
                    return '<';
                case '@':
                    return '=';
            }
            break;
        }
    }
    return 0;
}

bool infix::IsNum(char c) {
    if (c <= '9' && c >= '0')
        return true;
    return false;
}

int infix::Operate(int a, char op, int b) {
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
    }
    cerr << "operator error" << endl;
    exit(1);
}

int infix::Solve(string prefix_expression) {
    OPTR.Push('@');
    for (int i = 0; i < prefix_expression.length(); i++) {
        char c = prefix_expression[i];
        if (IsNum(c))
            OPND.Push(c - '0');
        else {
            if (c == ' ')
                continue;
            switch (CompareOp(OPTR.Top(), c)) {
                case '<':
                    OPTR.Push(c);
                    break;
                case '=':
                    OPTR.Pop();
                    break;
                case '>':
                    int b = OPND.Pop();
                    int a = OPND.Pop();
                    char op = OPTR.Pop();
                    OPND.Push(Operate(a, op, b));
                    i--;
            }
        }
    }
    return OPND.Top();
}

int infix::SolveEnhanced(string prefix_expression) {
    OPTR.Push('@');
    for (int i = 0; i < prefix_expression.length(); i++) {
        char c = prefix_expression[i];
        if (IsNum(c)) {
            int t = c - '0';
            while (IsNum(prefix_expression[++i])) {
                t *= 10;
                t += prefix_expression[i] - '0';
            }
            i--;
            OPND.Push(t);
        } else {
            if (c == ' ')
                continue;
            switch (CompareOp(OPTR.Top(), c)) {
                case '<':
                    OPTR.Push(c);
                    break;
                case '=':
                    OPTR.Pop();
                    break;
                case '>':
                    int b = OPND.Pop();
                    int a = OPND.Pop();
                    char op = OPTR.Pop();
                    OPND.Push(Operate(a, op, b));
                    i--;
            }
        }
    }
    return OPND.Top();
}

string infix::ToSuffix(string prefix_expression) {
    string suffix = "";
    OPTR.Push('@');
    for (int i = 0; i < prefix_expression.length(); i++) {
        char c = prefix_expression[i];
        if (c == '@') {
            while (!OPTR.Empty())
                suffix += OPTR.Pop();
        } else if (IsNum(c)) { suffix += c; }
        else if (c == '(')
            OPTR.Push(c);
        else if (c == ')') {
            while (OPTR.Top() != '(') { suffix += OPTR.Pop(); }
            OPTR.Pop();
        } else {
            switch (CompareOp(OPTR.Top(), c)) {
                case '<':
                    OPTR.Push(c);
                    break;
                case '>':
                case '=':
                    suffix += OPTR.Pop();
                    i--;
            }
        }
    }
    return suffix;

}

bool Suffix::IsNum(char c)
{
    if (c <= '9' && c >= '0')
        return true;
    return false;
}
int Suffix::Operator(int a, char op, int b)
{
    switch (op)
    {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
    }
    cerr << "operator error" << endl;
    exit(1);
}
int Suffix::Solve(string s)
{
    for(int i=0;i<s.length();i++)
    {
        char c = s[i];
        if(IsNum(c))
        {
            OPND.Push(c-'0');
        }
        else if (c=='@')
            return OPND.Top();
        else
        {
            int b = OPND.Pop();
            int a = OPND.Pop();
            OPND.Push(Operator(a,c,b));
        }
    }
    exit(1);
}
