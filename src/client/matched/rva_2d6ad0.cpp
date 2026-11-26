struct Inner {
    int pad;
    int value;
};

struct Outer {
    Inner* inner;
    int size;
};

class Widget {
public:
    Outer* state;
    int GetValue();
};

int Widget::GetValue() {
    if (state->size <= 0)
        return 0;
    return state->inner->value;
}
