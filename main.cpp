#include <cstdlib>
#include<iostream>
#include <SDL/SDL.h>
#include <string>
#include<fstream>
#include<ctime>
#include<sstream>
#include "SDL/SDL_ttf.h"
#include"SDL/SDL_mixer.h"
using namespace std;
SDL_Surface *load_image(string ) ;
void apply_surface( int , int , SDL_Surface* , SDL_Surface* );
bool init();
bool movebal(int,int&,int);
int cubeReplace();
bool movebal1(int,int&,int);
void snakeMouth(int, int);
const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 537;
const int SCREEN_BPP = 32;
int randforplayer();
int randforcomputer();
bool play(int& ,int& );
bool endofgame2(int, int);
SDL_Surface *bal1 = NULL;
SDL_Surface *bal2 = NULL;
SDL_Surface *report = NULL;
SDL_Event event;
SDL_Surface *background = NULL;
SDL_Surface *game1 = NULL;
SDL_Surface *game2=NULL;
SDL_Surface *instructions = NULL;
SDL_Surface *screen = NULL;
SDL_Surface *message = NULL;
SDL_Surface *message1 = NULL;
SDL_Surface *message2 = NULL;
SDL_Surface *mess = NULL;
SDL_Surface *report1 = NULL;
SDL_Surface *cardface1 =NULL;
SDL_Surface *cardface2 =NULL;
Mix_Music *music = NULL;
Mix_Music *music2 = NULL;
Mix_Chunk *high = NULL;
SDL_Surface *statisticsLadders = NULL;
SDL_Surface *statisticsCards = NULL;
int perecenesnakes(int,int);/* new*/
int perecenecards(int,int);/* new*/
const int resultred=120;
const int resultblue=72;
TTF_Font *font = NULL;
SDL_Color textColor = { 255, 255, 255 };
SDL_Color textColorBlack = { 0, 0, 0 };
const int X=69,Y=49;
int x1=30,y1=489 ,x2=65,y2=489;
bool endofgame1(int&,int&);
int countLadders1=0, countLadders2=0, countSnakes1=0, countSnakes2=0;
int round=1;

