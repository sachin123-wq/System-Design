#ifndef USER_HPP
#define USER_HPP

#include <string>
#include <vector>
#include <unordered_set>

class Question;
class Answer;
class Comment;
class Vote;

enum class VoteType { UPVOTE, DOWNVOTE };

class User {
private:
    int userId;
    std::string username;
    std::string email;
    int reputationScore;

    std::vector<Question*> postedQuestions;
    std::vector<Answer*> postedAnswers;
    std::vector<Comment*> postedComments;
    std::unordered_set<int> votedPosts;

public:
    User(int id, const std::string& name, const std::string& mail, int rscore);

    void postQuestion(Question* question);
    void postAnswer(Answer* answer);
    void postComment(Comment* comment);

    void updateReputation(int change) { reputationScore += change; }
    int getReputation() const { return reputationScore; }
    std::string getUsername() const { return username; }

    // Other user-related methods...
};

User::User(int id, const std::string& name, const std::string& mail, int rscore) : userId(id),username(name),email(mail),reputationScore(rscore){}

void User::postQuestion(Question* question){
    postedQuestions.push_back(question);
}

void User::postAnswer(Answer* answer){
    postedAnswers.push_back(answer);
}

void User::postComment(Comment* Comment){
    postedComments.push_back(Comment);
}

#endif // USER_HPP
