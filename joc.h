#ifndef JOC_H_INCLUDED
#define JOC_H_INCLUDED




//-> Variabile

bool castigator = false;

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
int turn = 1;
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
                setfillstyle(SOLID_FILL,RED);
                bar(tc[i][j].lX,tc[i][j].lY,tc[i][j].rX,tc[i][j].rY);
            }
            else if (t[i][j] == 1)
            {
                setfillstyle(SOLID_FILL,BLUE);
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
void mutare_banut()
{
    bool schimbat = false, change = false;
    int x,y,ii,jj;
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


bool verificare_castigator(int t[5][5], int player){


    system("cls");

    //-> Initializare Matrice de pozitii fara player
    int t_player[4][4], i, j;

    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            if (((t[i+1][j+1] != player) || (t[i+1][j+1] == 0)) && t[i+1][j+1] != 4) t_player[i][j] = t[i+1][j+1];
            else  {t_player[i][j] = 0; t[i+1][j+1] = 0;}
        }
    }




    //-> Algoritmul de cautare a numerelor de 0
    //-> Algoritmul impinge numarul de 0 in matricea t_player in cel mai inalt si stang punct.
    int ii, jj;
    for(i = 3; i >= 0; i--){
        for(j = 3; j >= 0; j--){
            ii = i+1;
            jj = j+1;

            if (t[ii][jj] == 0){

                //-> Linii Hot
                if(ii == 4 && jj == 4){
                    t_player[i][j]++;
                }
                else if (ii == 4){
                    if(t[ii][jj+1] == 0){                       //<- Cautare doar in dreapta
                        t_player[i][j] = t_player[i][j+1] + 1;
                        t_player[i][j+1] = 0;
                    }else t_player[i][j]++;
                }
                else if (jj == 4){
                    if(t[ii+1][jj] == 0){                       //<- Cautare doar in jos si optional diagonala
                        t_player[i][j] = t_player[i+1][j] + 1;
                        t_player[i+1][j] = 0;


                        if(t[ii+1][jj-1] == 0){
                            t_player[i][j] += t_player[i+1][j-1];
                            t_player[i+1][j-1] = 0;

                            if(ii+1 == 4)
                                t_player[i][j]++;

                        }
                    }else t_player[i][j]++;

                }
                else{
                    //-> Interior Matrice
                    if(t[ii+1][jj] == 0 && t[ii][jj+1] == 0){       //<- Adancime si dreapta si optional diagonala
                        t_player[i][j] = t_player[i+1][j] + t_player[i][j+1] + 1;
                        t_player[i+1][j] = 0;
                        t_player[i][j+1] = 0;

                        if(j > 0 && t[ii+1][jj-1] == 0){
                            t_player[i][j] += t_player[i+1][j-1];
                            t_player[i+1][j-1] = 0;

                        }

                    }
                    else if(t[ii+1][jj] == 0){                  //<- Adancime si optional diagonala
                        t_player[i][j] = t_player[i+1][j] + 1;
                        t_player[i+1][j] = 0;

                        if(j > 0 && t[ii+1][jj-1] == 0){
                            t_player[i][j] += t_player[i+1][j-1];
                            t_player[i+1][j-1] = 0;
                        }

                    }
                    else if(t[ii][jj+1] == 0){              //Dreapta
                        t_player[i][j] = t_player[i][j+1] + 1;
                        t_player[i][j+1] = 0;
                    }
                    else t_player[i][j]++;                  //Fara vecini
                }
            }

        }
    }




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

    //-> Cautam min_c(5) min_p(4)
    int min_c = 0, min_p = 0;
    for(i = 0; i < 4; i++)
        for(j = 0; j < 4; j++)
            if (t_player[i][j] >= 5 && t_player[i][j] > min_c) { min_c = t_player[i][j]; t_player[i][j] = 0; }





    //-> Analize de cazuri, sunt mai multe cazuri care trebuie cercetate, cel mai problematic fiind 5, 4
    if (min_c > 5) {  return false; }   //<- Iese automat daca a gasit o grupa de 5+ zerouri
    else if(min_c == 5){

        int i_p = 0, j_p = 0;
        //-> Cautam sa gasim grupul de 4
        for(i = 0; i < 4; i++)
            for(j = 0; j < 4; j++)
                if (t_player[i][j] >= 4 && t_player[i][j] > min_p) { min_p = t_player[i][j]; t_player[i][j] = 0; i_p = i; j_p = j;}


        //-> Cautam sa gasim grupul de 3, chiar daca am cautat 4 si nu am gasit, trebuie cautat si grupe de 3 si 1, anume 1 grupa de 3, 2 grupe de 1
        int min_t = 0;
        int min_1 = 0;
        for(i = 0; i < 4; i++)
            for(j = 0; j < 4; j++){
                if (t_player[i][j] == 3) { min_t++;}
                if (t_player[i][j] == 1) { min_1++;}
            }
        if((min_t-2) == 1 && min_1 >= 1) return false; //<- Cazul dat este valid, mutari exista




        //-> Daca totusi avem un grup de 4
        if(min_p == 4){
            //-> Creare piesa de L din blocul de 4
            int conectari = 0; bool spate_zero = false;
            for(i = i_p; i <= 3; i++){
                for(j = j_p; j <= 3; j++){

                    //-> Verificare pe dreapta si jos, in functie de i si j pentru a nu primi erori la sfarsit de matrice
                    if(i == 3 && j == 3 && spate_zero && t_player[i][j] == 0){
                        t_player[i][j] = 8;
                        conectari++;
                    }
                    else if(i == 3){
                        if(t_player[i][j] == 0 && (t_player[i][j+1] == 0)) { t_player[i][j] = 8; spate_zero = true; conectari++;}
                        else if(t_player[i][j] == 0 && spate_zero && t_player[i][j-1] != 0 && t_player[i-1][j] != 0) { t_player[i][j] = 8; spate_zero = true; conectari++;}
                    }
                    else if(j == 3){
                        if(t_player[i][j] == 0 && (t_player[i+1][j] == 0)) { t_player[i][j] = 8; spate_zero = true; conectari++;}
                        else if(t_player[i][j] == 0 && spate_zero && t_player[i-1][j] != 0 && t_player[i][j-1] != 0) { t_player[i][j] = 8; spate_zero = true; conectari++;}
                    }else{
                        if(t_player[i][j] == 0 && ((t_player[i][j+1] == 0) || ((t_player[i+1][j] == 0)))) { t_player[i][j] = 8; spate_zero = true; conectari++;}
                    }

                    //-> Este necesar ca un sa fie conectate, daca e vreo piesa diferita intr-e 0, sarim randul
                    if(t_player[i][j+1] != 0) break;
                    if (conectari == 4) break;
                }
                if (conectari == 4) break;
            }


            //-> Algoritmul clasic de verificare L, modificat pentru tabelul t_playeri
            //-> Verificare daca e un L
            //-> Diagonale si Vecini
            int dig = 0, vecini = 0; bool da = false;

            //-> Cautare diagonale[1]
            for(int i = 0; i <= 3; i++){
                for(int j = 0; j <= 3; j++){

                    //-> Cazul Diagonalelor
                    if((t_player[i][j] == 8) && t_player[i+1][j+1] == 8 && i > 0) dig++; //dreapta jos
                    if((t_player[i][j] == 8) && t_player[i-1][j-1] == 8 && i < 3) dig++; //stanga sus
                    if((t_player[i][j] == 8) && t_player[i-1][j+1] == 8 && j < 3) dig++; //dreapta sus
                    if((t_player[i][j] == 8) && t_player[i+1][j-1] == 8 && j > 0) dig++; //stanga sus

                    //-> Cazul Vecinilor
                    if((t_player[i][j] == 8) && t_player[i-1][j] == 8 && i > 0) vecini++; //sus
                    if((t_player[i][j] == 8) && t_player[i+1][j] == 8 && i < 3) vecini++; //jos
                    if((t_player[i][j] == 8) && t_player[i][j+1] == 8 && j < 3) vecini++; //dreapta
                    if((t_player[i][j] == 8) && t_player[i][j-1] == 8 && j > 0) vecini++; //stanga
                }
            }
            dig++; //<- Eroare la gasire diagonale, este necesara o incrementare


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
            //-> Verificare daca este piesa valida
            if (dig == 2 && vecini == 6 && rand) { da = true;}
            else da = false;

            //Daca e DA[piesa valida] miscari inca exista, daca nu jocul s-a terminat
            if (da) {return false; }
            else return true;
        }
        else if(min_p < 4) return true;
        else return false;

    }else return true;
}





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

                printf("\n Castigator player %d", player);

                castigator = true;
                break;
            }

        while(k!=4)
        {
            x = mousex();
            y=  mousey();


            if(ismouseclick(WM_LBUTTONDOWN)!=0)
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

        } buton_back_start(x,y,1);
        break;
    }
    if(mutat_piesa == true){
    mutare_banut();
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
        if((x >= 388 && x <=893 && y>= 108 && y <= 613) && !(castigator))
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


#endif // JOC_H_INCLUDED
