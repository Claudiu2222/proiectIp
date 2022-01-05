#ifndef JOC_H_INCLUDED
#define JOC_H_INCLUDED
#include "scripts.h"



//-> Variabile

bool castigator = false;
 int nr_poz = 0;
const int numar = 4, width = 500, height=500, latura=width/numar, sus=(720-width)/2, stanga=(1280-height)/2;
bool game_back;
void buton_back_start(int x,int y, int alegere);
void sectiune_start();
void text_butoane_start(char alegere);
void incarcare_tabla(int t[5][5]);
int t[5][5], t_pozitii[5][5] = { {0, 0, 0, 0, 0},
                                 {0, 0, 2, 2, 0},
                                 {0, 0, 1, 2, 0},
                                 {0, 0, 1, 2, 0},
                                 {0, 0, 1, 1, 0}
                               };
int t_player[4][4];
int turn = 1;

//-> Pentru AI
int ai_i, ai_j, nr_caz;

int NR_POSIBILITATI = 0, ind_ai = 0, ind_aj = 0, ind_caz = 0;


void desenare_tabla()
{

    int i,j;
    clearviewport();
    setcolor(WHITE);
    for (i=1; i<=numar; i++)
        for (j=1; j<=numar; j++)
            rectangle(stanga+latura*(i-1),sus+latura*(j-1),stanga+latura*i,sus+latura*j);
    setcolor(BLACK);



}
void copiere_matrice(int a[5][5], int t[5][5])
{
    for(int i =1;i<=4;i++)
        for(int j= 1;j<=4;j++)
        a[i][j] = t[i][j];
}
void verificare_pozitie(int x,int y, int & ii, int & jj)
{
    int i,j;
    for(i=1; i<=4; i++)
        for(j=1; j<=4; j++)
        {
            if(x >= tc[i][j].lX && x <=tc[i][j].rX && y>= tc[i][j].lY && y <= tc[i][j].rY)
            {
                ii = i;
                jj=j;
                i=5;
                break;
            }
        }

}
void modificare_piesa(int i, int j,int player,int t[5][5])
{
    if(player == 1 )
    {
        t[i][j] = 1;
    }
    else if(player == 2)
    {

        t[i][j] = 2;
    }


}
void afisare_text_joc(int alegere)
{
    setviewport(300,20,990,80,0);


setbkcolor(COLOR(r_fundal, g_fundal, b_fundal));
    clearviewport();
setviewport(0,0,1280,720,0);
char text[3][18] = {"Muta piesa","Move the piece","Déplacer la pièce"};
        char text_mutari[3][30] = {"Mutari posibile: ","Possible moves: ","Mouvements possibles: "};
        char text_banut[3][18] = {"Muta banutul","Move the coin","Déplacer la pièce"};
        char text_castigator[3][11]={"Castigator","Winner","Gagnant"};

        char numar_pozitii[3];
        itoa(nr_poz,numar_pozitii,10);
        strcat(text_mutari[limba],numar_pozitii);
   if(alegere == 0 && castigator == false)
    {

        setcolor(COLOR(r_player_2,g_player_2,b_player_2));


        if(limba == 0)
            {   settextstyle(0, HORIZ_DIR, 3);
                outtextxy((rezX / 2) - 115 , 30, text[limba]);
                settextstyle(0, HORIZ_DIR, 2);
             outtextxy((rezX / 2) - 127 , 60, text_mutari[limba]);
            }
        if(limba == 1)
            { settextstyle(0, HORIZ_DIR, 3);
                outtextxy((rezX / 2) -164, 30, text[limba]);
                   settextstyle(0, HORIZ_DIR, 2);
             outtextxy((rezX / 2) - 125 , 60, text_mutari[limba]);
            }
        if(limba == 2)
             { settextstyle(0, HORIZ_DIR, 3);
                outtextxy((rezX / 2) -200, 30, text[limba]);
                   settextstyle(0, HORIZ_DIR, 2);
             outtextxy((rezX / 2) - 164 , 60, text_mutari[limba]);
            }

    }
    else  if(alegere == 1 && castigator == false)
    {
        setcolor(COLOR(r_player_1,g_player_1,b_player_1));

        if(limba == 0 && castigator == false)
            {   settextstyle(0, HORIZ_DIR, 3);
                outtextxy((rezX / 2) - 115 , 30, text[limba]);
                settextstyle(0, HORIZ_DIR, 2);
           outtextxy((rezX / 2) - 127 , 60, text_mutari[limba]);
            }
        if(limba == 1 && castigator == false)
            {   settextstyle(0, HORIZ_DIR, 3);
                outtextxy((rezX / 2) - 164 , 30, text[limba]);
                settextstyle(0, HORIZ_DIR, 2);
            outtextxy((rezX / 2) - 125, 60, text_mutari[limba]);
            }
        if(limba == 2)
           {   settextstyle(0, HORIZ_DIR, 3);
                outtextxy((rezX / 2) - 200 , 30, text[limba]);
                settextstyle(0, HORIZ_DIR, 2);
           outtextxy((rezX / 2) - 164 , 60, text_mutari[limba]);
            }

    }
    else  if(alegere == 2)
    {
        setcolor(COLOR(r_player_2,g_player_2,b_player_2));

        if(limba == 0)
            {   settextstyle(0, HORIZ_DIR, 3);
                outtextxy((rezX / 2) - 135, 30, text_banut[limba]);

            }
        if(limba == 1)
            {   settextstyle(0, HORIZ_DIR, 3);
                outtextxy((rezX / 2) - 149 , 30, text_banut[limba]);

            }
        if(limba == 2)
           {   settextstyle(0, HORIZ_DIR, 3);
                outtextxy((rezX / 2) - 200 , 30, text_banut[limba]);

            }

    }
      else  if(alegere == 3)
    {
        setcolor(COLOR(r_player_1,g_player_1,b_player_1));

        if(limba == 0)
            {   settextstyle(0, HORIZ_DIR, 3);
                outtextxy((rezX / 2) - 135 , 30, text_banut[limba]);

            }
        if(limba == 1)
            {   settextstyle(0, HORIZ_DIR, 3);
                outtextxy((rezX / 2) - 149 , 30, text_banut[limba]);

            }
        if(limba == 2)
           {   settextstyle(0, HORIZ_DIR, 3);
                outtextxy((rezX / 2) - 200 , 30, text_banut[limba]);

            }

    }
    else  if(alegere == 1 && castigator == true)
    {
        setcolor(COLOR(r_player_2,g_player_2,b_player_2));

        if(limba == 0)
            {   settextstyle(0, HORIZ_DIR, 3);
                outtextxy((rezX / 2) - 115 , 30, text_castigator[limba]);

            }
        if(limba == 1)
            {   settextstyle(0, HORIZ_DIR, 3);
                outtextxy((rezX / 2) - 70 , 30, text_castigator[limba]);

            }
        if(limba == 2)
           {   settextstyle(0, HORIZ_DIR, 3);
                outtextxy((rezX / 2) - 80 , 30, text_castigator[limba]);

            }
    }
    else  if(alegere == 0 && castigator == true)
    {
        setcolor(COLOR(r_player_1,g_player_1,b_player_1));

        if(limba == 0)
            {   settextstyle(0, HORIZ_DIR, 3);
                outtextxy((rezX / 2) - 115 , 30, text_castigator[limba]);

            }
        if(limba == 1)
            {   settextstyle(0, HORIZ_DIR, 3);
                outtextxy((rezX / 2) - 70 , 30, text_castigator[limba]);

            }
        if(limba == 2)
           {   settextstyle(0, HORIZ_DIR, 3);
                outtextxy((rezX / 2) - 80, 30, text_castigator[limba]);

            }
    }
    setcolor(BLACK);


}
void mutare_invalida(int t[5][5],int player)
{
    int i,j;
    for(i=1; i<=4; i++)
        for(j=1; j<=4; j++)
        {
            if(t[i][j]== 4)
            {
                if(player == 1)
                    t[i][j] = 1;

                else if(player == 2)
                    t[i][j]=2;
            }
        }
}
void eliminare_piese_dupa_mutare(int t[5][5])
{
    int i,j;
    for(i=1; i<=4; i++)
        for(j=1; j<=4; j++)
        {

            if(t[i][j] == 5 || t[i][j]==4)
            {
                t[i][j] = 0;
            }
        }
}
void schimbare_valori_piese(int alegere)
{
    int i,j;
    for(i=1; i<=4; i++)
        for(j=1; j<=4; j++)
            if(t[i][j] == alegere)
                t[i][j]=4;

}
void desenare_piese(int t[5][5])
{
    int i,j;
    for(i=1; i<=4; i++)
        for(j=1; j<=4; j++)
        {
            if(t[i][j] == 5)
            {
                setfillstyle(SOLID_FILL,COLOR(192,192,192));
                setlinestyle(SOLID_LINE,0,2);
                fillellipse((tc[i][j].rX-tc[i][j].lX) / 2 + tc[i][j].lX, (tc[i][j].rY - tc[i][j].lY)/2 +tc[i][j].lY,50,50);
                setlinestyle(SOLID_LINE,0,5 );
            }
            else if(t[i][j] == 4)
            {
                setfillstyle(SOLID_FILL,COLOR(192,192,192));
                bar(tc[i][j].lX,tc[i][j].lY,tc[i][j].rX,tc[i][j].rY);
            }
            else if(t[i][j] == 3)
            {
                setfillstyle(SOLID_FILL,WHITE);
                setlinestyle(SOLID_LINE,0,2);
                fillellipse((tc[i][j].rX-tc[i][j].lX) / 2 + tc[i][j].lX, (tc[i][j].rY - tc[i][j].lY)/2 +tc[i][j].lY,50,50);
                setlinestyle(SOLID_LINE,0,5 );
            }
            else if (t[i][j] == 2)
            {
                setfillstyle(SOLID_FILL,COLOR(r_player_2,g_player_2,b_player_2));
                bar(tc[i][j].lX,tc[i][j].lY,tc[i][j].rX,tc[i][j].rY);
            }
            else if (t[i][j] == 1)
            {
                setfillstyle(SOLID_FILL,COLOR(r_player_1,g_player_1,b_player_1));
                bar(tc[i][j].lX,tc[i][j].lY,tc[i][j].rX,tc[i][j].rY);
            }
            else if(t[i][j] == 0)
            {
                setfillstyle(SOLID_FILL,COLOR(r_fundal,g_fundal,b_fundal));
                bar(tc[i][j].lX,tc[i][j].lY,tc[i][j].rX,tc[i][j].rY);
            }
        }

}
void coordonate_tabla() // teoretic trebuie sa retinem coordonatele pt fiecare patratel din matrice, ca sa stim unde desenam, m-am folosit de functia ta din scripts.h pt a gasi acele coordonate
// fara functia ta din scripts.h probabil am fi stat o saptamana intreaga sa gasim coordonatele, deci thumbs up pentru scripts.h  :)
{
    int i,j;
    //tc =tabla coordonate sau ceva de genu'( prescurtat ca o sa le folosim des si sa nu arate urat, e initializat in coordonate.h)


    for(i=1; i<=4; i++)
    {
        for(j = 1; j<=4; j++)
        {
            tc[i][j].lX=392 + (j-1) * 125;    //tc =tabla coordonate sau ceva de genu'( prescurtat ca o sa le folosim des si sa nu arate urat, e initializat in coordonate.h)
            tc[i][j].lY=112 + (i-1) * 125;
            tc[i][j].rX=513 + (j-1) * 125;
            tc[i][j].rY=233 + (i-1) * 125;
            t_pozitii[i][j] = 0;
        }
    }
}



