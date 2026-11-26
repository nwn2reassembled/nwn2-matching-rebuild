struct Vector5 {
    float x;
    float y;
    float z;
    float w;
    float v;
    int kind;

    Vector5* set(float a, float b, float c, float d, float e);
};

Vector5* Vector5::set(float a, float b, float c, float d, float e)
{
    x = a;
    kind = 5;
    y = b;
    z = c;
    w = d;
    v = e;
    return this;
}
