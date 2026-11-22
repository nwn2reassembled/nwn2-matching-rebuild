struct LegacyObject {
    void copyFrom(const float* src);
};

void LegacyObject::copyFrom(const float* src) {
    *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x11c) = src[0];
    *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x120) = src[1];
    *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x124) = src[2];

    *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x134) =
        *reinterpret_cast<const float*>(reinterpret_cast<const char*>(this) + 0x1a8);
    *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x138) =
        *reinterpret_cast<const float*>(reinterpret_cast<const char*>(this) + 0x1ac);
    *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x13c) =
        *reinterpret_cast<const float*>(reinterpret_cast<const char*>(this) + 0x1b0);
}

