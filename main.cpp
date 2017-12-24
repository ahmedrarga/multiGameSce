#include <cstdlib>
#include<iostream>
#include <SDL/SDL.h>
#include <string>
#include<ctime>
#include<sstream>


using namespace std;
SDL_Surface *load_image(string ) ;
void apply_surface( int , int , SDL_Surface* , SDL_Surface* );
bool init();
int cardreplace();
int randomcomp();
bool play(int& ,int& );
int rand2();
    const int SCREEN_WIDTH = 1000;
    const int SCREEN_HEIGHT = 537;
    const int SCREEN_BPP = 32;
    SDL_Event event;
    SDL_Surface *background = NULL;
    SDL_Surface *game2=NULL;
    SDL_Surface *screen = NULL;



    int main ( int argc, char** argv )
{

    bool quit = false;
    bool next = false;
    int x;
    int y;
    bool z;
    int count1=0,count2=0;

    if(!init())
        return 1;

    background = load_image( "background.bmp" );
    game2=load_image("index.bmp");
    apply_surface( 0, 0, background, screen );
    Uint8 *keystates;
    if( SDL_Flip( screen ) == -1 )
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

           if(next==false){
                keystates = SDL_GetKeyState( NULL );
                if( keystates[ SDLK_1 ] )
                  {
                       apply_surface( 0, 0, game2, screen );
                       next=true;
                   }
           }
           else{
               keystates = SDL_GetKeyState( NULL );
               if(z==true){
                if(keystates[ SDLK_SPACE])
                 {

                    srand(time(NULL));
                    z=play(count1,count2);
                    }
               }

               if(keystates[ SDLK_ESCAPE])
                 {
                     next=false;
                     apply_surface( 0, 0, background, screen );
                 }
              }
        }
    if( SDL_Flip( screen ) == -1 )
     {
       return 1;
     }


    }

    SDL_FreeSurface( background );
    SDL_FreeSurface(game2 );


    SDL_Quit();

    return 0;
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

    SDL_WM_SetCaption( "Event", NULL );

    return true;
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

int randomcomp(){


    SDL_Surface *cardface1 ;
    int cardnumber1 = 1;
    string cardname1;


    while(cardnumber1<14){
            stringstream ff;
        ff<<cardnumber1;
        cardname1=ff.str()+".bmp";
        cardface1 = load_image(cardname1.c_str());
        apply_surface(30, 270, cardface1, screen);
        if (SDL_Flip(screen) == -1)
        {
            exit(1);
        }
        SDL_Delay(150);
        cardnumber1++;
    }

    int random1;
     stringstream ff;
    random1 = rand()%13+1 ;
    ff<<random1;
    cardname1=ff.str()+".bmp";
    cardface1 = load_image(cardname1.c_str());
    apply_surface(30, 270, cardface1, screen);


        //Update the screen
        if (SDL_Flip(screen) == -1)
        {
            exit(1);
        }
        //SDL_FreeSurface(cardface);
        cardface1 = load_image(cardname1.c_str());
        apply_surface(30, 270, cardface1, screen);
        SDL_Delay(2000);
        return random1;

}


int cardreplace(){
    //string cardname = "1.bmp";

    SDL_Surface *cardface ;
    int cardnumber = 1;
    string cardname;

    while(cardnumber<14){
            stringstream ss;
        ss<<cardnumber;
        cardname=ss.str()+".bmp";
        cardface = load_image(cardname.c_str());
        apply_surface(800, 255, cardface, screen);
        if (SDL_Flip(screen) == -1)
        {
            exit(1);
        }
        SDL_Delay(150);
        cardnumber++;
    }
    int random;
     stringstream gg;
    random = rand()%13+1;
    gg<<random;
    cardname=gg.str()+".bmp";
    cardface = load_image(cardname.c_str());
    apply_surface(800, 255, cardface, screen);

        //Update the screen
        if (SDL_Flip(screen) == -1)
        {
            exit(1);
        }
        //SDL_FreeSurface(cardface);
        cardface = load_image(cardname.c_str());
        apply_surface(800, 255, cardface, screen);
        SDL_Delay(2000);
        return random;

}




bool play(int &count1,int &count2 ){

int xx, yy;
  string cardname2;
   SDL_Surface *cardface2 ;


 while((count1<=2) ||(count2<=2)){
        xx=cardreplace();
        yy=randomcomp();
    if(xx > yy){

        stringstream ss;
         ss<<xx;
        cardname2=ss.str()+".bmp";
        cardface2 = load_image(cardname2.c_str());
        apply_surface(450, 100, cardface2, screen);
         count1++;
        count2--;
return true;
   }
   else if(yy > xx) {

       stringstream tt;
       tt<<yy;
       cardname2=tt.str()+".bmp";
       cardface2 = load_image(cardname2.c_str());
       apply_surface(150, 100, cardface2, screen);
        count2++;
       count1--;
       return true;
   }
 }
 return false;
}


