struct Angles {
    float yaw;
    float pitch; // +0x4c from struct start; simplified below
    float pad[0x11];
    float x;
    float y;
};

class CPosSetter {
public:
    void __thiscall Set(float fx, float fy);
private:
    unsigned char pad0[0x4c];
    float x; // +0x4c
    float y; // +0x50
};

void __thiscall CPosSetter::Set(float fx, float fy) {
    this->x = fx;
    this->y = fy;
}
