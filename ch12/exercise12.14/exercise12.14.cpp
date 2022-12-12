#include <iostream>
#include <memory>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::ostream;
using std::shared_ptr;
using std::make_shared;

struct destination {};
struct connection {};

connection connect(destination *pd)
{
    cout << "Open a connection." << endl;
    return connection();
}

void disconnect(connection c)
{
    cout << "Close a connection." << endl;
}

void end_connection(connection *p)
{
    cout << "The connection is going to be closed." << endl;
    disconnect(*p);
}

void f(destination &d)
{
    cout << "Use connection in f..." << endl;
    connection c = connect(&d);

    // forget to call disconnect to close the connection
}

void my_f(destination &d)
{
    cout << "Use connection in my_f..." << endl;
    connection c = connect(&d);

    // Use shared_ptr and deleter to manage connection.
    shared_ptr<connection> p(&c, end_connection);
}

int main(int argc, char *argv[])
{
    destination d;

    cout << "Test 1:" << endl;
    f(d);

    cout << endl << "Test 2:" << endl;
    my_f(d);

    return 0;
}