//-> Memorare pozitie [chiar daca e apelata doar odata, e mai bine sa fie functie]
void memorare_pozitie(int player){
    for(int i = 1; i <= 4; i++)
        for(int j = 1; j <= 4; j++)
            if (t[i][j] == player) t_pozitii[i][j] = player;

     t_pozitii[0][0] = -1;
     t_pozitii[1][0] = -1;
     t_pozitii[2][0] = -1;
     t_pozitii[3][0] = -1;
     t_pozitii[4][0] = -1;

     t_pozitii[0][0] = -1;
     t_pozitii[0][1] = -1;
     t_pozitii[0][2] = -1;
     t_pozitii[0][3] = -1;
     t_pozitii[0][4] = -1;

}




//-> Functii ce returneaza vecinii in functie de pozitie
int ssus(int x, int y) {
    if (x > 0) return t_player[x-1][y];
    else return -1;
}

int jos(int x, int y) {
    if (x < 3) return t_player[x+1][y];
    else return -1;
}

int sstanga(int x, int y) {
    if (y > 0) return t_player[x][y-1];
    else return -1;
}

int dreapta(int x, int y) {
    if (y < 3) return t_player[x][y+1];
    else return -1;
}

bool caz_unu(int i, int j, int val){
    if((dreapta(i, j) == val) && (jos(i, j+1) == val) && (jos(i+1, j+1) == val)) return true;
    else return false;
}

