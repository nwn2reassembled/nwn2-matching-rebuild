struct TreeNode
{
    TreeNode* _Left;
    char _Unused[0x11];
    char _Isnil;
};

TreeNode* FindLeftmost(TreeNode* _Node)
{
    while (!_Node->_Left->_Isnil)
        _Node = _Node->_Left;

    return _Node;
}
