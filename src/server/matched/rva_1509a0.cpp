struct NeighborLength {
    unsigned int* data;
    unsigned int capacity;
    unsigned int length;
    unsigned int getLength();
};
unsigned int NeighborLength::getLength() { return length; }
