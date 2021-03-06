#include "lists.h"

/**
 *insert_dnodeint_at_index - inserts a new node at a given position.
 *@h: head address.
 *@idx: position of the node.
 *@n: int n.
 * Return: address of the new node idx.
 */

dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *newNodeIdx, *auxNode, *auxNodeProx;
	unsigned int count = 0;

	newNodeIdx = malloc(sizeof(dlistint_t));
	if (newNodeIdx == NULL)
		return (NULL);

	newNodeIdx->n = n;
	auxNode = *h;
	if (idx == 0)
	{
		return (add_dnodeint(h, n));
	} else if (idx == 1)
	{
		auxNodeProx = auxNode->next;
		auxNode->next = newNodeIdx;
		newNodeIdx->next = auxNodeProx;
		auxNodeProx->prev = newNodeIdx;
		newNodeIdx->prev = auxNode;
		return (newNodeIdx);
	}
	while (count != idx - 1 && auxNode != NULL)
	{
		auxNode = auxNode->next;
		if (auxNode == NULL)
			return (NULL);
		auxNodeProx = auxNode->next;
		count++;
	}
	if (count < idx - 1)
		return (NULL);
	if (auxNodeProx == NULL)
		return (add_dnodeint_end(h, n));
	auxNode->next = newNodeIdx;
	newNodeIdx->next = auxNodeProx;
	newNodeIdx->prev = auxNode;
	if (auxNodeProx != NULL)
		auxNodeProx->prev = newNodeIdx;
	return (newNodeIdx);
}
