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
#include "Var.h"

using namespace std;
using namespace boost;

void lineread(string str){
    if (str[0] == '#'|| str == ""){
    return;
    }
   tokenizer<> tok(str);
    vector<string> tokens;

    for(tokenizer<>::iterator beg=tok.begin(); beg!=tok.end();++beg){
        tokens.push_back(*beg);
    }    
   
    if (tokens[0] == "Road" && tokens[1] == "Id"){
     stringstream sst(tokens[2]);
    sst>>rd.id;
    }
    if (tokens[0] == "Road" && tokens[1]=="Length"){
      stringstream sst(tokens[2]);
    sst>>rd.length;   
    }
    if (tokens[0] == "Road" && tokens[1]=="Width"){
         stringstream sst(tokens[2]);
        sst>>rd.width;
    }
    if (tokens[0] == "Road" && tokens[1]=="Signal"){
         stringstream sst(tokens[2]);
    sst>>rd.signal;
    roads.push_back(rd);
    rf++;
    }
    if (tokens[0] == "Default" && tokens[1]=="MaxSpeed"){
         stringstream sst(tokens[2]);
    sst>>def_max_speed;
    }
    if (tokens[0] == "Default" && tokens[1]=="Acceleration"){
         stringstream sst(tokens[2]);
       sst>>def_acc;
    }
    if (tokens[0] == "Vehicle" && tokens[1]=="Type"){
         stringstream sst(tokens[2]);
    sst>>vd.id;
    }
    if (tokens[0] == "Vehicle" && tokens[1]=="Length"){
     stringstream sst(tokens[2]);
    sst>>vd.length;
    }
    if (tokens[0] == "Vehicle" && tokens[1]=="Width"){
         stringstream sst(tokens[2]);
    sst>>vd.width;
    vehicles.push_back(vd);
    vhf++;
    }
    if (tokens[0] == "Vehicle" && tokens[1]=="MaxSpeed"){
         stringstream sst(tokens[2]);
    sst>>vehicles[vhf-1].speed;vehicles[vhf-1].vflag=1;
    }
    if (tokens[0] == "Vehicle_Acceleration" && tokens[1]=="Acceleration"){
     stringstream sst(tokens[2]);
    sst>>vehicles[vhf-1].acceleration;vehicles[vhf-1].aflag=1;
    }
    else if (tokens[0] == "Signal"){
         stringstream sst(tokens[1]);
        sst>>roads[rf-1].signal_color;sig=1;
        roads[rf-1].sgnlclr.push_back(roads[rf-1].signal_color);
        roads[rf-1].clrtm.push_back(clr_counter);
        clr_counter = 0;
    }
    else if(sig = 2){
        for(int i=0;i<vehicles.size();i++){
            if (vehicles[i].id == tokens[0]){
                float tmpL = (vehicles[i].length);
                float tmpW = (vehicles[i].width);

                vehicles[i].color = tokens[1];
                vehicles[i].k = kc;

                vehicles[i].length = (vehicles[i].length)*(1.0/20);
                vehicles[i].width = (vehicles[i].width)*(0.5/roads[0].width)*2.12/3;
                
                vehicles[i].vclno = vehicle_no;
                vehicle_no++;

                if (vehicles[i].vflag == 0)
                vehicles[i].speed = def_max_speed;
                  if (vehicles[i].aflag == 0)
                vehicles[i].acceleration = def_acc;
                addedAutoMob.push_back(vehicles[i]);
                clr_counter++;
                vehicles[i].length = tmpL;
                vehicles[i].width = tmpW;
               break;
            }
      }
    }
    if (tokens[0] == "Pass"){
        stringstream sst(tokens[1]);
         sst>>passtime;
         rvindex[kc] = passtime;
         kc++;
 }

}