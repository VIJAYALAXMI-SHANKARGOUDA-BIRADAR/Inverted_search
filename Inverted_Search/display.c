#include "inv.h"

#include<stdio.h>

void display_database(htable *hash)
{
   // printf("Index\tWord\t\tFile Count\t\tFile name\t\tWord count\n");
   printf("---------------------------------------------------------------------------------\n");
   printf("%-8s %-20s %-15s %-20s %-10s\n","Index","Word","File Count","File Name","Word Count");
    printf("---------------------------------------------------------------------------------\n");


    for(int i=0;i<=26;i++)//run a loop for 27 times 
    {
        if(hash[i].link!=NULL) //check if link is null or not if it is not equal to null
        {
            m_node *temp_m=hash[i].link; //traverse main 
            while(temp_m !=NULL)
            {
                s_node *temp_s =temp_m->s_link;
                if(temp_s!=NULL)
                {
                    //print main node contents
                    printf("%-8d %-20.*s %-15d %-20.*s %-10d\n",i,19,temp_m->word,temp_m->file_count,19,temp_s->file_name,temp_s->word_count);

                    temp_s=temp_s->sublink;
                }
            //traverse sub node
            while(temp_s!=NULL)
            {
                //prints sub node content
                printf("%45s %-20s %-10d\n","",temp_s->file_name,temp_s->word_count);
                temp_s=temp_s->sublink;
            }
            printf("\n");
            temp_m=temp_m->m_link;
        }
        }
    }
}