bool caz_doi(int i, int j, int val){
    if((sstanga(i, j) == val) && (jos(i, j-1) == val) && (jos(i+1, j-1) == val)) return true;
    else return false;
}

bool caz_trei(int i, int j, int val){
    if((jos(i, j) == val) && (dreapta(i+1, j) == val) && (dreapta(i+1, j+1) == val)) return true;
    else return false;
}

bool caz_patru(int i, int j, int val){
    if((jos(i, j) == val) && (sstanga(i+1, j) == val) && (sstanga(i+1, j-1) == val)) return true;
    else return false;
}

bool caz_cinci(int i, int j, int val){
    if((ssus(i, j) == val) && (dreapta(i-1, j) == val) && (dreapta(i-1, j+1) == val)) return true;
    else return false;
}

bool caz_sase(int i, int j, int val){
    if((ssus(i, j) == val) && (sstanga(i-1, j) == val) && (sstanga(i-1, j-1) == val)) return true;
    else return false;
}

bool caz_sapte(int i, int j, int val){
    if((sstanga(i, j) == val) && (ssus(i, j-1) == val) && (ssus(i-1, j-1) == val)) return true;
    else return false;
}

bool caz_opt(int i, int j, int val){
    if((dreapta(i, j) == val) && (ssus(i, j+1) == val) && (ssus(i-1, j+1) == val)) return true;
    else return false;
}

//[S]: Functie ce cauta numarul de miscari cat mai mici al unei mutari de banut
int posibilitati_banut(){


    //[S]: Cautare numar de miscari dupa algoritmul original
    int nr_miscari = 0;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(t_player[i][j] == 0){
                if(caz_unu(i, j, 0))    nr_miscari++;
                if(caz_doi(i, j, 0))    nr_miscari++;
                if(caz_trei(i, j, 0))   nr_miscari++;
                if(caz_patru(i,j, 0))   nr_miscari++;
                if(caz_cinci(i,j, 0))   nr_miscari++;
                if(caz_sase(i,j, 0))    nr_miscari++;
                if(caz_sapte(i,j, 0))   nr_miscari++;
                if(caz_opt(i,j, 0))     nr_miscari++;
            }
        }
    }

    --nr_miscari;

    printf("\n[BANUT]: Nr de miscari: %d", nr_miscari);

    

    return nr_miscari;

}







void mutare_banut(int player)
{
    bool schimbat = false, change = false;

    int x,y,ii,jj;
    afisare_text_joc(turn%2+2);

    if (dificultate == 1 && mod_joc == 2 && player == 2) schimbat = true;
    if (dificultate == 2 && mod_joc == 2 && player == 2) {

        delay(200); //<- Pentru a putea vedea piesa modificanduse

        //[S]: Algoritm de cautare si aranjare corecta a banutilor
        //[S]: Egalare matrice intermediara(T_Player) cu T
        for(int i = 1; i <=4; i++)
            for(int j = 1; j <= 4; j++) t_player[i-1][j-1] = t[i][j];


        //[S]: Egalare temporara a lui 1 cu 0
        printf("\n");
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                if(t_player[i][j] == 1) t_player[i][j] = 0;
            }
        }


        printf("\n");
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                printf("%d ", t_player[i][j]);
            }
        printf("\n");
        }
        

        //[S]: Testare daca este necesare modificare unui banuts
        if(posibilitati_banut() != 0){

            //[S]: Readucere la normal pentru a nu intr-a in conflict banutul cu 
            for(int i = 0; i < 4; i++)
                for(int j = 0; j < 4; j++)
                    if(t[i+1][j+1] == 1) t_player[i][j] = 1;


            int nr_modificari = 17, contor = 0;

            //[S]: Cautare a primului banuts si incercare de a il modifica
            struct ban{
                int imd_i, imd_j;
                int init_i, init_j;
                int val;
            }b1, b2;
            bool gasit = false;

            for (int i = 0; i < 4; ++i){
                for(int j = 0; j < 4; ++j)
                    if(t_player[i][j] == 3) {
                        gasit = true;
                        b1.init_i = i;
                        b1.init_j = j;
                        t_player[i][j] = 0;
                        printf("\n!Banuts Gasit 1: i = %d j = %d \n", b1.init_i, b1.init_j);
                        break;}
                if(gasit) break;
            }

            //[S]: Modificare primului banuts pe tabla si compararea repetata
            for (int i = 0; i < 4; ++i){
                for(int j = 0; j < 4; ++j){
                    if(t_player[i][j] == 0) {

                        t_player[i][j] = 3;

                        printf("\n");
                        for(int i = 0; i < 4; i++){
                            for(int j = 0; j < 4; j++){
                                if(t_player[i][j] == 1) t_player[i][j] = 0;
                                printf("%d ", t_player[i][j]);
                            }
                            printf("\n");
                        }

                        contor = posibilitati_banut();
                        if(contor < nr_modificari){
                            nr_modificari = contor;
                            b1.imd_i = i;
                            b1.imd_j = j;
                            b1.val = nr_modificari;
                        }

                        for(int i = 0; i < 4; i++)
                            for(int j = 0; j < 4; j++)
                                if(t[i+1][j+1] == 1) t_player[i][j] = 1;

                        t_player[i][j] = 0;
                    }
                }
            }

            
            
            gasit = false; nr_modificari = 17; contor = 0;
            //[S]: Modificare al doilea banuts pe tabla si compararea repetata
             for (int i = 0; i < 4; ++i){
                for(int j = 0; j < 4; ++j){
                    if(t_player[i][j] == 3) {
                        gasit = true;
                        b2.init_i = i;
                        b2.init_j = j;
                        t_player[i][j] = 0;
                        printf("\n!Banuts Gasit 2: i = %d j = %d \n", b2.init_i, b2.init_j);
                        break;}
                }
                if(gasit) break;
            }
            //[S]: Readucere piesa in T_Player la normal
            t_player[b1.init_i][b1.init_j] = 3;

            
            for (int i = 0; i < 4; ++i){
                for(int j = 0; j < 4; ++j){
                    if(t_player[i][j] == 0) {

                        t_player[i][j] = 3;

                        printf("\n");
                        for(int i = 0; i < 4; i++){
                            for(int j = 0; j < 4; j++){
                                if(t_player[i][j] == 1) t_player[i][j] = 0;
                                printf("%d ", t_player[i][j]);
                            }
                            printf("\n");
                        }

                        contor = posibilitati_banut();
                        if(contor < nr_modificari){
                            nr_modificari = contor;
                            b2.imd_i = i;
                            b2.imd_j = j;
                            b2.val = nr_modificari;
                        }

                        for(int i = 0; i < 4; i++)
                            for(int j = 0; j < 4; j++)
                                if(t[i+1][j+1] == 1) t_player[i][j] = 1;

                        t_player[i][j] = 0;
                    }
                }
            }
            
        
            //-- Partea cu if

            if(b1.val < b2.val){
                t[b1.init_i+1][b1.init_j+1] = 0;
                t[b1.imd_i+1][b1.imd_j+1] = 3;
            }else {
                t[b2.init_i+1][b2.init_j+1] = 0;
                t[b2.imd_i+1][b2.imd_j+1] = 3;
            }


            printf("\n");
            for(int i = 0; i < 4; i++){
                for(int j = 0; j < 4; j++){
                    printf("%d ", t[i+1][j+1]);
                }
                printf("\n");
            }

            desenare_piese(t);
            delay(1000);

            }


        schimbat = true;
    }

