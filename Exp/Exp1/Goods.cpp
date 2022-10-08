//
// Created by Rakan on 2022/9/25.
//
#include "Goods.h"

bool Good::operator<(const Good &other) const {
    return false;
}

Good::Good(string code, string name, float price, int store)
    :code(code), name(name), price(price), store(store) {}

Good &Good::operator=(const Good &other) {
    name = other.name;
    code = other.code;
    price = other.price;
    store = other.store;
    return *this;
}

ostream &operator<<(ostream &out, const Good &item) {
    out << "code:" << item.code << " name:" << item.name << "price:" << item.price << "store:" << item.store
        << endl;
    return out;
};


ostream &operator<<(ostream &out, const Goods &item) {
    out << item << endl;
    return out;
}

int Goods::Locate(string code) {
    for(int i=0; i < seqList.ListLength(); i++)
        if (seqList[i].code == code)
            return i;
    return -1;
}

void Goods::change(string code) {
    if (Locate(code) == -1) {
        string name;
        int store;
        float price;
        cout << "name price store" << endl;
        cin >> name >> price >> store;
        Good temp(code, name, price, store);
        seqList.Insert(seqList.ListLength(), temp);
    } else {
        int delta;
        cout << "delta" << endl;
        cin >> delta;
        seqList[Locate(code)].store += delta;
    }
}

void Goods::Delete(string code) {
    if (Locate(code) != -1) {
        seqList.DeleteIndex(Locate(code));
    }
}

void Goods::Sort() {
    seqList.Sort();
}

void Goods::menu() {
    int op;
    cout << "1.显示 2.修改库存(code) 3.删除记录(code) 4.排序" << endl;
    cin >> op;
    string temp;
    switch (op) {
        case 1:
            cout << seqList << endl;
            break;
        case 2:
            cin >> temp;
            change(temp);
            break;
        case 3:
            cin >> temp;
            Delete(temp);
            break;
        case 4:
            Sort();
            break;
    }
    menu();
}
