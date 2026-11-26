struct NeighborPair { unsigned int first, second; };
struct NeighborPairs {
    NeighborPair* data;
    NeighborPair* getAt(unsigned int index);
};
NeighborPair* NeighborPairs::getAt(unsigned int index) { return data + index; }
