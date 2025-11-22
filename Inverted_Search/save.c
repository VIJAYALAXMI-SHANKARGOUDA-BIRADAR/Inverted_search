#include "inv.h"

int save_database(char filename[],htable *hash)
{
    //1.save into an .txt file
    ///1.1 validate .txt file 
    char *txt=strstr(filename,".txt");
    //if not .txt file error
    if(txt==NULL || strcmp(txt,".txt")!=0)
    {
        printf("%s is not a .txt file\n",filename);
        return FAILURE;
    }
    //else create or open file in w mode

    FILE *fp = fopen(filename,"w");
    if(fp==NULL)
    {
        printf("error: not possible to create file\n");
        return -1;

    }
    for(int i=0;i<=26;i++)
    {
        m_node *temp_m=hash[i].link;
        if(temp_m==NULL)
        
        continue;

        while(temp_m !=NULL)
        {
            //save start with # and end with #
            fprintf(fp,"#%d;%s;%d",i,temp_m->word,temp_m->file_count);
            s_node *temp_s=temp_m->s_link;

            while(temp_s!=NULL)
            {
                fprintf(fp,";%s;%d",temp_s->file_name,temp_s->word_count);

                temp_s=temp_s->sublink;
            }
            fprintf(fp,"#\n");//line end with #
            temp_m =temp_m->m_link;
        }
    }
    fclose(fp);
    printf("INFO: Database saved successfully into %s\n",filename);
    return SUCCESS;

}




