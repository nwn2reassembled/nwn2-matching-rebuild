struct S {
    int pad0;
    int pad1;
    int v8;
    short v12;
};

void __cdecl SetFields(S* s, int value, short word) {
    s->v8 = value;
    s->v12 = word;
}
