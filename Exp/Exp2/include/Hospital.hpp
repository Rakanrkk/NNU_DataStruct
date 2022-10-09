//
// Created by Rakan on 2022/10/10.
//

#ifndef NNU_DS_RAKAN_HOSPITAL_HPP
#define NNU_DS_RAKAN_HOSPITAL_HPP
#endif //NNU_DS_RAKAN_HOSPITAL_HPP

#include <iostream>
#include <string>
#include <SeqQueue.hpp>

using namespace std;

class Case
{
    int code;
        string name;
        public:
    Case(string name=""):name(name)
    {
        code = e();
    }
    friend ostream& operator<<(ostream& out,const Case& c)
    {
        out << c.code;
        return out;
    }
    friend istream& operator>>(istream& in,Case& c)
    {
        cout << "Your name:" << endl;
        in >> c.name;
        return in;
    }
};
class Hospital
{
    SeqQueue<Case> q;
    public:
    void Queue()
    {
        Case c;
        cin >> c;
        q.EnQueue(c);
    }
    void Treat()
    {
        q.DeQueue();
    }
    void Show()
    {
        q.Show();
    }
    void Menu()
    {
        cout << "排队:1 就诊:2 查看:3 下班:4" << endl;
        int op;
        cin >> op;
        switch(op)
        {
            case 1:
                Queue();
                break;
            case 2:
                Treat();
                break;
            case 3:
                Show();
                break;
            case 4:
                return;
        }
        Menu();
    }
    
};