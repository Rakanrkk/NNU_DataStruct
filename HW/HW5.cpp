//
// Created by Charm on 2022/10/17.
//
/***
 * @Date: 2022-09-20 18:04:16
 * @LastEditors: Shujakuinkuraudo zhouyunyao1@gmail.com
 * @LastEditTime: 2022-09-26 09:48:51
 * @FilePath: /DSM/HW/HW2/main.cpp
 */
#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;


void GetNext(string t, int *next) {
    int n = t.length();
    next[0] = -1;
    int i = 0, j = -1;
    while (i < n) {
        if (j == -1 || t[i] == t[j]) {
            ++i, ++j;
            next[i] = j;
        } else {
            j = next[j];
        }
    }
}

int KMPMatch(const string &s, const string &t) {
    int n = s.length(), m = t.length();
    int i = -1, j = 0, times = 0;
    int next[m + 1];
    GetNext(t, next);
    while (i < n) {
        j = -1;
        while (i < n && j < m) {
            if (j == -1 || s[i] == t[j]) {
                i++;
                j++;
            } else {
                j = next[j];
            }
        }
        if (j >= m) {
            times++;
            i--;

        }
    }
    return times;
}

string KMPDel(string s, const string &t) {
    int n = s.length(), m = t.length();
    int i = -1, j = 0;
    int next[m + 1];
    GetNext(t, next);
    while (i < n) {
        j = -1;
        while (i < n && j < m) {
            if (j == -1 || s[i] == t[j]) {
                i++;
                j++;
            } else {
                j = next[j];
            }
        }
        if (j >= m) {
            for (int k = i - j; k < i; k++) {
                s[k] = 0;
            }
            i--;
        }
    }
    int head = -1, index = 0;
    while (++head < n) {
        if (s[head])
            s[index++] = s[head];
    }
    while (index < n)
        s[index++] = 0;
    return s;
}

pair<int, int> KMPMaxMatch(const string &s, const string &t) {
    int n = s.length(), m = t.length();
    int i = -1, j = -1, len = 0, start_index = -1;
    int next[m + 1];
    GetNext(t, next);
    while (i < n && j < m) {
        if (j == -1 || s[i] == t[j]) {
            i++;
            j++;
            if (j > len) {
                len = j;
                start_index = i - j;
            }
        } else {
            j = next[j];
        }
    }
    return make_pair(len, start_index);
}

string InvertString(string s) {
    int n = s.length();
    for (int i = 0; i < n / 2; i++)
        swap(s[i], s[n - 1 - i]);
    int start_index = -1;
    int i = 0;
    for (; i < n; i++) {
        if (s[i] != ' ') {
            start_index = i;
            break;
        }
        for (; i < n; i++)
            if (s[i] == ' ') {
                for (int j = 0; j < i - start_index >> 1; j++)
                    swap(s[start_index + j], s[i - 1 - j]);
                start_index = i + 1;
            }
    }
    for (int j = 0; j < i - start_index >> 1; j++)
        swap(s[start_index + j], s[i - 1 - j]);
    return s;
}

template<class T>
vector<pair<int, int>> SaddlePoint(vector<vector<T>> data) {
    vector<pair<int, int>> ans;
    int m = data.size(), n = data[0].size();
    T row_min[m], col_max[n];

    for (int x = 0; x < m; x++)
        row_min[x] = data[x][0];

    for (int x = 0; x < m; x++)
        for (int y = 0; y < n; y++)
            row_min[x] = min(row_min[x], data[x][y]);

    for (int y = 0; y < n; y++)
        col_max[y] = data[0][y];

    for (int y = 0; y < n; y++)
        for (int x = 0; x < m; x++)
            col_max[y] = max(col_max[y], data[x][y]);

    for (int x = 0; x < m; x++)
        for (int y = 0; y < n; y++)
            if (data[x][y] == row_min[x] && data[x][y] == col_max[y])
                ans.emplace_back(x, y);

    return ans;
}

template<class T>
struct MatrixTriple;

template<class T>
T AddDiagTriple(MatrixTriple<T> &data) {
    T ans = 0;
    for (int i = 0; i < data.size(); i++) {
        if (data[i].x == data[i].y)
            ans += data[i].data;
    }
    return ans;

}


int main() {
    int next[100];
    char *s[7] = {"ABCDEFG", "AAAAAAAA", "BABBABAB", "AAAAAAB", "ABCABDAAABC", "ABCABDABEABCABDABF", "ABBACXY"};
    for (auto X: s) {
        int l = strlen(X);
        GetNext(X, next);
        cout << X << " ";
        for (int i = 0; i < l; i++) {
            cout << next[i] << " ";
        }
        cout << endl;
    }
    //string s = "Do    or do not, there is no try.    ", t = "a";
    //cout << KMPDel(s,t);
    //cout << InvertString(s);
    //pair<int,int> lenAndStart = KMPMaxMatch(s,t);
    //_for(i,0,lenAndStart.first)
    //{
    //cout << s[lenAndStart.second+i];
    //}

    return 0;
}
