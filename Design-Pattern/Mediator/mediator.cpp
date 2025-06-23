#include <iostream>
#include <string>
#include <vector>


// Forward Declaration 
class User;

// Mediator Interface
class ChatMediator {
public:
    virtual void sendMessage(const std::string& msg, User* user) = 0;
    virtual void addUser(User* user) = 0;
    virtual ~ChatMediator() = default;
};

// User Class
class User {
private:
    std::string name;
    ChatMediator* mediator;
public:
    User(const std::string& name, ChatMediator* mediator) : name(name), mediator(mediator) {}

    void sendMessage(const std::string& msg) {
        std::cout << name << " sends: " << msg << std::endl;
        mediator->sendMessage(msg, this);
    }

    void receiveMessage(const std::string& msg) {
        std::cout << name << " receives: " << msg << std::endl;
    }

    const std::string& getName() const {
        return name;
    }
};

// Concrete Mediator Class
class ChatRoom : public ChatMediator {
private:
    std::vector<User*> users;
public:
    void sendMessage(const std::string& msg, User* user) override {
        for (User* u : users) {
            // Don't send the message to the user who sent it
            if (u != user) {
                u->receiveMessage(msg);
            }
        }
    }

    void addUser(User* user) override {
        users.push_back(user);
    }
};


int main() {
    ChatRoom chat;

    User* alice = new User("Alice", &chat);
    User* bob = new User("Bob", &chat);
    User* charlie = new User("Charlie", &chat);

    chat.addUser(alice);
    chat.addUser(bob);
    chat.addUser(charlie);

    alice->sendMessage("Hello everyone!");
    bob->sendMessage("Hi Alice!");

    delete alice;
    delete bob;
    delete charlie;
    return 0;
}
