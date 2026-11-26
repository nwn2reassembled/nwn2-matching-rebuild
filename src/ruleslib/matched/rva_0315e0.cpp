struct Payload {
    unsigned char reserved[0x600];
    int value;
    static void __stdcall SetValue(Payload* self, int newValue);
};

void __stdcall Payload::SetValue(Payload* self, int newValue) {
    self->value = newValue;
}
