#include "inv.h"

int update_database(char *file_update, htable *hash, Slist **head)
{
    FILE *fptr = fopen(file_update, "r");

    if (fptr == NULL)
    {
        printf("Error: No cotents in the file\n");
        return 0;
    }

    Slist *prev = NULL;
    Slist *cur = *head;

    // check if it is database file or not
    int ch = fgetc(fptr);
    if (ch != '#')
    {
        printf("Error: %s is not a database file\n", file_update);
        fclose(fptr);
        return 0;
    }
    fseek(fptr, 0, SEEK_SET);

    int index, fcount, wcount;
    char word[50], fname[50];
    int res;

    // while(fscanf(fptr)!=EOF)
    while (1)

    {
        res = fscanf(fptr, "#%d;%49[^;];%d;", &index, word, &fcount);

        // if(res==EOF)
        // {
        //     break;
        // }

        if (res != 3)
        {
            break;
        }
        //read from databse file restore into main_node and sub_node

        m_node *main_node = malloc(sizeof(m_node));

        strcpy(main_node->word, word);
        main_node->file_count = fcount;
        main_node->m_link = NULL;
        main_node->s_link = NULL;

        // attach to main_node from sub_node
        s_node *temp1 = NULL;
        s_node *temp2 = NULL;

        for (int i = 0; i < fcount; i++)
        {
            res = fscanf(fptr, "%49[^;];%d;", fname, &wcount);

            if (res != 2)
            {
                break;
            }
            //    printf("%s\n",fname);

            cur = *head, prev = NULL;
            while (cur)
            {
                //compare database files with sll files
                if (strcmp(cur->name, fname) == 0)
                {
                    if (prev == NULL)
                        *head = cur->link;
                    else
                        prev->link = cur->link;

                    free(cur);

                    /*    Slist *temp = cur;
                    cur = cur->link;
                    free();
                    continue;*/
                }
                prev = cur;
                cur = cur->link;
            }

            s_node *sub_node = malloc(sizeof(s_node));

            strcpy(sub_node->file_name, fname);
            sub_node->word_count = wcount;
            sub_node->sublink = NULL;

            if (temp1 == NULL)
            {
                temp1 = sub_node;
            }

            else
            {
                temp2->sublink = sub_node;
            }
            temp2 = sub_node;
        }
        main_node->s_link = temp1;

        if (hash[index].link == NULL)
        {
            hash[index].link = main_node;
        }
        else
        {
            main_node->m_link = hash[index].link;
            hash[index].link = main_node;
        }

        fscanf(fptr, "#\n");//read nxt line
    }
    print_list(*head);
    // main_node->s_link=temp1
    fclose(fptr);
    return 1;
}