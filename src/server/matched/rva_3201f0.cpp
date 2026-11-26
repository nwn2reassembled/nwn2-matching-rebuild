struct Vec2Info {
    float value;
    int flag;
};

void __stdcall InitOneAndZero(Vec2Info *out) {
    out->flag = 0;
    out->value = 1.0f;
}
