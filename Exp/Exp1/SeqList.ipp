
#include "SeqList.hpp"

template<class T, int Maxsize>
SeqList<T, Maxsize>::SeqList() {
    length = 0;
}

template<class T, int Maxsize>
SeqList<T, Maxsize>::SeqList(T *a, int n) {
    if (n > Maxsize) {
        cerr << "OverFlow";
        exit(1);
    }
    for (int i = 0; i < n; ++i) {
        data[i] = a[i];
    }
    length = n;
}

template<class T, int Maxsize>
int SeqList<T, Maxsize>::ListLength() {
    return length;
}

template<class T, int Maxsize>
T SeqList<T, Maxsize>::Get(int pos) {
    if (pos < 1 || pos > length) {
        cerr << "overflow";
        exit(1);
    }
    return data[pos - 1];
}

template<class T, int Maxsize>
int SeqList<T, Maxsize>::Locate(T item) {
    for (int i = 0; i < length; ++i) {
        if (data[i] == item) {
            return i + 1;
        }
    }
    return 0;
}

template<class T, int Maxsize>
void SeqList<T, Maxsize>::PrintSeqList() {
    for (int i=0;i<length;i++) {
        cout<<data[i]<<' ';
    }
}

template<class T, int Maxsize>
void SeqList<T, Maxsize>::Insert(int i, T item)
{
    if (i < 0 || i > length)
    {
        cerr << "越界";
        exit(1);
    }
    if (length >= Maxsize - 2)
    {
        cerr << "越界";
        exit(1);
    }
    else
    {
        for (int j = length; j > i; j--)
            data[j] = data[j- 1];
        data[i] = item;
    }
    length += 1;
}

template<class T, int Maxsize>
T SeqList<T, Maxsize>::DeleteIndex(int i) {
    T x=data[i-1];
    for (int j = i; j < length; ++j) {
        data[j]=data[j+1];
    }
    return x;
}

template<class T, int Maxsize>
void SeqList<T, Maxsize>::menu() {
    cout << "选择功能 \n 1.插入(index,item) 2.获取(index) 3.查找(item) 4.序数(index) 5.删除(index) 6.显示" << endl;
    int op;
    cin>>op;
    int index;
    T item;
    switch (op) {
        case 1:
            cin >> index >> item;
            Insert(index, item);
            break;
        case 2:
            cin >> index;
            Get(index);
            break;
        case 3:
            cin >> index;
            cout << Locate(index);
            break;
        case 4:
            cin >> index;
            cout << (*this)[index];
            break;
        case 5:
            cin >> index;
            DeleteIndex(index);
            break;
        case 6:
            cout << *this;
            break;
        default:
            break;
    }
}

template<class T, int Maxsize>
T &SeqList<T, Maxsize>::operator[](int index) {
    if (index < 0 || index > length)
    {
        cerr << "越界";
        exit(1);
    }
    return data[index];
}

template<class T, int Maxsize>
void SeqList<T, Maxsize>::Sort() {
    for (int i = 1; i < length; i++) {
        //cout << i << endl;
        T key = data[i];
        int j = i - 1;
        while ((j >= 0) && (key < data[j])) {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = key;
    }
}

template<class T, int Maxsize>
SeqList<T> SeqList<T, Maxsize>::Merge(const SeqList &a, const SeqList &b) {
    SeqList c;
    int i=0,j=0,k=0;
    while(i<a.length &&j<b.length)
    {
        if (a.data[i]<b.data[j]){
            c.data[k]=a.data[i];
            i++;k++;
        }else{
            c.data[k]=b.data[i];
            j++;k++;
        }
    }
    while(i<a.length){
        c.data[k]=a.data[i];
        i++;k++;
    }
    while(j<b.length){
        c.data[k]=b.data[j];
        j++;k++;
    }

    return c;
}

template<class T, int Maxsize>
void SeqList<T, Maxsize>::Add(int i) {
    if(length>Maxsize-2){
        cerr<<"full";
        exit(1);
    }
    length++;
    data[length]=i;
}

ostream &operator<<(ostream &out, const SeqList &s) {
    for (auto x: s.data) {
        out << x << ' ';
    }
    return out;
}
