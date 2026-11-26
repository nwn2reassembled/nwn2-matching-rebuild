struct Widget {
    int state;      // offset 0x0
    int value;      // offset 0x4

    int __fastcall TryGet(void* unusedArg, int* outState, int* outValue);
};

int Widget::TryGet(void* unusedArg, int* outState, int* outValue) {
    if (this->state != 3) {
        return 0;
    }
    *outState = 3;
    *outValue = this->value;
    return 1;
}
