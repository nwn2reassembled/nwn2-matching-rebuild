struct RulesParam {
    int field0;
    int field4;
    char field8;
};

void __stdcall RulesParam_SetByte(RulesParam* self, char value) {
    if (self != 0) {
        self->field8 = value;
    }
}
