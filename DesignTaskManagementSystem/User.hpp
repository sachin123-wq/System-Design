#ifndef USER
#define USER

#include <string>
#include <ctime>


class User{
private:
    const std::string id;
    const std::string name;
    const std::string email;

public:
    User(std::string id, std::string name, std::string email): id(id), 
    name(name), email(email) {}

    //Getters methods
    std::string getId() const {
        return id;
    }

    std::string getName() const{
        return name;
    }

    std::string getEmail() const{
        return email;
    }
};
#endif