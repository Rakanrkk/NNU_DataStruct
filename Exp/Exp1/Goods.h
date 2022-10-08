//
// Created by Rakan on 2022/9/24.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "SeqList.hpp"
#ifndef NNU_DS_RAKAN_GOODS_H
#define NNU_DS_RAKAN_GOODS_H

#endif //NNU_DS_RAKAN_GOODS_H

using namespace std;

class Goods;

class Good {
    string code = "";
    string name = "";
    float price = 0;
    int store = 0;
    friend Goods;
public:
    Good() {};

    Good(string code, string name, float price, int store);

    ~Good();

    bool operator<(const Good &other) const;

    Good &operator=(const Good &other);

    friend ostream &operator<<(ostream &out, const Good &item);

};

class Goods {
    SeqList<Good,10000> seqList;
public:
    friend ostream &operator<<(ostream &out, const Goods &item);

    int Locate(string code);

    void change(string code);

    void Delete(string code);

    void Sort();

    void menu();

};