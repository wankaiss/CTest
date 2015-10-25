//
//  Liner_list.c
//  DataStructure
//
//  Created by 杨辉 on 10/20/15.
//  Copyright © 2015 杨辉. All rights reserved.
//


void union(List &La, List Lb) {
    La_len = ListLength(La); Lb_len = ListLength(Lb);
    
    for(i = 1; i <= Lb_len; i++) {
        GetElem(Lb, i, e);
        if(!LocateElem(La, e, equal)) ListInsert(La, ++La_len, e);
    }
}

void MergeList(List La, List Lb, List &Lc) {
    InitList(Lc);
    i = j = 1; k = 0;
    
    La_len = ListLength(La); Lb_len = ListLength(Lb);
    
    while ((i <= La_len) && (j <= Lb_len)) {
        GetElem(La, i, ai); GetElem(Lb, i, bi);
        if (ai <= bi) {
            ListInsert(Lc, ++k, ai);
            ++i;
        }else {ListInsert(Lc, ++k, bi);
            ++j;
        }
    }
    
    while (i <= La_len) {
        GetElem(La, i++, ai);ListInsert(Lc, ++k, ai);
    }
    
    while (j <= Lb_len) {
        GetElem(Lb, j++, bi);ListInsert(Lc, ++k ,bi);
    }
}

#define LIST_INIT_SIZE  100
#define LISTINCREMENT 10
typedef struct {
    ElemType * elem;    //存储空间基址
    
    int         length;
    int         listsize;
}

Status InitList_Sq(SqList &L){
    L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType))
    if (!L.elem) exit(OVERFLOW);
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    return OK;
}

Status ListInsert_Sq(SqList &L, int i, ElemType e) {
    if (i < 1 || i >L.Length + 1) return ERROR;
    
    if (L.Length >= L.Listsize) {
        newbase = (ElemType *)malloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof (ElemType));
        
        if (!newbase) exit(OVERFLOW);
        L.elem = newbase;
        L.listsize += LISTINCREMENT;
    }
    
    q = & (L.elem[i-1]);
    
    for (p = &(L.elem[L.length-1]); p >= q ;--p) * (p + 1) = * p;
    
    * q = e;
    ++ L.length;
    return OK;
}

Status ListDelete_Sq(SqList &L, int i, ElemType &e) {
    if((i < 1) || (i > L.length)) return ERROR;
    
    p = & (L.elem[i-1]);
    
    e = * p;
    
    q = L.elem + L.length - 1;
    
    for ( ++p; p <= q ; ++p) * (p-1) = * p;
    
    --L.length;
    
    return OK;
}

void MergeList_Sq(SqList La, SqList Lb, SqList &c) {
    pa = La.elem; pb = Lb.elem;
    
    Lc.listsize = Lc.length = La.length + Lb.length;
    
    pc = Lc.elem = (ElemType *) malloc (Lc.listsize * sizeof (ElemType));
    
    if (!Lc.elem) exit(OVERFLOW);
    
    pa_last = La.elem + La.length; pb_last = Lb.elem + Lb.length;
    
    while (pa <= pa_last && pb <= pb_last) {
        if( * pa <= * pb) *pc++ = * pa++;
        else (* pc++ = * pb++);
    }
    
    while (pa <= pa_last) * pc++ = * pa++;
    
    while (pb <= pb_last) * pc++ = * pb++;
}//MergeList_Sq
