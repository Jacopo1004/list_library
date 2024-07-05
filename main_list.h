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
 *  @brief RESTITUISCE IL VALORE MAGGIORE TRA DUE INTERI.
 * 
 *  @param a Primo numero intero da confrontare.
 *  @param b Secondo numero intero da confrontare.
 * 
 *  @return IL VALORE MAGGIORE TRA a E b.
 */

int mymax(int a, int b);

/**
 *  @brief RESTITUISCE IL VALORE MINORE TRA DUE INTERI.
 * 
 *  @param a Primo numero intero.
 *  @param b Secondo numero intero.
 * 
 *  @return IL VALORE MINORE TRA a E b.
 */
 
int mymin(int a, int b);

/**
 *  @brief VERIFICA SE UNA LISTA È ORDINATA IN ORDINE CRESCENTE.
 * 
 *  @param i Puntatore alla testa della lista da verficare.
 *  
 *  @return TRUE SE LA LISTA È VUOTA O ORDINATA IN ORDINE CRESCENTE, FALSE ALTRIMENTI. 
 */

bool IsOrdered(Item* i);

/**
 *  @brief CONFRONTA DUE LISTE DI ELEMENTI.
 * 
 *  @param i1 Puntatore alla testa della prima lista da confrontare.
 *  @param i2 Puntatore alla testa della seconda lista da confrontare.
 *  
 *  @return TRUE SE LE LISTE SONO UGUALI (HANNO GLI STESSI VALORI NELLO STESSO ORDINE), 
 *          FALSE ALTRIMENTI. 
 */

bool MainConfrontaListe(Item* i1, Item* i2);

/**
 *  @brief CREA UNA COPIA DI UNA LISTA.
 * 
 *  @param l Puntatore alla testa della lista da copiare.
 *  
 *  @return UN PUNTATORE ALLA TESTA DELLA NUOVA LISTA.
 */

Item* MainCopyList(const Item* l);

/**
 *  @brief CREA UNA LISTA A PARTIRE DA UN ARRAY DI INTERI.
 * 
 *  @param v Puntatore all'array di interi da copiare.
 *  @param v_size Dimensione dell'array.
 *  
 *  @return UN PUNTATORE ALLA TESTA DELLA LISTA CREATA A PARTIRE DALL'ARRAY.
 */

Item* MainCreateListFromVector(const int *v, size_t v_size);

/**
 *  @brief VERIFICA SE UN ELEMENTO È PRESENTE IN UNA LISTA.
 * 
 *  @param e Puntatore all'elemento da cercare nella lista.
 *  @param i Puntatore alla testa della lista in cui cercare l'elemento.
 *  
 *  @return TRUE SE L'ELEMENTO È PRESENTE NELLA LISTA, FALSE ALTRIMENTI.
 */

bool MainIsMember(const ElemType *e, Item* i);

/**
 *  @brief CALCOLA LA LUNGHEZZA DI UNA LISTA.
 * 
 *  @param i Puntatore alla testa della lista di cui calcolare la lunghezza.
 *  
 *  @return IL NUMERO DI ELEMENTI NELLA LISTA.
 */

int GetLength(const Item* l);

/**
 *  @brief SCRIVE SU UN FILE LA RAPPRESENTAZIONE DELLA LISTA CON INDIRIZZI E VALORI.
 * 
 *  @param i Puntatore alla testa della lista da stampare.
 *  @param f Puntatore al file su cui scrivere gli indirizzi e i valori. 
 */

void WriteListWithAddresses(const Item *i, FILE *f);

/**
 *  @brief STAMPA A VIDEO LA RAPPRESENTAZIONE DELLA LISTA CON INDIRIZZI E VALORI.
 * 
 *  @param i Puntatore alla testa della lista da stampare.
 */

void ListWriteStdoutWithAddresses(const Item *i);

/**
 *  @brief VERIFICA L'UGUAGLIANZA TRA DUE ELEMENTI.
 * 
 *  @param e1 Puntatore al primo elemento da confrontare. 
 *  @param e2 Puntatore al secondo elemento da confrontare.  
 *  
 *  @return TRUE SE I DUE ELEMENTI SONO UGUALI, FALSE ALTRIMENTI
 */

bool MainAreEqual(const ElemType* e1, const ElemType* e2);

/**
 *  @brief CREA UNA COPIA DI UN VETTORE DI LISTE.
 * 
 *  @param ls Vettore di puntatori alle liste da copiare.
 *  @param n Lunghezza del vettore.
 *  
 *  @return IL NUMERO DI ELEMENTI NELLA LISTA.
 */

Item** MainCopyVectorOfLists(Item** ls, int n);

/**
 *  @brief STRUTTURA CHE RAPPRESENTA UN VETTORE DI LISTE:
 *  -addresses: ARRAY DI PUNTATORI ALLE LISTE, RAPPRESENTANTI GLI INDIRIZZI DEGLI ELEMENTI.
 *  -values: ARRAY DI ELEMENTI, RAPPRESENTANTI I VALORI DEGLI ELEMENTI.
 *  -vecs_size: DIMENSIONE DEGLI ARRAY addresses E values.
 */

typedef struct {
    Item** addresses;
    ElemType* values;
    size_t vecs_size;
} VectorList;

/**
 *  @brief ELIMINA UN VectorList E NE DEALLOCA LA MEMORIA.
 * 
 *  @param vl VectorList da eliminare e deallocare.
 */

void VectorListDelete(VectorList* vl);

/**
 *  @brief CREA UN VectorList CONTENENTE GLI ELEMENTI DELLA LISTA PASSATA COME PARAMETRO.
 * 
 *  @param i Puntatore alla testa della lista da cui prendere i valori.
 * 
 *  @return UN NUOVO VectorList CONTENENTE INDIRIZZI E VALORI DEGLI ELEMENTI E LA LORO GRANDEZZA.
 */

VectorList* MainListGetItemAddresses(Item* i);

/**
 *  @brief VERIFICA SE GLI INDIRIZZI DELLA LISTA SONO UGUALI A QUELLI CONTENUTI IN VectorList. 
 * 
 *  @param vl Puntatore al VectorList contenente gli indirizzi da confrontare.
 *  @param list Puntatore alla testa della lista da confrontare.
 * 
 *  @return TRUE SE LA LISTA HA GLI STESSI INDIRIZZI DI QUELLI CONENUTI IN VectorList, 
 *  FALSE ALTRIMENTI.
 */

bool MainListCompareWithAddressesVector(const VectorList* vl, const Item* list);

/**
 *  @brief SCRIVE SU UN FILE UNA LISTA DI INDIRIZZI E VALORI CONENUTI IN VectorList. 
 * 
 *  @param vl Puntatore al VectorList contenente gli indirizzi e i valori da scrivere.
 *  @param f Puntatore al file su cui scrivere gli indirizzi e i valori.
 */

void MainListWriteListByAddressesWithAddresses(const VectorList* vl, FILE* f);

#endif