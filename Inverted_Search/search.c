#include "inv.h"

int search_database(htable *hash,char *word)
{
    //convert into lowercase
    char w=tolower(word[0]);
    //generate index for that word
    int i=w-97;

    if(hash[i].link !=NULL)
    {
       m_node *main_temp=hash[i].link;

       while(main_temp!=NULL)
       {
        //word matches with database
        if(strcmp(main_temp->word,word)==0)
        {
            printf("Word %s present in %d files\n",word,main_temp->file_count);
        
            // Traverse sub-nodes
            s_node *sub_temp=main_temp->s_link;
        
        while(sub_temp!=NULL)
        {
            printf("In file %s %d times\n",sub_temp->file_name,sub_temp->word_count);

        
        sub_temp=sub_temp->sublink;
       }
       return SUCCESS;
       }
        // Move to next main node
       main_temp=main_temp->m_link;
    }
    printf("Word not found\n");
        return -1;

    }
    else
    {
        printf("Word not found\n");
        return -1;
    }

}