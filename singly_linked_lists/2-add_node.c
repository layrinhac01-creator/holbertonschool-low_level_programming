#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node - adds a new node at the beginning of a list_t list
 * @head: double pointer to the head of the list
 * @str: string to duplicate and store in the new node
 *
 * Return: address of the new element, or NULL if it failed
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new_node;
	char *dup_str;
	unsigned int len = 0;

	if (head == NULL)
		return (NULL);

	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
		return (NULL);

	if (str != NULL)
	{
		dup_str = strdup(str);
		if (dup_str == NULL)
		{
			free(new_node);
			return (NULL);
		}
		while (str[len] != '\0')
			len++;
	}
	else
	{
		dup_str = NULL;
		len = 0;
	}

	new_node->str = dup_str;
	new_node->len = len;
	new_node->next = *head;
	*head = new_node;

	return (new_node);
}
