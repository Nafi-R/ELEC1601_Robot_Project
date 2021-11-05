#include "stdio.h"
#include "stdlib.h"
#include "SDL.h"
#include "SDL2_gfxPrimitives.h"
#include "time.h"
#include <sys/time.h>

#include "formulas.h"
#include "wall.h"
#include "robot.h"
#include "math.h"

int done = 0;

void maze2(struct Wall_collection **head)
{
    insertAndSetFirstWall(head, 1, OVERALL_WINDOW_WIDTH / 2 - 400, OVERALL_WINDOW_HEIGHT / 2 + 230, 800, 10);                              //floor
    insertAndSetFirstWall(head, 2, OVERALL_WINDOW_WIDTH / 2 - 400, OVERALL_WINDOW_HEIGHT / 2 - 240, 800, 10);                              //roof
    insertAndSetFirstWall(head, 3, OVERALL_WINDOW_WIDTH / 2, OVERALL_WINDOW_HEIGHT / 2, 10, OVERALL_WINDOW_HEIGHT / 2);                    //first obstacle lower
    insertAndSetFirstWall(head, 4, OVERALL_WINDOW_WIDTH / 2, OVERALL_WINDOW_HEIGHT / 2 - 300, 10, OVERALL_WINDOW_HEIGHT / 2);              //first obstacle upper
    insertAndSetFirstWall(head, 6, OVERALL_WINDOW_WIDTH / 2 + 50, OVERALL_WINDOW_HEIGHT / 2 - 70, 50, 10);                                 //second obstacle sideways
    insertAndSetFirstWall(head, 7, OVERALL_WINDOW_WIDTH / 2 + 50, OVERALL_WINDOW_HEIGHT / 2 - 195, 10, 1000);                              //second obstacle tall
    insertAndSetFirstWall(head, 8, OVERALL_WINDOW_WIDTH / 2 + 100, OVERALL_WINDOW_HEIGHT / 2 - 300, 10, 100);                              //third obstacle stub
    insertAndSetFirstWall(head, 9, OVERALL_WINDOW_WIDTH / 2 + 100, OVERALL_WINDOW_HEIGHT / 2 - 150, 10, 90);                               //third obstacle stub
    insertAndSetFirstWall(head, 10, OVERALL_WINDOW_WIDTH / 2 + 150, OVERALL_WINDOW_HEIGHT / 2 + 70, 300, 10);                              //four obstacle long sideways
    insertAndSetFirstWall(head, 11, OVERALL_WINDOW_WIDTH / 2 + 150, OVERALL_WINDOW_HEIGHT / 2 - 230, 10, 300);                             //four obstacle long tall
    insertAndSetFirstWall(head, 12, OVERALL_WINDOW_WIDTH / 2 + 150, OVERALL_WINDOW_HEIGHT / 2 + 130, 10, 100);                             //four obstacle long from floor
    insertAndSetFirstWall(head, 13, OVERALL_WINDOW_WIDTH / 2 - 320, OVERALL_WINDOW_HEIGHT / 2 - 250, 10, OVERALL_WINDOW_HEIGHT / 2 + 250); //backwall
}

void maze1(struct Wall_collection **head)
{
    insertAndSetFirstWall(head, 1, OVERALL_WINDOW_WIDTH / 2, OVERALL_WINDOW_HEIGHT / 2, 10, OVERALL_WINDOW_HEIGHT / 2);
    insertAndSetFirstWall(head, 2, OVERALL_WINDOW_WIDTH / 2 - 100, OVERALL_WINDOW_HEIGHT / 2 + 100, 10, OVERALL_WINDOW_HEIGHT / 2 - 100);
    insertAndSetFirstWall(head, 3, OVERALL_WINDOW_WIDTH / 2 - 250, OVERALL_WINDOW_HEIGHT / 2 + 100, 150, 10);
    insertAndSetFirstWall(head, 4, OVERALL_WINDOW_WIDTH / 2 - 150, OVERALL_WINDOW_HEIGHT / 2, 150, 10);
    insertAndSetFirstWall(head, 5, OVERALL_WINDOW_WIDTH / 2 - 250, OVERALL_WINDOW_HEIGHT / 2 - 200, 10, 300);
    insertAndSetFirstWall(head, 6, OVERALL_WINDOW_WIDTH / 2 - 150, OVERALL_WINDOW_HEIGHT / 2 - 100, 10, 100);
    insertAndSetFirstWall(head, 7, OVERALL_WINDOW_WIDTH / 2 - 250, OVERALL_WINDOW_HEIGHT / 2 - 200, 450, 10);
    insertAndSetFirstWall(head, 8, OVERALL_WINDOW_WIDTH / 2 - 150, OVERALL_WINDOW_HEIGHT / 2 - 100, 250, 10);
    insertAndSetFirstWall(head, 9, OVERALL_WINDOW_WIDTH / 2 + 200, OVERALL_WINDOW_HEIGHT / 2 - 200, 10, 300);
    insertAndSetFirstWall(head, 10, OVERALL_WINDOW_WIDTH / 2 + 100, OVERALL_WINDOW_HEIGHT / 2 - 100, 10, 300);
    insertAndSetFirstWall(head, 11, OVERALL_WINDOW_WIDTH / 2 + 100, OVERALL_WINDOW_HEIGHT / 2 + 200, OVERALL_WINDOW_WIDTH / 2 - 100, 10);
    insertAndSetFirstWall(head, 12, OVERALL_WINDOW_WIDTH / 2 + 200, OVERALL_WINDOW_HEIGHT / 2 + 100, OVERALL_WINDOW_WIDTH / 2 - 100, 10);
}

void maze3(struct Wall_collection **head)
{
    insertAndSetFirstWall(head, 1, OVERALL_WINDOW_WIDTH / 2, OVERALL_WINDOW_HEIGHT / 2 + 150, 10, OVERALL_WINDOW_HEIGHT / 2);            //1
    insertAndSetFirstWall(head, 12, OVERALL_WINDOW_WIDTH / 2, OVERALL_WINDOW_HEIGHT / 2 + 150, OVERALL_WINDOW_WIDTH / 2 - 150, 10);      //2
    insertAndSetFirstWall(head, 12, OVERALL_WINDOW_WIDTH / 2 + 170, OVERALL_WINDOW_HEIGHT / 2 + 85, 10, OVERALL_WINDOW_HEIGHT / 8 + 15); //3
    insertAndSetFirstWall(head, 12, 130, OVERALL_WINDOW_HEIGHT / 2 + 85, OVERALL_WINDOW_WIDTH / 2 + 40, 10);                             //4
    insertAndSetFirstWall(head, 1, 120, OVERALL_WINDOW_HEIGHT / 2 - 25, 10, OVERALL_WINDOW_HEIGHT / 4);                                  //5
    insertAndSetFirstWall(head, 12, 120, OVERALL_WINDOW_HEIGHT / 2 - 25, 65, 10);                                                        //6
    insertAndSetFirstWall(head, 1, 185, 165, 10, 60);                                                                                    //7
    insertAndSetFirstWall(head, 12, 185, 165, OVERALL_WINDOW_WIDTH / 2 - 10, 10);                                                        //8
    insertAndSetFirstWall(head, 1, 490, 165, 10, OVERALL_WINDOW_HEIGHT / 2 - 100);                                                       //9
    insertAndSetFirstWall(head, 12, 490, 300, 150, 10);                                                                                  //10
    insertAndSetFirstWall(head, 12, 550, 245, 100, 10);                                                                                  //11
    insertAndSetFirstWall(head, 1, 550, 110, 10, OVERALL_WINDOW_HEIGHT / 2 - 100);                                                       //12
    insertAndSetFirstWall(head, 12, 360, 110, OVERALL_WINDOW_WIDTH / 2 - 130, 10);                                                       //13
    insertAndSetFirstWall(head, 1, OVERALL_WINDOW_WIDTH / 2 + 30, 55, 10, 65);                                                           //14
    insertAndSetFirstWall(head, 12, OVERALL_WINDOW_WIDTH / 2 - 30, 55, 60, 10);                                                          //15
    insertAndSetFirstWall(head, 1, OVERALL_WINDOW_WIDTH / 2 - 30, 55, 10, 65);                                                           //16
    insertAndSetFirstWall(head, 12, 125, 110, OVERALL_WINDOW_WIDTH / 2 - 150, 10);                                                       //17
    insertAndSetFirstWall(head, 1, 125, 110, 10, 65);                                                                                    //18
    insertAndSetFirstWall(head, 12, 60, OVERALL_WINDOW_HEIGHT / 2 - 75, 65, 10);                                                         //19
    insertAndSetFirstWall(head, 1, 60, OVERALL_WINDOW_HEIGHT / 2 - 75, 10, OVERALL_WINDOW_HEIGHT / 3 + 75);                              //20
    insertAndSetFirstWall(head, 12, OVERALL_WINDOW_WIDTH / 2 - 250, OVERALL_WINDOW_HEIGHT / 2 + 150, OVERALL_WINDOW_WIDTH / 4, 10);      //21
    insertAndSetFirstWall(head, 2, OVERALL_WINDOW_WIDTH / 2 - 100, OVERALL_WINDOW_HEIGHT / 2 + 150, 10, OVERALL_WINDOW_HEIGHT / 2);      //22
}

