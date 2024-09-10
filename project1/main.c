#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swapchar(char ** arr1, char ** arr2)
{
    char **temp;
    strcpy(*temp,*arr1);
    *arr1 = *arr2;
    *arr2 = *temp;
}
void swapint(int * arr1, int * arr2)
{
    int temp = *arr1;
    *arr1 = *arr2;
    *arr2 = temp;
}
void swapvlongint(long int * arr1, long int * arr2)
{
    long int temp = *arr1;
    *arr1 = *arr2;
    *arr2 = temp;
}

void swapdates_time(long long * arr1, long long * arr2)
{
    long long temp = *arr1;
    *arr1 = *arr2;
    *arr2 = temp;
}
void swapvalues(double * arr1, double * arr2)
{
    double temp = *arr1;
    *arr1 = *arr2;
    *arr2 = temp;
}
// A function to implement bubble sort
void bubbleSort(long long arr1[],double arr2[],int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
            if (arr1[j] > arr1[j + 1])
            {
                swapdates_time(&arr1[j], &arr1[j + 1]);
                swapvalues(&arr2[j],&arr2[j+1]);
            }

}

void h (FILE **fp, long long int **ids, char ***modules, char ***types, double **values, int **time, long int **dates,int *pocet,int *ns,int *vs){
    int pocetintervalov=0; int pocethodnot=0;
    int index=0;
    if(*ns==0){
        printf("Polia nie su vytvorene");
    }
    else{
        char vstup[0][3];
        double *hodnoty;
        hodnoty=(double*) malloc(sizeof(double));
        scanf("%s",&vstup[0]);

        for(int i=0; i<*pocet; i++){
            if(strcmp(vstup[0],(*types)[i])==0){
                hodnoty[index]=(*values)[i];

                index++;
                hodnoty=realloc(hodnoty,sizeof(double)*(index+1));
            }
        }
        double max=hodnoty[0];
        double min=hodnoty[0];
        for (int i=0; i<index; i++) {
            if (hodnoty[i] > max) {max = hodnoty[i];}
            if (hodnoty[i] < min) {min = hodnoty[i];}
        }

        int max2=max+1;
        int min2=min;
        while(max2%5!=0){
            max2++;
        }
        while(min2%5!=0){
            min2--;
        }
        if(min2<0 && max2>0){pocetintervalov=(((min2-max2)*(-1))/5 );}
        else if(min2>0 && max2>0){pocetintervalov=((min2+max2)/5);}
        else if(min2>0 && max2<0){pocetintervalov=(((max2-min2)*(-1))/5);}
        else if(min2<0 && max2<0){pocetintervalov=(((max2+min2)*(-1))/5);}
        else{pocetintervalov=(max2+min2)/5;}
        int z=0;


        for(int l=min2;l<=pocetintervalov; l++){
            for(int p=0;p<=index;p++)
            {
                if((hodnoty[p]<=(5*l)) && (hodnoty[p]>((5*l)-5))) {pocethodnot++;}

            }
            if(pocethodnot>0){
                if(l==0 )
                {}
                else{
                    printf("( %d.0- %d.0>\t %d\n",(5*l-5),(5*l),pocethodnot);
                }
            }
            pocethodnot=0; z=0;

        }
    }




}
void c(FILE **fp, long long int **ids, char ***modules, char ***types, double **values, int **time, long int **dates,int *pocet,int *ns,int *vs){
    if(*vs==0){
        printf("Neotvoreny subor\n");
    }
    else{
        char cc;
        long long int ids_p=0;
        char modules_p[0][4];
        char types_p[0][3];
        double values_p;
        int time_p;
        long int dates_p;
        int id_k,mod_k,types_k,time_k,dates_k;
        fseek(*fp, 0, SEEK_SET);
        while (fscanf(*fp, "%c", &cc) != EOF) {
            if (cc == '\n') {
                (*pocet)++;
            }
        }
        *pocet = (((*pocet) + 1) / 7);
        for(int i=0;i<*pocet;i++) {
            fseek(*fp, 0, SEEK_SET);
            while ((fscanf(*fp, "%lld\n", &ids_p)) != EOF) {
                if ((ids_p >= 1000000000) && (ids_p <= 9999999999) && (ids_p%11==0)) {
                    id_k = 0;
                    break;
                } else {
                    id_k = 1;
                    break;
                }
            }
            while ((fscanf(*fp, "%s\n",modules_p[0])) != EOF) {
                if (((modules_p[0][0] > 64) && (modules_p[0][0] < 91)) && ((modules_p[0][1] > 47) && (modules_p[0][1] < 58)) && ((modules_p[0][2] > 47) && (modules_p[0][2] < 58))) {
                    mod_k = 0;
                    break;
                } else {
                    mod_k = 1;
                    break;
                }
            }
            while ((fscanf(*fp, "%s\n",types_p[0])) != EOF) {

                if (((types_p[0][0] == 'R') || (types_p[0][0] == 'U') || (types_p[0][0] == 'A')) && ((types_p[0][1] == '1') || (types_p[0][1] == '2') || (types_p[0][1] == '4'))) {
                    types_k = 0;
                    break;
                } else {
                    types_k = 1;
                    break;
                }
            }
            while ((fscanf(*fp, "%lf\n%d\n", &values_p, &time_p)) != EOF) {

                if (((time_p / 100) >= 0) && ((time_p / 100) <= 23) && ((time_p % 100) >= 0) && ((time_p % 100) <= 59)) {
                    time_k = 0;
                    break;
                } else {
                    time_k = 1;
                    break;
                }
            }
            while ((fscanf(*fp, "%ld\n\n",&dates_p)) != EOF) {

                if (((dates_p / 10000) > 1900) && ((dates_p / 10000) < 2023) && (((dates_p / 100) % 10) > 0) &&
                    (((dates_p / 100) % 10) < 13) && (((dates_p) % 100) > 0) && (((dates_p) % 100) < 32)) {
                    dates_k = 0;
                    break;
                } else {
                    dates_k = 1;
                    break;
                }
            }
        }

        if(id_k==1){
            printf("Nekorektne zadany vstup: ID cislo mer. osoby. \n");
        }
        if(mod_k==1)
        {
            printf("Nekorektne zadany vstup: Mer. modul. \n");
        }
        if(types_k==1)
        {
            printf("Nekorektne zadany vstup: Typ mer. velicinyy. \n");
        }
        if(time_k==1)
        {
            printf("Nekorektne zadany vstup: Cas merania. \n");
        }
        if(dates_k==1)
        {
            printf("Nekorektne zadany vstup: Datum. \n");
        }
        if(id_k==0 && mod_k==0 && types_k==0 && time_k==0 && dates_k==0)
        {
            printf("Data su korektne.");
        }
    }
}

