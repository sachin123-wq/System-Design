#include <string>
class Player {
public:
    std::string name;
    int position;
    Player(std::string name) : name(name), position(0) {}
};