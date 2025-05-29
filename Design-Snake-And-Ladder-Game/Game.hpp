#include "Board.hpp"
#include "Player.hpp"
#include "Dice.hpp"
#include <queue>

class Game {
    Board board;
    Dice dice;
    std::queue<Player*> players;
    std::unordered_map<std::string, Player*> playerMap;
public:
    Game(Board b, std::vector<std::string>& playerNames) : board(b) {
        for (auto& name : playerNames) {
            Player* p = new Player(name);
            players.push(p);
            playerMap[name] = p;
        }
        srand(time(0));
    }

    void play() {
        while (!players.empty()) {
            Player* curr = players.front();
            players.pop();

            int roll = dice.roll();
            int initial = curr->position;
            int tentative = initial + roll;
            int finalPos = (tentative > 100) ? initial : board.getNextPosition(tentative);

            curr->position = finalPos;
            std::cout << curr->name << " rolled a " << roll << " and moved from " << initial << " to " << finalPos << std::endl;

            if (finalPos == 100) {
                std::cout << curr->name << " wins the game" << std::endl;
                break;
            }
            players.push(curr);
        }
    }
};