void n(FILE **fp, long long int **ids, char ***modules, char ***types, double **values, int **time, long int **dates,int *pocet,int *ns,int *vs)
{
    long long pomocid;
    char pomocmod[4];
    char pomoctp[3];
    double pomocval;
    int pomoctime;
    long int pomocdt;
    int nd=0;
    int ww=0;
    char cc;

    if(*vs==0){
        printf("Neotvoreny subor \n");
    }
    else{
        if (*ns==1){
            while (ww < *pocet)
            {
                free ((*modules)[ww]);
                free ((*types)[ww]);
                ww++;
            }
            free(*ids);
            free(*modules);
            free(*types);
            free(*values);
            free(*time);
            free(*dates);
        }
        else {}

        fseek(*fp, 0, SEEK_SET);
        while (fscanf(*fp, "%c", &cc) != EOF) {
            if (cc == '\n') {
                (*pocet)++;
            }
        }
        *pocet = (((*pocet) + 1) / 7); // kolko typov zapisov

        *ids = (long long int *) malloc(sizeof(long long int) * (*pocet));
        *modules = (char **) malloc(sizeof(char *) * (*pocet));
        *types = (char **) malloc(sizeof(char *) * (*pocet));
        *values = (double *) malloc(sizeof(double) * (*pocet));
        *time = (int *) malloc(sizeof(int) * (*pocet));
        *dates = (long int *) malloc(sizeof(long int) * (*pocet));
        ww=0;
        while (ww < *pocet) {
            (*modules)[ww] = (char *) malloc(4 * sizeof(char));
            (*types)[ww] = (char *) malloc(3 * sizeof(char));
            ww++;
        }
        fseek(*fp, 0, SEEK_SET);

        while ((fscanf(*fp, "%lld\n%s\n%s\n%lf\n%d\n%ld\n\n", &pomocid, &pomocmod, &pomoctp, &pomocval, &pomoctime, &pomocdt) !=
                EOF) && (nd < *pocet)) {
            (*ids)[nd] = pomocid;
            strcpy((*modules)[nd],pomocmod);
            strcpy((*types)[nd],pomoctp);
            (*values)[nd] = pomocval;
            (*time)[nd] = pomoctime;
            (*dates)[nd] = pomocdt;
            nd++;
        }

    }
    *ns=1;
}

