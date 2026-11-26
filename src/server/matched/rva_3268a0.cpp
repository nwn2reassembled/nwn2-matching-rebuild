struct EngineObject {
    unsigned int state;
    void* nested;

    int GetStateOut(unsigned int* outState, void** outNested);
};

int EngineObject::GetStateOut(unsigned int* outState, void** outNested)
{
    if (this->state != 3)
        return 0;
    *outState = 3;
    *outNested = this->nested;
    return 1;
}
