class MyStruct {
public:
    float data[16];
    void init();
};

void MyStruct::init() {
    this->data[0] = 1.0f;
    this->data[1] = 0.0f;
    this->data[2] = 0.0f;
    this->data[3] = 0.0f;
    this->data[4] = 0.0f;
    this->data[6] = 0.0f;
    this->data[7] = 0.0f;
    this->data[8] = 0.0f;
    this->data[9] = 0.0f;
    this->data[11] = 0.0f;
    this->data[12] = 0.0f;
    this->data[13] = 0.0f;
    this->data[14] = 0.0f;
    this->data[5] = 1.0f;
    this->data[10] = 1.0f;
    this->data[15] = 1.0f;
}

