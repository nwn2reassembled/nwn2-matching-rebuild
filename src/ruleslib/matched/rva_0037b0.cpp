class Legacy {
public:
    void clear();
};

void Legacy::clear() {
    *(int*)((char*)this + 4) = 0,
     *(int*)((char*)this + 8) = 0,
     *(int*)(this)          = 0;
}

