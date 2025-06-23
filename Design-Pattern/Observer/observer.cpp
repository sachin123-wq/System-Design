#include <iostream>
#include <memory>
#include <string>
using namespace std;

// Observer Interface
class Observer {
public:
    virtual ~Observer() = default;
    virtual void update(const float& temperature, const float& humidity) = 0;
};

// Concrete Observer
class PhoneDisplay : public Observer {
public:
    void update(const float& temperature, const float& humidity) override {
        cout << "PhoneDisplay => Temp: " << temperature << ", Humidity: " << humidity << endl;
    }
};

class LEDDisplay : public Observer {
public:
    void update(const float& temperature, const float& humidity) override {
        cout << "LEDDisplay => Temp: " << temperature << ", Humidity: " << humidity << endl;
    }
};

// Subject Interface (Observable interface to attach/detach and notify observers)
class Subject {
public:
    virtual ~Subject() = default;
    virtual void attach(Observer* observer) = 0;
    virtual void detach(Observer* observer) = 0;
    virtual void notify() = 0;
};

// Concrete Subject (WeatherStation => It maintains a list of observers and notifies them for any update on weather)
class WeatherStation : public Subject {
private:
    vector<Observer*> observers;
    float temperature;
    float humidity;

public:
    void attach(Observer* o) override {
        observers.push_back(o);
    }

    void detach(Observer* o) override {
        observers.erase(remove(observers.begin(), observers.end(), o), observers.end());
    }

    void notify() override {
        for (Observer* o : observers)
            o->update(temperature, humidity);
    }

    void setMeasurements(float temp, float hum) {
        temperature = temp;
        humidity = hum;
        notify();  // Notify observers about change
    }
};

int main() {
    WeatherStation station;

    PhoneDisplay phone;
    LEDDisplay led;

    station.attach(&phone);
    station.attach(&led);

    station.setMeasurements(28.5f, 60.0f);  // Both observers get update
    station.setMeasurements(30.0f, 55.5f);  // Update again

    return 0;
}

