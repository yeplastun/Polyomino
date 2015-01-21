#include "Detail.h"

#define dsize 8

using std::vector;
using std::pair;
using std::cout;
using std::endl;

/* ----------
 
    1 - white
    0 - black

 */
class Deck {
private:
    pair<int, int> data[dsize][dsize];
public:
    Deck();
    ~Deck() {};
    void Print() const;
    void Bust(const int& used);
    bool Attach(const int& x, const int& y, const Detail& det);
};

Deck::Deck(){
    for (int i = 0; i < dsize; ++i) {
        for (int j = 0; j < dsize; ++j) {
            data[i][j].first = 0;
            if ((i+j) % 2 == 0)
                data[i][j].second = 0;
            else
                data[i][j].second = 1;
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

bool Deck::Attach(const int& x, const int& y, const Detail& det) {
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
    //Print();
    return 1;
}

void Deck::Bust(const int& used) {
    Detail det;
    det.Make(used+1);
    for (int i = 0; i < 2; i++) {
        if (i == 1)
            det.Reflect();
        for (int j = 0; j < 4; j++) {
            if (j > 0)
                det.Turn();
            for (int k = 0; k < dsize-det.height+1; ++k) {
                for (int l = 0; l < dsize-det.length+1; ++l) {
                    if (Attach(k, l, det)) {
                        // Print();
                        if (used == 13) {
                            Print();
                            return;
                        }
                        Bust(used+1);
                    }
                }
            }
            for (int i = 0; i < dsize; ++i)
                for (int j = 0; j < dsize; ++j)
                    if (data[i][j].first == det.num)
                        data[i][j].first = 0;
        }
    }
}
