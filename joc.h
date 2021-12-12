#ifndef JOC_H_INCLUDED
#define JOC_H_INCLUDED
const int numar = 4, width = 500, height=500, latura=width/numar, sus=(720-width)/2, stanga=(1280-height)/2;
bool game_back;
void buton_back_start(int x,int y, int alegere);
void sectiune_start();
void text_butoane_start(char alegere);
void incarcare_tabla(int t[5][5]);
int t[5][5];
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
void desenare_piese(int t[5][5])
{
    int i,j;
    for(i=1; i<=4; i++)
        for(j=1; j<=4; j++)
        {
            if(t[i][j] == 3)
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
void start_joc_pvp()
{
    delay(2);
    //-> Fundal
    game_back == false;
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

    while(game_back == false)
    {

        x=mousex();
        y=mousey();
        buton_back_start(x,y,1);
    }
    delay(100);
    if(game_back == true)
    {
        game_back = false;
        sectiune_start();
    }

}


#endif // JOC_H_INCLUDED
