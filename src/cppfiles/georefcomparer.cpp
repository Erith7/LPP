/*=====================================================================================================================================================
|                                                               georefcomparer.cpp
|======================================================================================================================================================
|Author: Erith Alexander Muñoz, erith7@gmail.com
|Organization: FAO-Ecuador
|version:2015.1.0
|Update: 01/06/2016
|Description: Automation of the Radiance Conversion from DN for LandSat 8 Imagery by reading the MKL file.
|Compilation Comand: g++ -std=c++11 -o georefcomparer.cpp.exe georefcomparer.cpp.cpp $(pkg-config opencv --libs)
|                   -I/usr/local/include/opencv2/ -I/usr/local/include/opencv/
|
|
======================================================================================================================================================*/
#include </usr/local/include/opencv2/core/core.hpp>
#include </usr/local/include/opencv2/highgui/highgui.hpp>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <cstring>
#include </usr/local/include/opencv2/core/types_c.h>
#include </usr/local/include/opencv2/core/core_c.h>
#include <math.h>
#include <sstream>
#include <fstream>
#include <vector>

#define PI 3.14159265
 
using namespace cv;
using namespace std;



 
int main (int argc, char *argv[])
{


  if (argc != 3)
    cout << "Uso: ./georefcomparer.exe gdalinfo_txt nombre_txt_output\n";
  else
    {

    //char ruta_directorio[200]=argv[1];

    char inputImagesPath0[200];
    char *t0=inputImagesPath0;
    t0=strcpy(t0,argv[1]);
    puts(inputImagesPath0);

    char Outputtxt[200];
    char *o8=Outputtxt;
    o8=strcpy(o8,argv[2]);
    puts(Outputtxt);

    ifstream Metadato;
    ofstream parameters_file;
    Metadato.open(inputImagesPath0);

 	//char output[100];
 	if (Metadato.is_open()) 	
		{
    cout<<"Sigo leyendo"<<endl;
		string line="";
		getline(Metadato,line);
		while(!Metadato.eof())
		{	getline(Metadato,line);
            stringstream strstr(line);
			string angleRead="";
			size_t pch1;
            pch1=line.find("PROJCS[\"WGS 84 / ");
            if(pch1 != string::npos)
            {
                int counter=pch1+17;
                angleRead=line.substr(counter,12);

        parameters_file.open(Outputtxt);
        parameters_file<<angleRead;
        parameters_file.close();

            }

        }

        }
	

	Metadato.close();

                    // Wait for a keystroke in the window


    }

    return 0;
}
