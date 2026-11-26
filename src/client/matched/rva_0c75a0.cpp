struct Sub {
    unsigned char data[0xE0];
    bool flag;
};

struct Obj {
    Sub* sub;
    void NotifyDetach();
};

void Obj::NotifyDetach() {
    Sub* s = sub;
    if (s != 0) {
        s->flag = true;
    }
}
