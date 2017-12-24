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