void v (FILE **fp,long long int  **ids,char ***modules,char ***types,double **values, int **time,long int  **dates,int *vs,int *ns,int *pocet)
{
    char pz;
    int mn=1; int mw=0;

    if (*vs==0){
        if ((*fp=fopen("dataloger.txt","r"))==NULL){
            printf("Neotvoreny subor");
        }
        else{}
    }
    if(*vs==1 || *fp!=NULL){
        if(*ns==1){
            while(mw<*pocet)
            {

                printf("ID cislo mer. osoby: %lld\n",(*ids)[mw]);
                printf("Mer.modul: %s\n",(*modules)[mw]);
                printf("Typ mer.velciny: %s\n",(*types)[mw]);
                printf("Hodnota: %lf\n",(*values)[mw]);
                printf("Cas merania: %d\n",(*time)[mw]);
                printf("Datum: %ld\n\n",(*dates)[mw]);
                mw++;
            }
        }
        else{
            fseek(*fp,0,SEEK_SET);
            while((fscanf(*fp,"%c",&pz))!=EOF){
                if(mn==1) {
                    printf("\nID cislo mer. osoby: ");
                    mn++;
                }
                else if((mn==2) && (pz =='\n')) {
                    printf("\nMer.modul: ");
                    mn++;
                }
                else if((mn==3) && (pz =='\n')) {
                    printf("\nTyp mer.veliciny: ");
                    mn++;
                }
                else if((mn==4) && (pz =='\n')) {
                    printf("\nHodnota: ");
                    mn++;
                }
                else if((mn==5) && (pz =='\n')) {
                    printf("\nCas merania: ");
                    mn++;
                }
                else if((mn==6) && (pz =='\n')) {
                    printf("\nDatum: ");
                    mn++;
                }
                else if((mn==7) && (pz =='\n')) {
                    printf("\n");
                    mn=1;
                }

                if(pz != '\n'){
                    printf("%c", pz);
                }
            }
        }
    }

    *vs=1;
}
void s(FILE**fp,char **modules,char ** types, int *pocet,double *values,int *time,long int *dates,int *ns) {
    long long pomocid; FILE *fayl;
    char pomocmod[4];
    char pomoctp[3];
    double pomocval;
    int pomoctime;
    long int pomocdt;
    char o[4],r[3];
    int pmp=0;
    if(*ns==0)
    {
        printf("Polia nie su vytvorene");
    }
    else {
        scanf("%s %s", &o, &r);

        long long *dates_time = (long long *) malloc(sizeof(long long));
        double *values_new = (double *) malloc(sizeof(double));
        fseek(*fp, 0, SEEK_SET);

        while ((fscanf(*fp, "%lld\n%s\n%s\n%lf\n%d\n%ld\n\n", &pomocid, &pomocmod, &pomoctp, &pomocval, &pomoctime,
                       &pomocdt) !=
                EOF)) {
            if ((strcmp(o, pomocmod) == 0) && (strcmp(r, pomoctp) == 0)) {
                values_new[pmp] = pomocval;
                long long prvy = pomoctime;
                long long druhy = pomocdt;
                dates_time[pmp] = ((druhy * 10000) + prvy);
                pmp++;
                values_new = realloc(values_new, (pmp + 1) * sizeof(double));
                dates_time = realloc(dates_time, (pmp + 1) * sizeof(long long));
            }
        }
        bubbleSort(dates_time, values_new, pmp);
        fayl = fopen("vystup_S.txt", "w");
        if(pmp==0)
        {
            printf("Pre dany vstup neexistuju zaznamy\n");
        }
        else {
            for (int d = 0; d < pmp; d++) {
                fprintf(fayl, "%lld\t%lf\n", dates_time[d], values_new[d]);
            }
            printf("Pre dany vstup je vytvoreny txt subor\n");
            fclose(fayl);
        }
        free(dates_time); free(values_new);
    }
}




