#include "main.h"

int main(){
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
        }else if(strcmp(input, "delete") == 0){
            char *key = NULL;
            printf("key: ");
            scanf("%m[^\n]", &key);
            getchar();
            delete(key, &head);
        } else if(strcmp(input,"help") == 0){
            printf("store: store a key and value\n");
            printf("retrieve: retrieve a value\n");
            printf("delete: delete a key\n");
            printf("quit: quit the program\n");
        } else {
            printf("invalid input\n");
        }
        printf(">");
        scanf("%m[^\n]", &input);
        getchar();
    }
}
    