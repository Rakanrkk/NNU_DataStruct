//
// Created by Rakan on 2022/9/20.
//
#include <iostream>

using namespace std;

template<class T, int Maxsize=10000>
class SeqList {
protected:
    T data[Maxsize];
    int length;
public:
    SeqList();

    SeqList(T a[], int n);

    int ListLength();

    T Get(int pos);

    int Locate(T item);

    void PrintSeqList();

    void Insert(int i, T item);

    T DeleteIndex(int i);

    void menu();

    T &operator[](int index);

    void Sort();

    SeqList<T> Merge(const SeqList &a, const SeqList &b);

    void Add(int i);

    friend ostream &operator<<(ostream &out, const SeqList &s);


};
