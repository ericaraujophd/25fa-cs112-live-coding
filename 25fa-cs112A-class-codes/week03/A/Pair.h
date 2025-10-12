#ifndef _PAIR_H_
#define _PAIR_H_

#include <string>
using namespace std;

class Pair{
    public:
        // constructors
        Pair();
        Pair(int, int);
        // getters
        int getFirst() const;
        int getSecond() const;
        // setters
        void setFirst(int);
        void setSecond(int);

        // toString
        string toString() const;
    private:
        int myFirst;
        int mySecond;
};

ostream &operator<<(ostream &out, const Pair &p);
#endif