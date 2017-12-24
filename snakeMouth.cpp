void snakeMouth(int place,int numBall){
    if (numBall == 2){//red ball
        if (place == 13){
            x2 = 547;
            y2 = 438;
            apply_surface(0,0,game1,screen);
            apply_surface(x2,y2,bal2,screen);
            countSnakes2++;
        }
        if (place == 29){
            x2 = 615;
            y2 = 390;
            apply_surface(0,0,game1,screen);
            apply_surface(x2,y2,bal2,screen);
            countSnakes2++;
        }
        if (place == 40){
            x2 = 63;
            y2 = 341;
            apply_surface(0,0,game1,screen);
            apply_surface(x2,y2,bal2,screen);
            countSnakes2++;
        }
        if (place == 22){
            x2 = 132;
            y2 = 390;
            apply_surface(0,0,game1,screen);
            apply_surface(x2,y2,bal2,screen);
            countSnakes2++;
        }
        if (place == 79){
            x2 = 132;
            y2 = 144;
            apply_surface(0,0,game1,screen);
            apply_surface(x2,y2,bal2,screen);
            countSnakes2++;
        }
        if (place == 18){
            x2 = 202;
            y2 = 438;
            apply_surface(0,0,game1,screen);
            apply_surface(x2,y2,bal2,screen);
            countSnakes2++;
        }
        if (place == 51){
            x2 = 683;
            y2 = 242;
            apply_surface(0,0,game1,screen);
            apply_surface(x2,y2,bal2,screen);
            countSnakes2++;
        }
    }
    if (numBall == 1){//Blue Ball
        if (place == 13){
            x1 = 514;
            y1 = 438;
            apply_surface(0,0,game1,screen);
            apply_surface(514,438,bal1,screen);
            countSnakes1++;
        }
        if (place == 29){
            x1 = 582;
            y1 = 390;
            apply_surface(0,0,game1,screen);
            apply_surface(x1,y1,bal1,screen);
            countSnakes1++;
        }
        if (place == 40){
            x1 = 30;
            y1 = 341;
            apply_surface(0,0,game1,screen);
            apply_surface(x1,y1,bal1,screen);
            countSnakes1++;
        }
        if (place == 22){
            x1 = 99;
            y1 = 390;
            apply_surface(0,0,game1,screen);
            apply_surface(x1,y1,bal1,screen);
            countSnakes1++;
        }
        if (place == 79){
            x1 = 99;
            y1 = 144;
            apply_surface(0,0,game1,screen);
            apply_surface(x1,y1,bal1,screen);
            countSnakes1++;
        }
        if (place == 18){
            x1 = 169;
            y1 = 438;
            apply_surface(0,0,game1,screen);
            apply_surface(x1,y1,bal1,screen);
            countSnakes1++;
        }
        if (place == 51){
            x1 = 650;
            y1 = 242;
            apply_surface(0,0,game1,screen);
            apply_surface(x1,y1,bal1,screen);
            countSnakes1++;
        }
    }

}