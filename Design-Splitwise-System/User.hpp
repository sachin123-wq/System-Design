#include <string>
class User {
public:
    std::string userId;
    std::string name;
    std::string email;
    std::string mobile;

    User(std::string id, std::string n, std::string e, std::string m)
        : userId(id), name(n), email(e), mobile(m) {}
};