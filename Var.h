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
#include <boost/lexical_cast.hpp>

using namespace std;
using namespace boost;


class vehicle {
    public:
    float length,width,lcf;
    int k;
    float speed;
    float speedT =0;
    float pox = -1.0;
    float poy;
    float acceleration ;
    int vflag = 0;int aflag =0;
    string color,id;
    int ln;
    int tr =0;
    int vclno;
    bool behindX = true;
    bool movdn = true;
    float Yvelocity = 0;
};

vector<vehicle> automob;

vector<vehicle> addedAutoMob;


int lon;
int kc =0;
int t=0;
int clockTime = 0;
int clr_counter = 0;
int vehicle_no = 0;
bool acc = false;
int vCount = 0;
int accCount = 0;

float Default_MaxSpeed = 1;
float Default_Acceleration = 1;
int passtime;
int counter = 0;
bool cls;
int timeStamp=0;
int sgclr =0;
int extraAdd = 0;




class road{
    public:
    string id;
    float length; 
    float width;
    float signal;
    vector<string> sgnlclr;
    vector<int> clrtm;
    string signal_color;           
};
float def_max_speed,def_acc;
vector<road>  roads;
vector<vehicle>  vehicles;
vector<int> rvindex(20); 
int rf =0;int vhf=0;int sig =0;
road rd;
vehicle vd;
int tl = 0;
