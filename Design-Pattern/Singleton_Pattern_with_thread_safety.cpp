#include <iostream>
#include <mutex>
using namespace std;


class Singleton {
private:
    // Member variables
    string name, loves;

    // Static pointer to the Singleton instance
    static Singleton* instancePtr;

    // Mutex to ensure thread safety
    static mutex mtx;

    // Private Constructor
    Singleton() {}
public:
    // Deleting the copy constructor to prevent copies
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    // Static method to get the Singleton instance
    static Singleton* getInstance() {
        if (instancePtr == nullptr) {
            // Lock the mutex to ensure thread safety
            lock_guard<mutex> lock(mtx);
            // Double-check if instancePtr is still null after acquiring the lock
            if (instancePtr == nullptr) {
                instancePtr = new Singleton();
            }
        }
        return instancePtr;
    }

    // Method to set values
    void setValues(const string& n, const string& l) {
        name = n;
        loves = l;
        return;
    }

    // Method to display values
    void display() {
        cout << "Name: " << name << ", Loves: " << loves << endl;
        return;
    }

    // Static method to clean up the Singleton instance
    static void cleanup() {
        delete instancePtr;
        instancePtr = nullptr;
    }
};

// Initialize static members
Singleton* Singleton::instancePtr = nullptr;
mutex Singleton::mtx;

// Driver Code

int main() {
    Singleton* s1 = Singleton::getInstance();
    s1->setValues("Manish", "GeeksForGeeks");
    s1->display();

    Singleton* s2 = s1;
    s2->display();  // Should display the same values as s1
    s2->setValues("Vartika", "GeeksForGeeks");
    return 0;
}