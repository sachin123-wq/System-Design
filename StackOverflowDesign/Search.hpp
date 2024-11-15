#ifndef SEARCH_HPP
#define SEARCH_HPP

#include <string>
#include <vector>

class Question;
class User;
class Tag;

class Search{
private:
    static Search *instance;
    Search() {} //Private Constructor for singleton pattern

public:
    static Search* getInstance(){
        if(instance == nullptr){
            instance = new Search();
        }
        return instance;
    }

    std::vector<Question*> searchByKeyword(const std::string &keyword);
    std::vector<Question*> searchByTag(const Tag& tag);
    std::vector<Question*> searchByUser(const User& user);
};
Search* Search::instance = nullptr;
#endif