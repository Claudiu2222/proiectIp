#ifndef JOC_H_INCLUDED
#define JOC_H_INCLUDED
const int numar = 4, width = 500, height=500, latura=width/numar, sus=(720-width)/2, stanga=(1280-height)/2;
bool game_back;
void buton_back_start(int x,int y, int alegere);
void sectiune_start();
void text_butoane_start(char alegere);
void incarcare_tabla(int t[5][5]);
int t[5][5];
int turn = 1;
bool cursor_in_tabla = false;
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
void modificare_piesa(int i, int j,int player)
{
    if(player == 1)
    {
        t[i][j] = 1;
    }
    else if(player == 2)
    {

        t[i][j] = 2;
    }


}
void eliminare_piese_dupa_mutare(int t[5][5])
{
    int i,j;
    for(i=1; i<=4; i++)
        for(j=1; j<=4; j++)
        {

          if(t[i][j] == 5 || t[i][j]==4)
            {   t[i][j] = 0;
              }}
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
            tc[i][j].lX=392 + (j-1)* 125;    //tc =tabla coordonate sau ceva de genu'( prescurtat ca o sa le folosim des si sa nu arate urat, e initializat in coordonate.h)
            tc[i][j].lY=112 + (i-1) * 125;
            tc[i][j].rX=513 + (j-1) * 125;
            tc[i][j].rY=233 + (i-1) * 125;
        }
    }
}
void mutare_banut()
{   bool schimbat = false, change = false;
    int x,y,ii,jj;

    while(schimbat == false && cursor_in_tabla==true)
    {
        x = mousex();
        y = mousey();
        if(ismouseclick(WM_MBUTTONDOWN)!=0)
        {schimbat = true;
        break;}
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
            {verificare_pozitie(x,y,ii,jj);
            if(t[ii][jj] == 0 || t[ii][jj] == 5 )
            {t[ii][jj] = 3;
            eliminare_piese_dupa_mutare(t);
            desenare_piese(t);
            schimbat = true;
            break;}
clearmouseclick(WM_RBUTTONDOWN);

            }
             if(!(x >= 388 && x <=893 && y>= 108 && y <= 613))
        {
            delay(1);
            cursor_in_tabla = false;

        }}
        }




void mutare_player(int player)
{
    delay(2);
    int x,y,ii=-1,jj=-1;
    int k=0;
    while(k!=4 && cursor_in_tabla == true)
    {
        x = mousex();
        y=  mousey();


        if((GetKeyState(VK_LBUTTON) & 0x80)!=0 )
        {
            delay(30);
            verificare_pozitie(x,y,ii,jj);
            if(t[ii][jj]!= player)
            {
                modificare_piesa(ii,jj,player);
                desenare_piese(t);
                k++;
            }
        }
        if(k==4)
            break;
        if(!(x >= 388 && x <=893 && y>= 108 && y <= 613))
        {
            delay(1);
            cursor_in_tabla = false;

        }
    }
    mutare_banut();
    turn++;

}
void start_joc_pvp()
{
    bool first_move = true;
    delay(2);
    //-> Fundal
    game_back == false;
    int ii,jj;
    coordonate_tabla();
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
        delay(2);
        x=mousex();
        y=mousey();
        buton_back_start(x,y,1);
        if(x >= 388 && x <=893 && y>= 108 && y <= 613) // b_back_start.lX, b_back_start.lY - 2, b_back_start.rX, b_back_start.rY + 1
        {
            delay(2);
            cursor_in_tabla = true;
            if(first_move == true)
            {
                first_move = false;
                if(turn%2==1)
                {
                    mutare_player(1);
                }


                else
                {
                    mutare_player(2);
                }

            }
            else
            {
                if(turn%2==1)
                {
                    delay(1000);
                    mutare_player(1);
                }


                else
                {
                    delay(1000);

                    mutare_player(2);
                }
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
