struct MyStruct{int field0; int field1;};

class Checker{
public:
    bool check(const MyStruct* ptr) const;
};

bool Checker::check(const MyStruct* ptr) const {
    return ptr->field1 != 0;
}
