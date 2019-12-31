#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
#include <vector>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
#include "parser.h"
#include "design.h"
using namespace std;
int ty = 0;

void RenderString(float x, float y, void *font, const char* str,float r,float g,float b){  
  glColor3f(r,g,b); 
  glRasterPos2f(x, y);
  int len = (int)strlen(str);
    for (int i = 0; i < len; i++)
    {
         glutBitmapCharacter(font, (int)str[i]);
    }
}

void roadprint()
{
    // road
    glClearColor(0.2, 0.5, 0.1, 0.3);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.2, 0.2, 0.2);
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glBegin(GL_POLYGON);
        glVertex2f(-1.0, -0.5);
        glVertex2f(-1.0, 0.5);
        glVertex2f(1.0, 0.5);
        glVertex2f(1.0, -0.5); 
    glEnd();
   
// ///////////////////////////////////////////////
RenderString(0.35,0.8, GLUT_BITMAP_TIMES_ROMAN_24, "Current Clock Time :",0.0,0.0,0.0);
std::stringstream ss2;
    ss2 << clockTime;
string er5 = ss2.str();
const char * c4 = er5.c_str();
RenderString(0.6,0.8, GLUT_BITMAP_TIMES_ROMAN_24,c4,0.0,0.0,0.0);
RenderString(0.64,0.8, GLUT_BITMAP_TIMES_ROMAN_24, ":",0.0,0.0,0.0);
std::stringstream ss3;
    ss3 << t%60;
string er3 = ss3.str();
const char * c3 = er3.c_str();
RenderString(0.655,0.8, GLUT_BITMAP_TIMES_ROMAN_24,c3,0.0,0.0,0.0);

hollowCircle(0.7,-0.825,0.16,1000);
hollowCircle(0.7,-0.825,0.18,1000);
RenderString(0.6,-0.78, GLUT_BITMAP_TIMES_ROMAN_24, "Traffic Simulator",0.0,0.0,0.0);
RenderString(0.6,-0.85, GLUT_BITMAP_TIMES_ROMAN_24, "By : kailash kumawat",0.0,0.0,0.0);
RenderString(0.616,-0.9, GLUT_BITMAP_TIMES_ROMAN_24, "     Ravneesh kumar",0.0,0.0,0.0);
if(acc)
    RenderString(-0.3,0.55, GLUT_BITMAP_TIMES_ROMAN_24, "Accident happened",0.8,0.8,0.8);

if(acc && ty <= 100){
    RenderString(-0.3,0.55, GLUT_BITMAP_TIMES_ROMAN_24, "Accident happened",1.0,0.0,0.0);
    ty++;
}
RenderString(-0.7,0.7, GLUT_BITMAP_TIMES_ROMAN_24, "VehicleInConfigFile :",1.0,1.0,1.0);
std::stringstream ss43;
    ss43 << addedAutoMob.size();
string er34 = ss43.str();
const char * c34 = er34.c_str();
RenderString(-0.45,0.7, GLUT_BITMAP_TIMES_ROMAN_24,c34,1.0,0.5,0.5);    

std::stringstream sn2;
    sn2 << extraAdd;
string ewr3 = sn2.str();
const char * ce3 = ewr3.c_str();    
RenderString(-0.7,0.6, GLUT_BITMAP_TIMES_ROMAN_24, "ExtraAddedVehicle :",0.8,1.0,1.0);
RenderString(-0.45,0.6, GLUT_BITMAP_TIMES_ROMAN_24,ce3,1.0,1.0,1.0);    

std::stringstream ss;
    ss << vCount;
string er = ss.str();
const char * c = er.c_str();
RenderString(-0.7,0.8, GLUT_BITMAP_TIMES_ROMAN_24, "vehical passed",1.0,1.0,1.0);
RenderString(-0.5,0.8, GLUT_BITMAP_TIMES_ROMAN_24,c,1.0,0.6,0.6);

sideLine(0.5,0.02,2,80);

sideLine(0.245,0.0075,2,40);

sideLine(0.01,0.02,2,60);

sideLine(-0.245,0.0075,2,40);

sideLine(-0.48,0.02,2,80);

zebraLine(0.04,1,0.055,50);

// DrawCircle(0.0, 0.0, 0.5, 1000);
float r,g,b;
if(cls) {r=1.0;g=0.0;b=0.0;}
else {r=0.0;g=1.0;b=0.0;}
DrawCircle(0.1, 0.7, 0.1, 1000,r,g,b);


// /////////////////////////////////////////////////
// lane
    // float p;
    // for(int i=1;i<roads[0].width;i++){
    //     p = i*(1.0/roads[0].width) - 0.5;
    //      glColor3f(0.0, 0.0, 1.0);
    //     glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    //     glBegin(GL_LINES);
    //         glVertex2f(1.0,p);
    //         glVertex2f(-1.0,p);
    //     glEnd();
    //     glFlush();
    // }
// /////////////////////////////////////////////////
    for(int i=0;i<automob.size();i++){
        float r,g,b;
        float x = automob[i].pox;
        float y = automob[i].poy;
        float l = automob[i].length;
        float w = automob[i].width; 
        // cout<<"i ="<<i<<": "<<x<<","<<y<<"|";
        
        if (automob[i].id == "Car"){
            Car(x,y,l,w,automob[i].color);
        }
        else if (automob[i].id == "Truck"){
            Truck(x,y,l,w,automob[i].color);
        }
        else if (automob[i].id == "bike"){
            bike(x,y,l,w,automob[i].color);
        }
        else if (automob[i].id == "Auto"){
            Auto(x,y,l,w,automob[i].color);
        }
        else if (automob[i].id == "Bus"){
            Bus(x,y,l,w,automob[i].color);
            RenderString(x-2*l/2.5,y-w/2, GLUT_BITMAP_TIMES_ROMAN_24,"City Bus",1.0,1.0,1.0);
        }
        // if(true){
        else{   
            if(automob[i].color == "BLUE"){
                r = 0.0;g=0.0;b=1.0; 
            }
            if(automob[i].color == "RED"){
                r = 1.0;g=0.0;b=0.0; 
            }
            if(automob[i].color == "GREEN"){
                r = 0.0;g=1.0;b=0.0; 
            }
            if(automob[i].color == "LIGHTBLUE"){
                r = 0.0;g=1.0;b=1.0; 
            }
            if(automob[i].color == "PURPLE"){
                r = 1.0;g=0.0;b=1.0; 
            }
            glColor3f(r,g,b);
            glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
            glBegin(GL_POLYGON);
            glVertex2f((x-automob[i].length),(y-automob[i].width)); 
            glVertex2f((x-automob[i].length),y);
            glVertex2f(x,y);
            glVertex2f(x,(y-automob[i].width));
            glEnd();
            // glColor3f(r,g,b);
            // glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
            // glBegin(GL_POLYGON);
            // glVertex2f((x-automob[i].length),(y-automob[i].width+0.008)); 
            // glVertex2f((x-automob[i].length),y-0.008);
            // glVertex2f(x,y-0.008);
            // glVertex2f(x,(y-automob[i].width+0.008));
            // glEnd();
            }
    }
}


