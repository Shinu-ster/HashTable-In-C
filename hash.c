#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LENGTH 25
#define TABLE_SIZE 10

typedef struct person
{
    char name[MAX_LENGTH];
    int age;
    struct person *next;
} person;

person *hash_table[TABLE_SIZE];

unsigned int hash(char *name)
{
    int len = strlen(name);
    unsigned int hashIndex = 0;
    for (int i = 0; i < len; i++)
    {
        // Hash Function    
        hashIndex += name[i] - 'a';
    }
    return hashIndex % TABLE_SIZE;
}

void create_table()
{
    // Create Empty Table
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hash_table[i] = NULL;
    }
}

void print_table()
{
    printf("Start of Table\n");
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (hash_table[i] == NULL)
        {
            printf("\t%i\t----\n", i);
        }
        else
        {
            printf("\t%i\t", i);
            person *tmp = hash_table[i];
            while (tmp != NULL)
            {
                printf("%s -", tmp->name);
                tmp = tmp->next;
            }
            printf("\n");
        }
    }
    printf("End of table\n");
    printf("\n");
}

bool hash_insert(person *p)
{
    if (p == NULL)
        return false;
    int index = hash(p->name);
    p->next = hash_table[index];
    hash_table[index] = p;
    return true;
}

person *hash_lookup(char *name)
{
    int index = hash(name);
    person *tmp = hash_table[index];
    while (tmp != NULL && strcmp(tmp->name, name) != 0)
    {
        tmp = tmp->next;
    }
    return tmp;
}

person *hash_delete(char *name)
{
    int index = hash(name);
    person *tmp = hash_table[index];
    person *prev = NULL;
    while (tmp != NULL && strcmp(tmp->name, name) != 0)
    {
        // Iterate through the linked list
        tmp = tmp->next;
    }
    if (tmp == NULL)
        return NULL;
    if (prev == NULL)
    {
        hash_table[index] = tmp->next;
    }
    else
    {
        // Updating the table
        prev->next = tmp->next;
    }

    return tmp;
}

int main(void)
{

    create_table();
    print_table();

    // Creating person struct
    person diya = {.name = "diya", .age = 20};
    person sajat = {.name = "sajat", .age = 21};
    person mario = {.name = "mario", .age = 200};
    person marko = {.name = "marko", .age = 100};
    person cuban = {.name = "cuban", .age = 202};
    person subin = {.name = "subin", .age = 22};
    person james = {.name = "james", .age = 02};
    person batman = {.name = "batman", .age = 02};
    person superman = {.name = "superman", .age = 02};
    person shinu = {.name = "shinu", .age = 02};



    // Insert data to Hash Table
    hash_insert(&diya);
    hash_insert(&sajat);
    hash_insert(&mario);
    hash_insert(&marko);
    hash_insert(&cuban);
    hash_insert(&subin);
    hash_insert(&james);
    hash_insert(&batman);
    hash_insert(&superman);
    hash_insert(&shinu);



    print_table();

    person *tmp = hash_lookup("mario");
    if (tmp == NULL)
    {

        printf("NOT FOUND\n");
    }
    else
    {
        printf("FOUND\n");
    }

    tmp = hash_lookup("mark");
    if (tmp == NULL)
    {

        printf("NOT FOUND\n");
    }
    else
    {
        printf("FOUND\n");
    }

    hash_delete("james");
    tmp = hash_lookup("mark");
    if (tmp == NULL)
    {

        printf("NOT FOUND\n");
    }
    else
    {
        printf("FOUND\n");
    }
    print_table();
}