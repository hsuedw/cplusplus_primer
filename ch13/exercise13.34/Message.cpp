#include "Message.h"

class Folder;

void Message::save(Folder &f) {
    folders.insert(&f); // add the given Folder to our list of Folders
    f.addMsg(this);     // this Message to f's set of Messages
}

void Message::remove(Folder &f) {
    folders.erase(& f);
    f.remMsg(this);
}

void Message::add_to_Folders(const Message &m) {
    for (auto f : m.folders) { // for each Folder that holds m
        f->addMsg(this); // add a pointer to this Message to that Folder
    }
}

Message::Message(const Message &m) :
    contents(m.contents), folders(m.folders) {
    add_to_Folders(m);
    
}

void Message::remove_from_Folders() {
    for (auto f : folders)  { // for each pointer in folders
        f->remMsg(this);      // remove this Message from that Folder
    }
}

Message::~Message() {
    remove_from_Folders();
}

Message& Message::operator=(const Message &rhs) {
    // handle self-assignment by removing pointers before inserting them
    remove_from_Folders();   // update exiting Folders
    contents = rhs.contents; // copy message contents from rhs
    add_to_Folders(rhs);     // copy Folder pointers from rhs
    return *this;            // add this Message to thos Folders
}

void swap(Message &lhs, Message &rhs) {
    using std::swap;   // not strictly needed in this case, but good habit
    // remove pointers to each Message from their (original) respective Folders
    for (auto f : lhs.folders) {
        f->remMsg(&lhs);
    }
    for (auto f : rhs.folders) {
        f->remMsg(&rhs);
    }

    // swap the contents and Folder pointer sets
    swap(lhs.folders, rhs.folders);    // use swap(set&, set&)
    swap(lhs.contents, rhs.contents);  // swap(string&, string&)

    // add pointers to each Messag to their (new) respective Folders
    for (auto f : lhs.folders) {
        f->addMsg(&lhs);
    }
    for (auto f : rhs.folders) {
        f->addMsg(&rhs);
    }
}
