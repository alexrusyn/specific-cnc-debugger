#ifndef FLAGS_H
#define FLAGS_H

template <class T>
class Flags
{
public:
    T get();
    // void set(const T x);

    // T mask(const T x);
    // bool read(const T x);

private:
    T buffer = 0;
};

#include "Flags.cpp"

#endif

/*

    // Online C++ compiler to run C++ program online
#include <iostream>

template <typename T>
class Flag {
public:
    T flags = 0;

    T get () {
        return flags;
    }

    void set (const T x) {
        flags |= x;
    }

    T mask(const T x) {
        return flags & x;
    }

    bool read (const T x) {
        return flags & x;
    }
};

#define EB_PRS_R (1 << 1)
#define EB_HLD_R (1 << 2)

#define EB_PRS (1 << 3)
#define EB_HLD (1 << 4)

// #define EB_PRESS (1 << 0)
// #define EB_HOLD (1 << 1)

unsigned short action (Flag<unsigned char> &flag){
    switch(flag.mask(0b11111111)){
        case (EB_PRS | EB_PRS_R): return 1;
        case (EB_PRS | EB_HLD | EB_HLD_R): return 2;
        default: return 0;
    }
}

int main() {
    Flag<unsigned char> flag;

    flag.set(EB_PRS);

    // Write C++ code here
    std::cout << static_cast<unsigned short>(flag.get()) << std::endl;

    flag.set(EB_HLD);
    flag.set(EB_HLD_R);

    std::cout << action(flag) << std::endl;


    return 0;
}

*/