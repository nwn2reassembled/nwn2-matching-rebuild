class MyClass{
public:
    char padding[0xa0];
    int a0;
    int a4;
    int a8;
    int ac;
    int dummy;
    int b4;
    int b8;

    unsigned char init();
};

unsigned char MyClass::init(){
    a8 = 0;
    ac = 0;
    a4 = 0;
    a0 = 0;
    b4 = 0;
    b8 = 0;
    return 1;
}

