//
// Created by Rakan on 2022/9/26.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include "../Exp/Exp1/SeqList.hpp"
#include "../Exp/Exp1/LinkList.hpp"

using namespace std;

class SeqList_int : public SeqList<int, 1000> {
public:
    int DeleteMin() {
        if (length == 0) {
            cerr << "empty_SeqList";
            exit(1);
        } else {
            int min = data[0];
            int index = 0;
            for (int i = 1; i < length; i++) {
                if (data[i] < min) {
                    min = data[i];
                    index = i;
                }
            }
            data[index] = data[length - 1];
            length--;
            return min;
        }
    }

    void DeleteX(int x) {
        if (length == 0) {
            cerr << "empty_SeqList";
            exit(1);
        } else {
            for (int i = 0; i < length; ++i) {
                if (data[i] == x) {
                    DeleteIndex(i);
                }
            }
        }
    }

    void DeleteS2T(int s, int t) {
        if (length == 0) {
            cerr << "empty_SeqList";
            exit(1);
        } else {
            for (int i = 0; i < length; ++i) {
                if (data[i] > s && data[i] < t) {
                    DeleteIndex(i);
                }
            }
        }
    }

    void Deduplication() {
        for (int i = 0; i < length; ++i) {
            for (int j = i + 1; j < length; ++j) {
                if (data[i] == data[j]) {
                    DeleteIndex(j);
                }
            }
        }
    }

};


class LinkList_int : public LinkList<int> {
public:

    //a、b为空链表
    friend void ParitySeparation(LinkList_int &a, LinkList_int &b, LinkList_int &c) {
        auto ahead = c.head;
        int index_a = 0, index_b = 0;
        while (ahead->next) {
            ahead = ahead->next;
            if (ahead->data % 2 == 0) {
                a.Insert(index_a, ahead->data);
                index_a++;
            } else {
                b.Insert(index_b, ahead->data);
                index_b++;
            }
        }
    }

    void OrderedInsertion(int x) {
        auto ahead = head;
        while (ahead->next) {
            ahead = ahead->next;
            if (ahead->next->data >= x) {
                auto *temp = new Node<int>(x);
                temp->next = ahead->next;
                ahead->next = temp;
                length++;
            }
        }
    }

    void CopyTo(LinkList_int &target) {
        int index = 0;
        auto ahead = head;
        while (ahead->next) {
            ahead = ahead->next;
            target.Insert(index, ahead->data);
            index++;
        }
    }

    void OrderedPrint() {
        vector<int> seq;
        int index=0;
        auto ahead = head;
        while (ahead->next) {
            ahead = head->next;
            seq[index++] = ahead->data;
        }
        for (int i = 1; i < seq.size(); i++) {
            //cout << i << endl;
            int key = seq[i];
            int j = i - 1;
            while ((j >= 0) && (key < seq[j])) {
                seq[j + 1] = seq[j];
                j--;
            }
            seq[j + 1] = key;
        }
        for(auto x:seq){
            cout<<x<<' ';
        }
    }

};

int main() {


    return 0;
}