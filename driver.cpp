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
