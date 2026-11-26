bool __stdcall IsSpecialKey(unsigned short key)
{
    return key == 200 || key == 201 || key == 202 ||
           key == 263 || key == 264 || key == 265 ||
           key == 203 || key == 204 || key == 205;
}
