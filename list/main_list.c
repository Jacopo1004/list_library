#include "main_list.h"

int mymax(int a, int b) { if (a > b)  return a; else return b; }

int mymin(int a, int b) { if (a < b) return a; else return b; }

bool IsOrdered(Item* i) {
    if (ListIsEmpty(i)) {
        return true;
    }

    while (!ListIsEmpty(ListGetTail(i))) {
        if (*ListGetHeadValue(i) > *ListGetHeadValue(ListGetTail(i))) {
            return false;
        }
        i = ListGetTail(i);
    }
    return true;
}

bool MainConfrontaListe(Item* i1, Item* i2) {
    for (; !ListIsEmpty(i1) && !ListIsEmpty(i2); i1 = ListGetTail(i1), i2 = ListGetTail(i2)) {
        if (ElemCompare(&i1->value, &i2->value) != 0) {
            return false;
        }
    }
    if (ListIsEmpty(i1) && ListIsEmpty(i2)) {
        return true;
    }
    return false;
}

Item* MainCopyList(const Item* l) {
    Item* n = ListCreateEmpty();

    while (!ListIsEmpty(l)) {
        n = ListInsertBack(n, &l->value);
        l = l->next;
    }

    return n;
}

Item* MainCreateListFromVector(const int *v, size_t v_size) {
    Item *list = ListCreateEmpty();
    for (size_t i = 0; i < v_size; ++i) {
        list = ListInsertBack(list, &v[i]);
    }
    return list;
}

bool MainIsMember(const ElemType *e, Item* i) {
    while (!ListIsEmpty(i)) {
        if (ElemCompare(e, ListGetHeadValue(i)) == 0) {
            return true;
        }

        i = ListGetTail(i);
    }
    return false;
}

int GetLength(const Item* l) {
    int length = 0;
    while (!ListIsEmpty(l)) {
        length++;
        l = l->next;
    }
    return length;
}

void MainListWriteWithAddresses(const Item* i, FILE* f) {
    fprintf(f, "[");
    while (!ListIsEmpty(i)) {
        fprintf(f, "(%p) ", (void*)i);
        ElemWrite(&i->value, f);
        i = ListGetTail(i);
        if (!ListIsEmpty(i)) {
            fprintf(f, ", ");
        }
    }
    fprintf(f, "]\n");
}

void MainListWriteStdoutWithAddresses(const Item *i) {
    MainListWriteWithAddresses(i, stdout);
}

bool MainAreEqual(const ElemType* e1, const ElemType* e2) {
    if (*e1 == *e2) {
        return true;
    }
    return false;
}

Item** MainCopyVectorOfLists(Item** ls, int n) {
    Item** new_ls = malloc(sizeof(Item*) * n);
    for (int i = 0; i < n; ++i) {
        new_ls[i] = MainCopyList(ls[i]);
    }
    return new_ls;
}

void VectorListDelete(VectorList* vl) {
    for (size_t i = 0; i < vl->vecs_size; ++i) {
        ElemDelete(&vl->values[i]);
    }
    free(vl->values);
    free(vl->addresses);
    free(vl);
}

VectorList* MainListGetItemAddresses(Item* i) {
    VectorList* vl = malloc(sizeof(VectorList));
    vl->addresses = NULL;
    vl->values = NULL;
    vl->vecs_size = 0;
    for (; !ListIsEmpty(i); i = ListGetTail(i)) {
        (vl->vecs_size)++;
        vl->addresses = realloc(vl->addresses, vl->vecs_size * sizeof(Item*));
        vl->addresses[vl->vecs_size - 1] = i;
        vl->values = realloc(vl->values, vl->vecs_size * sizeof(ElemType));
        vl->values[vl->vecs_size - 1] = ElemCopy(&i->value);
    }
    return vl;
}

bool MainListCompareWithAddressesVector(const VectorList* vl, const Item* list) {
    // N.B. Se hanno lo stesso indirizzo hanno anche gli stessi valori!
    size_t list_len = 0;
    for (size_t i = 0; i < vl->vecs_size && !ListIsEmpty(list); ++i) {
        if (vl->addresses[i] != list) {
            return false;
        }
        list = ListGetTail(list);
        list_len++;
    }
    if (list_len != vl->vecs_size || !ListIsEmpty(list)) {
        return false;
    }

    return true;
}

void MainListWriteListByAddressesWithAddresses(const VectorList* vl, FILE* f) {
    fprintf(f, "[");
    for (size_t i = 0; i < vl->vecs_size; ++i) {
        fprintf(f, "(%p) ", (void*)vl->addresses[i]);
        ElemWrite(&vl->values[i], f);
        if (i != vl->vecs_size - 1) {
            fprintf(f, ", ");
        }
    }
    fprintf(f, "]\n");
}
