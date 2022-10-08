//
// Created by Rakan on 2022/9/26.
//

#ifndef NNU_DS_RAKAN_SEQSTACK_HPP
#define NNU_DS_RAKAN_SEQSTACK_HPP

#endif //NNU_DS_RAKAN_SEQSTACK_HPP

#include <iostream>
#include <string>

using namespace std;

template<class T>
class SeqStack {
protected:
    T data[10000];
    int top;
public:
    SeqStack();

    void Push(T x);

    T Pop();

    T Top();

    bool Empty();

    friend double Operate(double a, char op, double b);

    friend char Precede(char preop, char op);

    friend string ConvertI2P(string const &expression);

    friend double Infix(string const &expression);

    friend double Postfix(string const &expression);

};

#include "SeqStack.ipp"