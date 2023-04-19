#ifndef __FOLDER_H__
#define __FOLDER_H__

#include <set>

using std::set;

class Message;

class Folder {
    friend void swap(Message &lhs, Message &rhs);
    friend class Message;
public:
    Folder() {}  // default constructor

    // Copy control 
    Folder(const Folder&);            // copy constructor
    Folder& operator=(const Folder&); // copy-assignment operator
    ~Folder();                        // destructor

    void save(Message&);
    void remove(Message&);

    void dbgPrint();
private:
    set<Message *> messages;

    void add_to_Messages(const Folder&);
    void remove_from_Messages();
    void addMsg(Message *msg);
    void remMsg(Message *msg);
};

#endif // __FOLDER_H__
