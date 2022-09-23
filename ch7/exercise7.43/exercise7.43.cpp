class NoDefault {
public:
    NoDefault(int a) {}
};

class C {
public:
    C(int i = 0) : c_member(i) {

    }
    NoDefault c_member;
};

int main()
{
    C c_obj(123);

    return 0;
}