while(schimbat == false && game_back == false)
   {

    while(true)
    {
        x = mousex();
        y = mousey();
        if(ismouseclick(WM_MBUTTONDOWN)!=0 && change ==false)
        {
            schimbat = true;
            clearmouseclick(WM_MBUTTONDOWN);
            break;
        }
        if(ismouseclick(WM_RBUTTONDOWN)!=0 && change == false )
        {
            delay(2);
            verificare_pozitie(x,y,ii,jj);
            if(t[ii][jj]== 3)
            {
                t[ii][jj] = 5;
                desenare_piese(t);
                change = true;
            }
            clearmouseclick(WM_RBUTTONDOWN);
        }

        x=mousex();
        y=mousey();
        if(ismouseclick(WM_RBUTTONDOWN)!=0 && change == true)
        {
            verificare_pozitie(x,y,ii,jj);
            if(t[ii][jj] == 0 || t[ii][jj] == 5 )
            {
                t[ii][jj] = 3;
                eliminare_piese_dupa_mutare(t);
                desenare_piese(t);
                schimbat = true;
                break;
            }
            clearmouseclick(WM_RBUTTONDOWN);

        }
        if(!(x >= 388 && x <=893 && y>= 108 && y <= 613))
        {
           break;

        }
    }


buton_back_start(x,y,1);
}

}










bool verificare_castigator(int t[5][5], int player){



    //-> Initializare Matrice de pozitii fara player
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if (((t[i+1][j+1] != player) || (t[i+1][j+1] == 0)) && t[i+1][j+1] != 4) t_player[i][j] = t[i+1][j+1];
            else  {t_player[i][j] = 0; t[i+1][j+1] = 0;}
        }
    }


    //-> Cautare L

    //-> Numarul de pozitii
    nr_poz = 0;

    //-> Incepem cautarea de 0
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){

            //->Verificam cazurile de L

            if(t_player[i][j] == 0){
                if(caz_unu(i, j, 0)) {nr_poz++; /*printf("[CAZ_UNU] i = %d, j = %d  nr_poz = %d\n ", i, j, nr_poz);*/}
                if(caz_doi(i, j, 0)) {nr_poz++; /*printf("[CAZ_DOI] i = %d, j = %d  nr_poz = %d\n ", i, j, nr_poz);*/}
                if(caz_trei(i, j, 0)) {nr_poz++; /*printf("[CAZ_TREI] i = %d, j = %d  nr_poz = %d\n ", i, j, nr_poz);*/}
                if(caz_patru(i,j, 0)) {nr_poz++; /*printf("[CAZ_PATRU] i = %d, j = %d  nr_poz = %d\n ", i, j, nr_poz);*/}
                if(caz_cinci(i,j, 0)) {nr_poz++; /*printf("[CAZ_CINCI] i = %d, j = %d  nr_poz = %d\n ", i, j, nr_poz);*/}
                if(caz_sase(i,j, 0)) {nr_poz++; /*printf("[CAZ_SASE] i = %d, j = %d  nr_poz = %d\n ", i, j, nr_poz);*/}
                if(caz_sapte(i,j, 0)) {nr_poz++; /*printf("[CAZ_SAPTE] i = %d, j = %d  nr_poz = %d\n ", i, j, nr_poz);*/}
                if(caz_opt(i,j, 0)) {nr_poz++; /*printf("[CAZ_OPT] i = %d, j = %d  nr_poz = %d\n ", i, j, nr_poz);*/}
            }


        }
    }

    //->Scoate pozitia initiala a noastra
    nr_poz--;

    //Afisare nr de mutari posibile
   // printf("Nr de mutari posibile : %d", nr_poz);


    if (nr_poz == 0) return true;
    else return false;

}

    /*







/*
//-> Afisari pentru a intelege algoritmul
        printf("Matrice T:\n");
        for(i = 1; i <= 4; i++){
            for(j = 1; j <= 4; j++){
                printf("%d ", t[i][j]);
            }
            printf("\n");
        }

        printf("MAtrice T_PLAYER\n");


        for(i = 0; i < 4; i++){
            for(j = 0; j < 4; j++){
                printf("%d ", t_player[i][j]);
            }
            printf("\n");
        }

*/



