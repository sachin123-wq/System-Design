#include <iostream>
#include <unordered_map>

class Board {
    std::unordered_map<int, int> snakes;
    std::unordered_map<int, int> ladders;
public:
    void addSnake(int head, int tail) {
        snakes[head] = tail;
    }
    void addLadder(int start, int end) {
        ladders[start] = end;
    }
    int getNextPosition(int pos) {
        while (true) {
            if (snakes.count(pos)) pos = snakes[pos];
            else if (ladders.count(pos)) pos = ladders[pos];
            else break;
        }
        return pos;
    }
};