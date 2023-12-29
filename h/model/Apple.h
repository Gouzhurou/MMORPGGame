#ifndef APPLE_H_INCLUDED
#define APPLE_H_INCLUDED

class Apple {
private:
    unsigned hp;
public:
    Apple(unsigned hp = 0);
    unsigned getHp();
    void setHp(unsigned);
    bool isEqual(Apple&);
    void copy(Apple&);
};

#endif