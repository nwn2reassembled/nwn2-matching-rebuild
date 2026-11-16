struct MyClass {
    int *array;
    int get(int);
};

int MyClass::get(int idx) {
    return array[idx];
}

