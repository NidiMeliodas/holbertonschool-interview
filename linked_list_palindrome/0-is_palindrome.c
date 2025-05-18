#include "lists.h"
#include <stddef.h>

/* Helper function to reverse a linked list */
static listint_t *reverse_list(listint_t *head)
{
	listint_t *prev = NULL, *next = NULL;

	while (head != NULL)
	{
		next = head->next;
		head->next = prev;
		prev = head;
		head = next;
	}

	return prev;
}

int is_palindrome(listint_t **head)
{
	listint_t *slow, *fast, *second_half, *first_half;
	int palindrome = 1;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		return 1; /* Empty or single node list is palindrome */

	slow = fast = *head;

	/* Find middle using slow and fast pointers */
	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	/* Reverse second half */
	second_half = reverse_list(slow);

	/* Save pointer to restore list later */
	first_half = *head;

	/* Compare first half and reversed second half */
	while (second_half != NULL)
	{
		if (first_half->n != second_half->n)
		{
			palindrome = 0;
			break;
		}
		first_half = first_half->next;
		second_half = second_half->next;
	}

	/* Restore the second half */
	slow = reverse_list(slow);

	return palindrome;
}
