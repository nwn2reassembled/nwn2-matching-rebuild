class Legacy {
public:
    void copy_fields(unsigned *dst1, unsigned *dst2, unsigned *dst3,
                     unsigned *dst4, unsigned char *dst5, unsigned *dst6);
private:
    char pad[0x2f4];
    unsigned field_2f4;
    unsigned field_2f8;
    unsigned field_2fc;
    unsigned field_300;
    unsigned field_304;
    unsigned char field_308;
};

void Legacy::copy_fields(unsigned *dst1, unsigned *dst2, unsigned *dst3,
                         unsigned *dst4, unsigned char *dst5, unsigned *dst6) {
    *dst1 = this->field_2f4;
    *dst2 = this->field_2f8;
    *dst3 = this->field_2fc;
    *dst4 = this->field_300;
    *dst5 = this->field_308;
    *dst6 = this->field_304;
}

