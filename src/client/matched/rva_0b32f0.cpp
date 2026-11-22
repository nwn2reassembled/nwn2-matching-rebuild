struct Legacy {
    char pad[20];
    float field;
    float getField() const;
};

float Legacy::getField() const { return field; }