void maze4(struct Wall_collection **head)
{
    int k = 0; // 1st diag from left
    while (k < 50)
    {
        insertAndSetFirstWall(head, 1,
                              OVERALL_WINDOW_WIDTH / 7 + (k * 2),
                              OVERALL_WINDOW_HEIGHT / 2 + (k * 2),
                              10, 10);
        k++;
    }

    int l = 0; // 2nd diag from left
    while (l < 100)
    {
        insertAndSetFirstWall(head, 2,
                              OVERALL_WINDOW_WIDTH / 2 - 230 + (l * 2),
                              OVERALL_WINDOW_HEIGHT / 3.5 + (l * 2),
                              10, 10);
        l++;
    }

    int m = 0; // 3 diag from left
    while (m < 400)
    {
        insertAndSetFirstWall(head, 3,
                              OVERALL_WINDOW_WIDTH / 2 - 120 + (m * 2),
                              OVERALL_WINDOW_HEIGHT / 3.5 + (m * 2),
                              15, 10);
        m++;
    }

    insertAndSetFirstWall(head, 4, OVERALL_WINDOW_WIDTH / 2 - 320, OVERALL_WINDOW_HEIGHT / 2 - 250, 10, OVERALL_WINDOW_HEIGHT / 2 + 250); //leftwall
    insertAndSetFirstWall(head, 5, OVERALL_WINDOW_WIDTH / 2 + 310, OVERALL_WINDOW_HEIGHT / 2 - 160, 10, OVERALL_WINDOW_HEIGHT / 2 + 250); //rightwall with gap
    insertAndSetFirstWall(head, 6, OVERALL_WINDOW_WIDTH / 2 - 400, OVERALL_WINDOW_HEIGHT / 2 + 230, 800, 10);                             //floor
    insertAndSetFirstWall(head, 7, OVERALL_WINDOW_WIDTH / 2 - 400, OVERALL_WINDOW_HEIGHT / 2 - 240, 800, 10);                             //roof

    insertAndSetFirstWall(head, 8, OVERALL_WINDOW_WIDTH / 7, OVERALL_WINDOW_HEIGHT / 2, 10, OVERALL_WINDOW_HEIGHT / 2); //first wall lower
    insertAndSetFirstWall(head, 9, 0, OVERALL_WINDOW_HEIGHT / 2 - 103, 100, 10);                                        //first horizontal

    insertAndSetFirstWall(head, 10, OVERALL_WINDOW_WIDTH / (7 * 0.5) + 7, OVERALL_WINDOW_HEIGHT / 2 + 107, 10, OVERALL_WINDOW_HEIGHT / 2); //second wall lower

    insertAndSetFirstWall(head, 11, OVERALL_WINDOW_WIDTH / 2.2, OVERALL_WINDOW_HEIGHT / 2 + 180, 10, OVERALL_WINDOW_HEIGHT / 2); //third wall lower

    insertAndSetFirstWall(head, 12, OVERALL_WINDOW_WIDTH / 7, OVERALL_WINDOW_HEIGHT / 2 - 175, 370, 10); //long horizontal (closest to roof)
    insertAndSetFirstWall(head, 13, 200, OVERALL_WINDOW_HEIGHT / 2 - 103, 200, 10);                      //the horizontal under ^ at end of 3rd diag

    insertAndSetFirstWall(head, 14, OVERALL_WINDOW_WIDTH / 1.2, OVERALL_WINDOW_HEIGHT / 8 - 100, 10, OVERALL_WINDOW_HEIGHT / 1.25); //vertical down wall (fourth wall upper)
    insertAndSetFirstWall(head, 15, OVERALL_WINDOW_WIDTH / 1.45, OVERALL_WINDOW_HEIGHT / 2 - 50, 100, 10);                          //shorter horizontal in the middle of 3rd diag
    insertAndSetFirstWall(head, 16, 320, OVERALL_WINDOW_HEIGHT / 2 + 15, 150, 10);                                                  //horizontal wall stemming from middle of vertical down
    insertAndSetFirstWall(head, 17, OVERALL_WINDOW_WIDTH / 1.2, OVERALL_WINDOW_HEIGHT / 1.666, 50, 10);                             //tiny obstacle out horizontal near exit
    insertAndSetFirstWall(head, 18, OVERALL_WINDOW_WIDTH / 1.3, OVERALL_WINDOW_HEIGHT / 1.4, 50, 10);                               //tiny stem horizontal end of vertical
}

