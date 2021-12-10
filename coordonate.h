#ifndef COORDONATE
#define COORDONATE

const int spatiux = 50, spatiuy = 50;
const int inaltime = 100, lungime = 200;
int rezX=1280, rezY=720;
struct coordonate
{
    int lX, lY;
    int rX, rY;
} b_start, b_exit, b_settings, b_settings_back, b_settings_apply;

void init_coord_butoane_settings()
{
    b_settings_back.lX = rezX - spatiux - lungime;
    b_settings_back.rX = rezX - spatiux;
    b_settings_back.rY = rezY - spatiuy;
    b_settings_back.lY = b_settings_back.rY - inaltime;
    b_settings_apply.lX = abs(b_settings_back.lX - rezX );
    b_settings_apply.rX = abs(b_settings_back.rX - rezX );


    b_settings_apply.rY = rezY - spatiuy;
    b_settings_apply.lY = b_settings_back.rY - inaltime;
}


#endif // COORDONATE
