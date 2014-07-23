#include"app.h"
#include"enemy.h"


int Start(SApp * app){
allegro_init();
install_keyboard();
set_color_depth( 16 );
set_gfx_mode( GFX_AUTODETECT_WINDOWED, app->size.x, app->size.y, 0, 0 );
return 1;
}


int Init(SApp * app){
    app->bufor = create_bitmap( app->size.x, app->size.y );
    if( !app->bufor ) return 0;

    app->alpha = create_bitmap( app->size.x, app->size.y );
    if( !app->bufor ) return 0;
    return 1;
}


int Draw(SApp * app,SEnemy * enemy,SEnemy * enemy2,SConvexhull * convexhull){
    clear_to_color( app->bufor, makecol( 255, 0, 255 ) );
    clear_to_color( app->alpha, makecol( 0, 0, 0 ) );

    //circlefill( app->bufor, enemy->position.x, enemy->position.y, enemy->size, makecol( 255, 0, 0 ) );
    blit( enemy->image, app->bufor, 0, 0, enemy->position.x-enemy->size, enemy->position.y-enemy->size, enemy->image->w, enemy->image->h );
    circlefill( app->bufor, enemy2->position.x, enemy2->position.y, enemy2->size, makecol( 0, 255, 0 ) );

    DrawLight(app->alpha,enemy);
    //masked_blit( enemy->image,app->bufor , 0, 0, , enemy->position.y, enemy->image->w, enemy->image->h );
    ShadowCaster(app->alpha,enemy);
    DrawAll(app->bufor);

    //punkty
    char napis[20];
    itoa (app->ects,napis,10);
    textout_ex( app->bufor, font, "ECTS!", app->size.x-200, 50, makecol( 255, 255, 255 ), - 1 );
    textout_ex( app->bufor, font, napis, app->size.x-150, 50, makecol( 255, 255, 255 ), - 1 );

    masked_blit( app->bufor, app->alpha, 0, 0, 0, 0, app->size.x, app->size.y );
    blit( app->alpha, screen, 0, 0, 0, 0, app->size.x, app->size.y );
    return 1;
}


int End(SApp * app){

    destroy_bitmap( app->alpha );
    destroy_bitmap( app->bufor );
    allegro_exit();
    return 1;
}



int LoadConfig(SApp * app,SEnemy * enemy,SEnemy * enemy2){
    FILE *file;
    file = fopen("data/config.txt","rb");
    if(file==NULL) return 0;

    char c = fgetc(file);
    char * a= malloc(sizeof(char));
    int i =0;

    while(c!=EOF){
        if(c=='\n'){
            a[i]='\0';
            i =0;

            SetProperties(app,enemy,enemy2,a);
            free(a);
            a = malloc(sizeof(char));
            c =  fgetc(file);
            continue;
        }

    a[i]=c;
    c =  fgetc(file);
    a = realloc(a,sizeof(char) * (i+2));
    i++;
    }
    free(a);

    fclose(file);
    return 1;
}



int SetProperties(SApp * app,SEnemy * enemy,SEnemy * enemy2,char* element){

    int i =0;
    int j =0;
    int c =0;

    char  ** part = malloc(sizeof(char*)*2);
    part[0]=malloc(sizeof(char));

    while(element[i]!='\0'){
        if(element[i]=='='){
            part[0][j]='\0';

            j=0;
            c=1;
            i++;
            part[1]=malloc(sizeof(char));
            continue;
        }

        part[c][j]=element[i];

        part[c]= realloc(part[c],sizeof(char) * (j+2));
        i++;
        j++;


    }
    part[1][j]='\0';



    //printf("%s - %s",part[0],part[1]);
    if(strcmp(part[0],"sizex")==0)app->size.x= atoi(part[1]);
    if(strcmp(part[0],"sizey")==0)app->size.y= atoi(part[1]);
    if(strcmp(part[0],"ditance_collision")==0)app->ditance_collision= atoi(part[1]);

    if(strcmp(part[0],"enemy_range")==0)enemy->range= atoi(part[1]);
    if(strcmp(part[0],"enemy_speed")==0)enemy->speed= atoi(part[1]);
    if(strcmp(part[0],"enemy_size")==0)enemy->size= atoi(part[1]);

    if(strcmp(part[0],"enemy2_range")==0)enemy2->range= atoi(part[1]);
    if(strcmp(part[0],"enemy2_speed")==0)enemy2->speed= atoi(part[1]);
    if(strcmp(part[0],"enemy2_size")==0)enemy2->size= atoi(part[1]);

    free(part[0]);
     free(part[1]);
     free(part);
    return 1;
}
