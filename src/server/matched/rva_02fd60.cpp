struct XForm {
    float m[12];
    float t[4];
};

void InitXForm(XForm* out, const float* translation)
{
    out->m[0] = 1.0f;
    out->m[1] = 0.0f;
    out->m[2] = 0.0f;
    out->m[3] = 0.0f;
    out->m[4] = 0.0f;
    out->m[6] = 0.0f;
    out->m[7] = 0.0f;
    out->m[8] = 0.0f;
    out->m[9] = 0.0f;
    out->m[11] = 0.0f;
    out->m[5] = 1.0f;
    out->m[10] = 1.0f;
    out->t[0] = translation[0];
    out->t[1] = translation[1];
    out->t[2] = translation[2];
    out->t[3] = 1.0f;
}
