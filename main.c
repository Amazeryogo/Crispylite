/* so basically a memory only database */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

/* store the data in memory */
struct data {
    char *key;
    char *value;
    struct data *next;
};

int store(char *key, char *value, struct data **head){
    struct data *new_node = malloc(sizeof(struct data));
    if(new_node == NULL){
        return -1;
    }
    new_node->key = key;
    new_node->value = value;
    new_node->next = *head;
    *head = new_node;
    return 0;
}

int retrieve(char *key, struct data *head, char **value){
    struct data *current = head;
    while(current != NULL){
        if(strcmp(current->key, key) == 0){
            *value = current->value;
            return 0;
        }
        current = current->next;
    }
    return -1;
}

int main(){
    /* ask for a input, if the first word is store, then store the key and value */
    /* if the first word is retrieve, then retrieve the value */
    /* if the first word is quit, then quit the program */
    char *input = NULL;
    size_t size = 0;
    struct data *head = NULL;
    printf("Welcome to crispylite\n");
    printf(">");
    scanf("%m[^\n]", &input);
    getchar();
    while(strcmp(input, "quit") != 0){
        if(strcmp(input, "store") == 0){
            char *key = NULL;
            char *value = NULL;
            printf("key: ");
            scanf("%m[^\n]", &key);
            getchar();
            printf("value: ");
            scanf("%m[^\n]", &value);
            getchar();
            store(key, value, &head);
        } else if(strcmp(input, "retrieve") == 0){
            char *key = NULL;
            char *value = NULL;
            printf("key: ");
            scanf("%m[^\n]", &key);
            getchar();
            retrieve(key, head, &value);
            printf("value: %s\n", value);
        } else {
            printf("invalid input\n");
        }
        printf(">");
        scanf("%m[^\n]", &input);
        getchar();
    }
}
    