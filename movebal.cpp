bool movebal(int num,int& waze,int numofball)
{
    int i=0;
    int* xx=&x1;
    int* yy=&y1;
    string toshow="0";
    stringstream ss;
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