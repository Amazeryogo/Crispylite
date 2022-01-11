/* so basically a memory only database */
#include "main.h"

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
    