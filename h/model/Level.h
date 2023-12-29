#ifndef LEVEL_H_INCLUDED
#define LEVEL_H_INCLUDED
#define MAX_EXP 100

class Level {
private:
    unsigned level;
    unsigned exp;
public:
    Level();
    void addExp(unsigned);
};

#endif // LEVEL_H_INCLUDED
