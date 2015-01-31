#include "Detail.h"

#define dsize 8

using std::vector;
using std::pair;
using std::cout;
using std::endl;

/* ----------
 
 1 - white
 0 - black
    Модифицировать перевоб начальных положений: центральный
 элемент 1й детали достаточно поместить в точки с
 координатами:
    (1, 2) (2, 2) (2, 3) (3, 3) (1, 3)
 Учесть совпадения цветов на доске и того, что центр фигуры белый.
 Запустить как 5 разных процессов.
 
   ---------- */
class Deck {
private:
    pair<int, int> data[dsize][dsize];
public:
    Deck();
    ~Deck() {};
    void Solve();
    void Clear();
    void Print() const;
    bool Bust(const int& used);
    bool Attach(const int x, const int y, Detail det);
};

Deck::Deck(){
    for (int i = 0; i < dsize; ++i) {
        for (int j = 0; j < dsize; ++j) {
            data[i][j].first = 0;
            if ((i+j) % 2 == 0)
                data[i][j].second = 1;
            else
                data[i][j].second = 0;
        }
    }
}

void Deck::Print() const {
    cout << "/---------------------/" << endl;
    for (int i = 0; i < dsize; ++i) {
        for (int j = 0; j < dsize; ++j) {
            if (data[i][j].first / 10 != 0)
                cout << data[i][j].first << ' ';
            else {
                if (data[i][j].first == 0)
                    cout << " * ";
                else
                    cout << ' ' << data[i][j].first << ' ';
            }
        }
        cout << endl;
    }
    cout << "/---------------------/" << endl;
}

bool Deck::Attach(const int x, const int y, Detail det) {
    // cout << data[x][y].second <<  ' ' << det.color << endl;
    if (data[x][y].second != det.color)
        return 0;
    for (int i = 0; i < det.data.size(); ++i) {
        if (data[x+det.data[i].first][y+det.data[i].second].first == 0)
            data[x+det.data[i].first][y+det.data[i].second].first = det.num;
        else {
            for (int j = 0; j < i; ++j)
                data[x+det.data[j].first][y+det.data[j].second].first = 0;
            return 0;
        }
    }
    return 1;
}

void Deck::Solve() {
    Detail det;
    det.Make(1);
    Attach(0, 0,  det);
    Bust(1);
    Clear();
    Attach(0, 1, det);
    Bust(1);
    Clear();
    Attach(1, 1, det);
    Bust(1);
    Clear();
    Attach(0, 2, det);
    Bust(1);
    Clear();
    Attach(1, 2, det);
    Bust(1);
    Clear();
    Attach(2, 2, det);
    Bust(1);
    Clear();
}

void Deck::Clear() {
    for (int i = 0; i < dsize; ++i) {
        for (int j = 0; j < dsize; ++j) {
            data[i][j].first = 0;
            if ((i+j) % 2 == 0)
                data[i][j].second = 1;
            else
                data[i][j].second = 0;
        }
    }
}

bool Deck::Bust(const int& used) {
    Detail det;
    det.Make(used+1);
    for (int i = 0; i <= det.before; ++i) {
        for (int k = 0; k < dsize-det.height+1; ++k) {
            for (int l = 0; l < dsize-det.length+1; ++l) {
                if (Attach(k, l, det)) {
                    if (used == 12) {
                        Print();
                        return 1;
                    }
                    else {
                        if (Bust(used+1))
                            return 1;
                    }
                    for (int i = 0; i < dsize; ++i)
                        for (int j = 0; j < dsize; ++j)
                            if (data[i][j].first == det.num)
                                data[i][j].first = 0;
                }
            }
        }
    }
    if (det.after > -1) {
        det.Reflect();
        for (int i = 0; i <= det.after; ++i) {
            for (int k = 0; k < dsize-det.height+1; ++k) {
                for (int l = 0; l < dsize-det.length+1; ++l) {
                    if (Attach(k, l, det)) {
                        if (used == 12) {
                            Print();
                            return 1;
                        }
                        else {
                            if (Bust(used+1))
                                return 1;
                        }
                        for (int i = 0; i < dsize; ++i)
                            for (int j = 0; j < dsize; ++j)
                                if (data[i][j].first == det.num)
                                    data[i][j].first = 0;
                    }
                }
            }
            det.Turn();
        }
    }
    return 0;
}
