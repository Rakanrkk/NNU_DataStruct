//
// Created by Rakan on 2022/9/26.
//

#ifndef NNU_DS_RAKAN_SEQQUEUE_HPP
#define NNU_DS_RAKAN_SEQQUEUE_HPP

#endif //NNU_DS_RAKAN_SEQQUEUE_HPP

#include <iostream>
#include <string>

using namespace std;

template <class T>
class SeqQueue
{
    T *data;
    int front, rear;
    int max_size;

public:
    SeqQueue();
    void EnQueue(T x);
    T DeQueue();
    T GetQueue();
    bool Empty();
    int Length() const;
    void Show();
};



#include "SeqQueue.ipp"