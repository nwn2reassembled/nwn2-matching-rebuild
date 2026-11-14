struct Element {
    unsigned int key;
    char pad1[36];
    unsigned int field28;
    char pad2[4];
    unsigned int field30;
    unsigned char flag34;
    char pad3[3];
};

struct MyClass {
    char dummy[0x110];
    Element* array;
    char pad_to118[4];
    int count;
    void myfunc(unsigned int key, unsigned int val28, unsigned int val30);
};

void MyClass::myfunc(unsigned int key, unsigned int val28, unsigned int val30) {
    int n = count;
    int i = 0;
    if (n > 0) {
        Element* cursor = array;
        do {
            if (cursor->key == key) {
                array[i].field28 = val28;
                array[i].field30 = val30;
                array[i].flag34 = 1;
                return;
            }
            ++i;
            ++cursor;
        } while (i < n);
    }
}
