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