struct Matrix44 {
    float m[16];
};

void __cdecl MakeScaleMatrix(Matrix44 *out, float sx, float sy, float sz)
{
    out->m[0] = sx;
    out->m[1] = 0.0f;
    out->m[2] = 0.0f;
    out->m[3] = 0.0f;
    out->m[4] = 0.0f;
    out->m[5] = sy;
    out->m[6] = 0.0f;
    out->m[7] = 0.0f;
    out->m[8] = 0.0f;
    out->m[9] = 0.0f;
    out->m[10] = sz;
    out->m[11] = 0.0f;
    out->m[12] = 0.0f;
    out->m[13] = 0.0f;
    out->m[14] = 0.0f;
    out->m[15] = 1.0f;
}
