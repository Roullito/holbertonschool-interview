#include <stdlib.h>
#include "lists.h"

listint_t *insert_node(listint_t **head, int number)
{
    listint_t *new;
    listint_t *prev = NULL;
    listint_t *curr;

    /* 1) valider head */
    /* 2) malloc new + init */
    /* 3) si liste vide ou insertion avant head -> cas spécial */
    /* 4) sinon: avancer prev/curr jusqu'à la position */
    /* 5) recoller les pointeurs */
    /* 6) return new (ou NULL si malloc fail) */
}
