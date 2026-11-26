struct NeighborQuad { unsigned int first, second, third, fourth; };
struct NeighborQuads {
    NeighborQuad* data;
    NeighborQuad* getAt(unsigned int index);
};
NeighborQuad* NeighborQuads::getAt(unsigned int index) { return data + index; }
