
#include <iostream>

using std::cerr;
using std::endl;

#include "Folder.h"
#include "Message.h"


Folder::Folder(const Folder &f) : messages(f.messages) {
    add_to_Messages(f); // Add this Folder object to all the messages in f.messages
}

Folder& Folder::operator=(const Folder &f) {
    remove_from_Messages();
    messages = f.messages;
    add_to_Messages(f);

    return *this;
}

Folder::~Folder() {
    remove_from_Messages(); // Remove the pointers to this Folder object from
                            // all the messages.
}

void Folder::save(Message &msg) {
    messages.insert(&msg); // Add the pointer to msg to this Folder object.
    msg.addFolder(this); // Add the pointer to this Folder objec to msg
}

void Folder::remove(Message &msg) {
    messages.erase(&msg);   // Remove the pointer to msg from this Folder object.
    msg.remFolder(this); // Remove the pointer to this Folder object from msg.
}

void Folder::dbgPrint() {
    cerr << "Folder contains " << messages.size() << " messages" << endl;
    int i = 1;
    for (auto &msg : messages) {
         cerr << "Message " << i++ << ":\n\t" << msg->contents << endl;
    }
}

void Folder::add_to_Messages(const Folder &f) {
    for (auto &msg : f.messages) {
        msg->addFolder(this);
    }
}

void Folder::remove_from_Messages() {
    while(!messages.empty()) {
        auto iter = messages.begin();
	(*iter)->remove(*this);
    }
}

void Folder::addMsg(Message *msg) {
    messages.insert(msg);
}

void Folder::remMsg(Message *msg) {
    messages.erase(msg);
}
