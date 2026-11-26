class CSetVec3 {
public:
    void SetField3(const float* src);
private:
    unsigned char pad[0x738];
    float x;
    float y;
    float z;
};

void CSetVec3::SetField3(const float* src)
{
    x = src[0];
    y = src[1];
    z = src[2];
}
