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