int main ( int argc, char** argv )
{
    string countsnake="0",countcards="0";
    ifstream indata("reportgames.txt");
    if(indata.fail())
        return 1;
    if(!indata.eof())
        indata>>countsnake>>countcards;
    indata.close();
    ofstream outdata("reportgames.txt",ios::trunc);
    indata.close();
    int countsna=atoi(countsnake.c_str());
    int countcard=atoi(countcards.c_str());
    bool quit = false;
    bool next = false;
    int startgame=NULL;
    if(!init())
        return 1;
    music = Mix_LoadMUS( "mu.wav" );
    if( music == NULL )
    {
        return 1;
    }
    high = Mix_LoadWAV( "high.wav" );
     if( high == NULL )
    {
        return 1;
    }
    string toshow="";
    stringstream ss;
    bal1 = load_image( "bal1.bmp" );
    bal2= load_image( "bal2.bmp" );
    report = load_image( "reportofgames.bmp" );
    int turn=NULL;
    background = load_image( "background.bmp" );
    game1 = load_image( "backg.bmp" );
    game2=load_image("index.bmp");
    apply_surface( 0, 0, background, screen );
    int waze1=1,waze2=1;
    int countplayer=0,countcomputer=0;
    Uint8 *keystates;
    srand(time(NULL));
    if( SDL_Flip( screen ) == -1 )
    {
        return 1;
    }
    int x;
    if( Mix_PlayMusic( music, -1 ) == -1 )
    {
       return 1;
    }

    while( quit == false )
    {
        while( SDL_PollEvent( &event ) )
        {
            if( event.type == SDL_QUIT )
            {
                //Quit the program
                quit = true;
            }

           if(next==false)
             {

                keystates = SDL_GetKeyState( NULL );
                if( keystates[ SDLK_1 ] )
                  {
                       countsna++;
                       string toshow="1";
                       font = TTF_OpenFont( "lazy.ttf", 40 );
                       message1 = TTF_RenderText_Solid( font, toshow.c_str(), textColor );
                       message2 = TTF_RenderText_Solid( font, toshow.c_str(), textColor );
                       apply_surface( 0, 0, game1, screen );
                       apply_surface( x1, y1, bal1, screen );
                       apply_surface( x2, y2,bal2,screen);
                       apply_surface( 831, resultblue, message1, screen );
                       apply_surface( 831, resultred, message2, screen );
                       turn=rand()%2+1;
                       next=true;
                       startgame=1;
                       if( SDL_Flip( screen ) == -1 )
                        {
                          return 1;
                        }
                   }
                 else if (keystates[ SDLK_2 ])
                 {
                     countcard++;
                     font = TTF_OpenFont( "lazy.ttf", 30 );
                     stringstream ss, ss1;
                     mess=TTF_RenderText_Solid( font, "26", textColorBlack );
                     apply_surface( 0, 0, game2, screen );
                     apply_surface(860, 94, mess,screen);
                     apply_surface(890, 150, mess,screen);
                       next=true;
                       round=0;
                       countplayer=26,countcomputer=26;
                       if( SDL_Flip( screen ) == -1 )
                        {
                          return 1;
                        }
                        startgame=2;
                 }
                 else if(keystates[SDLK_3]){
                        instructions = load_image("instructions.bmp");
                    apply_surface(0,0,instructions,screen);
                    if( SDL_Flip( screen ) == -1 )
                        {
                          return 1;
                        }
                    startgame = 3;
                    next = true;
                 }
            }
          else if(startgame==1)
            {
                keystates = SDL_GetKeyState( NULL );
                if( keystates[ SDLK_SPACE ] )
                 {
                    if(turn==1)
                    {
                        x=cubeReplace();
                        if(!(movebal(x,waze1,1)))
                            return 1;
                        turn=2;

                    }
                    else if (turn ==2)
                    {
                        x=cubeReplace();
                        if(!(movebal(x,waze2,2)))
                            return 1;
                        turn=1;


                    }
                    if(endofgame1(waze1,waze2))
                    {
                        keystates = SDL_GetKeyState( NULL );
                        if(keystates[ SDLK_ESCAPE])
                            {
                                next=false;
                                apply_surface( 0, 0, background, screen );
                                x1=30;y1=489 ;x2=65;y2=489;
                                waze1=1,waze2=1;
                                if( SDL_Flip( screen ) == -1 )
                                  {
                                    return 1;
                                  }
                            }

                    }

                 }
                 else if(keystates[ SDLK_ESCAPE])
                 {
                     next=false;
                     apply_surface( 0, 0, background, screen );
                     if( SDL_Flip( screen ) == -1 )
                        {
                          return 1;
                        }
                     x1=30;y1=489 ;x2=65;y2=489;
                     waze1=1,waze2=1;
                 }
              }
              else if (startgame==2)
              {
                  keystates = SDL_GetKeyState( NULL );

                if(keystates[ SDLK_SPACE])
                 {
                    if(!play(countplayer,countcomputer))
                     {
                         next=false;
                         apply_surface( 0, 0, background, screen );
                     }
                 }
                  if(endofgame2(countplayer,countcomputer)){
                        keystates = SDL_GetKeyState( NULL );
                        if(keystates[ SDLK_ESCAPE])
                        {
                             next=false;
                             countplayer=26,countcomputer=26;round=0;
                             apply_surface( 0, 0, background, screen );
                            if( SDL_Flip( screen ) == -1 )
                               {
                                return 1;
                               }

                        }
                  }
                 else  if(keystates[ SDLK_ESCAPE])
                    {
                     next=false;
                     countplayer=26,countcomputer=26;
                     apply_surface( 0, 0, background, screen );
                     if( SDL_Flip( screen ) == -1 )
                        {
                          return 1;
                        }
                     }
                 }
                 else if (startgame == 3){
                    keystates = SDL_GetKeyState(NULL);
                    if(keystates[SDLK_ESCAPE]){
                        apply_surface(0,0,background,screen);
                        if( SDL_Flip( screen ) == -1 )
                        {
                          return 1;
                        }
                        next = false;
                    }
                    else if(keystates[SDLK_2])
                    {
                        /*percens*/
                        stringstream rsnake, rcard;
                        string snakeperecene,cardsperecene;
                        apply_surface(0,0,report,screen);
                        font = TTF_OpenFont( "lazy.ttf", 30 );
                        if(countsna>countcard)
                            report1 = TTF_RenderText_Solid( font, "Snakes and leaders", textColorBlack );
                        else
                            report1= TTF_RenderText_Solid( font, "Card Game", textColorBlack );
                        apply_surface(532, 97, report1,screen);
                        rsnake<<perecenesnakes(countsna,countcard);
                        rcard<<perecenecards(countsna,countcard);
                        snakeperecene=rsnake.str()+"%";
                        cardsperecene=rcard.str()+"%";
                        report1 = TTF_RenderText_Solid( font, snakeperecene.c_str(), textColorBlack );
                        apply_surface(524, 232, report1,screen);
                        report1 = TTF_RenderText_Solid( font, cardsperecene.c_str(), textColorBlack );
                        apply_surface(524, 332, report1,screen);
                        if( SDL_Flip( screen ) == -1 )
                        {
                          return 1;
                        }
                        keystates = SDL_GetKeyState(NULL);
                        if(keystates[SDLK_ESCAPE]){
                        apply_surface(0,0,background,screen);
                        if( SDL_Flip( screen ) == -1 )
                        {
                          return 1;
                        }
                        next = false;
                        }
                 }
        }
    }
    }

    if( SDL_Flip( screen ) == -1 )
     {
       return 1;
     }
    Mix_PauseMusic();
    stringstream ssnakes,scards;
    ssnakes<<countsna;
    scards<<countcard;
    countsnake=ssnakes.str();
    countcards=scards.str();
    outdata<<countsnake<<" "<<countcards;
    outdata.close();
    SDL_FreeSurface( bal1 );
    SDL_FreeSurface( bal2 );
    SDL_FreeSurface( background );
    SDL_FreeSurface( message );
    SDL_FreeSurface( message1 );
    SDL_FreeSurface( message2 );
    SDL_FreeSurface(game1 );
    Mix_FreeMusic( music );
    Mix_FreeMusic( music2 );
    Mix_CloseAudio();
    SDL_Quit();
    TTF_Quit();

    return 0;

}
int perecenesnakes(int countsnak,int countcard)
{
    float percenesnakes;
    percenesnakes=(float(countsnak)/(countcard+countsnak));
    return static_cast<int>(percenesnakes*100);
}
int perecenecards(int countsnak,int countcard)
{
    int percenecards;
    percenecards=100-perecenesnakes(countsnak,countcard);
    return percenecards;
}
bool endofgame1(int& waze1,int& waze2)
{
    bool golden=false;
    font = TTF_OpenFont( "lazy.ttf", 20 );
    string toshow="";
    if (waze1 == 100 || waze2 == 100){
            stringstream ss1;
            statisticsLadders = load_image("statistics.bmp");
            apply_surface(0,0,statisticsLadders,screen);
            toshow = "The Blue Player";
            message = TTF_RenderText_Solid( font, toshow.c_str(), textColorBlack );
            if( message == NULL )
            {
                exit(1);
            }
            apply_surface( 200, 200, message, screen );
            ss1<<countLadders1;
            toshow = ss1.str();
            message = TTF_RenderText_Solid( font, toshow.c_str(), textColorBlack );
            if( message == NULL )
            {
                exit(1);
            }
            apply_surface( 420, 200, message, screen );
            stringstream ss2;
            ss2<<countSnakes1;
            toshow = ss2.str();
            message = TTF_RenderText_Solid( font, toshow.c_str(), textColorBlack );
            if( message == NULL )
            {
                exit(1);
            }
            apply_surface( 620, 200, message, screen );

            toshow = "The Red Player";
            message = TTF_RenderText_Solid( font, toshow.c_str(), textColorBlack );
            if( message == NULL )
            {
                exit(1);
            }
            apply_surface( 200, 230, message, screen );
            stringstream ss3;
            ss3<<countLadders2;
            toshow = ss3.str();
            message = TTF_RenderText_Solid( font, toshow.c_str(), textColorBlack );
            if( message == NULL )
            {
                exit(1);
            }
            apply_surface( 420, 230, message, screen );
            stringstream ss4;
            ss4<<countSnakes2;
            toshow = ss4.str();
            message = TTF_RenderText_Solid( font, toshow.c_str(), textColorBlack );
            if( message == NULL )
            {
                exit(1);
            }
            apply_surface( 620, 230, message, screen );
            if(waze1 == 100){
                toshow = "The Blue Player";
                message = TTF_RenderText_Solid( font, toshow.c_str(), textColorBlack );
                if( message == NULL )
                    {
                        exit(1);
                    }
                    apply_surface( 502, 133, message, screen );
                if (countLadders1 > 0 && countSnakes1 == 0){
                    message = TTF_RenderText_Solid( font, toshow.c_str(), textColorBlack );
                    if( message == NULL )
                    {
                        exit(1);
                    }
                    golden=true;
                    apply_surface( 606, 296, message, screen );
                    stringstream ss5;
                    ss5<<countLadders1;
                    toshow = ss5.str();
                    message = TTF_RenderText_Solid( font, toshow.c_str(), textColorBlack );
                    if( message == NULL )
                    {
                        exit(1);
                    }
                    apply_surface( 524, 324, message, screen );
                }
            }
            else if(waze2 == 100){
                toshow = "The Red Player";
                message = TTF_RenderText_Solid( font, toshow.c_str(), textColorBlack );
                if( message == NULL )
                    {
                        exit(1);
                    }
                    apply_surface( 502, 133, message, screen );
                if (countLadders2 > 0 && countSnakes2 == 0){
                    message = TTF_RenderText_Solid( font, toshow.c_str(), textColorBlack );
                    if( message == NULL )
                    {
                        exit(1);
                    }
                    golden=true;
                    apply_surface( 606, 298, message, screen );
                    stringstream ss6;
                    ss6<<countLadders2;
                    toshow = ss6.str();
                    message = TTF_RenderText_Solid( font, toshow.c_str(), textColorBlack );
                    if( message == NULL )
                    {
                        exit(1);
                    }
                    apply_surface( 524, 324, message, screen );
                }
            }
            if(!golden)
            {
                toshow = "None";
                message = TTF_RenderText_Solid( font, toshow.c_str(), textColorBlack );
                if( message == NULL )
                {
                    exit(1);
                }
                apply_surface( 606, 298, message, screen );
                toshow = "X";
                message = TTF_RenderText_Solid( font, toshow.c_str(), textColorBlack );
                if( message == NULL )
                {
                    exit(1);
                }
                apply_surface( 524, 324, message, screen );
            }
            if( SDL_Flip( screen ) == -1 )
               {
                exit(1);
               }
            return true;
        }
    return false;

}
bool endofgame2(int points1, int points2){
    string toshow = "";
    stringstream ss;
    font = TTF_OpenFont( "lazy.ttf", 20 );
    if (points1 >= 52){
        statisticsCards = load_image("static_cards.bmp");
        apply_surface(0,0,statisticsCards,screen);
        toshow = "The player";
        mess = TTF_RenderText_Solid(font, toshow.c_str(),textColorBlack);
        if (mess == NULL){
            exit(1);
        }
        apply_surface(450,95,mess,screen);
        if( SDL_Flip( screen ) == -1 )
               {
                exit(1);
               }
        ss<<round;
        toshow = ss.str();
        mess = TTF_RenderText_Solid(font, toshow.c_str(),textColorBlack);
        if (mess == NULL){
            exit(1);
        }
        apply_surface(589,122,mess,screen);
        if( SDL_Flip( screen ) == -1 )
               {
                exit(1);
               }
        return true;
    }
    else if(points2 >= 52){
        statisticsCards = load_image("static_cards.bmp");
        apply_surface(0,0,statisticsCards,screen);
        toshow = "The computer ";
        ss<<round;
        mess = TTF_RenderText_Solid(font, toshow.c_str(),textColorBlack);
        if (mess == NULL){
            exit(1);
        }
        apply_surface(450,95,mess,screen);
        if( SDL_Flip( screen ) == -1 )
               {
                exit(1);
               }
        toshow = ss.str();
        mess = TTF_RenderText_Solid(font, toshow.c_str(),textColorBlack);
        if (mess == NULL){
            exit(1);
        }
        apply_surface(589,122,mess,screen);
        if( SDL_Flip( screen ) == -1 )
               {
                exit(1);
               }

        return true;
    }
    else{
        return false;
    }
}
bool movebal(int num,int& waze,int numofball)
{
    int i=0;
    int* xx=&x1;
    int* yy=&y1;
    string toshow="0";
    stringstream ss;
    if (waze+num>100)
    {
        num=100-waze;
    }
    font = TTF_OpenFont( "lazy.ttf", 40 );
    if(numofball==2)
      {
           xx= &x2;
           yy= &y2;
      }

    for(i=0;i<num;i++)
    {
        string toshow="0";
    stringstream ss;
    font = TTF_OpenFont( "lazy.ttf", 40 );
        if((waze%10)!=0)
        {

          if((waze/10)%2==0)
          {
            *xx=*xx+X;
            waze++;
            ss<<waze;
            toshow=ss.str();
            message = TTF_RenderText_Solid( font, toshow.c_str(), textColor );
            if( message == NULL )
            {
                return 1;
            }

          }
          else
          {
            *xx=*xx-X;
            waze++;
            ss<<waze;
            toshow=ss.str();
            message = TTF_RenderText_Solid( font, toshow.c_str(), textColor );
            if( message == NULL )
            {
            return 1;
            }
          }
        }
        else
        {
            *yy=*yy-Y;
            waze++;
            ss<<waze;
            toshow=ss.str();
            message = TTF_RenderText_Solid( font, toshow.c_str(), textColor );
            if( message == NULL )
            {
            return 1;
            }
        }
        if(numofball==1)
            message1=message;
        else
            message2=message;
        apply_surface( 0, 0, game1, screen );
        apply_surface( x1, y1, bal1, screen );
        apply_surface( x2, y2, bal2, screen );
        apply_surface( 831, resultblue, message1, screen );
        apply_surface( 831, resultred, message2, screen );
        if( SDL_Flip( screen ) == -1 )
        {
            return 1;
        }
        if( Mix_PlayChannel( -1, high, 0 ) == -1 )
            {
                return 1;
            }
        SDL_Delay( 400 );
    }
    num=0;
    switch(waze)
    {
        case 3: num=18;
        break;
        case 8:num=22;
        break;
        case 28:num=56;
        break;
        case 58:num=19;
        break;
        case 75:num=11;
        break;
        case 80:num=20;
        break;
        case 90:num=1;
        break;
    }
    if (num!=0){
        if (numofball == 1){
            countLadders1++;
        }
        if (numofball == 2){
            countLadders2++;
        }
    }
    for(i=0;i<num;i++)
    {
    string toshow="0";
    stringstream ss;
    font = TTF_OpenFont( "lazy.ttf", 40 );
        if((waze%10)!=0)
        {

          if((waze/10)%2==0)
          {
            *xx=*xx+X;
            waze++;
            ss<<waze;
            toshow=ss.str();
            message = TTF_RenderText_Solid( font, toshow.c_str(), textColor );
            if( message == NULL )
            {
            return 1;
            }
          }
          else
          {
            *xx=*xx-X;
            waze++;
            ss<<waze;
            toshow=ss.str();
            message = TTF_RenderText_Solid( font, toshow.c_str(), textColor );
            if( message == NULL )
            {
            return 1;
            }
          }
        }
        else
        {
            *yy=*yy-Y;
            waze++;
            ss<<waze;
            toshow=ss.str();
            message = TTF_RenderText_Solid( font, toshow.c_str(), textColor );
            if( message == NULL )
            {
            return 1;
            }
        }
        if(numofball==1)
            message1=message;
        else
            message2=message;
        apply_surface( 0, 0, game1, screen );
        apply_surface( x1, y1, bal1, screen );
        apply_surface( x2, y2, bal2, screen );
        apply_surface( 831, resultblue, message1, screen );
        apply_surface( 831, resultred, message2, screen );
        if( SDL_Flip( screen ) == -1 )
         {
            return 1;
         }
    }
    num=0;
    switch(waze)
    {
        case 17: waze=13;
        break;
        case 52:waze=29;
        break;
        case 57:waze=40;
        break;
        case 62:waze=22;
        break;
        case 97:waze=79;
        break;
        case 88:waze=18;
        break;
        case 95:waze=51;
        break;
    }
    snakeMouth(waze,numofball);
    apply_surface(0,0,game1,screen);
    apply_surface(x1,y1,bal1,screen);
    apply_surface(x2,y2,bal2,screen);
    ss<<waze;
    toshow=ss.str();
    message = TTF_RenderText_Solid( font, toshow.c_str(), textColor );
    if( message == NULL )
    {
        return 1;
    }
    if (numofball == 1)
        message1 = message;
    else if (numofball == 2)
        message2 = message;
    apply_surface( 831, resultblue, message1, screen );
    apply_surface( 831, resultred, message2, screen );



return true;
}
void snakeMouth(int place,int numBall){
    if (numBall == 2){//red ball
        if (place == 13){
            x2 = 547;
            y2 = 438;
            apply_surface(0,0,game1,screen);
            apply_surface(x2,y2,bal2,screen);
            countSnakes2++;
        }
        if (place == 29){
            x2 = 615;
            y2 = 390;
            apply_surface(0,0,game1,screen);
            apply_surface(x2,y2,bal2,screen);
            countSnakes2++;
        }
        if (place == 40){
            x2 = 63;
            y2 = 341;
            apply_surface(0,0,game1,screen);
            apply_surface(x2,y2,bal2,screen);
            countSnakes2++;
        }
        if (place == 22){
            x2 = 132;
            y2 = 390;
            apply_surface(0,0,game1,screen);
            apply_surface(x2,y2,bal2,screen);
            countSnakes2++;
        }
        if (place == 79){
            x2 = 132;
            y2 = 144;
            apply_surface(0,0,game1,screen);
            apply_surface(x2,y2,bal2,screen);
            countSnakes2++;
        }
        if (place == 18){
            x2 = 202;
            y2 = 438;
            apply_surface(0,0,game1,screen);
            apply_surface(x2,y2,bal2,screen);
            countSnakes2++;
        }
        if (place == 51){
            x2 = 683;
            y2 = 242;
            apply_surface(0,0,game1,screen);
            apply_surface(x2,y2,bal2,screen);
            countSnakes2++;
        }
    }
    if (numBall == 1){//Blue Ball
        if (place == 13){
            x1 = 514;
            y1 = 438;
            apply_surface(0,0,game1,screen);
            apply_surface(514,438,bal1,screen);
            countSnakes1++;
        }
        if (place == 29){
            x1 = 582;
            y1 = 390;
            apply_surface(0,0,game1,screen);
            apply_surface(x1,y1,bal1,screen);
            countSnakes1++;
        }
        if (place == 40){
            x1 = 30;
            y1 = 341;
            apply_surface(0,0,game1,screen);
            apply_surface(x1,y1,bal1,screen);
            countSnakes1++;
        }
        if (place == 22){
            x1 = 99;
            y1 = 390;
            apply_surface(0,0,game1,screen);
            apply_surface(x1,y1,bal1,screen);
            countSnakes1++;
        }
        if (place == 79){
            x1 = 99;
            y1 = 144;
            apply_surface(0,0,game1,screen);
            apply_surface(x1,y1,bal1,screen);
            countSnakes1++;
        }
        if (place == 18){
            x1 = 169;
            y1 = 438;
            apply_surface(0,0,game1,screen);
            apply_surface(x1,y1,bal1,screen);
            countSnakes1++;
        }
        if (place == 51){
            x1 = 650;
            y1 = 242;
            apply_surface(0,0,game1,screen);
            apply_surface(x1,y1,bal1,screen);
            countSnakes1++;
        }
    }

}
SDL_Surface *load_image( string filename )
{
    SDL_Surface* loadedImage = NULL;
    SDL_Surface* optimizedImage = NULL;
    loadedImage = SDL_LoadBMP( filename.c_str() );
    if( loadedImage != NULL )
    {
        optimizedImage = SDL_DisplayFormatAlpha( loadedImage );
        if( optimizedImage != NULL )
        {
            Uint32 colorkey = SDL_MapRGB( optimizedImage->format, 0, 0xFF, 0xFF );
            SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, colorkey );
        }

        SDL_FreeSurface( loadedImage );
    }
        return optimizedImage;
}
void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination )
{
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;
    SDL_BlitSurface( source, NULL, destination, &offset );
}
bool init()
{
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return false;
    }

    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

    if( screen == NULL )
    {
        return false;
    }
    if( TTF_Init() == -1 )
    {
        return false;
    }
    if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 )
    {
        return false;
    }
    SDL_WM_SetCaption( "TTF Test", NULL );

    SDL_WM_SetCaption( "Event test", NULL );

    return true;
}
int cubeReplace(){
    string cubeName = "1.bmp";
    SDL_Surface *cubeFace = load_image(cubeName.c_str());
    int a=0;

    int cubeNumber = 1;

    while(a<12){
        apply_surface(820, 290, cubeFace, screen);

        //Update the screen
        if (SDL_Flip(screen) == -1)
        {
            exit(1);
        }
        //SDL_FreeSurface(cubeFace);
        cubeFace = load_image(cubeName.c_str());
        apply_surface(820, 290, cubeFace, screen);
        SDL_Delay(150);
        a++;
        cubeName[0] = cubeNumber +'0';
        if (cubeNumber <= 6){
            cubeNumber++;
        }
        if (cubeNumber > 6){
            cubeNumber = 1;
        }
    }
    int random;
    srand(time(NULL));
    random = rand()%6+1;
    cubeName[0] = random+'0';
    cubeFace = load_image(cubeName.c_str());
    apply_surface(820, 290, cubeFace, screen);

        //Update the screen
        if (SDL_Flip(screen) == -1)
        {
            exit(1);
        }
        //SDL_FreeSurface(cubeFace);
        cubeFace = load_image(cubeName.c_str());
        apply_surface(820, 290, cubeFace, screen);
        SDL_Delay(2000);
        return random;

}
int randforplayer()
{
    string cardname1="backcardplayer.bmp";
    cardface1 = load_image(cardname1.c_str());
    apply_surface(800, 260, cardface1, screen);
    if (SDL_Flip(screen) == -1)
    {
        exit(1);
    }
    SDL_Delay(500);
    stringstream ff;
    int random1;
    random1 = rand()%13+1 ;
    ff<<random1+10;

    cardname1=ff.str()+".bmp";
    cardface1 = load_image(cardname1.c_str());
    apply_surface(496, 80, cardface1, screen);
    if (SDL_Flip(screen) == -1)
    {
        exit(1);
    }
    SDL_Delay(500);
    return random1;
}
int randforcomputer()
{
    string cardname2="backcardcomputer.bmp";
    cardface2 = load_image(cardname2.c_str());
    apply_surface(800, 260, cardface2, screen);
    if (SDL_Flip(screen) == -1)
    {
        exit(1);
    }
    SDL_Delay(500);
    stringstream ff;
    int random2;
    random2 = rand()%13+1 ;
    ff<<random2+10;
    cardname2=ff.str()+".bmp";
    cardface2 = load_image(cardname2.c_str());
    apply_surface(496, 80, cardface1, screen);
    apply_surface(164, 242, cardface2, screen);
    if (SDL_Flip(screen) == -1)
    {
        exit(1);
    }
    SDL_Delay(500);
    return random2;
}
bool play(int &count1,int &count2 )
{
    int countround=1;
    string toshow;
    stringstream ss, ss1,ss2,ss3;
    font = TTF_OpenFont( "lazy.ttf", 30);
    bool escap=true;
    Uint8 *keystates;
    bool countine=true;
    game2=load_image("index.bmp");
    apply_surface( 0, 0, game2, screen );
    ss<<count1;
    toshow = ss.str();
    message = TTF_RenderText_Solid(font , toshow.c_str(),textColorBlack);
    if(!message){
        exit(1);
    }
    apply_surface(860, 94, message,screen);
    ss1<<count2;
    toshow = ss1.str();
    message = TTF_RenderText_Solid(font , toshow.c_str(),textColorBlack);
    if(!message){
        exit(1);
    }
    apply_surface(890, 150, message,screen);
    int ResultPlayer,ResultComputer;
    font = TTF_OpenFont( "lazy.ttf", 50);
    message = TTF_RenderText_Solid(font , "TAKE AGAIN! ",textColorBlack);
    while(countine)
    {
        ResultPlayer=randforplayer();
        ResultComputer=randforcomputer();
        if (ResultPlayer>ResultComputer)
          {
            count1+=(countround*1);
            count2-=(countround*1);
            countine=false;
          }
        else if (ResultPlayer<ResultComputer)
          {
            count2+=(countround*1);
            count1-=(countround*1);
            countine=false;
          }
          else
            {
                escap=true;
                while(escap)
                {
                 keystates = SDL_GetKeyState( NULL );
                 apply_surface(314, 24, message,screen);
                 if (SDL_Flip(screen) == -1)
                     {
                        exit(1);
                     }
                 if(keystates[ SDLK_SPACE])
                 {
                     countround++;
                     escap=false;
                 }
                 else if (keystates[ SDLK_ESCAPE])
                 {
                     escap=false;
                     return false;
                 }
                }
            }
    }
    SDL_Delay(1250);
    apply_surface( 0, 0, game2, screen );
    font = TTF_OpenFont( "lazy.ttf", 30);
    ss2<<count1;
    toshow = ss2.str();
    message = TTF_RenderText_Solid(font , toshow.c_str(),textColorBlack);
    if(!message){
        exit(1);
    }
    apply_surface(860, 94, message,screen);
    ss3<<count2;
    toshow = ss3.str();
    message = TTF_RenderText_Solid(font , toshow.c_str(),textColorBlack);
    if(!message){
        exit(1);
    }
    apply_surface(890, 150, message,screen);
    if (SDL_Flip(screen) == -1)
    {
        exit(1);
    }
    round+=countround;

    return true;
}





