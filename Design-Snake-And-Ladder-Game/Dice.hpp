#include <math.h>

class Dice {
public:
    int roll() {
        return (rand() % 6) + 1;
    }
};