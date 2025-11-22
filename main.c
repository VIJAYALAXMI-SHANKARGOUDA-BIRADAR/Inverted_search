/*
NAME : VIJAYALAXMI SHANKARGOUDA BIRADAR.
DATE : 20/11/2024
PROJECT : INVERTED SEARCH
*/


#include "inv.h"
#include<stdio.h>

int main(int argc,char *argv[])
{
    char filename[40];
    char word[40];
    char file_update[40];
    if(argc<2)
    {
        printf("INFO : Pass the atleast 2 arguments\n");
        return 0;
    }
    Slist *head  = NULL;
    htable hash[27];

    for(int i=0;i<=26;i++)
    {
        hash[i].index = i;
        hash[i].link=NULL;

    }

    if(read_validate(argc,argv,&head)==-1)
    {
        return 0;
    }
    int createdb_flag =0,update_flag =0;
    printf("\nList is : ");
    print_list(head);

    int choice;
    while(1)
    {
        printf("\nSelect your choice among the following operations\n");
        printf("\n---------------------------------------------\n");
        printf("1. Create Database\n2. Display Database\n3. Search Database\n4. Save Database\n5. Update Database\n6. Exit");
        printf("\n---------------------------------------------\n");

        printf("\nEnter Your Choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            
            case 1:

            if( createdb_flag==1)
            {
                printf("INFO: Create after create database is not possible.\n");
                break;

            }

            if(createdb_flag == 0 && update_flag == 1)
            {
                printf("INFO: create database only possible for new files.\n");
                createdb_flag = 1;
                create_database(head,hash);

                break;
            }


            if(createdb_flag == 0 && update_flag == 0)
            {
            printf("Create Database Selected.\n");
            createdb_flag = 1;
            create_database(head,hash);
            printf("Database Created Successfully.\n");
            }
            
            // {
            //     printf("Create after create database is not possible\n");

            // }

            break;

            case 2:
            printf("Display Database Selected.\n");
            display_database(hash);
            printf("Data Displayed Successfully.\n");
            break;


            case 3:
            printf("Search Database Selected.\n");
            printf("Enter word you have to search: \n");
            scanf("%s",word);
            search_database(hash,word);
            break;

            case 4:
            printf("Save Database Selected.\n");
            printf("INFO: Enter the filename where you want to save.\n");
            scanf("%s",filename);
            save_database(filename,hash);
            break;


            case 5:

            if(update_flag==1)
            {
            printf("INFO: Update after update two times not possible.\n ");
            break;
            }

            if(createdb_flag==1 && update_flag==0)
            {
                printf("INFO: Update Database not possible after create.\n");
                break;
            }
            if(update_flag == 0)
            {
            printf("Update Database Selected.\n");
            printf("Enter the filename where you want to update.\n");
            scanf("%s",file_update);
            update_flag = 1;
            update_database(file_update,hash,&head);
            }
            
            break;

            case 6:
            
            printf("Exiting..\n");
            return 0;
            

            default:
            printf("Invalid choice.try again.\n");


    

    }
   // return 0;
}


}

