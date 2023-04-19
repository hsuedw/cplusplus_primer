#ifndef __MESSAGE_H__
#define __MESSAGE_H__

#include <string>
#include <set>

class Folder;

class Message {
    friend class Folder;
    friend void swap(Message&, Message&);
public:
    // folders is implicitly initialized to the empty set.
    explicit Message(const std::string &str = "") : contents(str) {}

    // copy control to manage pointers to this Message
    Message(const Message&);            // copy constructor
    Message& operator=(const Message&); // copy assignment
    ~Message();                         // destructor

    // add/remove this Message from the specified Folder's set of messages
    void save(Folder&);
    void remove(Folder&);

    void dbgPrint();
private:
    std::string contents;       // actual message text
    std::set<Folder *> folders; // Folders that have this Message

    // utility functions used by copy constructor, assignment, and destructor 
    // add this Message to the Folders that point to the parameter.
    void add_to_Folders(const Message&);

    // remove this Message from every Folder in Folders
    void remove_from_Folders();

    void addFolder(Folder *f);
    void remFolder(Folder *f);
};


#endif // __MESSAGE_H__
