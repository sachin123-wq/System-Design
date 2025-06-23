#include <iostream>
#include <memory>
#include <string>
using namespace std;

// Step 1: Interface
class Notification {
public:
    virtual void send(string message) = 0;
    virtual ~Notification() = default;
};

// Step 2: Concrete classes
class EmailNotification : public Notification {
public:
    void send(string message) override {
        cout << "Sending Email: " << message << endl;
    }
};

class SMSNotification : public Notification {
public:
    void send(string message) override {
        cout << "Sending SMS: " << message << endl;
    }
};

class PushNotification : public Notification {
public:
    void send(string message) override {
        cout << "Sending Push Notification: " << message << endl;
    }
};

// Step 3: Factory
class NotificationFactory {
public:
    static shared_ptr<Notification> createNotification(const string& type) {
        if (type == "email") return make_shared<EmailNotification>();
        if (type == "sms") return make_shared<SMSNotification>();
        if (type == "push") return make_shared<PushNotification>();
        return nullptr;
    }
};

// Step 4: Client
int main() {
    auto notifier = NotificationFactory::createNotification("sms");
    if (notifier)
        notifier->send("Hello from factory pattern!");
    return 0;
}
