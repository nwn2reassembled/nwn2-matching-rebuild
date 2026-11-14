struct Legacy {
    int data;                            // ordinary member
    static int __stdcall getField(int* p);
};

int Legacy::getField(int* p)
{
    return *reinterpret_cast<int*>( reinterpret_cast<char*>(p) + 0xe0 );
}

