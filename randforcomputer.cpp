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