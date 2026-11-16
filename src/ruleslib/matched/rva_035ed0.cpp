struct Data {
    int filler[103];
    int value;
};

class Wrapper {
public:
    static int __stdcall getValue(void* ptr);
};

int Wrapper::getValue(void* ptr) { return ((Data*)ptr)->value; }
