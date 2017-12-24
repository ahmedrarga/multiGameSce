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