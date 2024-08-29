/** @example test_main_list_advanced.c
* In questo esempio si mostrano le funzioni riguardanti le VectorList implementate in main_list
*/

#include "main_list.h"

int main(void) {
	int values[] = { 1,2,3 };
	size_t vecs_size = sizeof(values) / sizeof(int);

	// crea una lista a partire dal vettore values
    Item* list =  MainCreateListFromVector(values, vecs_size);

    // crea un VectorList a partire da list
	VectorList* vl = MainListGetItemAddresses(list);

	// confronta gli indirizzi presenti in vl->addresses con gli indirizzi di list 
	bool is_equal = MainListCompareWithAddressesVector(vl, list);
	if(!is_equal) return -1;

	// stampa su file (stdout) vl->addresses e vl->values corrispondenti 
	MainListWriteListByAddressesWithAddresses(vl, stdout);

	// elimina vl
	VectorListDelete(vl);

	return EXIT_SUCCESS;
}