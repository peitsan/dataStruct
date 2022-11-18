#include<iostream>
    using namespace std;
    // 图的深度遍历DFS 非递归实现
    typedef struct Node_Type{
        int db;
        struct Node_Type *next;
    }Node_Type;

    DFS(VNode*q)