void o(FILE**fp,char **modules,char ** types, int *pocet,double *values,int *time,long int *dates,int *ns) {

    long long pomocid;
    char pomocmod[4];
    char pomoctp[3];
    double pomocval;
    int pomoctime;
    long int pomocdt;
    char o[4],r[3];
    if(*ns==0)
    {
        printf("Polia nie su vytvorene");
    }
    int pmp=0; //urcovanie indexu a zvacovanie dp
    scanf("%s %s",&o,&r);

    char **modules_new = (char **) malloc(sizeof(char *));
    char **types_new = (char **) malloc(sizeof(char *) );
    double *values_new = (double *) malloc(sizeof(double) );
    int *time_new = (int *) malloc(sizeof(int));
    long int *dates_new = (long int *) malloc(sizeof(long int) );
    long long *dates_time=(long long *) malloc(sizeof (long long));
    *modules_new=(char *) malloc(4*sizeof (char ));
    *types_new=(char *) malloc(3*sizeof (char));

    fseek(*fp, 0, SEEK_SET);

    while ((fscanf(*fp, "%lld\n%s\n%s\n%lf\n%d\n%ld\n\n", &pomocid, &pomocmod, &pomoctp, &pomocval, &pomoctime, &pomocdt) !=
            EOF) ) {
        if((strcmp(o,pomocmod)==0) && (strcmp(r,pomoctp)==0)){
            values_new[pmp]=pomocval;
            time_new[pmp]=pomoctime;
            dates_new[pmp]=pomocdt;
            long long prvy=pomoctime; long long druhy=pomocdt;
            dates_time[pmp]=((druhy*10000)+prvy); //spoji datum a cas
            pmp++;
            values_new= realloc(values_new,(pmp+1)*sizeof(double));   //zvacujem polia podla poctu zhod
            time_new= realloc(time_new, (pmp+1)*sizeof (int));
            dates_new= realloc(dates_new,(pmp+1)*sizeof (long int));
            dates_time= realloc(dates_time,(pmp+1)*sizeof (long long));
        }
    }
    bubbleSort(dates_time,values_new,pmp); //zoradujem hodnoty v poli pomocou bubbleSort
    for (int x = 0; x < pmp; ++x) {
        printf("%s %s %lld %lld\t %lf\n",o,r,dates_time[x]/10000,dates_time[x]%10000,values_new[x]);
    }


}
void z(FILE **fp, long long int **ids, char ***modules, char ***types, double **values, int **time, long int **dates,int *pocet,int *ns,int *vs)
{
    if (*ns==0){
        printf("Polia nie je su vytvorene\n");
    }
    long long pomocid;
    char pomocmod;
    char pomoctp;
    double pomocval;
    int pomoctime;
    long int pomocdt;
    long long id;
    int pocet2=-1;


    scanf("%lld",&id);

    for(int i=0; i<*pocet; i++)
    {
        if((*ids)[i]==id)
        {
            int m=i;
            for(int j=i+1; j<*pocet; j++)
            {
                if((*ids)[m]==(*ids)[j])
                {
                    pomocid = (*ids)[m];
                    pomocmod = (*modules)[m];
                    pomoctp = (*types)[m];
                    pomoctime = (*time)[m];
                    pomocval = (*values)[m];
                    pomocdt = (*dates)[m];

                    (*ids)[m]=(*ids)[j];
                    (*modules)[m]=(*modules)[j];
                    (*types)[m]=(*types)[j];
                    (*values)[m]=(*values)[j];
                    (*time)[m]=(*time)[j];
                    (*dates)[m]=(*dates)[j];

                    (*ids)[j]=pomocid;
                    (*modules)[j]=pomocmod;
                    (*types)[j]=pomoctp;
                    (*values)[j]=pomocval;
                    (*time)[j]=pomoctime;
                    (*dates)[j]=pomocdt;
                }
                else
                {
                    pomocid=(*ids)[m];
                    pomocmod=(*modules)[m];
                    pomoctp=(*types)[m];
                    pomocval=(*values)[m];
                    pomoctime=(*time)[m];
                    pomocdt=(*dates)[m];

                    (*ids)[m]=(*ids)[j];
                    (*modules)[m]=(*modules)[j];
                    (*types)[m]=(*types)[j];
                    (*values)[m]=(*values)[j];
                    (*time)[m]=(*time)[j];
                    (*dates)[m]=(*dates)[j];

                    (*ids)[j]=pomocid;
                    (*modules)[j]=pomocmod;
                    (*types)[j]=pomoctp;
                    (*values)[j]=pomocval;
                    (*time)[j]=pomoctime;
                    (*dates)[j]=pomocdt;

                    m++;
                }
            }

            pocet2++;
            printf("%d",pocet2);
        }
    }

    *ids = (long long int *) realloc(*ids,(*pocet-pocet2)*sizeof (long long int));
    *modules = (char **) realloc(*modules,(*pocet-pocet2)*(sizeof(char *)));
    *types = (char **) realloc(*types, (*pocet-pocet2)*(sizeof(char *)));
    *values = (double *)realloc(*values,(*pocet-pocet2)* sizeof(double ));
    *time = (int *) realloc(*time,(*pocet-pocet2)* sizeof(int));
    *dates = (long int *) realloc(*dates,(*pocet-pocet2)* sizeof(long int));

    if(pocet2==-1){
        printf("\nPre dany vstup neexistuju zaznamy\n");
    }
    else
    {
        printf("\nVymazalo sa : %d zaznamov!\n",pocet2);
    }
    *pocet=*pocet-pocet2;

}
void r(FILE **fp, long long int **ids, char ***modules, char ***types, double **values, int **time, long int **dates,int *pocet,int *ns,int *vs)
{ if(*ns==0)
    {
        printf("Polia nie je su vytvorene");
    }


}

