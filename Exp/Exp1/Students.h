//
// Created by Rakan on 2022/9/24.
//

#ifndef NNU_DS_RAKAN_STUDENTS_H
#define NNU_DS_RAKAN_STUDENTS_H

#endif //NNU_DS_RAKAN_STUDENTS_H

#include <iostream>
#include "LinkList.hpp"
using namespace std;



class Students;
class Student
{
    string name;
    string code;
    string major;
    string birthday;
    bool sex;
public:
    Student();
    Student(const Student& other);
    Student(string name,string code,string major,string birthday,bool sex);
    Student& operator =(const Student& another);
    string key() const;
    friend istream& operator>>(istream& in,Student& s);
    friend ostream& operator<<(ostream& out,const Student& s);
    friend Students;
};

class Students
{
    LinkList<Student> data;
public:
    Students();
    Students(Student arr[],int n);
    void Create(string name,string code,string major,string birthday,bool sex);
    void Create();
    int Query(string code);
    Student Delete(int index);
    void Modify(int index);
    void Menu();
};

