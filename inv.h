#include<stdio.h>

#include<stdlib.h>
#include<string.h>
#include<ctype.h>


/*macros*/

#define SUCCESS 0;
#define FAILURE -1;



/*strcture declaration*/

//structure declaration  for node, storing files in SLL. 
typedef struct file_node
{
    char name[50];
    struct file_node *link;

}Slist;

//structure declaration for hash table
typedef struct hash_table
{
    int index;
    struct main_node *link;
}htable;

//structure declaration for main node
typedef struct main_node
{
    int file_count;
    char word[50];
    struct main_node *m_link;
    struct sub_node *s_link;
}m_node;

//structure declaration for sub node

    typedef struct sub_node
    {
        int word_count;
        char file_name[50];
        struct sub_node *sublink;

    }s_node;




/*Function declaration*/

int read_validate(int argc,char *argv[],Slist **head);



void print_list(Slist *head);

int create_database(Slist *head,htable *hash);
void display_database(htable *hash);
int  save_database(char filename[],htable *hash);
int search_database(htable *hash,char *word);
int update_database(char *file_update,htable *hash,Slist **head);




//int display_database();





