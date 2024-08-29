/** @example test_main_list.c
* In questo esempio si mostrano le funzioni riguardanti le liste implementate in main_list
*/

#include "main_list.h"

int main(void) {
	int v[] = { 1,2,3,4,5,6,7,8,9 };
    size_t v_size = sizeof(v) / sizeof(int);

    // crea una lista a partire dal vettore v
    Item* list =  MainCreateListFromVector(v, v_size);

    // controlla se la lista è in ordine
    bool is_ordered = IsOrdered(list);
    if(!is_ordered) return -1;

    // copia la lista list
    Item* list2 = MainCopyList(list);

    // confronta le due liste
    bool list_is_equal = MainConfrontaListe(list, list2);
    if(!list_is_equal) return -2;

    ElemType e = 3;

    // controlla se e è presente in list
    bool is_member = MainIsMember(&e, list);
    if(!is_member) return -3;

    // controlla la lunghezza
    int lenght = GetLength(list);
    if(lenght != (int)v_size) return -4;

    // stampa la lista su stdout
    MainListWriteStdoutWithAddresses(list);

    ElemType e2 = 3;

    // controllo se e ed e2 sono uguali
    bool elem_is_equal = MainAreEqual(&e, &e2);
    if(!elem_is_equal) return -5;

	return EXIT_SUCCESS;
}