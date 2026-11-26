unsigned int Foo(void* self, unsigned int value)
{
    unsigned int* p = (unsigned int*)((char*)self + 0xd7);
    unsigned int old = *p;
    *p = value;
    return old;
}
