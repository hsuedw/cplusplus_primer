#include <string>
using std::string;

typedef string Type;
Type initVal();
class Exercise {
public:
    typedef double Type;
    Type setVal(Type);
    Type initVal();
private:
    Type val; // Change the type of val to Type.
};

// Add the scope operator (Exercise::) to specify the Type is that declared
// inside the Exercise class.
Exercise::Type Exercise::setVal(Type parm) {
    val = parm + initVal();
    return val;
}
