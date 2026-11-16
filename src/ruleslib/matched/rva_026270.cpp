class Legacy {
public:
    static int __stdcall getValue(const Legacy *obj);
private:
    unsigned char padding[472];
    int data;
};

int __stdcall Legacy::getValue(const Legacy *obj) {
    return obj->data;
}

