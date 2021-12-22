#ifndef COORDONATE
#define COORDONATE

const int spatiux = 50, spatiuy = 50;
const int inaltime = 100, lungime = 200;
int rezX=1280, rezY=720;
struct coordonate
{
    int lX, lY;
    int rX, rY;
} b_start, b_exit, b_settings, b_settings_back, b_settings_apply, b_muzica, b_back_start, b_start_game, tc[5][5],b_color[3][7];

void init_coord_butoane()
{
    b_settings_back.lX = rezX - spatiux - lungime;
    b_settings_back.rX = rezX - spatiux;
    b_settings_back.rY = rezY - spatiuy;
    b_settings_back.lY = b_settings_back.rY - inaltime;


    b_settings_apply.lX = abs(b_settings_back.lX - rezX );
    b_settings_apply.rX = abs(b_settings_back.rX - rezX );
    b_settings_apply.rY = rezY - spatiuy;
    b_settings_apply.lY = b_settings_back.rY - inaltime;


    b_muzica.lX = rezX - 80;
    b_muzica.lY = rezY - 700;
    b_muzica.rY = rezY - 650;
    b_muzica.rX = rezX - 30;



    b_back_start.lX = b_settings_apply.lX - 2;
    b_back_start.rX = b_settings_apply.rX;
    b_back_start.rY = b_settings_apply.rY + 2;
    b_back_start.lY = b_settings_apply.lY;



    b_start_game.lX = rezX - spatiux - lungime + 1;
    b_start_game.rX = rezX - spatiux;
    b_start_game.rY = rezY - spatiuy;
    b_start_game.lY = b_settings_back.rY - inaltime;



}


#endif // COORDONATE
