struct Inner;

struct Outer {
    Inner* inner;
};

struct Inner {
    void* vtbl;
    int value;
};

int __fastcall GetInnerValue(Outer* thisPtr)
{
    Inner* p = thisPtr->inner;
    if (p != 0)
        return p->value;
    return 0;
}