bool verifica_lpiesa(int t[5][5], int player){

    //-> Diagonale si Vecini
    int dig = 0, vecini = 0, egal = 0;

    //-> Cautare diagonale[1]
    for(int i = 1; i <= 4; i++){
        for(int j = 1; j <= 4; j++){

            //-> Cazul Diagonalelor
            if((t[i][j] == player) && t[i+1][j+1] == player) dig++; //dreapta jos
            if((t[i][j] == player) && t[i-1][j-1] == player) dig++; //stanga sus
            if((t[i][j] == player) && t[i-1][j+1] == player) dig++; //dreapta sus
            if((t[i][j] == player) && t[i+1][j-1] == player) dig++; //stanga sus

            //-> Cazul Vecinilor
            if((t[i][j] == player) && t[i-1][j] == player) vecini++; //jos
            if((t[i][j] == player) && t[i+1][j] == player) vecini++; //sus
            if((t[i][j] == player) && t[i][j+1] == player) vecini++; //dreapta
            if((t[i][j] == player) && t[i][j-1] == player) vecini++; //stanga

            //-> Verificare pozitie noua
            if(t[i][j] == t_pozitii[i][j] && t[i][j] == player) egal++;
        }
    }
    //-> Verificare daca este piesa valida
    if (dig == 2 && vecini == 6 && egal != 4) {

        //->Stergere ultima pozitie din t_pozitii
        for(int i = 1; i <= 4; i++)
            for(int j = 1; j <= 4; j++)
                if(t_pozitii[i][j] == player) t_pozitii[i][j] = 0;



        return true;
    } else return false;
}


void colorare_tabla(int player){

    //-> Am facut un for da idk de ce nu dorea sa se faca toata tabla 0
    //-> Resetare tabla la 0
    t[1][1] = 0;
    t[1][2] = 0;
    t[1][3] = 0;
    t[1][4] = 0;

    t[2][1] = 0;
    t[2][2] = 0;
    t[2][3] = 0;
    t[2][4] = 0;

    t[3][1] = 0;
    t[3][2] = 0;
    t[3][3] = 0;
    t[3][4] = 0;

    t[4][1] = 0;
    t[4][2] = 0;
    t[4][3] = 0;
    t[4][4] = 0;
    //------------------------

    //-> Desenare in centru
    delay(50);
    t[2][2] = player;
    desenare_piese(t);

    delay(50);
    t[2][3] = player;
    desenare_piese(t);

    delay(50);
    t[3][3] = player;
    desenare_piese(t);

    delay(50);
    t[3][2] = player;
    desenare_piese(t);


    //-> Desenare laturi
    delay(25);
    t[3][1] = player;
    desenare_piese(t);

    delay(25);
    t[2][1] = player;
    desenare_piese(t);
    delay(25);
    t[1][1] = player;
    desenare_piese(t);
    delay(25);
    t[1][2] = player;
    desenare_piese(t);
    delay(25);
    t[1][3] = player;
    desenare_piese(t);
    delay(25);
    t[1][4] = player;
    desenare_piese(t);

    delay(25);
    t[2][4] = player;
    desenare_piese(t);
    delay(25);
    t[3][4] = player;
    desenare_piese(t);
    delay(25);
    t[4][4] = player;
    desenare_piese(t);
    delay(25);
    t[4][3] = player;
    desenare_piese(t);
    delay(25);
    t[4][2] = player;
    desenare_piese(t);
    delay(25);
    t[4][1] = player;
    desenare_piese(t);
    delay(25);



    desenare_piese(t);


}

void mutare_player(int player)
{
    int a[5][5];
    bool mutat_piesa = false;
    schimbare_valori_piese(player);
    desenare_piese(t);
    delay(2);

    int x,y,ii=-1,jj=-1;

    clearmouseclick(WM_LBUTTONDOWN);
    while(mutat_piesa == false)
    {

        int k=0;
        copiere_matrice(a,t);
        clearmouseclick(WM_LBUTTONDOWN);

        //-> Verificare Castigator
        if (verificare_castigator(t, player)){

                if(player == 1) player = 2;
                else player = 1;



                castigator = true;
                afisare_text_joc(turn%2);
                colorare_tabla(player);
                break;
            }
        delay(50);
        afisare_text_joc(turn%2);
        delay(2);

        while(k!=4)
        {
            x = mousex();
            y=  mousey();


            if(ismouseclick(WM_LBUTTONDOWN)!=0 && (x >= 388 && x <=893 && y>= 108 && y <= 613))
            {

                verificare_pozitie(x,y,ii,jj);
                if(t[ii][jj]==0 || t[ii][jj]==4)
                {
                    modificare_piesa(ii,jj,player,t);
                    desenare_piese(t);
                    k++;
                }

                if((GetKeyState(VK_LBUTTON) & 0x80)==0 && k !=4)
                {
                    copiere_matrice(t,a);
                    desenare_piese(t);
                    break;

                }


                if(k == 4 && !(verifica_lpiesa(t, player))){ //<- verificam daca avem deja 4 patrate si daca piesa nu este un L
                    delay(10);                               //<- il putem pastra doar daca vrei sa vezi si ultima piesa pentru o clipa
                    clearmouseclick(WM_LBUTTONDOWN);
                    copiere_matrice(t,a);
                    desenare_piese(t);
                    k = 0;
                }


            }


            if(k==4){
                clearmouseclick(WM_LBUTTONDOWN);
                eliminare_piese_dupa_mutare(t);
                desenare_piese(t);
                mutat_piesa = true;

                //-> Memorare pozitie
                memorare_pozitie(player);
                break;
            }

            if(!(x >= 388 && x <=893 && y>= 108 && y <= 613))
            {
                copiere_matrice(t,a);
                 desenare_piese(t);

                break;


            }

        }



        buton_back_start(x,y,1);
        break;
    }
    if(mutat_piesa == true){
    mutare_banut(player);
    turn++;}
}






