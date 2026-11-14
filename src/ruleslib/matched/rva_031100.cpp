struct Legacy {
    static int __stdcall getValue(int* ptr);
};

int Legacy::getValue(int* ptr)
{
    return ptr[376];
}

