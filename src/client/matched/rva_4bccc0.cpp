struct InnerBlock {
    unsigned short w0;
    unsigned short w2;
    unsigned char pad[20];
    int dw;
    unsigned char tail[4];
};

struct OuterThing {
    unsigned char head[20];
    InnerBlock data;
    InnerBlock dataCopy;
};

void ResetThing(OuterThing* thing)
{
    InnerBlock* p = &thing->data;
    p->w2 = 0;
    p->w0 = 0;
    p->dw = 0;
    thing->dataCopy = *p;
}
