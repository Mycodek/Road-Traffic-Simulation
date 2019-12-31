#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
#include<sstream>
#include<string>
#include <vector>
#include <bits/stdc++.h>
#include<boost/tokenizer.hpp>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <GL/gl.h>
#include "simulate.h"
#include <boost/lexical_cast.hpp>


using namespace std;
using namespace boost;

vector<vector<char>> Troad (100,vector<char>(1000));

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    roadprint();
    glutSwapBuffers ();
}
//////////////////
void clearElement(){
    for(int j=0;j<automob.size();j++){
        if((automob[j].pox-automob[j].length)>1.2)
            automob.erase(automob.begin()+j);
    }    
}      
/////////////////
void modifiedArr(){
    int wid = static_cast<int>(roads[0].width);
    for(int j=0;j<automob.size();j++){
        float w1 = automob[j].pox; float z1 = automob[j].poy;
        float w2 = automob[j].pox-automob[j].length ; float z2 = automob[j].poy-automob[j].width ;
        int x1 = static_cast<int>(w1*10+10);
        int y1 = static_cast<int>(z1*10+10);
        int s = static_cast<int>(roads[0].signal);
        // cout<<x1<<" "<<y1<<"   ";
        if(x1 == s && cls) Troad[x1][y1] = '|';
        else if(automob[j].id == "Car")  Troad[x1][y1] = 'C';
        else if(automob[j].id == "bike")  Troad[x1][y1] = 'b';
        else if(automob[j].id == "Bus")  Troad[x1][y1] = 'B';
        else if(automob[j].id == "Truck")  Troad[x1][y1] = 'T';
    }
} 
void printroad(){
    modifiedArr();
    int l = static_cast<int>(roads[0].length);
    int w = static_cast<int>(roads[0].width);
        int s = static_cast<int>(roads[0].signal);
    cout<<s;
    for(int i=0;i<l;i++)
        cout<<'-';
    cout<<endl;    
    for(int i=0;i<w;i++){
        for(int j=0;j<l;j++){
            if(j == s && cls) cout<<'|';
            else cout<<Troad[i][j];
        }
        cout<<endl;
    }
    for(int i=0;i<l;i++)
        cout<<'-';
    cout<<endl;    
}
float lcf(int i){
    if(automob[i].id == "Car") return 0.7;
    else if(automob[i].id == "bike") return 0.9;
    else if(automob[i].id == "Bus") return 0.5;
    else if(automob[i].id == "Truck") return 0.5;
    else if(automob[i].id == "Auto") return 1.2;
    return 0;
}

