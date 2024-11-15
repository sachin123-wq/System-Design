#ifndef ANSWER_HPP
#define ANSWER_HPP

#include <string>
#include <vector>


class User;
class Question;
class Comment;
enum class VoteType;
// enum class VoteType { UPVOTE, DOWNVOTE };

class Answer {
private:
    int answerId;
    Question* question;
    User* author;
    std::string body;
    int voteCount;
    std::vector<Comment*> comments;

public:
    Answer(int id, Question* q, User* user, const std::string& text)
        : answerId(id), question(q), author(user), body(text), voteCount(0) {}

    void addComment(Comment* comment) { comments.push_back(comment); }
    void castVote(VoteType voteType);

    std::string getBody() const { return body; }
    int getVoteCount() const { return voteCount; }

    // Other answer-related methods...
};

#endif