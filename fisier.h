#ifndef FISIER
#define FISIER
bool need_exit = false;
int limba ;
int r_fundal, g_fundal, b_fundal;
bool muzica_on;

void incarcare_date()
{


    FILE *fptr;
    if ((fptr = fopen("setari.txt","r")) == NULL)
    {
        std::cout<< "[!]:Fisierul nu a putut fi deshis sau nu exista."<<std::endl;

        need_exit = true;
    }

    fscanf(fptr,"%d", &r_fundal);
    fscanf(fptr,"%d", &g_fundal);
    fscanf(fptr,"%d", &b_fundal);

    if (b_fundal > -1 && g_fundal > -1 &&b_fundal > -1  ) std::cout << "[*]:Fundal incarcat cu succes." << std::endl;
    else
    {
        std::cout << "[!]:Fundalul nu a putut fi incarcat." << std::endl;
        need_exit = true;
    }

    fscanf(fptr,"%d", &limba);
    if (limba == 0 || limba == 1 || limba == 2) std::cout << "[*]:Limba a fost selectata cu succes." << std::endl;
    else
    {
        std::cout << "[!]:Limba nu a putut fi selectata."<< std::endl;
        need_exit = true;
    }
    fscanf(fptr,"%d", &muzica_on);
    fclose(fptr);
}
void scriere_date()
{
    FILE *fptr;
    fptr = fopen("setari.txt","w");
    if(fptr == NULL)
    {
        std::cout<<"[!]: Eroare scriere fisier!";
        exit(1);
    }
    fprintf(fptr,"%d %d %d",r_fundal,g_fundal,b_fundal);
    fprintf(fptr, "\n%d",limba);
    fprintf(fptr,"\n%d",muzica_on);

    fclose(fptr);
}

void incarcare_tabla(int t[5][5])
{

 FILE *fptr;
    if ((fptr = fopen("tabla.txt","r")) == NULL)
    {
        std::cout<< "[!]:Fisierul nu a putut fi deshis sau nu exista."<<std::endl;

        need_exit = true;
    }

   int i,j;
   for(i=1;i<=4;i++)
    for(j=1;j<=4;j++)
        fscanf(fptr,"%d", &t[i][j]);



    fclose(fptr);
}

#endif // FISIER
