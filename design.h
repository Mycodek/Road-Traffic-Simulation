#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
#include <vector>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
using namespace std;

void DrawCircle(float cx, float cy, float rad, int num_segments,float r,float g,float b)
{
    glColor3f(r,g,b);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx,cy);
    for(int ii = 0; ii < num_segments; ii++)
    {
        float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle

        float x = rad * cosf(theta);//calculate the x component
        float y = rad * sinf(theta);//calculate the y component

        glVertex2f(x + cx, y + cy);//output vertex

    }
    glEnd();
}

void Car(float x,float y,float l,float w,string color)
{   
    float r,g,b;
            if(color == "BLUE"){
                r = 0.0;g=0.0;b=1.0; 
            }
            if(color == "RED"){
                r = 1.0;g=0.0;b=0.0; 
            }
            if(color == "GREEN"){
                r = 0.0;g=1.0;b=0.0; 
            }
            if(color == "LIGHT BLUE"){
                r = 0.0;g=1.0;b=1.0; 
            }
            if(color == "PURPLE"){
                r = 1.0;g=0.0;b=1.0; 
            } 
            float x1,x2,x3,x4,y1,y2,y3,y4,x5,y5;
        // 1 R
            glColor3f(r,g,b);
            glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
            x1 = x-l/4;y1=y-w;
            x2= x-l/4 ;y2 = y;
            x3 = x; y3 = y-w/4;
            x4 = x; y4 = y-3*w/4;
            glBegin(GL_POLYGON);
                glVertex2f(x1,y1);
                glVertex2f(x2,y2);
                glVertex2f(x3,y3);
                glVertex2f(x4,y4); 
            glEnd();
        // 2 lb
            glColor3f(0.0, 1.0, 1.0);
            glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
            x1 = x-7*l/16;y1=y-3*w/4;
            x2 = x-7*l/16 ;y2 = y-w/4;
            x3 = x-l/4; y3 = y;
            x4 = x-l/4; y4 = y-w;
            glBegin(GL_POLYGON);
                glVertex2f(x1,y1);
                glVertex2f(x2,y2);
                glVertex2f(x3,y3);
                glVertex2f(x4,y4); 
            glEnd();
        // 3R
            glColor3f(r,g,b);
            glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

            x1 = x-13*l/16 ;y1 = y-3*w/4;
            x2 = x-13*l/16 ;y2 = y-w/4;
            x3 = x-7*l/16 ; y3 = y-w/4;
            x4 = x-7*l/16 ; y4 = y-3*w/4;

            glBegin(GL_POLYGON);
                glVertex2f(x1,y1);
                glVertex2f(x2,y2);
                glVertex2f(x3,y3);
                glVertex2f(x4,y4); 
            glEnd();
        // 4lb
            glColor3f(0.0, 1.0, 1.0);
            glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
            x1 = x-l ; y1 = y-7*w/8;
            x2 = x-l ; y2 = y-w/8;
            x3 = x-13*l/16; y3 = y-w/4;
            x4 = x-13*l/16; y4 = y-3*w/4;
            glBegin(GL_POLYGON);
                glVertex2f(x1,y1);
                glVertex2f(x2,y2);
                glVertex2f(x3,y3);
                glVertex2f(x4,y4); 
            glEnd();
        // 5db
            glColor3f(0.0, 0.0, 1.0);
            glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
            x1 = x-l;y1=y-w/8;
            x2= x-29*l/32 ;y2 = y;
            x3 = x - l/4; y3 = y;
            x4 = x - 7 * l/16; y4 = y-w/4;
            x5 = x-13*l/16 ; y5 = y - w/4;
            glBegin(GL_POLYGON);
                glVertex2f(x1,y1);
                glVertex2f(x2,y2);
                glVertex2f(x3,y3);
                glVertex2f(x4,y4);
                glVertex2f(x5,y5); 
            glEnd();
        // 6
            glColor3f(0.0, 0.0, 1.0);
            glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
            x1 = x-l;y1=y-7*w/8;
            x2=  x-13*l/16 ;y2 = y - 3*w/4;
            x3 = x - 7*l/16; y3 = y - 3*w/4;
            x4 = x - l/4; y4 = y-w;
            x5 = x -29*l/32 ; y5 = y - w;
            glBegin(GL_POLYGON);
                glVertex2f(x1,y1);
                glVertex2f(x2,y2);
                glVertex2f(x3,y3);
                glVertex2f(x4,y4);
                glVertex2f(x5,y5); 
            glEnd();
}
void Truck(float x,float y,float l,float w,string color)
{   
    float r,g,b;
            if(color == "BLUE"){
                r = 0.0;g=0.0;b=1.0; 
            }
            if(color == "RED"){
                r = 1.0;g=0.0;b=0.0; 
            }
            if(color == "GREEN"){
                r = 0.0;g=1.0;b=0.0; 
            }
            if(color == "LIGHT BLUE"){
                r = 0.0;g=1.0;b=1.0; 
            }
            if(color == "PURPLE"){
                r = 1.0;g=0.0;b=1.0; 
            } 
            float x1,x2,x3,x4,y1,y2,y3,y4,x5,y5;
        // 1 Y
            glColor3f(1.0,1.0,0.0);
            glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
            
            x1 = x-l/3;y1=y-w;
            x2 = x-l/3;y2 = y;
            x3 = x-4*l/90; y3 = y;
            x4 = x-4*l/90; y4 = y-w;
            glBegin(GL_POLYGON);
                glVertex2f(x1,y1);
                glVertex2f(x2,y2);
                glVertex2f(x3,y3);
                glVertex2f(x4,y4); 
            glEnd();
        // 2 orange
            glColor3f(1.0, 0.5, 0.0);
            glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
            x1 = x-4*l/90; y1 = y-w;
            x2 = x-4*l/90; y2 = y;
            x3 = x; y3 = y-w/10;
            x4 = x; y4 = y-9*w/10;
            glBegin(GL_POLYGON);
                glVertex2f(x1,y1);
                glVertex2f(x2,y2);
                glVertex2f(x3,y3);
                glVertex2f(x4,y4); 
            glEnd();
        // 3 light blue mirror
            glColor3f(0.0,1.0,1.0);
            glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

            x1 = x-4*l/30 ; y1 = y-4*w/5;
            x2 = x-4*l/30 ; y2 = y-w/5;
            x3 = x-8*l/90 ; y3 = y-w/10;
            x4 = x-8*l/90 ; y4 = y-9*w/10;

            glBegin(GL_POLYGON);
                glVertex2f(x1,y1);
                glVertex2f(x2,y2);
                glVertex2f(x3,y3);
                glVertex2f(x4,y4); 
            glEnd();
        // 4 cyan
            glColor3f(0.5, 1.0, 1.0);
            glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

            x2 = x-7*l/18;y2 =y-9*w/10;
            x1 = x-7*l/18;y1 = y-w/10;
            x3 = x-l/3   ; y3 = y-9*w/10;
            x4 = x-l/3   ; y4 = y-w/10;
            glBegin(GL_POLYGON);
                glVertex2f(x1,y1);
                glVertex2f(x2,y2);
                glVertex2f(x3,y3);
                glVertex2f(x4,y4); 
            glEnd();
        // 5 vehical color
            glColor3f(r,g,b);
            glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
            x2 = x-l   ; y2 = y-9*w/10;
            x1 = x-l   ; y1 = y-w/10;
            x3 = x-7*l/18;y3=y-9*w/10;
            x4 = x-7*l/18;y4 = y-w/10;
            
            glBegin(GL_POLYGON);
                glVertex2f(x1,y1);
                glVertex2f(x2,y2);
                glVertex2f(x3,y3);
                glVertex2f(x4,y4);
            glEnd();
        // 6 black
            glColor3f(0.0, 0.0, 0.0);
            glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

            x1 = x-17*l/18   ; y1 = y-3*w/10;
            x2 = x-17*l/18   ; y2 = y-w/5;
            x3 = x-4*l/9 ; y3 = y-w/5;
            x4 = x-4*l/9 ; y4 = y-3*w/10;
            
            glBegin(GL_POLYGON);
                glVertex2f(x1,y1);
                glVertex2f(x2,y2);
                glVertex2f(x3,y3);
                glVertex2f(x4,y4);
            glEnd();
        // 7 black
            glColor3f(0.0, 0.0, 0.0);
            glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

            x1 = x-17*l/18   ; y1 = y-4*w/5;
            x2 = x-17*l/18   ; y2 = y-7*w/10;
            x3 = x-4*l/9 ; y3 = y-7*w/10;
            x4 = x-4*l/9 ; y4 = y-4*w/5;
            
            glBegin(GL_POLYGON);
                glVertex2f(x1,y1);
                glVertex2f(x2,y2);
                glVertex2f(x3,y3);
                glVertex2f(x4,y4);
            glEnd();
        // 8 lilac
            glColor3f(2.0, 0.5, 1.0);
            glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

            x1 = x-l   ; y1 = y-w/10;
            x2 = x-l   ; y2 = y;
            x3 = x-l/3 ; y3 = y;
            x4 = x-l/3 ; y4 = y-w/10;
            
            glBegin(GL_POLYGON);
                glVertex2f(x1,y1);
                glVertex2f(x2,y2);
                glVertex2f(x3,y3);
                glVertex2f(x4,y4);
            glEnd();
        // 9 lilac
        glColor3f(2.0, 0.5, 1.0);
            glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

            x1 = x-l   ; y1 = y-w;
            x2 = x-l   ; y2 = y-9*w/10;
            x3 = x-l/3 ; y3 = y-9*w/10;
            x4 = x-l/3 ; y4 = y-w;
            
            glBegin(GL_POLYGON);
                glVertex2f(x1,y1);
                glVertex2f(x2,y2);
                glVertex2f(x3,y3);
                glVertex2f(x4,y4);
            glEnd(); 
}
void bike(float x,float y,float l,float w,string color){   
    float r,g,b;
            if(color == "BLUE"){
                r = 0.0;g=0.0;b=1.0; 
            }
            if(color == "RED"){
                r = 1.0;g=0.0;b=0.0; 
            }
            if(color == "GREEN"){
                r = 0.0;g=1.0;b=0.0; 
            }
            if(color == "LIGHT BLUE"){
                r = 0.0;g=1.0;b=1.0; 
            }
            if(color == "PURPLE"){
                r = 1.0;g=0.0;b=1.0; 
            } 
            float x1,x2,x3,x4,y1,y2,y3,y4,x5,y5;
        // 1 Y
            glColor3f(0.5,1.0,1.0);
            glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
            
            x1 = x-l; y1 = y-4*w/7;
            x2 = x-l; y2 = y-3*w/7;
            x3 = x;   y3 = y-3*w/7;
            x4 = x;   y4 = y-4*w/7;
            glBegin(GL_POLYGON);
                glVertex2f(x1,y1);
                glVertex2f(x2,y2);
                glVertex2f(x3,y3);
                glVertex2f(x4,y4); 
            glEnd();
        // 2 Y
            glColor3f(0.0,0.0,1.0);
            glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
            
            x1 = x-5*l/16;   y1 = y-6*w/7;
            x2 = x-5*l/16;   y2 = y-w/7;
            x3 = x-4*l/16;   y3 = y-w/7;
            x4 = x-4*l/16;   y4 = y-6*w/7;
            glBegin(GL_POLYGON);
                glVertex2f(x1,y1);
                glVertex2f(x2,y2);
                glVertex2f(x3,y3);
                glVertex2f(x4,y4); 
            glEnd();   
        // 3 circle
        // float cx = x-3*l/8;float cy = y - w/2;
        DrawCircle((x-3*l/8),(y - w/2),1.2*l/8,1000,r,g,b);
        // 4 circle
        DrawCircle((x-11*l/16),(y-w/2),3*l/16,1000,1.0,0.5,0.0);
          
}
void Auto(float x,float y,float l,float w,string color)
{   
    float r,g,b;
            if(color == "BLUE"){
                r = 0.0;g=0.0;b=1.0; 
            }
            if(color == "RED"){
                r = 1.0;g=0.0;b=0.0; 
            }
            if(color == "GREEN"){
                r = 0.0;g=1.0;b=0.0; 
            }
            if(color == "LIGHT BLUE"){
                r = 0.0;g=1.0;b=1.0; 
            }
            if(color == "PURPLE"){
                r = 1.0;g=0.0;b=1.0; 
            } 
            float x1,x2,x3,x4,y1,y2,y3,y4,x5,y5;
        // 1 Y
            glColor3f(r,g,b);
            glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
            
            x1 = x-7*l/8;y1=y-w;
            x2 = x-7*l/8;y2 = y;
            x3 = x-l/2; y3 = y;
            x4 = x-l/2; y4 = y-w;
            glBegin(GL_POLYGON);
                glVertex2f(x1,y1);
                glVertex2f(x2,y2);
                glVertex2f(x3,y3);
                glVertex2f(x4,y4); 
            glEnd();
        // 2 Y
            glColor3f(0.1,0.3,1.0);
            glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
            x1 = x-l/2; y1 = y-w;
            x2 = x-l/2; y2 = y;            
            x3 = x-2*l/6;y3=y-w/6;
            x4 = x-2*l/6;y4 = y-5*w/6;
            glBegin(GL_POLYGON);
                glVertex2f(x1,y1);
                glVertex2f(x2,y2);
                glVertex2f(x3,y3);
                glVertex2f(x4,y4); 
            glEnd();
        // 3 Y
            glColor3f(r,g,b);
            glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
            x1 = x-l/3;y1 = y-5*w/6;
            x2 = x-l/3;y2=y-w/6;
            x3 = x-l/6; y3 = y-4*w/9;
            x4 = x-l/6; y4 = y-5*w/9;            
            glBegin(GL_POLYGON);
                glVertex2f(x1,y1);
                glVertex2f(x2,y2);
                glVertex2f(x3,y3);
                glVertex2f(x4,y4); 
            glEnd();
        // 4 Y
            glColor3f(0.0,0.3,0.0);
            glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
            x1 = x-l/6; y1 = y-5*w/9; 
            x2 = x-l/6; y2 = y-4*w/9;
            x3 = x;y3 = y-4*w/9;
            x4 = x;y4 =y-5*w/9;
                      
            glBegin(GL_POLYGON);
                glVertex2f(x1,y1);
                glVertex2f(x2,y2);
                glVertex2f(x3,y3);
                glVertex2f(x4,y4); 
            glEnd(); 
        // 5 Y
            glColor3f(1.0,0.0,0.0);
            glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
            x1 = x-l; y1 = y-w/6; 
            x2 = x-l; y2 = y;
            x3 = x-3*l/4;y3 = y;
            x4 = x-3*l/4;y4 =y-w/6;
                      
            glBegin(GL_POLYGON);
                glVertex2f(x1,y1);
                glVertex2f(x2,y2);
                glVertex2f(x3,y3);
                glVertex2f(x4,y4); 
            glEnd();
        // 6 Y
            glColor3f(1.0,0.0,0.0);
            glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
            x1 = x-l; y1 = y-w; 
            x2 = x-l; y2 = y-5*w/6;
            x3 = x-3*l/4;y3 = y-5*w/6;
            x4 = x-3*l/4;y4 =y-w;
                      
            glBegin(GL_POLYGON);
                glVertex2f(x1,y1);
                glVertex2f(x2,y2);
                glVertex2f(x3,y3);
                glVertex2f(x4,y4); 
            glEnd();                    
}            
void Bus(float x,float y,float l,float w,string color)
{   
    float r,g,b;
            if(color == "BLUE"){
                r = 0.0;g=0.0;b=1.0; 
            }
            if(color == "RED"){
                r = 1.0;g=0.0;b=0.0; 
            }
            if(color == "GREEN"){
                r = 0.0;g=1.0;b=0.0; 
            }
            if(color == "LIGHT BLUE"){
                r = 0.0;g=1.0;b=1.0; 
            }
            if(color == "PURPLE"){
                r = 1.0;g=0.0;b=1.0; 
            } 
            float x1,x2,x3,x4,y1,y2,y3,y4,x5,y5;
        // 0 Y
            glColor3f(r,g,b);
            glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
            
            x1 = x-l; y1 = y-w;
            x2 = x-l; y2 = y;
            x3 = x-2*l/9; y3 = y; 
            x4 = x-2*l/9; y4 = y-w;
            glBegin(GL_POLYGON);
                glVertex2f(x1,y1);
                glVertex2f(x2,y2);
                glVertex2f(x3,y3);
                glVertex2f(x4,y4); 
            glEnd();
        // 1 Y
            glColor3f(1.0,0.8,0.7);
            glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
            
            x1 = x-2*l/9;y1= y-w;
            x2 = x-2*l/9;y2 = y;
            x3 = x; y3 = y-w/10;
            x4 = x; y4 = y-9*w/10;
            glBegin(GL_POLYGON);
                glVertex2f(x1,y1);
                glVertex2f(x2,y2);
                glVertex2f(x3,y3);
                glVertex2f(x4,y4); 
            glEnd();
        // 2 Y mirror
            glColor3f(0.1,0.0,0.9);
            glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
            x1 = x-l/3; y1 = y-9*w/10;
            x2 = x-l/3; y2 = y-w/10;
            x3 = x-2*l/9;y3 = y;
            x4 = x-2*l/9;y4 = y-w;
            glBegin(GL_POLYGON);
                glVertex2f(x1,y1);
                glVertex2f(x2,y2);
                glVertex2f(x3,y3);
                glVertex2f(x4,y4); 
            glEnd();    
        // 3 Y
            glColor3f(0.1,0.0,0.9);            
            glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
            
            x1 = x-2*l/9;y1 = y-w/10;
            x2 = x-2*l/9;y2 = y;
            x3 = x-l/3; y3 = y;
            x4 = x-l/3; y4 = y-w/10;
            
            glBegin(GL_POLYGON);
                glVertex2f(x1,y1);
                glVertex2f(x2,y2);
                glVertex2f(x3,y3);
                glVertex2f(x4,y4); 
            glEnd(); 
        // 4 Y
            glColor3f(0.1,0.0,0.9);            
            glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
            
            x2 = x-2*l/9;y2 = y-9*w/10;
            x1 = x-2*l/9;y1 = y-w;
            x3 = x-l/3; y3 = y-9*w/10;
            x4 = x-l/3; y4 = y-w;
            
            glBegin(GL_POLYGON);
                glVertex2f(x1,y1);
                glVertex2f(x2,y2);
                glVertex2f(x3,y3);
                glVertex2f(x4,y4); 
            glEnd();  
         // 5 Y
            glColor3f(0.1,0.0,0.9);            
            glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
            
            x1 = x-5*l/6; y1 = y-w;
            x2 = x-5*l/6; y2 = y-9*w/10;
            x3 = x-2*l/3; y3 = y-9*w/10; 
            x4 = x-2*l/3; y4 = y-w;
            glBegin(GL_POLYGON);
                glVertex2f(x1,y1);
                glVertex2f(x2,y2);
                glVertex2f(x3,y3);
                glVertex2f(x4,y4); 
            glEnd();
         // 6 Y
            glColor3f(0.1,0.0,0.9);    
            glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
            
            x1 = x-5*l/6; y1 = y-w/10;
            x2 = x-5*l/6; y2 = y;
            x3 = x-2*l/3; y3 = y; 
            x4 = x-2*l/3; y4 = y-w/10;
            glBegin(GL_POLYGON);
                glVertex2f(x1,y1);
                glVertex2f(x2,y2);
                glVertex2f(x3,y3);
                glVertex2f(x4,y4); 
            glEnd();
         // 7 Y
            glColor3f(0.1,0.0,0.9);            
            glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
            
            x1 = x-l; y1 = y-w;
            x2 = x-l; y2 = y-9*w/10;
            x3 = x-17*l/18; y3 = y-9*w/10; 
            x4 = x-17*l/18; y4 = y-w;
            glBegin(GL_POLYGON);
                glVertex2f(x1,y1);
                glVertex2f(x2,y2);
                glVertex2f(x3,y3);
                glVertex2f(x4,y4); 
            glEnd();
        // 8 Y
            glColor3f(0.1,0.0,0.9);            
            glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
            
            x1 = x-l; y1 = y-w/10;
            x2 = x-l; y2 = y;
            x3 = x-17*l/18; y3 = y; 
            x4 = x-17*l/18; y4 = y-w/10;
            glBegin(GL_POLYGON);
                glVertex2f(x1,y1);
                glVertex2f(x2,y2);
                glVertex2f(x3,y3);
                glVertex2f(x4,y4); 
            glEnd();                      
}            
// zebra crosing                 x
//          <------l------------->
//          |--------------------|  ^
//          |                    |  |
//          |                    |  w/n
//          |--------------------|  \
// 
void zebraLine(float x,float w,float l,float n){
    for(int i = 1; i <= n; i = i+2){
        float y= i*w/n - 0.5;
            // glColor3f(0.5, 0.3, 0.3);
            glColor3f(0.9, 0.9, 0.99);
            glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
            glBegin(GL_POLYGON);
                glVertex2f(x-l,y-w/n);
                glVertex2f(x-l,y);
                glVertex2f(x,y);
                glVertex2f(x,y-w/n);
            glEnd();
            glFlush();
    }   
} 
void sideLine(float y,float w,float l,float n){
    for(int i = 1; i <= n; i = i+2){
        float x= i*l/n-1;
            glColor3f(0.8, 0.8, 0.8);
            glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
            glBegin(GL_POLYGON);
                glVertex2f(x-l/n,y-w);
                glVertex2f(x-l/n,y);
                glVertex2f(x,y);
                glVertex2f(x,y-w);
            glEnd();
            glFlush();
    }   
}        
void hollowCircle(float cx, float cy, float r, int num_segments){
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_LINE_LOOP);
    for(int ii = 0; ii < num_segments; ii++)
    {
        float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle

        float x = r * cosf(theta);//calculate the x component
        float y = r * sinf(theta);//calculate the y component

        glVertex2f(x + cx, y + cy);//output vertex

    }
    glEnd();
}