void maze5(struct Wall_collection **head)
{
    insertAndSetFirstWall(head, 1, OVERALL_WINDOW_WIDTH / 2 - 200, OVERALL_WINDOW_HEIGHT / 2 + 100, 10, 500);
    insertAndSetFirstWall(head, 2, OVERALL_WINDOW_WIDTH / 2 - 100, OVERALL_WINDOW_HEIGHT / 2, 10, OVERALL_WINDOW_HEIGHT / 2);
    insertAndSetFirstWall(head, 3, OVERALL_WINDOW_WIDTH / 2 - 225, OVERALL_WINDOW_HEIGHT / 2, 125, 10);
    insertAndSetFirstWall(head, 4, OVERALL_WINDOW_WIDTH / 2 - 300, OVERALL_WINDOW_HEIGHT / 2 + 100, 150, 10);
    insertAndSetFirstWall(head, 5, OVERALL_WINDOW_WIDTH / 2 - 300, OVERALL_WINDOW_HEIGHT / 2 - 210, 10, OVERALL_WINDOW_HEIGHT / 2 + 75);
    insertAndSetFirstWall(head, 6, OVERALL_WINDOW_WIDTH / 2 - 300, OVERALL_WINDOW_HEIGHT / 2 - 210, 500, 10);
    insertAndSetFirstWall(head, 7, OVERALL_WINDOW_WIDTH / 2 - 220, OVERALL_WINDOW_HEIGHT / 2 - 210, 10, OVERALL_WINDOW_HEIGHT / 2 - 100);
    insertAndSetFirstWall(head, 8, OVERALL_WINDOW_WIDTH / 2 - 160, OVERALL_WINDOW_HEIGHT / 2 - 100, 10, OVERALL_WINDOW_HEIGHT / 2 - 175);
    insertAndSetFirstWall(head, 9, OVERALL_WINDOW_WIDTH / 2 - 100, OVERALL_WINDOW_HEIGHT / 2 - 150, 10, OVERALL_WINDOW_HEIGHT / 2 + 20);
    insertAndSetFirstWall(head, 10, OVERALL_WINDOW_WIDTH / 2 + 50, OVERALL_WINDOW_HEIGHT / 2 - 210, 10, OVERALL_WINDOW_HEIGHT / 2 - 100);
    insertAndSetFirstWall(head, 11, OVERALL_WINDOW_WIDTH / 2 - 50, OVERALL_WINDOW_HEIGHT / 2 - 150, 50, 10);
    insertAndSetFirstWall(head, 12, OVERALL_WINDOW_WIDTH / 2 + 10, OVERALL_WINDOW_HEIGHT / 2 - 75, 50, 10);
    insertAndSetFirstWall(head, 13, OVERALL_WINDOW_WIDTH / 2, OVERALL_WINDOW_HEIGHT / 2 - 150, 10, OVERALL_WINDOW_HEIGHT / 2 - 155);
    insertAndSetFirstWall(head, 12, OVERALL_WINDOW_WIDTH / 2 - 50, OVERALL_WINDOW_HEIGHT / 2 - 75, 50, 10);
    insertAndSetFirstWall(head, 13, OVERALL_WINDOW_WIDTH / 2 - 50, OVERALL_WINDOW_HEIGHT / 2 - 75, 10, OVERALL_WINDOW_HEIGHT / 2 - 100);
    insertAndSetFirstWall(head, 12, OVERALL_WINDOW_WIDTH / 2 - 50, OVERALL_WINDOW_HEIGHT / 2 + 60, 150, 10);
    insertAndSetFirstWall(head, 13, OVERALL_WINDOW_WIDTH / 2 - 25, OVERALL_WINDOW_HEIGHT / 2 + 125, 10, OVERALL_WINDOW_HEIGHT / 2 - 180);
    insertAndSetFirstWall(head, 13, OVERALL_WINDOW_WIDTH / 2 + 25, OVERALL_WINDOW_HEIGHT / 2 + 100, 10, OVERALL_WINDOW_HEIGHT / 2 - 220);
    insertAndSetFirstWall(head, 13, OVERALL_WINDOW_WIDTH / 2 + 25, OVERALL_WINDOW_HEIGHT / 2 + 180, 10, OVERALL_WINDOW_HEIGHT / 2 - 220);
    insertAndSetFirstWall(head, 12, OVERALL_WINDOW_WIDTH / 2 - 100, OVERALL_WINDOW_HEIGHT / 2 + 230, 450, 10);
    insertAndSetFirstWall(head, 12, OVERALL_WINDOW_WIDTH / 2 + 200, OVERALL_WINDOW_HEIGHT / 2 + 150, 150, 10);
    insertAndSetFirstWall(head, 13, OVERALL_WINDOW_WIDTH / 2 + 100, OVERALL_WINDOW_HEIGHT / 2, 10, OVERALL_WINDOW_HEIGHT / 2 - 125);
    insertAndSetFirstWall(head, 13, OVERALL_WINDOW_WIDTH / 2 + 200, OVERALL_WINDOW_HEIGHT / 2 - 210, 10, OVERALL_WINDOW_HEIGHT / 2 + 125);
    insertAndSetFirstWall(head, 13, OVERALL_WINDOW_WIDTH / 2 + 25, OVERALL_WINDOW_HEIGHT / 2 - 20, 10, OVERALL_WINDOW_HEIGHT / 2 - 200);
    insertAndSetFirstWall(head, 12, OVERALL_WINDOW_WIDTH / 2 + 125, OVERALL_WINDOW_HEIGHT / 2 - 100, 80, 10);
    insertAndSetFirstWall(head, 12, OVERALL_WINDOW_WIDTH / 2 + 175, OVERALL_WINDOW_HEIGHT / 2, 30, 10);
    insertAndSetFirstWall(head, 12, OVERALL_WINDOW_WIDTH / 2 + 100, OVERALL_WINDOW_HEIGHT / 2 + 75, 30, 10);
    insertAndSetFirstWall(head, 12, OVERALL_WINDOW_WIDTH / 2 + 175, OVERALL_WINDOW_HEIGHT / 2 + 150, 30, 10);
    insertAndSetFirstWall(head, 12, OVERALL_WINDOW_WIDTH / 2 + 110, OVERALL_WINDOW_HEIGHT / 2 - 150, 30, 10);
}

void maze6(struct Wall_collection **head)
{

    insertAndSetFirstWall(head, 1, OVERALL_WINDOW_WIDTH / 2 - 320, OVERALL_WINDOW_HEIGHT / 2 - 250, 10, OVERALL_WINDOW_HEIGHT / 2 + 250); //left wall
    insertAndSetFirstWall(head, 2, OVERALL_WINDOW_WIDTH / 2 - 400, OVERALL_WINDOW_HEIGHT / 2 - 240, 800, 10);                             //roof
    insertAndSetFirstWall(head, 3, OVERALL_WINDOW_WIDTH / 2 + 310, OVERALL_WINDOW_HEIGHT / 2 - 250, 10, OVERALL_WINDOW_HEIGHT / 2 + 100); //right wall

    insertAndSetFirstWall(head, 4, OVERALL_WINDOW_WIDTH / 2 - 250, OVERALL_WINDOW_HEIGHT / 2 + 50, 10, OVERALL_WINDOW_HEIGHT / 2); //first lower wall
    insertAndSetFirstWall(head, 5, OVERALL_WINDOW_WIDTH / 2 - 250, OVERALL_WINDOW_HEIGHT / 2 - 170, 10, 150);                      //first upper wall
    insertAndSetFirstWall(head, 6, OVERALL_WINDOW_WIDTH / 2 - 240, OVERALL_WINDOW_HEIGHT / 2 + 230, 800, 10);                      //floor
    insertAndSetFirstWall(head, 7, OVERALL_WINDOW_WIDTH / 2 - 250, OVERALL_WINDOW_HEIGHT / 2 + 50, 160, 10);                       //second horizontal lower wall
    insertAndSetFirstWall(head, 8, OVERALL_WINDOW_WIDTH / 2 - 250, OVERALL_WINDOW_HEIGHT / 2 - 30, 100, 10);                       //second horizontal middle wall
    insertAndSetFirstWall(head, 9, OVERALL_WINDOW_WIDTH / 2 - 250, OVERALL_WINDOW_HEIGHT / 2 - 180, 100, 10);                      //second horizontal upper wall

    insertAndSetFirstWall(head, 10, OVERALL_WINDOW_WIDTH / 2 - 160, OVERALL_WINDOW_HEIGHT / 2 + 120, 10, OVERALL_WINDOW_HEIGHT / 2);      //third lower wall
    insertAndSetFirstWall(head, 11, OVERALL_WINDOW_WIDTH / 2 - 160, OVERALL_WINDOW_HEIGHT / 2 - 70, 10, 40);                              //third middle wall
    insertAndSetFirstWall(head, 12, OVERALL_WINDOW_WIDTH / 2 - 160, OVERALL_WINDOW_HEIGHT / 2 - 230, 10, 50);                             //third upper wall
    insertAndSetFirstWall(head, 13, OVERALL_WINDOW_WIDTH / 2 - 160, OVERALL_WINDOW_HEIGHT / 2 + 170, 80, 10);                             //fourth horizontal lower wall
    insertAndSetFirstWall(head, 14, OVERALL_WINDOW_WIDTH / 2 - 100, OVERALL_WINDOW_HEIGHT / 2 - 115, 10, OVERALL_WINDOW_HEIGHT / 2 - 65); //fourth middle wall
    insertAndSetFirstWall(head, 15, OVERALL_WINDOW_WIDTH / 2 - 180, OVERALL_WINDOW_HEIGHT / 2 - 120, 260, 10);                            //fourth horizontal upper wall
    insertAndSetFirstWall(head, 16, OVERALL_WINDOW_WIDTH / 2 - 60, OVERALL_WINDOW_HEIGHT / 2 - 230, 10, 50);                              //fourth upper wall

    insertAndSetFirstWall(head, 17, OVERALL_WINDOW_WIDTH / 2 - 60, OVERALL_WINDOW_HEIGHT / 2 + 120, 140, 10);                            //fifth horizontal lower wall
    insertAndSetFirstWall(head, 18, OVERALL_WINDOW_WIDTH / 2 - 20, OVERALL_WINDOW_HEIGHT / 2 - 115, 10, OVERALL_WINDOW_HEIGHT / 2 - 65); //fifth middle wall
    insertAndSetFirstWall(head, 19, OVERALL_WINDOW_WIDTH / 2 - 60, OVERALL_WINDOW_HEIGHT / 2 - 180, 140, 10);                            //fifth horizontal upper wall
    insertAndSetFirstWall(head, 20, OVERALL_WINDOW_WIDTH / 2 + 70, OVERALL_WINDOW_HEIGHT / 2 - 230, 10, 50);                             //sixth upper wall
    insertAndSetFirstWall(head, 21, OVERALL_WINDOW_WIDTH / 2 + 70, OVERALL_WINDOW_HEIGHT / 2, 10, OVERALL_WINDOW_HEIGHT / 2 - 65);       //sixth middle wall

    insertAndSetFirstWall(head, 22, OVERALL_WINDOW_WIDTH / 2 + 150, OVERALL_WINDOW_HEIGHT / 2 + 70, 10, OVERALL_WINDOW_HEIGHT / 2 - 65);  //seventh lower wall
    insertAndSetFirstWall(head, 23, OVERALL_WINDOW_WIDTH / 2 + 70, OVERALL_WINDOW_HEIGHT / 2, 160, 10);                                   //seventh horizontal middle wall
    insertAndSetFirstWall(head, 24, OVERALL_WINDOW_WIDTH / 2 + 150, OVERALL_WINDOW_HEIGHT / 2 - 170, 10, OVERALL_WINDOW_HEIGHT / 2 - 65); //seventh upper wall
    insertAndSetFirstWall(head, 25, OVERALL_WINDOW_WIDTH / 2 + 150, OVERALL_WINDOW_HEIGHT / 2 + 60, 80, 10);                              //eighth horizontal middle wall
    insertAndSetFirstWall(head, 26, OVERALL_WINDOW_WIDTH / 2 + 220, OVERALL_WINDOW_HEIGHT / 2 - 240, 10, OVERALL_WINDOW_HEIGHT / 2);      // eighth upper wall
    insertAndSetFirstWall(head, 27, OVERALL_WINDOW_WIDTH / 2 + 220, OVERALL_WINDOW_HEIGHT / 2 + 120, 10, OVERALL_WINDOW_HEIGHT / 2 - 65); //eighth horizontal middle wall
}

