//
// Created by Rakan on 2022/9/23.
//

#ifndef NNU_DS_RAKAN_LINKLIST_HPP
#define NNU_DS_RAKAN_LINKLIST_HPP

#endif //NNU_DS_RAKAN_LINKLIST_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <fstream>

using namespace std;

template<class T>
class Node {
public:
    T data;
    Node<T> *next = nullptr;

    Node() = default;

    Node(T data) : data(data) {};
};

template<class T>
class LinkList {
protected:
    Node<T> *head = new Node<T>;
    int length = 0;
public:
    LinkList();

    LinkList(T a[], int n);

    ~LinkList();

    int ListLength() const;

    T &Get(int index);

    T &operator[](int index);

    int Locate(T item);

    void Insert(int index, T item);

    T Delete(int index);

    void Reverse();

    void Menu();

    friend ostream &operator<<(ostream &out, const LinkList<T> &L);

    friend void Merge(LinkList<T> &l1, const LinkList<T> &l2);
};