class Legacy {
public:
    int field0;
    int field4;
    int field8;
    float field12f;
    float field16f;
    int field20;
    int placeholder;
    int field28;
    int field32;
    int field36;

    Legacy* init();
};

Legacy* Legacy::init() {
    field12f = 0.0f;
    field0 = 0;
    field16f = 0.0f;
    field8 = 0;
    field20 = 0;
    field4 = 100;
    field28 = -1;
    field32 = -1;
    field36 = -1;
    return this;
}