void maze7(struct Wall_collection **head)
{
    insertAndSetFirstWall(head, 1, OVERALL_WINDOW_WIDTH / 2 - 250, OVERALL_WINDOW_HEIGHT / 2 - 175, 10, OVERALL_WINDOW_HEIGHT / 5);
    insertAndSetFirstWall(head, 2, OVERALL_WINDOW_WIDTH / 2 - 140, OVERALL_WINDOW_HEIGHT / 2 - 175, 10, OVERALL_WINDOW_HEIGHT / 5);
    insertAndSetFirstWall(head, 3, OVERALL_WINDOW_WIDTH / 2 - 250, OVERALL_WINDOW_HEIGHT / 2 - 175, OVERALL_WINDOW_HEIGHT / 4, 10);
    insertAndSetFirstWall(head, 4, OVERALL_WINDOW_WIDTH / 2 - 250, OVERALL_WINDOW_HEIGHT / 2 - 85, OVERALL_WINDOW_HEIGHT / 4, 10);
    insertAndSetFirstWall(head, 5, OVERALL_WINDOW_WIDTH / 2 + 125, OVERALL_WINDOW_HEIGHT / 2 + 50, 10, OVERALL_WINDOW_HEIGHT / 4.5);
    insertAndSetFirstWall(head, 6, OVERALL_WINDOW_WIDTH / 2 + 245, OVERALL_WINDOW_HEIGHT / 2 + 50, 10, OVERALL_WINDOW_HEIGHT / 4.35);
    insertAndSetFirstWall(head, 7, OVERALL_WINDOW_WIDTH / 2 + 125, OVERALL_WINDOW_HEIGHT / 2 + 50, OVERALL_WINDOW_HEIGHT / 4, 10);
    insertAndSetFirstWall(head, 8, OVERALL_WINDOW_WIDTH / 2 + 125, OVERALL_WINDOW_HEIGHT / 2 + 150, OVERALL_WINDOW_HEIGHT / 4, 10);
    insertAndSetFirstWall(head, 9, OVERALL_WINDOW_WIDTH / 2 - 225, OVERALL_WINDOW_HEIGHT / 2 + 50, 10, OVERALL_WINDOW_HEIGHT / 2);
    insertAndSetFirstWall(head, 10, OVERALL_WINDOW_WIDTH / 2 - 150, OVERALL_WINDOW_HEIGHT / 2 + 50, 10, OVERALL_WINDOW_HEIGHT / 2);
    insertAndSetFirstWall(head, 11, OVERALL_WINDOW_WIDTH / 2 - 150, OVERALL_WINDOW_HEIGHT / 2 + 50, OVERALL_WINDOW_HEIGHT / 2.5, 10);
    insertAndSetFirstWall(head, 12, OVERALL_WINDOW_WIDTH / 2 - 150, OVERALL_WINDOW_HEIGHT / 2 + 140, OVERALL_WINDOW_HEIGHT / 4, 10);
    insertAndSetFirstWall(head, 13, OVERALL_WINDOW_WIDTH / 2 - 40, OVERALL_WINDOW_HEIGHT / 2 + 140, 10, OVERALL_WINDOW_HEIGHT / 13);
    insertAndSetFirstWall(head, 14, OVERALL_WINDOW_WIDTH / 2 + 125, OVERALL_WINDOW_HEIGHT / 2 - 25, OVERALL_WINDOW_HEIGHT / 2, 10);
    insertAndSetFirstWall(head, 15, OVERALL_WINDOW_WIDTH / 2 - 180, OVERALL_WINDOW_HEIGHT / 2 - 25, OVERALL_WINDOW_HEIGHT / 4, 10);
    insertAndSetFirstWall(head, 16, OVERALL_WINDOW_WIDTH / 2 - 65, OVERALL_WINDOW_HEIGHT / 2 - 175, 10, OVERALL_WINDOW_HEIGHT / 3);
    insertAndSetFirstWall(head, 17, OVERALL_WINDOW_WIDTH / 2 - 55, OVERALL_WINDOW_HEIGHT / 2 - 175, OVERALL_WINDOW_HEIGHT / 1.25, 10);
    insertAndSetFirstWall(head, 18, OVERALL_WINDOW_WIDTH / 2 + 150, OVERALL_WINDOW_HEIGHT / 2 - 175, 10, OVERALL_WINDOW_HEIGHT / 6.85);
    insertAndSetFirstWall(head, 19, OVERALL_WINDOW_WIDTH / 2 + 60, OVERALL_WINDOW_HEIGHT / 2 - 115, OVERALL_WINDOW_HEIGHT / 5, 10);
    insertAndSetFirstWall(head, 20, OVERALL_WINDOW_WIDTH / 2 - 350, OVERALL_WINDOW_HEIGHT / 2 - 240, OVERALL_WINDOW_HEIGHT / 1.005, 10);
    insertAndSetFirstWall(head, 21, OVERALL_WINDOW_WIDTH / 2 - 150, OVERALL_WINDOW_HEIGHT / 2 - 240, OVERALL_WINDOW_HEIGHT / 1.005, 10);
    insertAndSetFirstWall(head, 22, OVERALL_WINDOW_WIDTH / 2 - 150, OVERALL_WINDOW_HEIGHT / 2 + 230, OVERALL_WINDOW_HEIGHT / 1.005, 10);
    insertAndSetFirstWall(head, 23, OVERALL_WINDOW_WIDTH / 2 - 340, OVERALL_WINDOW_HEIGHT / 2 + 230, OVERALL_WINDOW_HEIGHT / 4, 10);
    insertAndSetFirstWall(head, 24, OVERALL_WINDOW_WIDTH / 2 - 320, OVERALL_WINDOW_HEIGHT / 2 - 250, 10, OVERALL_WINDOW_HEIGHT / 1);
    insertAndSetFirstWall(head, 25, OVERALL_WINDOW_WIDTH / 2 + 310, OVERALL_WINDOW_HEIGHT / 2 - 265, 10, OVERALL_WINDOW_HEIGHT / 5);
    insertAndSetFirstWall(head, 26, OVERALL_WINDOW_WIDTH / 2 + 310, OVERALL_WINDOW_HEIGHT / 2 - 85, 10, OVERALL_WINDOW_HEIGHT / 7);
    insertAndSetFirstWall(head, 27, OVERALL_WINDOW_WIDTH / 2 + 250, OVERALL_WINDOW_HEIGHT / 2 - 85, OVERALL_WINDOW_HEIGHT / 7, 10);
    insertAndSetFirstWall(head, 28, OVERALL_WINDOW_WIDTH / 2 + 310, OVERALL_WINDOW_HEIGHT / 2 - 15, 10, OVERALL_WINDOW_HEIGHT / 1.05);
}