void adancime_cazuri(int y, int x, int caz){

    printf("[*]Am intrat cu caz: %d(i = %d, j = %d) \n", caz, y, x);

    //system("cls");
    int i, j;
    //Construim piesa LUI AI in T_Player
    switch(caz){
        case 1:
            t_player[y][x]   = 2;
            t_player[y][x+1] = 2;
            t_player[y+1][x+1] = 2;
            t_player[y+2][x+1] = 2;

            if(t[y+1][x+1] != 0 || t[y+1][x+1+1] != 0 || t[y+1+1][x+1+1] != 0 || t[y+2+1][x+1+1] != 0) {
                for(i = 1; i <= 4; i++){
                    for(j = 1; j <= 4; j++){
                        t_player[i-1][j-1] = t[i][j];
                    }
                }
                return;
            }
        break;
        case 2:
            t_player[y][x]   = 2;
            t_player[y][x-1] = 2;
            t_player[y+1][x-1] = 2;
            t_player[y+2][x-1] = 2;

            if(t[y+1][x+1] != 0 || t[y+1][x+1-1] != 0 || t[y+1+1][x+1-1] != 0 || t[y+2+1][x+1-1] != 0) {
                for(i = 1; i <= 4; i++){
                    for(j = 1; j <= 4; j++){
                        t_player[i-1][j-1] = t[i][j];
                    }
                }
                return;
            }
        break;
        case 3:
            t_player[y][x]   = 2;
            t_player[y+1][x] = 2;
            t_player[y+1][x+1] = 2;
            t_player[y+1][x+2] = 2;

            if(t[y+1][x+1] != 0 || t[y+1+1][x+1+1] != 0 || t[y+1+1][x+1+1] != 0 || t[y+1+1][x+2+1] != 0) {
                for(i = 1; i <= 4; i++){
                    for(j = 1; j <= 4; j++){
                        t_player[i-1][j-1] = t[i][j];
                    }
                }
                return;
            }
        break;
        case 4:
            t_player[y][x]   = 2;
            t_player[y+1][x] = 2;
            t_player[y+1][x-1] = 2;
            t_player[y+1][x-2] = 2;

            if(t[y+1][x+1] != 0 || t[y+1+1][x+1] != 0 || t[y+1+1][x+1-1] != 0 || t[y+1+1][x+1-2] != 0) {
                for(i = 1; i <= 4; i++){
                    for(j = 1; j <= 4; j++){
                        t_player[i-1][j-1] = t[i][j];
                    }
                }
                return;
            }
        break;
        case 5:
            t_player[y][x]   = 2;
            t_player[y-1][x] = 2;
            t_player[y-1][x+1] = 2;
            t_player[y-1][x+2] = 2;

            if(t[y+1][x+1] != 0 || t[y+1-1][x+1] != 0 || t[y-1+1][x+1+1] != 0 || t[y-1+1][x+2+1] != 0) {
                for(i = 1; i <= 4; i++){
                    for(j = 1; j <= 4; j++){
                        t_player[i-1][j-1] = t[i][j];
                    }
                }
                return;
            }
        break;
        case 6:
            t_player[y][x]   = 2;
            t_player[y-1][x] = 2;
            t_player[y-1][x-1] = 2;
            t_player[y-1][x-2] = 2;

            if(t[y+1][x+1] != 0 || t[y+1-1][x+1] != 0 || t[y+1-1][x+1-1] != 0 || t[y+1-1][x+1-2] != 0) {
                for(i = 1; i <= 4; i++){
                    for(j = 1; j <= 4; j++){
                        t_player[i-1][j-1] = t[i][j];
                    }
                }
                return;
            }
        break;
        case 7:
            t_player[y][x]   = 2;
            t_player[y][x-1] = 2;
            t_player[y-1][x-1] = 2;
            t_player[y-2][x-1] = 2;

            if(t[y+1][x+1] != 0 || t[y+1][x+1-1] != 0 || t[y+1-1][x+1-1] != 0 || t[y-2+1][x+1-1] != 0) {
                for(i = 1; i <= 4; i++){
                    for(j = 1; j <= 4; j++){
                        t_player[i-1][j-1] = t[i][j];
                    }
                }
                return;
            }
        break;
        case 8:
            t_player[y][x]   = 2;
            t_player[y][x+1] = 2;
            t_player[y-1][x+1] = 2;
            t_player[y-2][x+1] = 2;

            if(t[y+1][x+1] != 0 || t[y+1][x+1+1] != 0 || t[y-1+1][x+1+1] != 0 || t[y-2+1][x+1+1] != 0) {
                for(i = 1; i <= 4; i++){
                    for(j = 1; j <= 4; j++){
                        t_player[i-1][j-1] = t[i][j];
                    }
                }
                return;
            }
        break;
        default: printf("[*] Err: NR CAZ DE INTRARE IN ADANCIME GRESIT.");
    }



    //-> Schimbare pozitii in t_player pt PLAYER = 1
    for(i = 0; i<=3; i++)
        for(j = 0; j <= 3; j++) if (t_player[i][j] == 1) t_player[i][j] = 0;

    //-> Cautare nr de pozitii afectate
    int nr_pz = 0;
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){

            //->Verificam cazurile de L
            if(t_player[i][j] == 0){
                if(caz_unu(i, j, 0)) {nr_pz++; }
                if(caz_doi(i, j, 0)) {nr_pz++; }
                if(caz_trei(i, j, 0)) {nr_pz++; }
                if(caz_patru(i,j, 0)) {nr_pz++; }
                if(caz_cinci(i,j, 0)) {nr_pz++; }
                if(caz_sase(i,j, 0)) {nr_pz++;}
                if(caz_sapte(i,j, 0)) {nr_pz++; }
                if(caz_opt(i,j, 0)) {nr_pz++; }
            }


        }
    }



   --nr_pz;


    //[DEV CONTROL] printf("nr de pz: %d \n", nr_pz);
    if(dificultate == 1){
        if(nr_pz > NR_POSIBILITATI) {
            NR_POSIBILITATI = nr_pz;
            ind_ai = y;
            ind_aj = x;
            ind_caz = caz;
            printf("-> [v]: Caz intermediar utilizat : %d \n", ind_caz);
            printf("-> [v]: Coordonata [i] intermediar utilizat : %d \n", ind_ai);
            printf("-> [v]: Coordonata [j] intermediar utilizat : %d \n\n", ind_aj);
        }
    }

    if(dificultate == 2){
        printf("-> [x]: Nr de posiblitati: %d\n", nr_pz);
        if(nr_pz < NR_POSIBILITATI) {
            NR_POSIBILITATI = nr_pz;
            ind_ai = y;
            ind_aj = x;
            ind_caz = caz;
            printf("-> [v]: Caz intermediar utilizat : %d \n", ind_caz);
            printf("-> [v]: Coordonata [i] intermediar utilizat : %d \n", ind_ai);
            printf("-> [v]: Coordonata [j] intermediar utilizat : %d \n\n", ind_aj);
        }
    }



        //delay(1000);

/*
printf("nr caz %d \n", nr_pz);
//-> Afisari pentru a intelege algoritmul
        printf("Matrice T:\n");
        for(i = 1; i <= 4; i++){
            for(j = 1; j <= 4; j++){
                printf("%d ", t[i][j]);
            }
            printf("\n");
        }

        printf("MAtrice T_PLAYER\n");


        for(i = 0; i < 4; i++){
            for(j = 0; j < 4; j++){
                printf("%d ", t_player[i][j]);
            }
            printf("\n");
        }
        //delay(3000);

*/

    for(i = 1; i <= 4; i++){
        for(j = 1; j <= 4; j++){
            t_player[i-1][j-1] = t[i][j];
        }
    }




}










