#include <allegro.h>
#include <assert.h>
#include"enemy.h"
#include"convexhull.h"
#include"app.h"

#include "maths.h"


int main()
{

    //start
    SApp app = {{1040,880},NULL,NULL,100,0};

    SKeyBoardSettings keyboardSettings = {84,85,83,82};
    SKeyBoardSettings keyboardSettings2 = {23,19,4,1};
    int timer =0;
    SEnemy enemy = {
        {100, 100},
        500,
        0.5,
        DOWN,
        4,
        30,
        0.02,
        &keyboardSettings,
        NULL
    };

    SEnemy enemy2 = {
        {850, 850},
        0,
        0.5,
        DOWN,
        4,
        5,
        0.02,
        &keyboardSettings2,
        NULL
    };

    assert(LoadConfig(&app,&enemy,&enemy2));


    assert(Start(&app));
    assert(Init(&app));

    enemy.image = load_bmp( "data/sesja.bmp", default_palette );
    assert(enemy.image);
    //printf("%d/%d/%d/%d",KEY_W,KEY_S,KEY_D,KEY_A);



    //init





    //triangle
        vector v[3];

        v[0].x = 500;
        v[0].y = 400;
        v[1].x = 600;
        v[1].y = 400;
        v[2].x = 500;
        v[2].y = 500;




    SConvexhull convexhull = {
        3,
        makecol( 0, 0, 255 ),

        v};

    AddtoStack(&convexhull);


    vector v2[4];

    v2[0].x = 200;
    v2[0].y = 500;
    v2[1].x = 400;
    v2[1].y = 500;
    v2[2].x = 400;
    v2[2].y = 600;
    v2[3].x = 200;
    v2[3].y = 600;

    SConvexhull convexhull2 = {
        4,
        makecol( 0, 255, 0 ),
        v2};

    AddtoStack(&convexhull2);





    vector v3[3];

    v3[0].x = 200;
    v3[0].y = 200;
    v3[1].x = 400;
    v3[1].y = 200;
    v3[2].x = 200;
    v3[2].y = 300;


    SConvexhull convexhull3 = {
        3,
        makecol( 0, 255, 255 ),
        v3};

    AddtoStack(&convexhull3);


    vector v4[4];

    v4[0].x = 600;
    v4[0].y = 600;
    v4[1].x = 800;
    v4[1].y = 600;
    v4[2].x = 800;
    v4[2].y = 800;
    v4[3].x = 600;
    v4[3].y = 800;

    SConvexhull convexhull4 = {
        4,
        makecol( 0, 255, 120 ),
        v4};

    AddtoStack(&convexhull4);



    vector v5[4];

    v5[0].x = 950;
    v5[0].y = 600;
    v5[1].x = 1000;
    v5[1].y = 600;
    v5[2].x = 1000;
    v5[2].y = 800;
    v5[3].x = 850;
    v5[3].y = 800;

    SConvexhull convexhull5 = {
        4,
        makecol( 125, 255, 120 ),
        v5};

    AddtoStack(&convexhull5);



    vector v6[4];

    v6[0].x = 600;
    v6[0].y = 100;
    v6[1].x = 700;
    v6[1].y = 100;
    v6[2].x = 700;
    v6[2].y = 250;
    v6[3].x = 600;
    v6[3].y = 150;

    SConvexhull convexhull6 = {
        4,
        makecol( 255, 120, 0 ),
        v6};

    AddtoStack(&convexhull6);




    vector v7[6];

    v7[0].x = 800;
    v7[0].y = 300;
    v7[1].x = 850;
    v7[1].y = 200;
    v7[2].x = 900;
    v7[2].y = 300;
    v7[3].x = 900;
    v7[3].y = 350;
    v7[4].x = 820;
    v7[4].y = 450;
    v7[5].x = 800;
    v7[5].y = 350;

    SConvexhull convexhull7 = {
        6,
        makecol( 255, 120, 255 ),
        v7};

    AddtoStack(&convexhull7);


    vector v8[6];

    v8[0].x = 100;
    v8[0].y = 700;
    v8[1].x = 150;
    v8[1].y = 650;
    v8[2].x = 200;
    v8[2].y = 700;
    v8[3].x = 300;
    v8[3].y = 750;
    v8[4].x = 120;
    v8[4].y = 850;
    v8[5].x = 100;
    v8[5].y = 750;

    SConvexhull convexhull8 = {
        6,
        makecol( 255, 120, 34 ),
        v8};

    AddtoStack(&convexhull8);


    vector v9[3];

    v9[0].x = 450;
    v9[0].y = 700;
    v9[1].x = 550;
    v9[1].y = 800;
    v9[2].x = 300;
    v9[2].y = 800;


    SConvexhull convexhull9 = {
        3,
        makecol( 0, 255, 255 ),
        v9};

    AddtoStack(&convexhull9);


    //traingle
    while( !key[ KEY_ESC ] )
    {

         Move(&enemy);
         Move(&enemy2);

    if(timer>100){app.ects++;timer=0;}

        int ditance_collision = app.ditance_collision;
        Collision(ditance_collision,&enemy);
        Collision(ditance_collision,&enemy2);

        CheckTriangles(enemy2.position);

        DeleteAllTriangles();
        assert(Draw(&app,&enemy,&enemy2,&convexhull));
        if(Catch(&enemy,&enemy2))break;
    timer++;
    }

    while( !key[ KEY_ESC ] )
    {

        textprintf( app.alpha, font, app.size.x/2,app.size.y/2, makecol( 255, 255, 255 ), "ECTS : %d", app.ects );
        blit( app.alpha, screen, 0, 0, 0, 0, app.size.x, app.size.y );
    }

    //end


    destroy_bitmap( enemy.image);
    DeleteAll();
    DeleteAllTriangles();
    assert(End(&app));
    return 0;
}
END_OF_MAIN();