float minimum(float a,float b){
    if(a<=b) return a;
    else b;
}  
int CaseIs(float x1,float x2,float w1,float w2){
    if(w1==x1&&w2==x2) return 1;
    if(x1==w2) return 2;
    if(w1==x2) return 3;
    if(w1<x1&&w1>x2&&w2>x2) return 4;
    if(w1>x1&&w2<x1&&w2>x2) return 5;
    if(w1<x1&&w1>x2&&w2<x2) return 6;
    if(w1>x1&&w2<x2) return 7;
    if(w2>x1) return 8;
    if(w1<x2) return 9;
    if(w1==x1&&w2>x2) return 10;
    if(w2==x2&&w1<x1) return 11;
    return 0;
}
float MinSepXbackward(int index){
    float x1 = automob[index].pox; float y1 = automob[index].poy;
    float x2 = automob[index].pox-automob[index].length ; float y2 = automob[index].poy-automob[index].width ;
    float min = 100;
    for(int j=0;j<automob.size()&&j!=index;j++){
        float w1 = automob[j].pox; float z1 = automob[j].poy;
        float w2 = automob[j].pox-automob[j].length ; float z2 = automob[j].poy-automob[j].width ;
        if(x2>=w1){
            if(y1<=z2 || y2 >= z1);
            // else if( y1>z2 && y1<z1 || (y1<=z1 && y2>=z2)||(y1>z1 && y2<z2) || y2>z2 && y2 <z1)
            else{
                if(min > (x2 - w1))
                    min = (x2-w1);
            }
        }
    }
    return min;
}
bool checkonto(int index){
    float x1 = automob[index].pox; float y1 = automob[index].poy;
    float x2 = automob[index].pox-automob[index].length ; float y2 = automob[index].poy-automob[index].width ;
    for(int j=0;j<automob.size()&&j!=index;j++){
        float w1 = automob[j].pox; float z1 = automob[j].poy;
        float w2 = automob[j].pox-automob[j].length ; float z2 = automob[j].poy-automob[j].width ;
        if(z2>y1+0.00005||w2>x1+0.00005||z1<y2-0.00005||w1<x2-0.00005);        
        else{
            acc = true;
            ty = 0;
            return true;
            }
        }
    return false;
}
void clearOnto(int index){
    float x1 = automob[index].pox; float y1 = automob[index].poy;
    float x2 = automob[index].pox-automob[index].length ; float y2 = automob[index].poy-automob[index].width ;
    for(int j=0;j<automob.size()&&j!=index;j++){
        float w1 = automob[j].pox; float z1 = automob[j].poy;
        float w2 = automob[j].pox-automob[j].length ; float z2 = automob[j].poy-automob[j].width ;
        if(z2>y1+0.00005||w2>x1+0.00005||z1<y2-0.00005||w1<x2-0.00005);
        else {
            int t=MinSepXbackward(index);
            // if(t > 0.002){
                if(x1>w1){
                    automob[j].pox = automob[j].pox - 0.001;
                    automob[j].speedT = 0;
                }
                else{
                    automob[index].pox = automob[index].pox - 0.001;
                    automob[index].speedT = 0;
                }
            // }
        }
    }
}
float MinSepX(int index){
    float x1 = automob[index].pox; float y1 = automob[index].poy;
    float x2 = automob[index].pox-automob[index].length ; float y2 = automob[index].poy-automob[index].width ;
    float min = 100;
    for(int j=0;j<automob.size()&&j!=index;j++){
        float w1 = automob[j].pox; float z1 = automob[j].poy;
        float w2 = automob[j].pox-automob[j].length ; float z2 = automob[j].poy-automob[j].width ;
        if(w2>=x1){
            if(y1<=z2-0.0001 || y2 >= z1+0.0001);
            // else if( y1>z2 && y1<z1 || (y1<=z1 && y2>=z2)||(y1>z1 && y2<z2) || y2>z2 && y2 <z1)
            else{
                if(min > (w2 - x1))
                    min = (w2-x1);
            }
        }
    }
    if(cls && min > (-1)*x1 && x1 < 0.0 && automob[index].id == "bike") min = (-1)*x1+0.008;
    else if(cls && min > (-1)*x1 && x1 < 0.0) min = (-1)*x1;
    return min;
}
float MinimumSepdown(int ind){
    float min = 100;
    float x1 = automob[ind].pox; float y1 = automob[ind].poy;
    float x2 = automob[ind].pox-automob[ind].length ; float y2 = automob[ind].poy-automob[ind].width ;
    //if(y2 <= -0.485) return 0;
    for(int j=0;j<automob.size();j++){
        if(j==ind && j < automob.size()-1){
            j++;
        }
        float w1 = automob[j].pox; float z1 = automob[j].poy;
        float w2 = automob[j].pox-automob[j].length ; float z2 = automob[j].poy-automob[j].width ;
        int c = CaseIs(x1,x2,w1,w2);
        if(c == 1||c==4||c==5||c==6||c==7||c==10||c==11){
            if(z1 <= y2){
                if(min > y2-z1) {min = y2-z1;}
            }
        }  
    }
    if(min > (y2+0.5)){return y2+0.5;}
    return min;
}

float MinimumSepUp(int ind){
    float min = 100;
    float x1 = automob[ind].pox; float y1 = automob[ind].poy;
    float x2 = automob[ind].pox-automob[ind].length ; float y2 = automob[ind].poy-automob[ind].width ;
   // if(y1 >= 0.485) return 0;
    for(int j=0;j<automob.size() ;j++){
        if(j==ind && j < automob.size()-1){
            j++;
        }
        float w1 = automob[j].pox; float z1 = automob[j].poy;
        float w2 = automob[j].pox-automob[j].length ; float z2 = automob[j].poy-automob[j].width ;
        int c = CaseIs(x1,x2,w1,w2);
        if(c == 1||c==4||c==5||c==6||c==7||c==10||c==11){
            if(y1 <= z2+0.001){
                if(min > z2-y1) min = z2-y1;
            }
        } 
    }
    if(min > 0.5-y1) return 0.5-y1;
    return min;
}