void maze8(struct Wall_collection **head)
{
    int j = 0; // Key value
    // Adding a circle with radius 50
    for (int i = -50; i < 51; i += 1)
    {
        // Leaving a gap
        if (-20 > i || i > 20)
        {
            insertAndSetFirstWall(head, j, OVERALL_WINDOW_WIDTH / 2 + i, OVERALL_WINDOW_HEIGHT / 2 + sqrt(2500 - i * i), 5, 5);
            j += 1;
        }
        insertAndSetFirstWall(head, j, OVERALL_WINDOW_WIDTH / 2 + i, OVERALL_WINDOW_HEIGHT / 2 - sqrt(2500 - i * i), 5, 5);
        j += 1;
    }
    // Adding a circle with radius 125
    for (int i = -125; i < 126; i += 1)
    {
        // Leaving a few gaps
        if ((70 > i || i > 100) && (-100 > i || i > -75))
        {
            insertAndSetFirstWall(head, j, OVERALL_WINDOW_WIDTH / 2 + i, OVERALL_WINDOW_HEIGHT / 2 - sqrt(15625 - i * i), 5, 5);
            j += 1;
        }
        // Leaving more gaps
        if ((-100 > i || i > -75) && (110 > i || i > 121))
        {
            insertAndSetFirstWall(head, j, OVERALL_WINDOW_WIDTH / 2 + i, OVERALL_WINDOW_HEIGHT / 2 + sqrt(15625 - i * i), 5, 5);
            j += 1;
        }
        // Creating a wall between the circles
        if (18 < i && i < 70)
        {
            insertAndSetFirstWall(head, j, OVERALL_WINDOW_WIDTH / 2 + 19 + i, OVERALL_WINDOW_HEIGHT / 2 + 19 + i, 5, 5);
            j += 1;
        }
        // Creating a wall between the circles
        if (20 < i && i < 85)
        {
            insertAndSetFirstWall(head, j, OVERALL_WINDOW_WIDTH / 2 + 20 + i, OVERALL_WINDOW_HEIGHT / 2 - 15 - i / 1.5, 5, 5);
            j += 1;
        }
    }
    // Adding a circle with radius 200
    for (int i = -200; i < 201; i += 1)
    {
        // Leaving a gap
        if (198 > i)
        {
            insertAndSetFirstWall(head, j, OVERALL_WINDOW_WIDTH / 2 + i, OVERALL_WINDOW_HEIGHT / 2 + sqrt(40000 - i * i), 5, 5);
            insertAndSetFirstWall(head, j + 1, OVERALL_WINDOW_WIDTH / 2 + i, OVERALL_WINDOW_HEIGHT / 2 - sqrt(40000 - i * i), 5, 5);
            j += 2;
        }
        // Creating two walls between the circles
        if (125 < i && i < 195)
        {
            insertAndSetFirstWall(head, j, OVERALL_WINDOW_WIDTH / 2 + i, (OVERALL_WINDOW_HEIGHT / 2 - 2 + (i / 5)), 5, 5);
            j += 1;
        }
    }
    // Cleaining up the circles and adding the end corridoor
    insertAndSetFirstWall(head, j, OVERALL_WINDOW_WIDTH / 2 - 200, OVERALL_WINDOW_HEIGHT / 2 - 12.5, 5, 30);
    insertAndSetFirstWall(head, j + 1, OVERALL_WINDOW_WIDTH / 2 - 125, OVERALL_WINDOW_HEIGHT / 2 - 10, 5, 25);
    insertAndSetFirstWall(head, j + 2, OVERALL_WINDOW_WIDTH / 2 + 125, OVERALL_WINDOW_HEIGHT / 2 - 10, 5, 25);
    insertAndSetFirstWall(head, j + 3, OVERALL_WINDOW_WIDTH / 2 + 200, OVERALL_WINDOW_HEIGHT / 2 + 35, 150, 5);
    insertAndSetFirstWall(head, j + 4, OVERALL_WINDOW_WIDTH / 2 + 200, OVERALL_WINDOW_HEIGHT / 2 - 35, 150, 5);
    // Creating more walls between the circles
    insertAndSetFirstWall(head, j + 5, OVERALL_WINDOW_WIDTH / 2, OVERALL_WINDOW_HEIGHT / 2 - 200, 5, 75);
    insertAndSetFirstWall(head, j + 6, OVERALL_WINDOW_WIDTH / 2 - 200, OVERALL_WINDOW_HEIGHT / 2, 75, 5); // Adding a circle with radius 125
    for (int i = -125; i < 126; i += 1)
    {
        // Leaving a few gaps
        if ((70 > i || i > 100) && (-100 > i || i > -75))
        {
            insertAndSetFirstWall(head, j, OVERALL_WINDOW_WIDTH / 2 + i, OVERALL_WINDOW_HEIGHT / 2 - sqrt(15625 - i * i), 5, 5);
            j += 1;
        }
        // Leaving more gaps
        if ((-100 > i || i > -75) && (110 > i || i > 121))
        {
            insertAndSetFirstWall(head, j, OVERALL_WINDOW_WIDTH / 2 + i, OVERALL_WINDOW_HEIGHT / 2 + sqrt(15625 - i * i), 5, 5);
            j += 1;
        }
        // Creating a wall between the circles
        if (18 < i && i < 70)
        {
            insertAndSetFirstWall(head, j, OVERALL_WINDOW_WIDTH / 2 + 19 + i, OVERALL_WINDOW_HEIGHT / 2 + 19 + i, 5, 5);
            j += 1;
        }
        // Creating a wall between the circles
        if (20 < i && i < 85)
        {
            insertAndSetFirstWall(head, j, OVERALL_WINDOW_WIDTH / 2 + 20 + i, OVERALL_WINDOW_HEIGHT / 2 - 15 - i / 1.5, 5, 5);
            j += 1;
        }
    }
    // Adding a circle with radius 200
    for (int i = -200; i < 201; i += 1)
    {
        // Leaving a gap
        if (198 > i)
        {
            insertAndSetFirstWall(head, j, OVERALL_WINDOW_WIDTH / 2 + i, OVERALL_WINDOW_HEIGHT / 2 + sqrt(40000 - i * i), 5, 5);
            insertAndSetFirstWall(head, j + 1, OVERALL_WINDOW_WIDTH / 2 + i, OVERALL_WINDOW_HEIGHT / 2 - sqrt(40000 - i * i), 5, 5);
            j += 2;
        }
        // Creating two walls between the circles
        if (125 < i && i < 195)
        {
            insertAndSetFirstWall(head, j, OVERALL_WINDOW_WIDTH / 2 + i, (OVERALL_WINDOW_HEIGHT / 2 - 2 + (i / 5)), 5, 5);
            j += 1;
        }
    }
    // Cleaining up the circles and adding the end corridoor
    insertAndSetFirstWall(head, j, OVERALL_WINDOW_WIDTH / 2 - 200, OVERALL_WINDOW_HEIGHT / 2 - 12.5, 5, 30);
    insertAndSetFirstWall(head, j + 1, OVERALL_WINDOW_WIDTH / 2 - 125, OVERALL_WINDOW_HEIGHT / 2 - 10, 5, 25);
    insertAndSetFirstWall(head, j + 2, OVERALL_WINDOW_WIDTH / 2 + 125, OVERALL_WINDOW_HEIGHT / 2 - 10, 5, 25);
    insertAndSetFirstWall(head, j + 3, OVERALL_WINDOW_WIDTH / 2 + 200, OVERALL_WINDOW_HEIGHT / 2 + 35, 150, 5);
    insertAndSetFirstWall(head, j + 4, OVERALL_WINDOW_WIDTH / 2 + 200, OVERALL_WINDOW_HEIGHT / 2 - 35, 150, 5);
    // Creating more walls between the circles
    insertAndSetFirstWall(head, j + 5, OVERALL_WINDOW_WIDTH / 2, OVERALL_WINDOW_HEIGHT / 2 - 200, 5, 75);
    insertAndSetFirstWall(head, j + 6, OVERALL_WINDOW_WIDTH / 2 - 200, OVERALL_WINDOW_HEIGHT / 2, 75, 5);
}

