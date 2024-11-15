#include <string>
class User;

class Comment {
private:
    int commentId;
    User* author;
    std::string text;

public:
    Comment(int id, User* user, const std::string& commentText)
        : commentId(id), author(user), text(commentText) {}

    std::string getText() const { return text; }
    User* getAuthor() const { return author; }

    // Other comment-related methods...
};