void mutare_player_pc(int player)
{
    int a[5][5];
    bool mutat_piesa = false;
    schimbare_valori_piese(player);
    desenare_piese(t);
    delay(2);

    int x,y,ii=-1,jj=-1;

    clearmouseclick(WM_LBUTTONDOWN);
    while(mutat_piesa == false)
    {

        int k=0;
        copiere_matrice(a,t);
        clearmouseclick(WM_LBUTTONDOWN);

        //-> Verificare Castigator
        if (verificare_castigator(t, player)){

                if(player == 1) player = 2;
                else player = 1;



                castigator = true;
                afisare_text_joc(turn%2);
                colorare_tabla(player);
                break;
            }
        delay(50);
        afisare_text_joc(turn%2);
        delay(2);
        if(player == 1){
            while(k!=4)
            {
                x = mousex();
                y=  mousey();


               if(ismouseclick(WM_LBUTTONDOWN)!=0 && (x >= 388 && x <=893 && y>= 108 && y <= 613))
               {

                    verificare_pozitie(x,y,ii,jj);
                    if(t[ii][jj]==0 || t[ii][jj]==4)
                    {
                        modificare_piesa(ii,jj,player,t);
                        desenare_piese(t);
                        k++;
                    }

                    if((GetKeyState(VK_LBUTTON) & 0x80)==0 && k !=4)
                    {
                        copiere_matrice(t,a);
                        desenare_piese(t);
                        break;

                    }


                   if(k == 4 && !(verifica_lpiesa(t, player))){ //<- verificam daca avem deja 4 patrate si daca piesa nu este un L
                        delay(10);                               //<- il putem pastra doar daca vrei sa vezi si ultima piesa pentru o clipa
                        clearmouseclick(WM_LBUTTONDOWN);
                        copiere_matrice(t,a);
                        desenare_piese(t);
                        k = 0;
                   }


                }


                if(k==4){
                    clearmouseclick(WM_LBUTTONDOWN);
                    eliminare_piese_dupa_mutare(t);
                    desenare_piese(t);
                    mutat_piesa = true;

                    //-> Memorare pozitie
                    memorare_pozitie(player);
                    break;
                }

                if(!(x >= 388 && x <=893 && y>= 108 && y <= 613))
                {
                    copiere_matrice(t,a);
                    desenare_piese(t);

                    break;


               }

            }
        }

        if(player == 2){

            if(dificultate == 2) NR_POSIBILITATI = 17;

            if(dificultate == 1 || dificultate == 2)
            {
                system("cls");
                /* [DEV CONTROL]
                printf("ai %d \n", ai_i);
                printf("ai %d \n", ai_j);
                printf("nr caz %d \n ", nr_caz);

                */

                //-> Doar ca siguranta, inlocuim cu 0 pozitia lui 2
                for(int i = 1; i <= 4; i++){
                    for(int j = 1; j <= 4; j++){
                        if(t[i][j] == 2) t[i][j] = 0;
                        t_player[i-1][j-1] = t[i][j];
                    }
                }

                /* [DEV CONTROL]
                for(int i = 0; i < 4; i++){
                    for(int j = 0; j < 4; j++){
                        printf("%d ", t_player[i][j]);
                    }
                    printf("\n");
                }*/



                int intm = 1;
                //Cautam in matricea T figuri
                //-> Incepem cautarea de 0
                for(int i = 0; i < 4; i++){
                    for(int j = 0; j < 4; j++){
                        intm = 1;

                        //->Verificam cazurile de L

                        if(t_player[i][j] == 0 && t[i+1][j+1] != 1){



                            if(i == ai_i && j == ai_j){
                                //printf("Coordonate: i=%d j=%d [CAZ EGAL ANTERIOR]\n", i, j);
                                if(caz_unu(i, j, 0) && nr_caz != intm) {adancime_cazuri(i, j, 1); /*printf("->1 \n");*/} intm++;
                                if(caz_doi(i, j, 0) && nr_caz != intm) {adancime_cazuri(i, j, 2); /*printf("->2 \n");*/} intm++;
                                if(caz_trei(i, j, 0) && nr_caz != intm) {adancime_cazuri(i, j, 3);/*printf("->3 \n");*/} intm++;
                                if(caz_patru(i,j, 0) && nr_caz != intm) {adancime_cazuri(i, j, 4);/*printf("->4 \n");*/} intm++;
                                if(caz_cinci(i,j, 0) && nr_caz != intm) {adancime_cazuri(i, j, 5);/*printf("->5 \n");*/} intm++;
                                if(caz_sase(i,j, 0) && nr_caz != intm) {adancime_cazuri(i, j, 6); /*printf("->6 \n");*/} intm++;
                                if(caz_sapte(i,j, 0) && nr_caz != intm) {adancime_cazuri(i, j, 7);/*printf("->7 \n");*/} intm++;
                                if(caz_opt(i,j, 0) && nr_caz != intm) {adancime_cazuri(i, j, 8);  /*printf("->8 \n");*/}
                                //delay(1000);

                            }else{
                                //printf("Coordonate: i=%d j=%d [CAZ OBISNUIT] \n", i, j);
                                if(caz_unu(i, j, 0)) {adancime_cazuri(i, j, 1); /*printf("->1 \n");*/}
                                if(caz_doi(i, j, 0)) {adancime_cazuri(i, j, 2);/*printf("->2 \n");*/}
                                if(caz_trei(i, j, 0)) {adancime_cazuri(i, j, 3);/*printf("->3 \n");*/}
                                if(caz_patru(i,j, 0)) {adancime_cazuri(i, j, 4);/*printf("->4 \n");*/}
                                if(caz_cinci(i,j, 0)) {adancime_cazuri(i, j, 5);/*printf("->5 \n");*/}
                                if(caz_sase(i,j, 0)) {adancime_cazuri(i, j, 6);/*printf("->6 \n");*/}
                                if(caz_sapte(i,j, 0)) {adancime_cazuri(i, j, 7);/*printf("->7 \n");*/}
                                if(caz_opt(i,j, 0)) {adancime_cazuri(i, j, 8);/*printf("->8 \n");*/}
                                //delay(1000);

                            }

                        }
                    }
                }



                //-> Resetare valori ce vin din Adancime Cazuri
                NR_POSIBILITATI = 0;
                ai_i = ind_ai+1;
                ai_j = ind_aj+1;
                nr_caz = ind_caz;




                printf("\n\n[x]: Coordonata finala pt mutare [i] : %d \n", ai_i-1);
                printf("[x]: Coordonata finala pt mutare [j] : %d \n", ai_j-1);
                printf("[x]: Numar CAZ :  %d \n", nr_caz);


                ind_ai = 0;
                ind_aj = 0;
                ind_caz = 0;


                //-> Desenare pe tabla a pieselor castigatorului
                switch(nr_caz){
                    case 1:
                        t[ai_i][ai_j]   = 2;
                        t[ai_i][ai_j+1] = 2;
                        t[ai_i+1][ai_j+1] = 2;
                        t[ai_i+2][ai_j+1] = 2;
                    break;
                    case 2:
                        t[ai_i][ai_j]   = 2;
                        t[ai_i][ai_j-1] = 2;
                        t[ai_i+1][ai_j-1] = 2;
                        t[ai_i+2][ai_j-1] = 2;
                    break;
                    case 3:
                        t[ai_i][ai_j]   = 2;
                        t[ai_i+1][ai_j] = 2;
                        t[ai_i+1][ai_j+1] = 2;
                        t[ai_i+1][ai_j+2] = 2;
                    break;
                    case 4:
                        t[ai_i][ai_j]   = 2;
                        t[ai_i+1][ai_j] = 2;
                        t[ai_i+1][ai_j-1] = 2;
                        t[ai_i+1][ai_j-2] = 2;
                    break;
                    case 5:
                        t[ai_i][ai_j]   = 2;
                        t[ai_i-1][ai_j] = 2;
                        t[ai_i-1][ai_j+1] = 2;
                        t[ai_i-1][ai_j+2] = 2;
                    break;
                    case 6:
                        t[ai_i][ai_j]   = 2;
                        t[ai_i-1][ai_j] = 2;
                        t[ai_i-1][ai_j-1] = 2;
                        t[ai_i-1][ai_j-2] = 2;
                    break;
                    case 7:
                        t[ai_i][ai_j]   = 2;
                        t[ai_i][ai_j-1] = 2;
                        t[ai_i-1][ai_j-1] = 2;
                        t[ai_i-2][ai_j-1] = 2;
                    break;
                    case 8:
                        t[ai_i][ai_j]   = 2;
                        t[ai_i][ai_j+1] = 2;
                        t[ai_i-1][ai_j+1] = 2;
                        t[ai_i-2][ai_j+1] = 2;
                    break;
                    default: printf("[*] Err: TF?.");
                }
                desenare_piese(t);
                --ai_j; --ai_i;
                mutat_piesa = true;

/* [DEV CONTROL]
                printf("Matrice T:\n");
                int i, j;
        for(i = 1; i <= 4; i++){
            for(j = 1; j <= 4; j++){
                printf("%d ", t[i][j]);
            }
            printf("\n");
        }

        printf("MAtrice T_PLAYER\n");


        for(i = 0; i < 4; i++){
            for(j = 0; j < 4; j++){
                printf("%d ", t_player[i][j]);
            }
            printf("\n");
        }
*/
            }

        }


        buton_back_start(x,y,1);
        break;
    }
    if(mutat_piesa == true){
    mutare_banut(player);
    turn++;}
}