void maze9(struct Wall_collection **head)
{
    insertAndSetFirstWall(head, 1, 0 + 15, 0 + 10, 610, 10);
    insertAndSetFirstWall(head, 2, 0 + 15, 150 + 10, 310, 10);
    insertAndSetFirstWall(head, 3, 0 + 15, 250 + 10, 60, 10);
    insertAndSetFirstWall(head, 4, 0 + 15, 0 + 10, 10, 160);
    insertAndSetFirstWall(head, 5, 0 + 15, 200 + 10, 10, 260);
    insertAndSetFirstWall(head, 6, 50 + 15, 150 + 10, 10, 60);
    insertAndSetFirstWall(head, 7, 50 + 15, 250 + 10, 10, 60);
    insertAndSetFirstWall(head, 8, 100 + 15, 100 + 10, 10, 160);
    insertAndSetFirstWall(head, 9, 50 + 15, 50 + 10, 10, 60);
    insertAndSetFirstWall(head, 10, 50 + 15, 50 + 10, 60, 10);
    insertAndSetFirstWall(head, 11, 100 + 15, 0 + 10, 10, 60);
    insertAndSetFirstWall(head, 12, 0 + 15, 350 + 10, 110, 10);
    insertAndSetFirstWall(head, 13, 100 + 15, 350 + 10, 10, 60);
    insertAndSetFirstWall(head, 14, 100 + 15, 400 + 10, 60, 10);
    insertAndSetFirstWall(head, 15, 150 + 15, 350 + 10, 10, 60);
    insertAndSetFirstWall(head, 16, 50 + 15, 400 + 10, 10, 60);
    insertAndSetFirstWall(head, 17, 150 + 15, 350 + 10, 210, 10);
    insertAndSetFirstWall(head, 18, 250 + 15, 350 + 10, 10, 60);
    insertAndSetFirstWall(head, 19, 350 + 15, 350 + 10, 10, 60);
    insertAndSetFirstWall(head, 20, 350 + 15, 400 + 10, 160, 10);
    insertAndSetFirstWall(head, 21, 500 + 15, 350 + 10, 10, 60);
    insertAndSetFirstWall(head, 22, 200 + 15, 400 + 10, 10, 60);
    insertAndSetFirstWall(head, 23, 300 + 15, 400 + 10, 10, 60);
    insertAndSetFirstWall(head, 24, 100 + 15, 300 + 10, 210, 10);
    insertAndSetFirstWall(head, 25, 150 + 15, 250 + 10, 10, 60);
    insertAndSetFirstWall(head, 26, 250 + 15, 250 + 10, 10, 60);
    insertAndSetFirstWall(head, 27, 300 + 15, 300 + 10, 10, 60);
    insertAndSetFirstWall(head, 28, 150 + 15, 50 + 10, 110, 10);
    insertAndSetFirstWall(head, 29, 150 + 15, 50 + 10, 10, 110);
    insertAndSetFirstWall(head, 30, 200 + 15, 100 + 10, 160, 10);
    insertAndSetFirstWall(head, 31, 300 + 15, 50 + 10, 10, 60);
    insertAndSetFirstWall(head, 32, 350 + 15, 0 + 10, 10, 110);
    insertAndSetFirstWall(head, 33, 400 + 15, 50 + 10, 10, 60);
    insertAndSetFirstWall(head, 34, 400 + 15, 50 + 10, 60, 10);
    insertAndSetFirstWall(head, 35, 450 + 15, 0 + 10, 10, 60);
    insertAndSetFirstWall(head, 36, 150 + 15, 200 + 10, 210, 10);
    insertAndSetFirstWall(head, 37, 200 + 15, 200 + 10, 10, 60);
    insertAndSetFirstWall(head, 38, 300 + 15, 200 + 10, 10, 60);
    insertAndSetFirstWall(head, 39, 300 + 15, 250 + 10, 60, 10);
    insertAndSetFirstWall(head, 40, 350 + 15, 250 + 10, 10, 60);
    insertAndSetFirstWall(head, 41, 350 + 15, 300 + 10, 60, 10);
    insertAndSetFirstWall(head, 42, 400 + 15, 200 + 10, 10, 110);
    insertAndSetFirstWall(head, 43, 400 + 15, 200 + 10, 60, 10);
    insertAndSetFirstWall(head, 44, 450 + 15, 200 + 10, 10, 60);
    insertAndSetFirstWall(head, 45, 450 + 15, 250 + 10, 60, 10);
    insertAndSetFirstWall(head, 46, 350 + 15, 150 + 10, 10, 60);
    insertAndSetFirstWall(head, 46, 350 + 15, 150 + 10, 210, 10);
    insertAndSetFirstWall(head, 47, 450 + 15, 100 + 10, 10, 60);
    insertAndSetFirstWall(head, 48, 500 + 15, 50 + 10, 60, 10);
    insertAndSetFirstWall(head, 49, 500 + 15, 50 + 10, 10, 160);
    insertAndSetFirstWall(head, 50, 500 + 15, 200 + 10, 110, 10);
    insertAndSetFirstWall(head, 51, 550 + 15, 200 + 10, 10, 210);
    insertAndSetFirstWall(head, 52, 400 + 15, 350 + 10, 60, 10);
    insertAndSetFirstWall(head, 53, 450 + 15, 300 + 10, 10, 60);
    insertAndSetFirstWall(head, 54, 450 + 15, 300 + 10, 110, 10);
    insertAndSetFirstWall(head, 55, 550 + 15, 100 + 10, 60, 10);
    insertAndSetFirstWall(head, 56, 600 + 15, 0 + 10, 10, 210);
    insertAndSetFirstWall(head, 57, 600 + 15, 250 + 10, 10, 210);
    insertAndSetFirstWall(head, 58, 0 + 15, 450 + 10, 610, 10);
}

void basic_1(struct Wall_collection **head)
{
    insertAndSetFirstWall(head, 2, 220, 400, 10, 80);
    insertAndSetFirstWall(head, 2, 20, 400, 200, 10);
    insertAndSetFirstWall(head, 2, 20, 50, 10, 350);
    insertAndSetFirstWall(head, 2, 20, 50, 280, 10);
    insertAndSetFirstWall(head, 2, 300, 50, 10, 100);
    insertAndSetFirstWall(head, 2, 300, 150, 110, 10);
    insertAndSetFirstWall(head, 2, 400, 50, 10, 100);
    insertAndSetFirstWall(head, 2, 400, 50, 220, 10);
    insertAndSetFirstWall(head, 2, 620, 50, 10, 290);
    insertAndSetFirstWall(head, 2, 620, 340, 20, 10);

    insertAndSetFirstWall(head, 1, 320, 300, 10, 180);
    insertAndSetFirstWall(head, 2, 120, 300, 200, 10);
    insertAndSetFirstWall(head, 2, 120, 150, 10, 150);
    insertAndSetFirstWall(head, 2, 120, 150, 80, 10);
    insertAndSetFirstWall(head, 2, 200, 150, 10, 100);
    insertAndSetFirstWall(head, 2, 200, 250, 310, 10);
    insertAndSetFirstWall(head, 2, 500, 150, 10, 100);
    insertAndSetFirstWall(head, 2, 500, 150, 10, 100);
    insertAndSetFirstWall(head, 2, 500, 150, 20, 10);
    insertAndSetFirstWall(head, 2, 520, 150, 10, 290);
    insertAndSetFirstWall(head, 2, 520, 440, 120, 10);
}

