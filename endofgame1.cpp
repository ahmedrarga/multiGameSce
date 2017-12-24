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