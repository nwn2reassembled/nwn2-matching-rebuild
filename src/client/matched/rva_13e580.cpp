class VertexBuffer {
public:
    int count;
    int pad;
    int stride;
    int pad2[2];
    char* base;

    void* __cdecl GetElement(int index);
};

void* __cdecl VertexBuffer::GetElement(int index)
{
    if (index < 0 || index >= count)
        return 0;
    return base + stride * index;
}
