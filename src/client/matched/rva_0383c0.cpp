long double Vector3_Dot(const float *a, const float *b)
{
    return (long double)a[2] * b[2] + (long double)a[1] * b[1] + (long double)a[0] * b[0];
}
