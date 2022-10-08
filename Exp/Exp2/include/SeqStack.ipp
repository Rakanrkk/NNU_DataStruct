//
// Created by Rakan on 2022/9/26.
//

#ifndef NNU_DS_RAKAN_SEQSTACK_IPP
#define NNU_DS_RAKAN_SEQSTACK_IPP

#endif //NNU_DS_RAKAN_SEQSTACK_IPP


template<class T>
SeqStack<T>::SeqStack() {
    top = -1;
};


template<class T>
void SeqStack<T>::Push(T x) {
    data[top + 1] = x;
    top++;
}

template<class T>
T SeqStack<T>::Pop() {
    top--;
    return data[top + 1];
}

template<class T>
T SeqStack<T>::Top() {
    return data[top];
}

template<class T>
bool SeqStack<T>::Empty() {
    if (top == -1) return false;
    else return true;
}

char Precede(char preop, char op) {
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
            break;
    }
    return 0;
}

double Operate(double a, char op, double b) {
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
    return 0;
}

string ConvertI2P(const string &expression) {
    string result;
    SeqStack<char> OPTR;

    for (auto x: expression) {
        if (x > '0' && x < '9') {
            result += x;
        } else if (x == '(') {
            OPTR.Push(x);
        } else if (x == ')') {
            while (OPTR.Top() != '(') {
                result += OPTR.Pop();
            }
            OPTR.Pop();
        } else if (x == '@') {
            while (OPTR.Empty()) {
                result += OPTR.Pop();
            }
        } else {
            char preop = OPTR.Top();
            if (Precede(preop, x) == '<') {
                OPTR.Push(x);
            }else{

            }
        }
    }
    return result;
}

double Infix(const string &expression) {
    if (expression.empty()) {
        return 0.0;
    }
    SeqStack<char> OPRT;
    SeqStack<int> OPND;
    OPRT.Push('@');
    for (auto x: expression) {
        if (x > '0' && x < '9') {
            OPND.Push(x);
        } else {
            char pre_op = OPRT.Top();
            switch (Precede(pre_op, x)) {
                case '<': {
                    OPRT.Push(x);
                    break;
                }
                case '=': {
                    OPRT.Pop();
                    break;
                }
                case '>': {
                    double b = OPND.Pop();
                    double a = OPND.Pop();
                    pre_op = OPRT.Pop();
                    OPND.Push(Operate(a, pre_op, b));
                    break;
                }

            }
        }
    }
    return OPND.Top();
}

double Postfix(const string &expression) {
    if (expression.empty()) {
        return 0;
    }

    return 0;
}

