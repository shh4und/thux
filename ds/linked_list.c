#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

typedef int type_key;

typedef struct item
{
    type_key key;
    int value;
} item;

typedef struct record
{
    item content;
    struct record *next;
} record;

typedef struct
{
    record *head;
} list;

void init_list(list *l)
{
    l->head = NULL;
}

bool insert(item content, list *l)
{
    record *new = (record *)malloc(sizeof(record));
    if (new == NULL)
    {
        return false;
    }
    new->content = content;
    new->next = l->head;
    l->head = new;
    return true;
}

bool get_item(type_key key, item *content, list *l)
{
    record *p = l->head;
    while (p) // p!=NULL
    {
        if (p->content.key == key)
        {
            *content = p->content;
            return true;
        }
        p = p->next;
    }
    content = NULL;
    return false;
}

// // recursive approach
// int size_list_r(list *l)
// {
//     record *p = l->head;
//     if (p)
//     {
//         return 1 + size_list_r(p->next);
//     }
//     return 0;
// }

// iterative approach
int size_list_i(list *l)
{
    int counter = 0;
    record *p = l->head;
    while (p) // p!=NULL
    {
        counter++;
        p = p->next;
    }
    return counter;
}

bool empty(list *l)
{
    return l->head == NULL;
}

bool remove_item(type_key key, list *l)
{
    if (empty(l))
    {
        return false;
    }

    record *p_previous = l->head;
    if (l->head->content.key == key)
    {
        l->head = l->head->next;
        free(p_previous);
        return true;
    }
    else
    {
        while (p_previous->next)
        {
            record *p_curr = p_previous->next;
            if (p_curr->content.key == key)
            {
                p_previous = p_curr->next;
                free(p_curr);
                return true;
            }

            p_previous = p_curr;
        }
    }
    return false;
}

bool update(item content, list *l)
{
    record *p = l->head;
    while (p)
    {
        if (p->content.key == content.key)
        {
            p->content = content;
            return true;
        }
        p = p->next;
    }
    return false;
}

bool nth_item(int n, item *content, list *l)
{
    if (n >= size_list_i(l))
    {
        printf("n must be < size of l");
        content = NULL;
        return false;
    }
    record *p = l->head;
    int i = 0;
    while (p && (i < n)) // breaks on p==NULL or if i >= n
    {
        p = p->next;
        i++;
    }
    if (p && (i == n))
    {
        *content = p->content;
        return true;
    }

    return false;
}

// recursive approach
// void print_list_r(record *lst)
// {
//     if (lst != NULL)
//     {
//         printf("C%d:V%d\n", lst->content.key, lst->content.value);
//         print_list_r(lst->next);
//     }
// }
// // iterative approach
// void print_list_i(record *lst)
// {
//     record *p;
//     for (p = lst; p != NULL; p = p->next)
//     {
//         printf("%d\n", p->content);
//     }
// }

int main(void)
{
    printf("sizeof (record) = %ld\n",
           sizeof(record));

    list lst;
    init_list(&lst);

    for (int i = 1; i < 4; i++)
    {
        item content = {i, i * 5};
        if (insert(content, &lst))
        {
            printf("Content added:\nK%d:V%d\n", content.key, content.value);
        }
    }

    printf("ADDR: %p\n", &lst);
    // print_list_r(lst);
    printf("COUNT: %d\n", size_list_i(&lst));
    return EXIT_SUCCESS;
}
