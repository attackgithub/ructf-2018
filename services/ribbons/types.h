#ifndef NEWS_TYPES_H
#define NEWS_TYPES_H

#include "constants.h"

struct Channel {
    int id;
    char name[NAME_SIZE];
    char password[PASSWORD_SIZE];
    char *key;
    struct Post *posts;
};

struct Post {
    char *text;
    struct Post *next;
};


struct Channel *create_channel(int id, char *name, char *password, char* key);
struct Post *create_post(char *text);
void append_post(struct Post **head, struct Post *post);
void delete_channel(struct Channel* channel);

#endif //NEWS_TYPES_H
