#include "inv.h"
void print_list(Slist *head)
{
	if (head == NULL)
	{
		printf("INFO : List is empty\n");
	}
    else
    {
	    while (head)		
	    {
		    printf("%s -> ", head -> name);
		    head = head -> link;
	    }

	    printf("NULL\n");
    }
}


int read_validate(int argc,char *argv[],Slist **head)
{
    int valid_file=0;
    for(int i=1;i<argc;i++)
    {
        //1) .txt or not
        char *t=strstr(argv[i],".txt");
        if(t==NULL || strcmp(t,".txt")!=0)
        {
            printf("Error:%s is not a .txt file\n",argv[i]);
            continue;
        }
        //2) file exist

        FILE *fp =fopen(argv[i],"r");
        if(fp==NULL)
        {
            printf("Error:%s does not exist\n",argv[i]);
            continue;
        }
        //3) empty

        fseek(fp,0,SEEK_END);
        if(ftell(fp)==0)
        {
            printf("Error: %s is empty\n",argv[i]);
            fclose(fp);
            continue;

        }
        fclose(fp);

        //4)duplicate or not

        Slist *temp=*head;
        int dup=0;
        
        while(temp!=NULL)
        {
            if(strcmp(temp->name,argv[i])==0)
            {
                dup=1;
                break;

            }
            temp=temp->link;
        }
        //if dup dont add to single linked list
        if(dup)
        {
            printf("Error: %s this file is duplicate,can not add into the SLL\n",argv[i]);
            continue;

        }
        //else add to sll
        // else
        // {
            Slist *new=malloc(sizeof(Slist));
            strcpy(new->name,argv[i]);
            new->link=NULL;
            if (*head==NULL)//first node
            {
                *head=new;
            }
            else
            {
                temp=*head;
            
            while(temp->link !=NULL)
            {
                temp=temp->link;
            }
                temp->link=new;


            
        }
        valid_file++;
         printf("INFO: %s added to SLL succcessfully\n",argv[i]);


        
    //}


}

if(valid_file==0)

    return -1;
else
return 0;

}