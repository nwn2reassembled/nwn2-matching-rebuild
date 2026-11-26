struct CacheHeader {
    char reserved[0x34];
    unsigned int capacity;
};

struct CacheRequest {
    char reserved[0x8];
    unsigned int offset;
};

class CacheBlock {
    char reserved0[0x50];
    CacheHeader* header;
    char reserved1[0x2c];
    char* data;
public:
    void* Acquire(CacheRequest* request, unsigned int* remaining);
};

void* CacheBlock::Acquire(CacheRequest* request, unsigned int* remaining)
{
    if (request == 0 || data == 0)
        return 0;

    CacheHeader* h = header;
    unsigned int offset = request->offset;
    unsigned int limit = h->capacity;
    if (offset >= limit)
        return 0;

    *remaining = limit - offset;
    return data + request->offset;
}
