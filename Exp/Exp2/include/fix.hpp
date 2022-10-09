//
// Created by Charm on 2022/10/8.
//

#ifndef EXP2_FIX_HPP
#define EXP2_FIX_HPP

#endif //EXP2_FIX_HPP



class infix
{
    SeqStack<char> OPTR;
    SeqStack<int> OPND;
    static char CompareOp(char preop, char op);

    static bool IsNum(char c);
    static int Operate(int a, char op, int b);
public:
    int Solve(string prefix_expression);
    int SolveEnhanced(string prefix_expression);
    string ToSuffix(string prefix_expression);

};

class Suffix
{
    SeqStack<int> OPND;
    bool IsNum(char c);
    int Operator(int a, char op, int b);
public:
    int Solve(string s);
};






#include "fix.ipp"