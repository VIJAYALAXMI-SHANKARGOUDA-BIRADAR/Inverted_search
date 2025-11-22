#include "inv.h"

#include<stdio.h>

int create_database(Slist *head,htable *hash )

{
    while(head !=NULL)//SLL iterate
    {
        FILE *fptr = fopen(head->name,"r");
        if(fptr==NULL)
        {
            printf("Error:Cannot open file %s\n",head->name);
            head=head->link;
            continue;
        }

        char word[50];
        while(fscanf(fptr,"%49s",word) !=EOF)//read each word in file until reaches EOF
        //store
        {
            /*----------------------------------*/
            //1)generate index
            /*----------------------------------*/

            char ch=word[0];
            if(ch>='A' && ch<='Z')
            ch=ch+32;//conert to lowercase
            // if(!(ch>='a' && ch<='z'))
            // continue;
            int index=ch-'a';//index generate
            if((!(ch>='a' && ch<='z') )&& (!(ch>='A' && ch<'Z')))
            {
                index=26;
            }

            if(hash[index].link==NULL)//if hash table link have the NULL address.
            {
                //create and attach main and sub nodes
                m_node *new_main=malloc(sizeof(m_node));

                strcpy(new_main->word,word);
                new_main->file_count=1;
                new_main->m_link=NULL;
                new_main->s_link=NULL;

                //sub node
                s_node *new_sub=malloc(sizeof(s_node));
                
                strcpy(new_sub->file_name,head->name);
                new_sub->word_count=1;
                new_sub->sublink=NULL;

                new_main->s_link=new_sub;

                //attach to hash table
                hash[index].link=new_main;

            }
            else
            {
                //take one main node temp
                m_node *prev_m=NULL;
                m_node *temp_m=hash[index].link;

                int word_found=0;
                while(temp_m !=NULL)
                {
                    //if word matches
                    if(strcmp(temp_m->word,word)==0)
                    {
                        word_found=1;

                        s_node *temp_s =temp_m->s_link;
                        s_node *prev_s=NULL;
                        int file_found=0;
                        while(temp_s!=NULL)
                        {
                            //check file matches if file matches increment word count
                            if(strcmp(temp_s->file_name,head->name)==0)
                            {
                                file_found=1;
                                temp_s->word_count++;//increment word count(same file)
                                break;
                            }
                            prev_s=temp_s;
                            temp_s=temp_s->sublink;

                        }
                        //when word matches bt file doesnt match, temp_sub reaches NULL,it is diff file so crete subnode and attach to main.
                        if(file_found==0)
                        {
                            s_node *new_s=malloc(sizeof(s_node));
                            strcpy(new_s->file_name,head->name);
                            new_s->word_count=1;
                            new_s->sublink=NULL;

                            if(prev_s==NULL)
                            {
                                temp_m->s_link=new_s;//first subnode
                            }
                            else{

                            prev_s->sublink=new_s;
                            }
                            temp_m->file_count++;//increment file count(diff file)

                        }
                        break;
                    }
                    prev_m=temp_m;
                    temp_m=temp_m->m_link;
                }
                //word not found or word not matches
                //when temp_main recahes NULL it is diff word so create main node and attach to prev main node.

                if(word_found==0)
                {

                    m_node *new_main=malloc(sizeof(m_node));
                    strcpy(new_main->word,word);

                    new_main->file_count=1;
                    new_main->m_link=NULL;
                    new_main->s_link=NULL;

                    s_node *new_sub=malloc(sizeof(s_node));
                    strcpy(new_sub->file_name,head->name);

                    new_sub->word_count=1;
                    new_sub->sublink=NULL;


                    new_main->s_link=new_sub;

                    //attach new main to prev main
                    if(prev_m==NULL)
                    
                        hash[index].link=new_main;
                    
                    else
                    prev_m->m_link=new_main;

                }

            }

        }
        //end store
        fclose(fptr);
        head=head->link;
       
    }
    return SUCCESS;
    
}