void updatesY(){
    for(int i=0;i<automob.size();i++){
        float x1 = automob[i].pox; float y1 = automob[i].poy;
        float x2 = automob[i].pox-automob[i].length ; float y2 = automob[i].poy-automob[i].width ;
        if(MinSepX(i) == (-1)*x1);
        // else if(checkonto(i));
        // else 
        else if(MinSepX(i)<0.5){  
            if(automob[i].movdn){
                if(MinimumSepdown(i)>0.0089){   
                        automob[i].Yvelocity=automob[i].Yvelocity+MinimumSepdown(i)*0.001*lcf(i);
                        automob[i].poy=automob[i].poy-automob[i].Yvelocity*0.01;
                    }
                else {
                    automob[i].Yvelocity = 0.001;
                    automob[i].movdn=false;
                    } 
             }
            else{
                if(MinimumSepUp(i)>0.0089){   
                        automob[i].Yvelocity=automob[i].Yvelocity+MinimumSepUp(i)*0.001*lcf(i);
                        automob[i].poy=automob[i].poy+automob[i].Yvelocity*0.01;
                    }
                else{
                    automob[i].Yvelocity = 0.001;                    
                    automob[i].movdn =true;
                    }
                }
            }   
        }    
}
void updateX(){
    for(int i=0;i<automob.size();i++){
        string name = automob[i].id;
        float x1 = automob[i].pox; float y1 = automob[i].poy;
        float x2 = automob[i].pox-automob[i].length ; float y2 = automob[i].poy-automob[i].width ;
        if(automob[i].behindX && x1 >= 0){
            vCount++;
            automob[i].behindX = false;
        }
        if(checkonto(i)){
            clearOnto(i);
        }
        // else if(cls && MinSepX(i) <= 0.04 && x1 >= 0 && automob[i].id!= "bike");
        // else if(cls && x1 <= 0.002 && x1 >= -0.002 && automob[i].id== "bike");
        else{
            float min = MinSepX(i);
            if(min >= 0.09){
                automob[i].speedT =minimum(automob[i].speedT + automob[i].acceleration*(0.01),automob[i].speed);
                automob[i].pox = x1 + automob[i].speedT*(0.008);
            }
            else if(min >= 0.01){
                automob[i].speedT =minimum(automob[i].speedT + automob[i].acceleration*(0.01),automob[i].speed);
                automob[i].pox = x1 + automob[i].speedT*(min)*(0.08);
                }
            else  {
                automob[i].speedT = 0;
            }    
        }       
    }
}
void addVehicle(char x){
    for(int i=0;i<vehicles.size();i++){
            if (vehicles[i].id[0] == x){
                float tmpL = (vehicles[i].length);
                float tmpW = (vehicles[i].width);

                vehicles[i].color = "RED";
                vehicles[i].k = 0;

                vehicles[i].length = (vehicles[i].length)*(1.0/20);
                vehicles[i].width = (vehicles[i].width)*(0.5/roads[0].width)*2.12/3;
                
                vehicles[i].vclno = vehicle_no;
                vehicle_no++;

                if (vehicles[i].vflag == 0)
                vehicles[i].speed = def_max_speed;
                  if (vehicles[i].aflag == 0)
                vehicles[i].acceleration = def_acc;
                automob.push_back(vehicles[i]);
                vehicles[i].length = tmpL;
                vehicles[i].width = tmpW;
                extraAdd++;
                break;
            }
    }
    int tu = static_cast<int>(roads[0].width);
    int ln = rand() % tu;
    // cout<<ln<<" "<<endl;
    float ycordi = ln*(1.0/roads[0].width) - 0.5;
    if(ycordi == -0.5){
        automob[automob.size()-1].ln = roads[0].width;
        automob[automob.size()-1].poy = 0.485;
    }
    else{
        automob[automob.size()-1].ln = ln;
        automob[automob.size()-1].poy = ycordi;
    }
}

////////////////
void keyboard(unsigned char key,int x,int y){
    if(key == ' '){
        exit(0);
    }
    if(key == 'r'){
        cls = true;
    }
    if(key == 'g'){
        cls = false;
    }
    if(key == 'C'||key == 'B'||key == 'b'||key == 'A'||key == 'T') addVehicle(key);
}

void spinDisplay ()        // ORIGINAL FUNCTION
{
    // if(t<5000){
        if(t%100 == 0){
        clockTime++;
            // printroad();
        if(timeStamp == 0){
            if(roads[0].clrtm[tl]==sgclr){ 
                sgclr = 0;
                if(roads[0].sgnlclr[tl] == "RED") cls = true;
                else cls = false;
                tl++;
            }
            vehicle v = addedAutoMob[counter];
            int tu = static_cast<int>(roads[0].width);
            int ln = rand() % tu;
            // cout<<ln<<" "<<endl;
            float ycordi = ln*(1.0/roads[0].width) - 0.5;
            if(ycordi == -0.5){
                addedAutoMob[counter].ln = roads[0].width;
                addedAutoMob[counter].poy = 0.485;
            }
            else{
                addedAutoMob[counter].ln = ln;
                addedAutoMob[counter].poy = ycordi;
            }
            // cout<<v.poy<<" "<<endl;
            sgclr ++;
            automob.push_back(addedAutoMob[counter]);
            counter++;
            if(v.k != 0){
                timeStamp = rvindex[v.k-1];
                rvindex[v.k-1] = 0;
            } 
        }
        else timeStamp--;
    }
    // MinimumSepdown(456);
    updateX();
    updatesY();
    // if(automob.size()>0)
        clearElement();
    // else return;    
    t++;
    glutPostRedisplay(); 
    glutKeyboardFunc(keyboard);   
    // }
}

void myinit ()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glColor3f(1.0, 0.0, 1.0);
    glShadeModel (GL_SMOOTH);
}

int main (int argc , char* argv[]){
    if (sig ==1 ){
        sig =2;
    }
    ifstream sim("configuration.ini");
    string line;
    while (getline (sim,line)){
    lineread(line);
    }
    glutInit(&argc,argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(10000,1000);
    glutInitWindowPosition(200,200);
    glutCreateWindow("Road");
    myinit ();
    glutDisplayFunc(display);
    glutIdleFunc (spinDisplay);
    glutMainLoop();
}