int main() {
    int vs=0;
    char znak;
    FILE *fp = NULL;
    long long int *ids = NULL;
    char **modules = NULL;
    char **types = NULL;
    double *values = NULL;
    int *time = NULL;
    long int *dates = NULL;
    int ns=0;
    int os=0;
    int pocet=0;



    for (int m = 0; m < 1;) {

        scanf("%c",&znak);
        switch (znak)
        {
            case 'v': {
                v(&fp, &ids, &modules, &types, &values, &time, &dates, &vs,&ns,&pocet);
                break;
            }
            case 'n': {
                n(&fp, &ids, &modules, &types, &values, &time, &dates,&pocet,&ns,&vs);
                break;

            }
            case 'o':{
                o(&fp,&modules,&types,&pocet,&values,&time,&dates,&ns);
                break;

            }
            case 's':{
                s(&fp,&modules,&types,&pocet,&values,&time,&dates,&ns);
                break;

            }
            case'z':{
                z(&fp, &ids, &modules, &types, &values, &time, &dates,&pocet,&ns,&vs);
                break;
            }
            case'c':{
                c(&fp, &ids, &modules, &types, &values, &time, &dates,&pocet,&ns,&vs);
                break;
            }
            case 'h':{
                h(&fp, &ids, &modules, &types, &values, &time, &dates,&pocet,&ns,&vs);
                break;

            }
            case 'r': {
                r(&fp, &ids, &modules, &types, &values, &time, &dates,&pocet,&ns,&vs);
                break;
            }
            case 'k':{
                free(ids);
                free(modules);
                free(types);
                free(values);
                free(time);
                free(dates);
                fclose(fp);
                break;
            }

            default:
                break;


        }

    }
    return 0;
}








