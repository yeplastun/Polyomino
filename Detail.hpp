#include <vector>
#include <algorithm>
#include <iostream>
#include <utility>

using std::vector;
using std::pair;
using std::swap;
using std::find;
using std::cout;
using std::endl;

/* ----------
 
 (i + j) % 2 == 0
 (i + j) % 2 == 1
 1 - white
 0 - black
 
 ---------- */

class Detail {
private:
    vector<pair<int, int> > data;
    int num;
    int height;
    int length;
    bool color;
    int before;
    int after;
public:
    friend class Deck;
    Detail() {
        num = 0;
        height = 0;
        length = 0;
        color = 0;
    };
    ~Detail() {
        data.clear();
    };
    void AddPoint(const int x, const int y);
    void Turn();
    void Reflect();
    void Make(int number);
    void Print();
};

void Detail::AddPoint(const int x, const int y) {
    pair<int, int> p;
    p.first = x;
    p.second = y;
    data.push_back(p);
}

void Detail::Turn() {
    for (int i = 0; i < data.size(); ++i) {
        data[i].first = height - 1 - data[i].first;
        swap(data[i].first, data[i].second);
    }
    if (height % 2 == 0)
        color = !color;
    swap (height, length);
}

void Detail::Reflect() {
    for (int i = 0; i < data.size(); ++i)
        data[i].second = length - data[i].second - 1;
    if (length % 2 == 0)
        color = !color;
}

void Detail::Make(int number) {
    switch (number)
    {
        case 1:
            color = 0;
            num = 1;
            height = 3;
            length = 3;
            before = 0;
            after = -1;
            AddPoint(0, 1);
            AddPoint(1, 0);
            AddPoint(1, 1);
            AddPoint(1, 2);
            AddPoint(2, 1);
            break;
        case 2:
            color = 0;
            num = 2;
            height = 1;
            length = 5;
            before = 1;
            after = -1;
            AddPoint(0, 0);
            AddPoint(0, 1);
            AddPoint(0, 2);
            AddPoint(0, 3);
            AddPoint(0, 4);
            break;
        case 3:
            color = 1;
            num = 3;
            height = 2;
            length = 2;
            before = 1;
            after = -1;
            AddPoint(0, 0);
            AddPoint(0, 1);
            AddPoint(1, 0);
            AddPoint(1, 1);
            break;
        case 4:
            color = 1;
            num = 4;
            height = 3;
            length = 3;
            before = 3;
            after = -1;
            AddPoint(0, 0);
            AddPoint(0, 1);
            AddPoint(0, 2);
            AddPoint(1, 0);
            AddPoint(2, 0);
            break;
        case 5:
            color = 1;
            num = 5;
            height = 3;
            length = 3;
            before = 1;
            after = 1;
            AddPoint(0, 0);
            AddPoint(0, 1);
            AddPoint(1, 1);
            AddPoint(2, 1);
            AddPoint(2, 2);
            break;
        case 6:
            color = 0;
            num = 6;
            height = 3;
            length = 3;
            before = 3;
            after = -1;
            AddPoint(0, 0);
            AddPoint(1, 0);
            AddPoint(1, 1);
            AddPoint(1, 2);
            AddPoint(2, 0);
            break;
        case 7:
            color = 0;
            num = 7;
            height = 3;
            length = 3;
            before = 3;
            after = -1;
            AddPoint(0, 1);
            AddPoint(0, 2);
            AddPoint(1, 0);
            AddPoint(1, 1);
            AddPoint(2, 0);
            break;
        case 8:
            color = 1;
            num = 8;
            height = 2;
            length = 3;
            before = 3;
            after = -1;
            AddPoint(0, 0);
            AddPoint(0, 1);
            AddPoint(0, 2);
            AddPoint(1, 0);
            AddPoint(1, 2);
            break;
        case 9:
            color = 0;
            num = 9;
            height = 4;
            length = 2;
            before = 3;
            after = 3;
            AddPoint(0, 0);
            AddPoint(1, 0);
            AddPoint(2, 0);
            AddPoint(2, 1);
            AddPoint(3, 0);
            break;
        case 10:
            color = 1;
            num = 10;
            height = 4;
            length = 2;
            before = 3;
            after = 3;
            AddPoint(0, 0);
            AddPoint(1, 0);
            AddPoint(2, 0);
            AddPoint(3, 0);
            AddPoint(3, 1);
            break;
        case 11:
            color = 1;
            num = 11;
            height = 4;
            length = 2;
            before = 3;
            after = 3;
            AddPoint(0, 1);
            AddPoint(1, 0);
            AddPoint(1, 1);
            AddPoint(2, 0);
            AddPoint(3, 0);
            break;
        case 12:
            color = 1;
            num = 12;
            height = 3;
            length = 3;
            before = 3;
            after = 3;
            AddPoint(0, 1);
            AddPoint(1, 0);
            AddPoint(1, 1);
            AddPoint(1, 2);
            AddPoint(2, 2);
            break;
        case 13:
            color = 0;
            num = 13;
            height = 2;
            length = 3;
            before = 3;
            after = 3;
            AddPoint(0, 0);
            AddPoint(0, 1);
            AddPoint(0, 2);
            AddPoint(1, 0);
            AddPoint(1, 1);
            break;
    }
    return;
}
void Detail::Print() {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < length; ++j) {
            pair<int, int> tmp;
            tmp.first = i;
            tmp.second = j;
            if (find(data.begin(), data.end(), tmp) == data.end()) {
                cout << '*' << ' ';
            }
            else {
                if ((i + j) % 2 != color)
                    cout << 1 << ' ';
                else
                    cout << 0 << ' ';
            }
        }
        cout << endl;
    }
    cout << endl;
}