void basic_3(struct Wall_collection **head)
{
    insertAndSetFirstWall(head, 2, 640 - 10 - 220, 400, 10, 80);
    insertAndSetFirstWall(head, 2, 640 - 200 - 20, 400, 200, 10);
    insertAndSetFirstWall(head, 2, 640 - 10 - 20, 50, 10, 350);
    insertAndSetFirstWall(head, 2, 640 - 280 - 20, 50, 280, 10);
    insertAndSetFirstWall(head, 2, 640 - 10 - 300, 50, 10, 100);
    insertAndSetFirstWall(head, 2, 640 - 110 - 300, 150, 110, 10);
    insertAndSetFirstWall(head, 2, 640 - 10 - 400, 50, 10, 100);
    insertAndSetFirstWall(head, 2, 640 - 400 - 220, 50, 220, 10);
    insertAndSetFirstWall(head, 2, 640 - 10 - 620, 50, 10, 290);
    insertAndSetFirstWall(head, 2, 640 - 620 - 20, 340, 20, 10);

    insertAndSetFirstWall(head, 1, 640 - 10 - 320, 300, 10, 180);
    insertAndSetFirstWall(head, 2, 640 - 200 - 120, 300, 200, 10);
    insertAndSetFirstWall(head, 2, 640 - 10 - 120, 150, 10, 150);
    insertAndSetFirstWall(head, 2, 640 - 80 - 120, 150, 80, 10);
    insertAndSetFirstWall(head, 2, 640 - 10 - 200, 150, 10, 100);
    insertAndSetFirstWall(head, 2, 640 - 310 - 200, 250, 310, 10);
    insertAndSetFirstWall(head, 2, 640 - 10 - 500, 150, 10, 100);
    insertAndSetFirstWall(head, 2, 640 - 20 - 500, 150, 20, 10);
    insertAndSetFirstWall(head, 2, 640 - 10 - 520, 150, 10, 290);
    insertAndSetFirstWall(head, 2, 640 - 120 - 520, 440, 120, 10);
}

void complex_5(struct Wall_collection **head)
{
    int i;
    insertAndSetFirstWall(head, 12, 120, 450, 10, 30);
    insertAndSetFirstWall(head, 12, 220, 450, 10, 30);
    for (i = 0; i < 100; i++)
    {
        insertAndSetFirstWall(head, i, 20 + i, 350 + i, 10, 10);       //1
        insertAndSetFirstWall(head, i, 20 + 100 + i, 350 + i, 10, 10); //1
    }
    insertAndSetFirstWall(head, 12, 20, 280, 10, 70);
    insertAndSetFirstWall(head, 12, 120, 280, 10, 70);
    for (i = 0; i < 180; i++)
    {
        insertAndSetFirstWall(head, i, 20 + 190 - i / 2, 100 + i, 10, 10); //1
    }
    for (i = 0; i < 105; i++)
    {
        insertAndSetFirstWall(head, i, 20 + 105 / 2 - i / 2, 175 + i, 10, 10); //1
    }
    insertAndSetFirstWall(head, 2, 20, 175, 105 / 2, 10);
    insertAndSetFirstWall(head, 2, 20, 20, 10, 155);
    insertAndSetFirstWall(head, 2, 20, 20, 300, 10);
    insertAndSetFirstWall(head, 2, 320, 20, 10, 60);
    insertAndSetFirstWall(head, 2, 80, 100, 130, 10);
    insertAndSetFirstWall(head, 2, 80, 80, 10, 20);
    insertAndSetFirstWall(head, 2, 80, 80, 160, 10);

    double j;
    for (i = 0; i < 50; i++)
    {
        j = i;
        insertAndSetFirstWall(head, i + 1,
                              // the most important bit is below.
                              // increase the 20 for a tighter bend
                              // descrease for a more meandering flow
                              320 + 30 * sin(10 * j * M_PI / 180),
                              // increase the 5 for a spacier curve
                              (i * 5) + 80,
                              10, 10);
    }
    for (i = 0; i < 75; i++)
    {
        j = i;
        insertAndSetFirstWall(head, i + 1,
                              // the most important bit is below.
                              // increase the 20 for a tighter bend
                              // descrease for a more meandering flow
                              240 + 30 * sin(10 * j * M_PI / 180),
                              // increase the 5 for a spacier curve
                              (i * 5) + 80,
                              10, 10);
    }
    insertAndSetFirstWall(head, 2, 345, 330, 105, 10);
    insertAndSetFirstWall(head, 2, 450, 190, 10, 150);
    insertAndSetFirstWall(head, 2, 380, 190, 70, 10);
    insertAndSetFirstWall(head, 2, 380, 20, 10, 170);
    insertAndSetFirstWall(head, 2, 380, 20, 260, 10);

    insertAndSetFirstWall(head, 2, 255, 455, 345, 10);
    insertAndSetFirstWall(head, 2, 600, 100, 10, 365);
    insertAndSetFirstWall(head, 2, 530, 100, 70, 10);
    insertAndSetFirstWall(head, 2, 530, 80, 10, 20);
    insertAndSetFirstWall(head, 2, 530, 80, 110, 10);
}

void complex_7(struct Wall_collection **head)
{
    int i;
    insertAndSetFirstWall(head, 12, 640 - 10 - 120, 450, 10, 30);
    insertAndSetFirstWall(head, 12, 640 - 10 - 220, 450, 10, 30);

    for (i = 0; i < 100; i++)
    {
        insertAndSetFirstWall(head, i, 640 - 10 - (20 + i), 350 + i, 10, 10);       //1
        insertAndSetFirstWall(head, i, 640 - 10 - (20 + 100 + i), 350 + i, 10, 10); //1
    }
    insertAndSetFirstWall(head, 12, 640 - 10 - 20, 280, 10, 70);
    insertAndSetFirstWall(head, 12, 640 - 10 - 120, 280, 10, 70);

    for (i = 0; i < 180; i++)
    {
        insertAndSetFirstWall(head, i, 640 - 10 - (20 + 190 - i / 2), 100 + i, 10, 10); //1
    }
    for (i = 0; i < 105; i++)
    {
        insertAndSetFirstWall(head, i, 640 - 10 - (20 + 105 / 2 - i / 2), 175 + i, 10, 10); //1
    }

    insertAndSetFirstWall(head, 2, 640 - 105 / 2 - 20, 175, 105 / 2, 10);
    insertAndSetFirstWall(head, 2, 640 - 10 - 20, 20, 10, 155);
    insertAndSetFirstWall(head, 2, 640 - 300 - 20, 20, 300, 10);
    insertAndSetFirstWall(head, 2, 640 - 10 - 320, 20, 10, 60);
    insertAndSetFirstWall(head, 2, 640 - 130 - 80, 100, 130, 10);
    insertAndSetFirstWall(head, 2, 640 - 10 - 80, 80, 10, 20);
    insertAndSetFirstWall(head, 2, 640 - 160 - 80, 80, 160, 10);

    double j;
    for (i = 0; i < 50; i++)
    {
        j = i;
        insertAndSetFirstWall(head, i + 1,
                              // the most important bit is below.
                              // increase the 20 for a tighter bend
                              // descrease for a more meandering flow
                              640 - 10 - (320 + 30 * sin(10 * j * M_PI / 180)),
                              // increase the 5 for a spacier curve
                              (i * 5) + 80,
                              10, 10);
    }
    for (i = 0; i < 75; i++)
    {
        j = i;
        insertAndSetFirstWall(head, i + 1,
                              // the most important bit is below.
                              // increase the 20 for a tighter bend
                              // descrease for a more meandering flow
                              640 - 10 - (240 + 30 * sin(10 * j * M_PI / 180)),
                              // increase the 5 for a spacier curve
                              (i * 5) + 80,
                              10, 10);
    }

    insertAndSetFirstWall(head, 2, 640 - 105 - 345, 330, 105, 10);
    insertAndSetFirstWall(head, 2, 640 - 10 - 450, 190, 10, 150);
    insertAndSetFirstWall(head, 2, 640 - 70 - 380, 190, 70, 10);
    insertAndSetFirstWall(head, 2, 640 - 10 - 380, 20, 10, 170);
    insertAndSetFirstWall(head, 2, 640 - 260 - 380, 20, 260, 10);

    insertAndSetFirstWall(head, 2, 640 - 345 - 255, 455, 345, 10);
    insertAndSetFirstWall(head, 2, 640 - 10 - 600, 100, 10, 365);
    insertAndSetFirstWall(head, 2, 640 - 70 - 530, 100, 70, 10);
    insertAndSetFirstWall(head, 2, 640 - 10 - 530, 80, 10, 20);
    insertAndSetFirstWall(head, 2, 640 - 110 - 530, 80, 110, 10);
}

