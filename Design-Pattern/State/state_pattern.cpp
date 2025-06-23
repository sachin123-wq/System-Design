#include <iostream>
#include <string>
using namespace std;

// Define State Interface
class Document;

class State {
public:
    virtual void edit(Document* doc) = 0;
    virtual void review(Document* doc) = 0;
    virtual void publish(Document* doc) = 0;
    virtual ~State() {}
};

// Concrete States
class DraftState : public State {
public:
    void edit(Document* doc) override;
    void review(Document* doc) override;
    void publish(Document* doc) override    {
        cout << "Document is in draft state. Cannot publish yet." << endl;
    }
};

class ReviewState : public State {
public:
    void edit(Document* doc) override {
        cout << "Document is under review. Cannot edit." << endl;
    }
    
    void review(Document* doc) override {
        cout << "Document is already under review." << endl;
    }
    
    void publish(Document* doc) override;
};

class PublishedState : public State {
public:
    void edit(Document* doc) override {
        cout << "Document is published. Cannot edit." << endl;
    }
    
    void review(Document* doc) override {
        cout << "Document is published. Cannot review." << endl;
    }
    
    void publish(Document* doc) override {
        cout << "Document is already published." << endl;
    }
};

// Document (Context)

class Document {
private:
    State* currState;
public:
    Document();

    void setState(State* state) {
        currState = state;
    }

    void edit() {
        currState->edit(this);
    }

    void review() {
        currState->review(this);
    }

    void publish() {
        currState->publish(this);
    }

    // Accessors for all states (static/shared)
    static State* getDraftState();
    static State* getReviewState();
    static State* getPublishedState();
};

// State Transitions (Implement Methods)
State* draftState = new DraftState();
State* reviewState = new ReviewState();
State* publishedState = new PublishedState();

Document::Document() {
    currState = draftState;
}

State* Document::getDraftState() { return draftState; }
State* Document::getReviewState() { return reviewState; }
State* Document::getPublishedState() { return publishedState; }

void DraftState::edit(Document* doc) {
    cout << "Editing document in Draft state.\n";
}
void DraftState::review(Document* doc) {
    cout << "Moving document to Review state.\n";
    doc->setState(Document::getReviewState());
}

void ReviewState::publish(Document* doc) {
    cout << "Publishing document.\n";
    doc->setState(Document::getPublishedState());
}


int main() {
    Document doc;

    doc.edit();     // Draft: Edit
    doc.review();   // Draft → Review
    doc.edit();     // Review: Cannot edit
    doc.publish();  // Review → Published
    doc.review();   // Already published
}