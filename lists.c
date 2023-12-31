#include "shell.h"

/**
 * add_node - at the start of the list a new node is added
 * @head: pointer to head node address
 * @str: string field of the node
 * @num: This is the node index used by history
 *
 * Return: On return, size of list
 */
list_t *add_node(list_t **head, const char *str, int num)
{
	list_t *new_head;

	if (!head)
		return (NULL);
	new_head = malloc(sizeof(list_t));
	if (!new_head)
		return (NULL);
	_memset((void *)new_head, 0, sizeof(list_t));
	new_head->num = num;
	if (str)
	{
		new_head->str = _strdup(str);
		if (!new_head->str)
		{
			free(new_head);
			return (NULL);
		}
	}
	new_head->next = *head;
	*head = new_head;
	return (new_head);
}

/**
 * add_node_end - at the end of the list, a node is added
 * @head: This is the address of pointer to head node
 * @str: This is the string field of the node
 * @num: This is the node index used by history
 *
 * Return: Return as size of list
 */
list_t *add_node_end(list_t **head, const char *str, int num)
{
	list_t *new_node, *node;

	if (!head)
		return (NULL);

	node = *head;
	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);
	_memset((void *)new_node, 0, sizeof(list_t));
	new_node->num = num;
	if (str)
	{
		new_node->str = _strdup(str);
		if (!new_node->str)
		{
			free(new_node);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = new_node;
	}
	else
		*head = new_node;
	return (new_node);
}

/**
 * print_list_str - will print only the str element of a list_t linked list
 * @h: pointer to first node address
 *
 * Return: return as size of list
 */
size_t print_list_str(const list_t *h)
{
	size_t d = 0;

	while (h)
	{
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		d++;
	}
	return (d);
}

/**
 * delete_node_at_index - This will delete the node at a given index
 * @head: pointer to first node address
 * @index: This is the index of the node to be deleted
 *
 * Return: on success 1 , on failure 0
 */
int delete_node_at_index(list_t **head, unsigned int index)
{
	list_t *node, *prev_node;
	unsigned int d = 0;

	if (!head || !*head)
		return (0);

	if (!index)
	{
		node = *head;
		*head = (*head)->next;
		free(node->str);
		free(node);
		return (1);
	}
	node = *head;
	while (node)
	{
		if (d == index)
		{
			prev_node->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		d++;
		prev_node = node;
		node = node->next;
	}
	return (0);
}

/**
 * free_list - This will free up all nodes of a list
 * @head_ptr: pointer to head node address
 *
 * Return: return void
 */
void free_list(list_t **head_ptr)
{
	list_t *node, *next_node, *head;

	if (!head_ptr || !*head_ptr)
		return;
	head = *head_ptr;
	node = head;
	while (node)
	{
		next_node = node->next;
		free(node->str);
		free(node);
		node = next_node;
	}
	*head_ptr = NULL;
}
