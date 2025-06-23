#include <iostream>
#include <string>
#include <memory>
using namespace std;

// Base Handler Interface
class Handler {
protected:
    shared_ptr<Handler> next;
public:
    void setNext(shared_ptr<Handler> nextHandler) {
        next = nextHandler;
    }

    virtual void handle(const string& request) {
        if (next) next->handle(request);
    }
};

// Auth Handler
class AuthHandler : public Handler {
public:
    void handle(const string& request) override {
        if (request.find("auth") != string::npos) {
            cout << "[Auth] Request is authenticated\n";
            if (next) next->handle(request);
        } else {
            cout << "[Auth] Request denied: No auth\n";
        }
    }
};

// Rate Limiter
class RateLimiterHandler : public Handler {
public:
    void handle(const string& request) override {
        cout << "[RateLimiter] Within rate limits\n";
        if (next) next->handle(request);
    }
};

// Logging Handler
class LoggingHandler : public Handler {
public:
    void handle(const string& request) override {
        cout << "[Logging] Request logged\n";
        if (next) next->handle(request);
    }
};

// Final Processor
class Controller : public Handler {
public:
    void handle(const string& request) override {
        cout << "[Controller] Processing request: " << request << endl;
    }
};

int main() {
    auto auth = make_shared<AuthHandler>();
    auto rate = make_shared<RateLimiterHandler>();
    auto log = make_shared<LoggingHandler>();
    auto controller = make_shared<Controller>();

    // Setup chain
    auth->setNext(rate);
    rate->setNext(log);
    log->setNext(controller);

    cout << "---- Test 1: With auth ----\n";
    auth->handle("auth/user=abc&data=42");

    cout << "\n---- Test 2: Without auth ----\n";
    auth->handle("user=abc&data=42");

    return 0;
}
