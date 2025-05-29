#include "Game.hpp"
int main() {
    Board board;
    int s; std::cin >> s;
    for (int i = 0; i < s; ++i) {
        int head, tail; std::cin >> head >> tail;
        board.addSnake(head, tail);
    }

    int l; std::cin >> l;
    for (int i = 0; i < l; ++i) {
        int start, end; std::cin >> start >> end;
        board.addLadder(start, end);
    }

    int p; std::cin >> p;
    std::vector<std::string> players;
    for (int i = 0; i < p; ++i) {
        std::string name; std::cin >> name;
        players.push_back(name);
    }

    Game game(board, players);
    game.play();
    return 0;
}