#ifndef MAIN_LIST_H
#define MAIN_LIST_H 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include "elemtype.h"
#include "list.h"

/**
 *  @brief Restituisce il valore maggiore tra due interi.
 * 
 *  @param a Primo numero intero da confrontare.
 *  @param b Secondo numero intero da confrontare.
 * 
 *  @return Il valore maggiore tra a e b.
 */

int mymax(int a, int b);

/**
 *  @brief Restituisce il valore minore tra due interi.
 * 
 *  @param a Primo numero intero.
 *  @param b Secondo numero intero.
 * 
 *  @return Il valore minore tra a e b.
 */
 
int mymin(int a, int b);

/**
 *  @brief Verifica se una lista è ordinata in ordine crescente.
 * 
 *  @param i Puntatore alla testa della lista da verficare.
 *  
 *  @return True se la lista è vuota o ordinata in ordine crescente, false altrimenti.
 */

bool IsOrdered(Item* i);

/**
 *  @brief Confronta due liste di elementi.
 * 
 *  @param i1 Puntatore alla testa della prima lista da confrontare.
 *  @param i2 Puntatore alla testa della seconda lista da confrontare.
 *  
 *  @return True se le liste sono uguali (hanno gli stessi valori nello stesso ordine), false altrimenti.
 */

bool MainConfrontaListe(Item* i1, Item* i2);

/**
 *  @brief Crea una copia di una lista.
 * 
 *  @param l Puntatore alla testa della lista da copiare.
 *  
 *  @return Un puntatore alla testa della nuova lista.
 */

Item* MainCopyList(const Item* l);

/**
 *  @brief Crea una lista a partire da un array di interi.
 * 
 *  @param v Puntatore all'array di interi da copiare.
 *  @param v_size Dimensione dell'array.
 *  
 *  @return Un puntatore alla testa della lista creata a partire dall'array.
 */

Item* MainCreateListFromVector(const int *v, size_t v_size);

/**
 *  @brief Verifica se un elemento è presente in una lista.
 * 
 *  @param e Puntatore all'elemento da cercare nella lista.
 *  @param i Puntatore alla testa della lista in cui cercare l'elemento.
 *  
 *  @return True se l'elemento è presente nella lista, false altrimenti.
 */

bool MainIsMember(const ElemType *e, Item* i);

/**
 *  @brief Calcola la lunghezza di una lista.
 * 
 *  @param i Puntatore alla testa della lista di cui calcolare la lunghezza.
 *  
 *  @return Il numero di elementi nella lista.
 */

int GetLength(const Item* l);

/**
 *  @brief Scrive su un file la rappresentazione della lista con indirizzi e valori.
 * 
 *  @param i Puntatore alla testa della lista da stampare.
 *  @param f Puntatore al file su cui scrivere gli indirizzi e i valori. 
 */

void WriteListWithAddresses(const Item *i, FILE *f);

/**
 *  @brief Stampa a video la rappresentazione della lista con indirizzi e valori.
 * 
 *  @param i Puntatore alla testa della lista da stampare.
 */

void ListWriteStdoutWithAddresses(const Item *i);

/**
 *  @brief Verifica l'uguaglianza tra due elementi.
 * 
 *  @param e1 Puntatore al primo elemento da confrontare. 
 *  @param e2 Puntatore al secondo elemento da confrontare.  
 *  
 *  @return True se i due elementi sono uguali, false altrimenti.
 */

bool MainAreEqual(const ElemType* e1, const ElemType* e2);

/**
 *  @brief Crea una copia di un vettore di liste.
 * 
 *  @param ls Vettore di puntatori alle liste da copiare.
 *  @param n Lunghezza del vettore.
 *  
 *  @return Un puntatore alla testa del nuovo vettore di liste.
 */

Item** MainCopyVectorOfLists(Item** ls, int n);

/**
 *  @brief Struttura che rappresenta un vettore di liste:
 *  -addresses: Array di puntatori alle liste, rappresentanti gli indirizzi degli elementi.
 *  -values: Array di elementi, rappresentanti i valori degli elementi.
 *  -vecs_size: Dimensione degli array addresses e values.
 */

typedef struct {
    Item** addresses;
    ElemType* values;
    size_t vecs_size;
} VectorList;

/**
 *  @brief Elimina un vettore di liste e ne dealloca la memoria.
 * 
 *  @param vl VectorList da eliminare e deallocare.
 */

void VectorListDelete(VectorList* vl);

/**
 *  @brief Crea un vettore di liste contenente gli elementi della lista passata come parametro.
 * 
 *  @param i Puntatore alla testa della lista da cui prendere i valori.
 * 
 *  @return Un puntatore alla testa del vettore di liste contenente indirizzi e valori degli elementi e la loro grandezza.
 */

VectorList* MainListGetItemAddresses(Item* i);

/**
 *  @brief Verifica se gli indirizzi della lista sono uguali a quelli contenuti nel vettore di liste.
 * 
 *  @param vl Puntatore al VectorList contenente gli indirizzi da confrontare.
 *  @param list Puntatore alla testa della lista da confrontare.
 * 
 *  @return True se la lista ha gli stessi indirizzi di quelli contenuti nel vettore di liste, false altrimenti.
 */

bool MainListCompareWithAddressesVector(const VectorList* vl, const Item* list);

/**
 *  @brief Scrive su un file una lista di indirizzi e valori contenuti nel vettore di liste.
 * 
 *  @param vl Puntatore al VectorList contenente gli indirizzi e i valori da scrivere.
 *  @param f Puntatore al file su cui scrivere gli indirizzi e i valori.
 */

void MainListWriteListByAddressesWithAddresses(const VectorList* vl, FILE* f);

#endif
