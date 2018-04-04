#include <stdlib.h>
#include <string.h>
#include "constants.h"
#include "types.h"

struct Channel *create_channel(int id, char *name, char *password, char *key) {
    struct Channel *channel = calloc(sizeof(struct Channel), 1);
    channel->id = id;
    strncpy(channel->name, name, NAME_SIZE);
    strncpy(channel->password, password, PASSWORD_SIZE);
    channel->key = key;
    return channel;
}

struct Post *create_post(char *text) {
    struct Post *post = calloc(sizeof(struct Post), 1);
    post->text = text;
    return post;
}

void append_post(struct Post **head, struct Post *post){
    if (!*head){
        *head = post;
        return;
    }
    struct Post *current = *head;
    while (current->next) {
        current = current->next;
    }
    current->next = post;
}

void delete_channel(struct Channel* channel){
    free(channel->key);
    struct Post *current = channel->posts;
    while (current) {
        struct Post *post = current;
        current = current->next;
        free(post);
    }
    free(channel);
}