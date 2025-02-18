#include <iostream>
#include <string>

#define STR std::string

class Card{
	private:
	STR cardNumber;
	STR pin;

	public:

	Card(STR cdn, STR pn): cardNumber(cdn), pin(pn){}
	
	STR getCardNumber() {
        return cardNumber;
    }

    STR getPin() {
        return pin;
    }
};