void change_text_color(char chr)
{

    switch (chr)
    {
    case 'R':
    {

        printf("\033[1;31m");
        break;
    }
    case 'Y':
    {
        printf("\033[33;1m");
        break;
    }
    case 'G':
    {
        printf("\033[1;32m");
        break;
    }
    default:
    {
        printf("\033[0m");
    }
    }
}

char get_color_from_value(int value, int red_limit)
{
    if (value >= red_limit)
    {
        return 'R';
    }

    if (value == red_limit)
    {
        return 'Y';
    }

    return 'G';
}

int main(int argc, char *argv[])
{
    SDL_Window *window;
    SDL_Renderer *renderer;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        return 1;
    }

    window = SDL_CreateWindow("Robot Maze", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, OVERALL_WINDOW_WIDTH, OVERALL_WINDOW_HEIGHT, SDL_WINDOW_OPENGL);
    window = SDL_CreateWindow("Robot Maze", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, OVERALL_WINDOW_WIDTH, OVERALL_WINDOW_HEIGHT, SDL_WINDOW_OPENGL);
    renderer = SDL_CreateRenderer(window, -1, 0);

    struct Robot robot;
    struct Wall_collection *head = NULL;
    int front_left_sensor, front_right_sensor, side_front_sensor, side_middle_sensor = 0;
    // clock_t start_time, end_time;
    // int msec;
    struct timeval start_time, end_time;
    gettimeofday(&start_time, 0);
    unsigned long msec;

    // SETUP MAZE
    // You can create your own maze here. line of code is adding a wall.
    // You describe position of top left corner of wall (x, y), then width and height going down/to right
    // Relative positions are used (OVERALL_WINDOW_WIDTH and OVERALL_WINDOW_HEIGHT)
    // But you can use absolute positions. 10 is used as the width, but you can change this.

    complex_7(&head);

    setup_robot(&robot);
    updateAllWalls(head, renderer);
    int foundWall = 0;        // check if wall is found at least once
    int is_angle_changed = 0; // check if robot's angle has been changed at least once
    int is_calibrated = 0;
    system("color");

    SDL_Event event;
    while (!done)
    {
        SDL_SetRenderDrawColor(renderer, 201, 227, 219, 100);
        SDL_RenderClear(renderer);

        //Move robot based on user input commands/auto commands
        if (robot.auto_mode == 1)
            foundWall = robotAutoMotorMove(&robot, front_left_sensor, front_right_sensor, side_front_sensor, side_middle_sensor, foundWall, &is_angle_changed, &is_calibrated);
        robotMotorMove(&robot);

        //Check if robot reaches endpoint. and check sensor values

        //if (checkRobotReachedEnd(&robot, 640, 340, 10, 100)){             // Basic maze 1
        //if (checkRobotReachedEnd(&robot, 220, 480, 100, 10)){             // Basic maze 2
        //if (checkRobotReachedEnd(&robot, 0, 340, 10, 100)){               // Basic maze 3
        //if (checkRobotReachedEnd(&robot, 640 - 10 - 320, 480, 100, 10)){   // Basic maze 4
        //if (checkRobotReachedEnd(&robot, 640, 20, 10, 60)){               // Complex Maze 5
        //if (checkRobotReachedEnd(&robot, 120, 480, 100, 10)){               //Maze 6
        //if (checkRobotReachedEnd(&robot, 0, 20, 10, 60)){                   //Maze 7'
        if (checkRobotReachedEnd(&robot, 640 - 10 - 220, 480, 100, 10))
        { //Maze 8
            //if (checkRobotReachedEnd(&robot, OVERALL_WINDOW_WIDTH,  OVERALL_WINDOW_HEIGHT / 2 + 100, 10, 100))

            // end_time = clock();
            // msec = (end_time - start_time) * 1000 / CLOCKS_PER_SEC;
            // robotSuccess(&robot, msec);
            gettimeofday(&end_time, 0);
            msec = ((end_time.tv_sec - start_time.tv_sec) * 1000) + (end_time.tv_usec - start_time.tv_usec) / 1000;
            robotSuccess(&robot, msec);
        }
        else if (checkRobotHitWalls(&robot, head))
            robotCrash(&robot);
        //Otherwise compute sensor information
        else
        {
            front_left_sensor = checkRobotSensorFrontLeftAllWalls(&robot, head);
            if (front_left_sensor > 0)
            {
                char color_code = get_color_from_value(front_left_sensor, 2);
                change_text_color(color_code);
                printf("Getting close on the front left. Score = %d\n", front_left_sensor);
                change_text_color('W');
            }

            front_right_sensor = checkRobotSensorFrontRightAllWalls(&robot, head);
            if (front_right_sensor > 0)
            {
                char color_code = get_color_from_value(front_right_sensor, 1);
                change_text_color(color_code);
                printf("Getting close on the front right. Score = %d\n", front_right_sensor);

                change_text_color('W');
            }

            side_front_sensor = checkRobotSensorSideFrontAllWalls(&robot, head);
            if (side_front_sensor > 0)
            {
                char color_code = get_color_from_value(side_front_sensor, 3);
                change_text_color(color_code);
                printf("Getting close on the side front. Score = %d\n", side_front_sensor);
                change_text_color('W');
            }

            side_middle_sensor = checkRobotSensorSideMiddleAllWalls(&robot, head);
            if (side_middle_sensor > 0)
            {
                char color_code = get_color_from_value(side_middle_sensor, 3);
                change_text_color(color_code);
                printf("Getting close on the side. Score = %d\n", side_middle_sensor);
                change_text_color('W');
            }
        }
        robotUpdate(renderer, &robot);
        updateAllWalls(head, renderer);

        // Check for user input
        SDL_RenderPresent(renderer);
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                done = 1;
            }
            const Uint8 *state = SDL_GetKeyboardState(NULL);
            if (state[SDL_SCANCODE_UP] && robot.direction != DOWN)
            {
                robot.direction = UP;
            }
            if (state[SDL_SCANCODE_DOWN] && robot.direction != UP)
            {
                robot.direction = DOWN;
            }
            if (state[SDL_SCANCODE_LEFT] && robot.direction != RIGHT)
            {
                robot.direction = LEFT;
            }
            if (state[SDL_SCANCODE_RIGHT] && robot.direction != LEFT)
            {
                robot.direction = RIGHT;
            }
            if (state[SDL_SCANCODE_SPACE])
            {
                setup_robot(&robot);
            }
            if (state[SDL_SCANCODE_RETURN])
            {
                robot.auto_mode = 1;
                //start_time = clock();
                gettimeofday(&start_time, 0);
            }
        }

        SDL_Delay(120);
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    printf("DEAD\n");
}