void start_joc_pvp()
{
    turn = 1;



    //-> Fundal
    game_back == false;
    castigator = false;
    int ii,jj;
    coordonate_tabla();

    //-> Initializare t_pozitii
     t_pozitii[2][2] = 1;
     t_pozitii[3][2] = 1;
     t_pozitii[4][2] = 1;
     t_pozitii[4][3] = 1;

     t_pozitii[1][2] = 2;
     t_pozitii[1][3] = 2;
     t_pozitii[2][3] = 2;
     t_pozitii[3][3] = 2;





    setbkcolor(COLOR(r_fundal, g_fundal, b_fundal));
    clearviewport();
    incarcare_tabla(t);
    desenare_tabla();
    rectangle(b_back_start.lX, b_back_start.lY - 2, b_back_start.rX, b_back_start.rY + 1);
    setfillstyle(SOLID_FILL, WHITE);
    bar(b_back_start.rX+1, b_back_start.lY, b_back_start.lX, b_back_start.rY);
    text_butoane_start(1);
    desenare_piese(t);

    int x,y;
//  setviewport(388,108,893,613,0);

    while(game_back == false)
    {

        x=mousex();
        y=mousey();
        buton_back_start(x,y,1);
        if(!(castigator))
        {



                if(turn%2==1 )
                {
                    mutare_player(1);
                }


                else if(turn%2==0 )
                {
                    mutare_player(2);
                }





        }
    }
    delay(100);
    if(game_back == true)
    {
        game_back = false;
        sectiune_start();
    }

}



void start_joc_pvpc()
{
    turn = 1;


    //-> Fundal
    game_back == false;
    castigator = false;


    ai_i = 0;
    ai_j = 1;
    nr_caz =1;

    int ii,jj;
    coordonate_tabla();

    //-> Initializare t_pozitii
     t_pozitii[2][2] = 1;
     t_pozitii[3][2] = 1;
     t_pozitii[4][2] = 1;
     t_pozitii[4][3] = 1;

     t_pozitii[1][2] = 2;
     t_pozitii[1][3] = 2;
     t_pozitii[2][3] = 2;
     t_pozitii[3][3] = 2;





    setbkcolor(COLOR(r_fundal, g_fundal, b_fundal));
    clearviewport();
    incarcare_tabla(t);
    desenare_tabla();
    rectangle(b_back_start.lX, b_back_start.lY - 2, b_back_start.rX, b_back_start.rY + 1);
    setfillstyle(SOLID_FILL, WHITE);
    bar(b_back_start.rX+1, b_back_start.lY, b_back_start.lX, b_back_start.rY);
    text_butoane_start(1);
    desenare_piese(t);

    int x,y;
//  setviewport(388,108,893,613,0);

    while(game_back == false)
    {

        x=mousex();
        y=mousey();
        buton_back_start(x,y,1);
        if(!(castigator))
        {



                if(turn%2==1 )
                {
                    mutare_player_pc(1);
                }


                else if(turn%2==0 )
                {
                    mutare_player_pc(2);
                }





        }
    }
    delay(100);
    if(game_back == true)
    {
        game_back = false;
        sectiune_start();
    }

}


#endif // JOC_H_INCLUDED
