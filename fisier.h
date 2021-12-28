#ifndef FISIER
#define FISIER
bool need_exit = false;
int limba ;
int r_fundal, g_fundal, b_fundal, r_player_1, g_player_1,b_player_1,r_player_2,g_player_2,b_player_2;
bool muzica_on;
short int mod_joc, dificultate;
void incarcare_date()
{


    FILE *fptr, *fptrdate;
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
    if ((fptrdate = fopen("date_player.txt","r")) == NULL)
    {
        std::cout<< "[!]:Fisierul nu a putut fi deshis sau nu exista."<<std::endl;

        need_exit = true;
    }

    fscanf(fptrdate,"%d", &r_player_1);
    fscanf(fptrdate,"%d", &g_player_1);
    fscanf(fptrdate,"%d", &b_player_1);
    fscanf(fptrdate,"%d", &r_player_2);
    fscanf(fptrdate,"%d", &g_player_2);
    fscanf(fptrdate,"%d", &b_player_2);
    fscanf(fptrdate,"%d", &mod_joc);
    fscanf(fptrdate,"%d", &dificultate);

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
void scriere_date_player()
{
    FILE *fptr;
    fptr = fopen("date_player.txt","w");
    if(fptr == NULL)
    {
        std::cout<<"[!]: Eroare scriere fisier!";
        exit(1);
    }
    fprintf(fptr,"%d %d %d",r_player_1,g_player_1,b_player_1);
     fprintf(fptr,"\n%d %d %d",r_player_2,g_player_2,b_player_2);
      fprintf(fptr,"\n%d",mod_joc);
      fprintf(fptr,"\n%d",dificultate);


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
