#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

/* store the data in memory */
struct data
{
    char *key;
    char *value;
    struct data *next;
};

int store(char *key, char *value, struct data **head)
{
    struct data *new_node = malloc(sizeof(struct data));
    if (new_node == NULL)
    {
        return -1;
    }
    new_node->key = key;
    new_node->value = value;
    new_node->next = *head;
    *head = new_node;
    return 0;
}

int retrieve(char *key, struct data *head, char **value)
{
    struct data *current = head;
    while (current != NULL)
    {
        if (strcmp(current->key, key) == 0)
        {
            *value = current->value;
            return 0;
        }
        current = current->next;
    }
    return -1;
}
int delete(char *key, struct data **head)
{
    struct data *current = *head;
    struct data *previous = NULL;
    while (current != NULL)
    {
        if (strcmp(current->key, key) == 0)
        {
            if (previous == NULL)
            {
                *head = current->next;
            }
            else
            {
                previous->next = current->next;
            }
            free(current);
            return 0;
        }
        previous = current;
        current = current->next;
    }
    return -1;
}