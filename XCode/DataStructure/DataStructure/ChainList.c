//
//  ChainList.c
//  DataStructure
//
//  Created by 杨辉 on 10/21/15.
//  Copyright © 2015 杨辉. All rights reserved.
//

#include "ChainList.h"

typedef struct LNode{
    ElemType    data;
    
    struct LNode    * next;
}LNode;

Status GetElem_L(LinkList L, int i, ElemType &e) {
    
    p = L -> next; j = 1;
    
    while (p && j < i) {
        p = p -> next; ++j;
    }
    
    if (!p || j > i) return ERROR;
    
    e = p -> data;
    
    return;
}


Status ListInsert_L(LinkList &L, int i, ElemType e) {
    p = L; j  = 0;
    
    while (p && j < i - 1) {
        p = p -> next;
        ++j;
    }
    
    if( !p || j > i-1) return ERROR;
    
    s = (LinkList) malloc (sizeof(LNode));
    
    s -> data = e; s -> next = p -> next;
    
    p -> next = s;
    
    return OK;
}