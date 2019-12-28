//
// Created by 陈思贝 on 2019/12/25.
//

#include <iostream>

using namespace std;

#define MAX_TREE_SIZE 100
typedef int DATA_TYPE;
// 孩子节点
typedef struct CTNode {
    int index;
    CTNode *next;
} *ChildPtr;

// 头节点
typedef struct {
    DATA_TYPE data;
    ChildPtr firstChild;
} CTBox;

// 树结构
typedef struct {
    CTBox nodes[MAX_TREE_SIZE];
    // 根节点的位置和节点数
    int r, n;
} CTree;


