#include <string>

class Tag {
private:
    int tagId;
    std::string name;

public:
    Tag(int id, const std::string& tagName) : tagId(id), name(tagName) {}

    std::string getName() const { return name; }

    // Other tag-related methods...
};
