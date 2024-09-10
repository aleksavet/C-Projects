#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct inf
{
    long long ids;
    char meno[31];
    char modules[4];
    char types[3];
    double values;
    int time;
    long int dates;
    long long dates_time;
    struct inf* next;

}INFO;

void newstruct(INFO **head, long long ids,char meno[31],char modules[4],char types[3],double values,int time,long int dates) // create a new structure
{
    INFO *newin= malloc(sizeof (INFO));
    long long timelld,dateslld,dates_timeslld; timelld=time; dateslld=dates;
    dates_timeslld=(dateslld*10000)+timelld;
    meno[strcspn(meno,"\n")] = 0;
    newin->ids=ids;
    strcpy(newin->meno,meno);
    strcpy(newin->modules,modules);
    strcpy(newin->types,types);
    newin->values=values;
    newin->time=time;
    newin->dates=dates;
    newin->dates_time=dates_timeslld;
    newin->next=NULL;

    if(*head==NULL)
    {
        *head=newin;
    }
    else{
        INFO *pomocnystruct=*head;

        while(pomocnystruct->next!= NULL)
        {
            pomocnystruct=pomocnystruct->next;
        }
        pomocnystruct->next=newin;
    }

}
void n(FILE **fp,int *pocet,int *n, INFO **head)
{
    if (*n == 1)
    {
        while (*head != NULL)
        {
            INFO *pomocnystruct = *head;
            *head = (*head)->next;
            free(pomocnystruct);
        }
    }
    fseek(*fp, 0, SEEK_SET);
    *pocet=0;
    if((*fp= fopen("dataloger_V2.txt","r"))==NULL)
    {
        printf("Zaznamy neboli nacitane!");
    }
    else
    {
        long long ids;
        char meno[31];
        char modules[4];
        char types[3];
        double values;
        int time;
        long int dates;
        char c;
        *head=NULL;

        fseek(*fp, 0, SEEK_SET);
        while (fscanf(*fp, "%c", &c) != EOF) {
            if (c == '\n') {
                (*pocet)++;
            }
        }
        *pocet = (((*pocet) + 1) / 8);
        printf("Nacitalo sa %d zaznamov\n",*pocet);
        fseek(*fp, 0, SEEK_SET);
        for (int i = 0; i < *pocet; i++) {

            fscanf(*fp, "$$$\n%lld\n", &ids);
            //printf("%lld\n", ids);
            fgets(meno, 31, *fp);
            //printf("%s", meno);
            fscanf(*fp, "%s\n", modules);
            //printf("%s\n", modules);
            fscanf(*fp, "%s\n", types);
            // printf("%s\n", types);
            fscanf(*fp, "%lf", &values);
            //  printf("%lf\n", values);
            fscanf(*fp, "%d\n", &time);
            // printf("%d\n", time);
            fscanf(*fp, "%ld\n", &dates);
            // printf("%ld\n", dates);
            newstruct(head,ids,meno,modules,types,values,time,dates);
        }

    }
    *n=1;
}

void v (FILE **fp,int *pocet,int n, INFO *head)
{
    if(n==0)
    {
        printf("Zaznamy neboli nacitane!\n");
        return;
    }
    else
    {
        if(n==1)
        {
            int i = 1;
            INFO *pomocnystruct;
            pomocnystruct = head;
            while (pomocnystruct != NULL)
            {

                printf("%d:\n", i);
                printf("ID cislo mer. osoby: %lld\n", pomocnystruct->ids);
                printf("Meno osoby: %s\n", pomocnystruct->meno);
                printf("Mer. modul: %s\n", pomocnystruct->modules);
                printf("Typ mer. veliciny: %s\n", pomocnystruct->types);
                printf("Hodnota: %lf\n", pomocnystruct->values);
                printf("Cas merania: %d\n", pomocnystruct->time);
                printf("Datum: %ld\n", pomocnystruct->dates);

                pomocnystruct = pomocnystruct->next;
                i++;

            }
        }
    }

}

INFO *z (INFO *head,int n)
{
    if(n==0)
    {
        printf("Zaznamy neboli nacitane!\n");
        return 0;
    }
    else
    {
        if(n==1)
        {
            long long idsz;
            scanf("%lld", &idsz);


            while (head->ids == idsz)
            {
                printf("Zaznam pre ID: %lld pre modul %s bol vymazany.\n", idsz, head->next->modules);
                head = head->next;
            }
            INFO *pomocnystruct = head;

            int i = 0;

            while (pomocnystruct->next != NULL) {
                if (pomocnystruct->next->ids == idsz) {
                    i++;
                    printf("Zaznam pre ID: %lld pre modul %s bol vymazany.\n", idsz, pomocnystruct->next->modules);
                    pomocnystruct->next = pomocnystruct->next->next;
                } else {
                    pomocnystruct = pomocnystruct->next;
                }

            }
            return head;
        }
    }
}


void swap( INFO *a, INFO *b)
{
    long long temp = a->dates_time;
    a->dates_time = b->dates_time;
    b->dates_time = temp;

    long long idstmp= a->ids;
    a->ids=b->ids;
    b->ids=idstmp;

    char menotmp[31];
    strcpy(menotmp,a->meno);
    strcpy(a->meno,b->meno);
    strcpy(b->meno,menotmp);

    char modulestmp[4];
    strcpy(modulestmp,a->modules);
    strcpy(a->modules,b->modules);
    strcpy(b->modules,modulestmp);

    char typestmp[3];
    strcpy(typestmp,a->types);
    strcpy(a->types,b->types);
    strcpy(b->types,typestmp);

    double valuestmp=a->values;
    a->values=b->values;
    b->values=valuestmp;

    int timetmp=a->time;
    a->time=b->time;
    b->time=timetmp;

    long int datestmp=a->dates;
    a->dates=b->dates;
    b->dates=datestmp;


}

