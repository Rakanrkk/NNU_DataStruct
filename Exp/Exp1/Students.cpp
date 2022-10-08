//
// Created by Rakan on 2022/9/26.
//

#include "Students.h"

Student::Student() = default;

Student::Student(string name, string code, string major, string birthday, bool sex) :
        name(name), code(code), major(major), birthday(birthday), sex(sex) {}

Student &Student::operator=(const Student &another) = default;

string Student::key() const {
    return code;
}

istream &operator>>(istream &in, Student &s) {
    cout << "name code major birthday sex" << endl;
    in >>s.name >> s.code >> s.major >> s.birthday >> s.sex;
    return in;
}

ostream &operator<<(ostream &out, const Student &s) {
    out << s.name << " " << s.code <<" "<<s.major << " "<<s.birthday << " "<<s.sex << endl;
    return out;

}

Student::Student(const Student &other) = default;


Students::Students(Student arr[], int n) {
    for (int i = 0; i < n; i++)
        data.Insert(0, arr[i]);
}

void Students::Create(string name, string code, string major, string birthday, bool sex) {
    data.Insert(0, Student(name, code, major, birthday, sex));
}

void Students::Create() {
    Student temp;
    cin >> temp;
    data.Insert(0, temp);
}

int Students::Query(string code) {
    int l = data.ListLength();
    for (int i = 0; i < l; i++) {
        if (data[i].key() == code)
            return i;
    }
    return -1;
}

Student Students::Delete(int index) {
    return data.Delete(index);
}

void Students::Modify(int index) {
    Student &obj = data[index];
    cout << "1.name 2.code 3.major 4.birthday 5.sex" << endl;
    int op;
    cin >> op;
    string s_temp;
    bool b_temp;
    switch (op) {
        case 1:
            cin >> obj.name;
            break;
        case 2:
            cin >> obj.code;
            break;
        case 3:
            cin >> obj.major;
            break;
        case 4:
            cin >> obj.birthday;
            break;
        case 5:
            cin >> obj.sex;
            break;
    }
}

void Students::Menu() {
    cout << "1.增加 2.查询(学号) 3.删除(序号) 4.修改(序号) 5.显示" << endl;
    int op;
    cin >> op;
    string s_temp;
    int i_temp;
    switch (op) {
        case 1:
            Create();
            break;
        case 2:
            cin >> s_temp;
            cout << data[Query(s_temp)];
            break;
        case 3:
            cin >> i_temp;
            cout << Delete(i_temp);
            break;
        case 4:
            cin >> i_temp;
            Modify(i_temp);
            break;
        case 5:
            cout << data;
            break;
    }
    Menu();
}

Students::Students() = default;
