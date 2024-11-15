#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// #include <vector>
#include "User.hpp"
#include "Answer.hpp"
#include "Question.hpp"
#include "Comment.hpp"
#include "Tag.hpp"
#include "Search.hpp"

using namespace std;


int main(){
    // Initialize users
    User alice(1, "Alice", "alice@example.com",0);
    User bob(2, "Bob", "bob@example.com",0);

    cout << "User: " << alice.getUsername() << " with Reputation: " << alice.getReputation() << endl;

    // Initialize tags
    Tag programmingTag(1, "Programming");
    Tag cppTag(2, "C++");

    // Initialize questions
    Question q1(1, &alice, "How to implement a stack?", "I need help with stack implementation in C++.");

    // Add tags to questions
    q1.addTag(&programmingTag);
    q1.addTag(&cppTag);

    // Initialize answers
    Answer a1(1, &q1, &bob, "You can use a linked list or an array to implement a stack.");

    // Add answers to questions
    q1.addAnswer(&a1);

    // Initialize comments
    Comment c1(1, &alice, "This answer is helpful, thanks!");

    // Add comments to answers
    a1.addComment(&c1);

    // Update reputation
    alice.updateReputation(10);  // Simulate reputation increase for Alice
    bob.updateReputation(-5);    // Simulate reputation decrease for Bob

     // Display user information
    std::cout << "User: " << alice.getUsername() << ", Reputation: " << alice.getReputation() << std::endl;
    std::cout << "User: " << bob.getUsername() << ", Reputation: " << bob.getReputation() << std::endl;

    // Display question information
    std::cout << "Question: " << q1.getTitle() << ", Vote Count: " << q1.getVoteCount() << std::endl;

    // Display answer information
    std::cout << "Answer: " << a1.getBody() << ", Vote Count: " << a1.getVoteCount() << std::endl;

    // Display comment information
    std::cout << "Comment: " << c1.getText() << std::endl;

    // Search for questions (using the Singleton Search class)
    Search* search = Search::getInstance();

}