class MyClass {
public:
    int getValue(int idx);
private:
    char padding[0x228];
    int arr[10]; // placeholder for the array field
};

int MyClass::getValue(int idx) { return arr[idx]; }
