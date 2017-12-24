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