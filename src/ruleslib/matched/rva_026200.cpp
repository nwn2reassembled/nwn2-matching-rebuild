class Dummy {
public:
    unsigned int func(int *p);
};

unsigned int Dummy::func(int *p) { return p[112]; }

