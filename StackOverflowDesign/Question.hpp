#ifndef QUESTION_HPP
#define QUESTION_HPP

#include <string>
#include <vector>

class User;
class Tag;
class Answer;
class Comment;

class Question {
private:
    int questionId;
    User* author;
    std::string title;
    std::string body;
    std::vector<Tag*> tags;
    std::vector<Answer*> answers;
    std::vector<Comment*> comments;
    int voteCount;

public:
    Question(int id, User* user, const std::string& title, const std::string& body)
        : questionId(id), author(user), title(title), body(body), voteCount(0) {}

    void addAnswer(Answer* answer) { answers.push_back(answer); }
    void addComment(Comment* comment) { comments.push_back(comment); }
    void addTag(Tag* tag) { tags.push_back(tag); }

    std::string getTitle() const { return title; }
    std::string getBody() const { return body; }
    int getVoteCount() const { return voteCount; }

};


#endif //QUESTION_HPP