void bubbleSort( INFO *head,int n)
{
    int swapped, i;
    INFO *ptr1;
    INFO *lptr = NULL;

    if(n==0)
    {
        printf("Chyba\n");
        return;
    }
    else
    {
        if(n==1)
        {

            if (head == NULL)
                return;

            do {
                swapped = 0;
                ptr1 = head;

                while (ptr1->next != lptr) {
                    if (ptr1->dates_time > ptr1->next->dates_time) {
                        swap(ptr1, ptr1->next);
                        swapped = 1;

                    }
                    ptr1 = ptr1->next;

                }
                lptr = ptr1;
            } while (swapped);
            printf("Spajany zoznam bol usporiadany.\n");
        }
    }
}

INFO *p(INFO *head,int *pocet,int n)
{
    long long ids;
    char meno[30];
    char modules[4];
    char types[3];
    double values;
    int time;
    long int dates;
    int num=0;

    if(n==0)
    {
        printf("Zaznamy neboli nacitane!\n");
        return 0;
    }

    else
   {
        if (n == 1) {
            scanf("%d\n", &num);
            scanf("%lld\n", &ids);
            scanf("%[^\n]", &meno);
            scanf("%s\n", modules);
            scanf("%s\n", types);
            scanf("%lf", &values);
            scanf("%d\n", &time);
            scanf("%ld\n", &dates);

            meno[strcspn(meno, "\n")] = 0;
            if (num > *pocet) {
                num = *pocet + 1;
            }
            INFO *newin = malloc(sizeof(INFO));
            long long timelld, dateslld, dates_timeslld;
            timelld = time;
            dateslld = dates;
            dates_timeslld = (dateslld * 10000) + timelld;
            newin->ids = ids;
            strcpy(newin->meno, meno);
            strcpy(newin->modules, modules);
            strcpy(newin->types, types);
            newin->values = values;
            newin->time = time;
            newin->dates = dates;
            newin->dates_time = dates_timeslld;
            newin->next = NULL;

            if (num == 1) {
                newin->next = head;
                head = newin;
            } else {
                INFO *pomoc = head;
                for (int i = 1; i < num -
                                    1; i++)
                {
                    pomoc = pomoc->next;
                }
                newin->next = pomoc->next;
                pomoc->next = newin;
            }


            return head;
        }
    }
}

void h(INFO *head,int n)
{


    INFO* pomocnystruct=head;
    int i=0;

    if(n==0)
    {
        printf("Zaznamy neboli nacitane!\n");
        return;
    }
    else
    {
        if(n==1)
        {
            char modules1[4];
            scanf("%s",modules1);
            while (pomocnystruct != NULL) {
                if (strcmp(pomocnystruct->modules, modules1) == 0) {
                    i++;
                     printf("%d:\n", i);
                    printf("ID cislo mer. osoby: %lld\n", pomocnystruct->ids);
                    printf("Meno osoby: %s\n", pomocnystruct->meno);
                    printf("Mer. modul: %s\n", pomocnystruct->modules);
                    printf("Typ mer. veliciny: %s\n", pomocnystruct->types);
                    printf("Hodnota: %lf\n", pomocnystruct->values);
                    printf("Cas merania: %d\n", pomocnystruct->time);
                    printf("Datum: %ld\n", pomocnystruct->dates);
                }


                pomocnystruct = pomocnystruct->next;
            }
            if (i == 0) {
                printf("Pre meraci modul %s niesu zaznamy.", modules1);

            }
        }
    }
}

void r(INFO *head,int n)
{
    if(n==0)
    {
        printf("Zaznamy neboli nacitane!\n");
        return;
    }
    else
    {
        if(n==1)
        {
            int num1;
            int num2;
            scanf("%d %d", &num1, &num2);
            INFO *pomocnystruct = head;
            int countstr = 0;
            int pocet2 = 1;
            INFO *helpstruct;
            INFO *helpstruct2;


            while (pomocnystruct != NULL)
            {

                if (pocet2 == num1)
                {
                    helpstruct = pomocnystruct;
                }
                else if (pocet2 == num2)
                {
                    helpstruct2 = pomocnystruct;
                }

                pomocnystruct = pomocnystruct->next;

                pocet2++;

            }
            swap(helpstruct, helpstruct2);
        }
    }
}




int main()
{
    INFO* head = NULL;
     char znak;
     FILE *fp=NULL;
     int ns=0;
     int pocet=0;


    while(1)
    {
        scanf("%c",&znak);
        switch (znak)
        {
            case 'n':
            {
               n (&fp,&pocet,&ns,&head);
               break;
            }
            case 'v':
            {
                v(&fp,&pocet,ns,head);
                break;
            }

           case 'z':
            {
                head=z(head,ns);
                break;
            }
            case 'u':
            {
                bubbleSort(head,ns);
                break;
            }
            case 'p':
            {
                head=p(head,&pocet,ns);
                break;
            }
            case'r':
            {
                r(head,ns);
                break;
            }
            case 'h':
            {
                h(head,ns);
                break;
            }
            case 'k':
            {
                while (head != NULL)
                {
                    INFO *pomocnystruct=head;
                    head=head->next;
                    free(pomocnystruct);
                    fclose(fp);
                }

                break;
            }

            default:
                break;
                return 0;
        }
    }
}

