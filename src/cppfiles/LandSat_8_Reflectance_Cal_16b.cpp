/*=====================================================================================================================================================
|                                                               LandSat_8_Reflectance_Cal_16b.cpp
|======================================================================================================================================================
|Author: Erith Alexander Muñoz, erith7@gmail.com
|Organization: FAO-Ecuador
|version:2016.1.0
|Update: 11/04/2016
|Description: Automation of the TOA Reflectance Conversion from DN for LandSat 8 Imagery by reading the MKL file.
|Compilation Comand: g++ -std=c++11 -o LandSat_8_Reflectance_Cal_16b.exe LandSat_8_Reflectance_Cal_16b.cpp $(pkg-config opencv --libs)
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


  if (argc != 4)
    cout << "Uso: ./LandSat_8_Reflectance_Cal_16b.exe ruta_directorio nombre_imagen_banda_1 ruta_output\n";
  else
    {

    //char ruta_directorio[200]=argv[1];

    char inputImagesPath0[200];
    char inputImagesPath1[200];
    char inputImagesPath2[200];
    char inputImagesPath3[200];
    char inputImagesPath4[200];
    char inputImagesPath5[200];
    char inputImagesPath6[200];
    char inputImagesPath7[200];


    char *t0=inputImagesPath0;
    char *t1=inputImagesPath1;
    char *t2=inputImagesPath2;
    char *t3=inputImagesPath3;
    char *t4=inputImagesPath4;
    char *t5=inputImagesPath5;
    char *t6=inputImagesPath6;
    char *t7=inputImagesPath7;


    char OutputImagesB2[200];
    char OutputImagesB3[200];
    char OutputImagesB4[200];
    char OutputImagesB5[200];
    char OutputImagesB6[200];
    char OutputImagesB7[200];
    char OutputImagesB9[200];
    char Outputtxt[200];

    char *o2=OutputImagesB2;
    char *o3=OutputImagesB3;
    char *o4=OutputImagesB4;
    char *o5=OutputImagesB5;
    char *o6=OutputImagesB6;
    char *o7=OutputImagesB7;
    char *o9=OutputImagesB9;
    char *o8=Outputtxt;


    o2=strcpy(o2,argv[3]);
    o3=strcpy(o3,argv[3]);
    o4=strcpy(o4,argv[3]);
    o5=strcpy(o5,argv[3]);
    o6=strcpy(o6,argv[3]);
    o7=strcpy(o7,argv[3]);
    o9=strcpy(o9,argv[3]);
    o8=strcpy(o8,argv[3]);

    o2=strcat(o2,argv[2]);
    o3=strcat(o3,argv[2]);
    o4=strcat(o4,argv[2]);
    o5=strcat(o5,argv[2]);
    o6=strcat(o6,argv[2]);
    o7=strcat(o7,argv[2]);
    o9=strcat(o9,argv[2]);
    o8=strcat(o8,argv[2]);

    o2=strcat(o2,"_B2.TIF");
    o3=strcat(o3,"_B3.TIF");
    o4=strcat(o4,"_B4.TIF");
    o5=strcat(o5,"_B5.TIF");
    o6=strcat(o6,"_B6.TIF");
    o7=strcat(o7,"_B7.TIF");
    o9=strcat(o9,"_B9.TIF");
    o8=strcat(o8,"_Parameters.txt");

    puts(OutputImagesB2);
    puts(OutputImagesB3);
    puts(OutputImagesB4);
    puts(OutputImagesB5);
    puts(OutputImagesB6);
    puts(OutputImagesB7);
    puts(OutputImagesB9);
    puts(Outputtxt);


    t0=strcpy(t0,argv[1]);
    t1=strcpy(t1,argv[1]);
    t2=strcpy(t2,argv[1]);
    t3=strcpy(t3,argv[1]);
    t4=strcpy(t4,argv[1]);
    t5=strcpy(t5,argv[1]);
    t6=strcpy(t6,argv[1]);
    t7=strcpy(t7,argv[1]);

    t0=strcat(t0,argv[2]);
    t1=strcat(t1,argv[2]);
    t2=strcat(t2,argv[2]);
    t3=strcat(t3,argv[2]);
    t4=strcat(t4,argv[2]);
    t5=strcat(t5,argv[2]);
    t6=strcat(t6,argv[2]);
    t7=strcat(t7,argv[2]);

    t0=strcat(t0,"_B2.TIF");
    t1=strcat(t1,"_B3.TIF");
    t2=strcat(t2,"_B4.TIF");
    t3=strcat(t3,"_B5.TIF");
    t4=strcat(t4,"_B6.TIF");
    t5=strcat(t5,"_B7.TIF");
    t6=strcat(t6,"_B9.TIF");
    t7=strcat(t7,"_MTL.txt");

    puts(inputImagesPath0);
    puts(inputImagesPath1);
    puts(inputImagesPath2);
    puts(inputImagesPath3);
    puts(inputImagesPath4);
    puts(inputImagesPath5);
    puts(inputImagesPath6);
    puts(inputImagesPath7);

	//cout << "Me falta leer la ruta de la imagen\n";
        
	Mat image;
	
	image= imread(inputImagesPath0, IMREAD_ANYDEPTH); 

       if(! image.data )  // Check for invalid input
       {
              cout <<  "Could not open or find the image" << std::endl ;
              return -1;
       }


	//int x, y, h;
        int filas=0;
        int columnas=0;

    ifstream Metadato;
    ofstream parameters_file;
    Metadato.open(inputImagesPath7);

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
            pch1=line.find("SUN_ELEVATION = ");
            if(pch1 != string::npos)
            {
                int counter=pch1+16;
                angleRead=line.substr(counter,11);

	parameters_file.open(Outputtxt);
        parameters_file<<angleRead;
        parameters_file.close();

            }
            string MultiBand2="";
            size_t pch2;
            pch2=line.find("REFLECTANCE_MULT_BAND_2 = ");
            if(pch2 != string::npos)
            {
            int counter=pch2+26;
            MultiBand2=line.substr(counter,11);
            parameters_file.open(Outputtxt,fstream::in | fstream::out | fstream::app);
            parameters_file<<":"<<MultiBand2;
            parameters_file.close();
            }
            string AddBand2="";
            size_t pch2A;
            pch2A=line.find("REFLECTANCE_ADD_BAND_2 = ");
            if(pch2A != string::npos)
            {
            int counter=pch2A+25;
            AddBand2=line.substr(counter,11);
            parameters_file.open(Outputtxt,fstream::in | fstream::out | fstream::app);
            parameters_file<<":"<<AddBand2;
            parameters_file.close();
            }
            string MultiBand3="";
            size_t pch3;
            pch3=line.find("REFLECTANCE_MULT_BAND_3 = ");
            if(pch3 != string::npos)
            {
            int counter=pch3+26;
            MultiBand3=line.substr(counter,11);
            parameters_file.open(Outputtxt,fstream::in | fstream::out | fstream::app);
            parameters_file<<":"<<MultiBand3;
            parameters_file.close();
            }
            string AddBand3="";
            size_t pch3A;
            pch3A=line.find("REFLECTANCE_ADD_BAND_3 = ");
            if(pch3A != string::npos)
            {
            int counter=pch3A+25;
            AddBand3=line.substr(counter,11);
            parameters_file.open(Outputtxt,fstream::in | fstream::out | fstream::app);
            parameters_file<<":"<<AddBand3;
            parameters_file.close();
            }
            string Multiband4="";
            size_t pch4;
            pch4=line.find("REFLECTANCE_MULT_BAND_4 = ");
            if(pch4 != string::npos)
            {
            int counter=pch4+26;
            Multiband4=line.substr(counter,11);
            parameters_file.open(Outputtxt,fstream::in | fstream::out | fstream::app);
            parameters_file<<":"<<Multiband4;
            parameters_file.close();
            }
            string Addband4="";
            size_t pch4A;
            pch4A=line.find("REFLECTANCE_ADD_BAND_4 = ");
            if(pch4A != string::npos)
            {
            int counter=pch4A+25;
            Addband4=line.substr(counter,11);
            parameters_file.open(Outputtxt,fstream::in | fstream::out | fstream::app);
            parameters_file<<":"<<Addband4;
            parameters_file.close();
            }
            string Multiband5="";
            size_t pch5;
            pch5=line.find("REFLECTANCE_MULT_BAND_5 = ");
            if(pch5 != string::npos)
            {
            int counter=pch5+26;
            Multiband5=line.substr(counter,11);
            parameters_file.open(Outputtxt,fstream::in | fstream::out | fstream::app);
            parameters_file<<":"<<Multiband5;
            parameters_file.close();
            }
            string Addband5="";
            size_t pch5A;
            pch5A=line.find("REFLECTANCE_ADD_BAND_5 = ");
            if(pch5A != string::npos)
            {
            int counter=pch5A+25;
            Addband5=line.substr(counter,11);
            parameters_file.open(Outputtxt,fstream::in | fstream::out | fstream::app);
            parameters_file<<":"<<Addband5;
            parameters_file.close();
            }
            string Multiband6="";
            size_t pch6;
            pch6=line.find("REFLECTANCE_MULT_BAND_6 = ");
            if(pch6 != string::npos)
            {
            int counter=pch6+26;
            Multiband6=line.substr(counter,11);
            parameters_file.open(Outputtxt,fstream::in | fstream::out | fstream::app);
            parameters_file<<":"<<Multiband6;
            parameters_file.close();
            }
            string Addband6="";
            size_t pch6A;
            pch6A=line.find("REFLECTANCE_ADD_BAND_6 = ");
            if(pch6A != string::npos)
            {
            int counter=pch6A+25;
            Addband6=line.substr(counter,11);
            parameters_file.open(Outputtxt,fstream::in | fstream::out | fstream::app);
            parameters_file<<":"<<Addband6;
            parameters_file.close();
            }
            string Multiband7="";
            size_t pch7;
            pch7=line.find("REFLECTANCE_MULT_BAND_7 = ");
            if(pch7 != string::npos)
            {
            int counter=pch7+26;
            Multiband7=line.substr(counter,11);
            parameters_file.open(Outputtxt,fstream::in | fstream::out | fstream::app);
            parameters_file<<":"<<Multiband7;
            parameters_file.close();
            }
            string Addband7="";
            size_t pch7A;
            pch7A=line.find("REFLECTANCE_ADD_BAND_7 = ");
            if(pch7A != string::npos)
            {
            int counter=pch7A+25;
            Addband7=line.substr(counter,11);
            parameters_file.open(Outputtxt,fstream::in | fstream::out | fstream::app);
            parameters_file<<":"<<Addband7;
            parameters_file.close();
            }
            string Multiband9="";
            size_t pch9;
            pch9=line.find("REFLECTANCE_MULT_BAND_9 = ");
            if(pch9 != string::npos)
            {
            int counter=pch9+26;
            Multiband9=line.substr(counter,11);
            parameters_file.open(Outputtxt,fstream::in | fstream::out | fstream::app);
            parameters_file<<":"<<Multiband9;
            parameters_file.close();
            }
            string Addband9="";
            size_t pch9A;
            pch9A=line.find("REFLECTANCE_ADD_BAND_9 = ");
            if(pch9A != string::npos)
            {
            int counter=pch9A+25;
            Addband9=line.substr(counter,11);
            parameters_file.open(Outputtxt,fstream::in | fstream::out | fstream::app);
            parameters_file<<":"<<Addband9;
            parameters_file.close();
            }

        }

        }

		
        ifstream infile;
        infile.open(Outputtxt);
        if (infile.is_open())
                {cout<<"Paso 1: El fichero de entrada ha sido reconocido...\n"<<endl;//Si se lee el archivo de entrada, se notifica
            string line2 = "";//Se define una variable ¨String¨ para almacenar la lectura de cada linea de infile
            vector<string> all_words;//Pendiente
            while (getline(infile,line2))  //Mientras se lean lineas en infile (Cada linea de inline se almacena en la variable
                                                  //infile)
                    {
                    stringstream strstr(line2); //Se almacena la variable line en la variable strstr
                    string word = "";

                            while (getline(strstr,word, ':'))//Se lee toda strst hasta llegar al simbolo ":", y se almacena lo leido en la vari
                            {                                //able  "word"
                                all_words.push_back(word);// Cada palabra word, se va agregando al vector string "all_words"
                            }

                            float angle=stof(all_words[0].c_str());
                            float MB2=stof(all_words[1].c_str());
                            float A2=stof(all_words[8].c_str());
                            float MB3=stof(all_words[2].c_str());
                            float A3=stof(all_words[9].c_str());
                            float MB4=stof(all_words[3].c_str());
                            float A4=stof(all_words[10].c_str());
                            float MB5=stof(all_words[4].c_str());
                            float A5=stof(all_words[11].c_str());
                            float MB6=stof(all_words[5].c_str());
                            float A6=stof(all_words[12].c_str());
                            float MB7=stof(all_words[6].c_str());
                            float A7=stof(all_words[13].c_str());
                            float MB8=stof(all_words[7].c_str());
                            float A8=stof(all_words[14].c_str());


        infile.close();
	Metadato.close();


    cout<<"Prueba"<<"MB2=  "<<MB2<<endl;
    cout<<"Prueba"<<"A2=  "<<A2<<endl;
    cout<<"Prueba"<<"angle=  "<<angle<<endl;
    float result = sin (angle*PI/180);
    float result2= 1/result;
    cout<<"Prueba"<<"Result=  "<<result<<endl;
    //float result = sin (angle);
    filas=image.size().height;
    columnas=image.size().width;


//=========================================================================================
// Calibracion de Banda 1
//=========================================================================================
    Mat image1(filas,columnas,CV_64F);
    image1= imread(inputImagesPath0, IMREAD_ANYDEPTH);
    Mat dimage1;
    image1.convertTo(dimage1, CV_64F);
    cout<<"El tipo de Mat para dimage1 es:   "<<dimage1.type()<<endl;
    Mat image11(filas,columnas,CV_64F);
    image11=(dimage1*MB2+A2)*result2;
    if( image11.type() != 6 ){ throw std::runtime_error("Image type must be CV_64F"); }
    image1.release();
    dimage1.release();
	double minVal11; 
	double maxVal11; 
	Point minLoc11; 
	Point maxLoc11;
	minMaxLoc( image11, &minVal11, &maxVal11, &minLoc11, &maxLoc11 );
	image11=255*(image11-minVal11)/(maxVal11-minVal11);
    imwrite(OutputImagesB2,image11);// it will store the image in name "result.jpg"
	image11.release();


//=========================================================================================
// Calibracion de Banda 2
//=========================================================================================
    Mat image2(filas,columnas,CV_64F);
    image2= imread(inputImagesPath1, IMREAD_ANYDEPTH);
    Mat dimage2;
    image2.convertTo(dimage2, CV_64F);
    cout<<"El tipo de Mat para dimage2 es:   "<<dimage2.type()<<endl;
    Mat image22(filas,columnas,CV_64F);
    image22=(dimage2*MB3+A3)*result2;
    if( image22.type() != 6 ){ throw std::runtime_error("Image type must be CV_64F"); }
    image2.release();
    dimage2.release();	
 double minVal22; 
	double maxVal22; 
	Point minLoc22; 
	Point maxLoc22;
	minMaxLoc( image22, &minVal22, &maxVal22, &minLoc22, &maxLoc22 );
	image22=255*(image22-minVal22)/(maxVal22-minVal22);
    imwrite(OutputImagesB3,image22);// it will store the image in name "result.jpg"
	image22.release();

//=========================================================================================
// Calibracion de Banda 3
//=========================================================================================
    Mat image3(filas,columnas,CV_64F);
    image3= imread(inputImagesPath2, IMREAD_ANYDEPTH);
    Mat dimage3;
    image3.convertTo(dimage3, CV_64F);
    cout<<"El tipo de Mat para dimage3 es:   "<<dimage3.type()<<endl;
    Mat image33(filas,columnas,CV_64F);
    image33=(dimage3*MB4+A4)*result2;
    if( image33.type() != 6 ){ throw std::runtime_error("Image type must be CV_64F"); }
    image3.release();
    dimage3.release();	
   double minVal33; 
	double maxVal33; 
	Point minLoc33; 
	Point maxLoc33;
	minMaxLoc( image33, &minVal33, &maxVal33, &minLoc33, &maxLoc33 );
	image33=255*(image33-minVal33)/(maxVal33-minVal33);
    imwrite(OutputImagesB4,image33);// it will store the image in name "result.jpg"
	image33.release();

//=========================================================================================
// Calibracion de Banda 4
//=========================================================================================
    Mat image4(filas,columnas,CV_64F);
    image4= imread(inputImagesPath3, IMREAD_ANYDEPTH);
    Mat dimage4;
    image4.convertTo(dimage4, CV_64F);
    cout<<"El tipo de Mat para dimage4 es:   "<<dimage4.type()<<endl;
    Mat image44(filas,columnas,CV_64F);
    image44=(dimage4*MB5+A5)*result2;
    if( image44.type() != 6 ){ throw std::runtime_error("Image type must be CV_64F"); }
    image4.release();
    dimage4.release();	
   double minVal44; 
	double maxVal44; 
	Point minLoc44; 
	Point maxLoc44;
	minMaxLoc( image44, &minVal44, &maxVal44, &minLoc44, &maxLoc44 );
	image44=255*(image44-minVal44)/(maxVal44-minVal44);
    imwrite(OutputImagesB5,image44);// it will store the image in name "result.jpg"
	image44.release();
//=========================================================================================
// Calibracion de Banda 5
//=========================================================================================
    Mat image5(filas,columnas,CV_64F);
    image5= imread(inputImagesPath4, IMREAD_ANYDEPTH);
    Mat dimage5;
    image5.convertTo(dimage5, CV_64F);
    cout<<"El tipo de Mat para dimage5 es:   "<<dimage5.type()<<endl;
    Mat image55(filas,columnas,CV_64F);
    image55=(dimage5*MB6+A6)*result2;
    if( image55.type() != 6 ){ throw std::runtime_error("Image type must be CV_64F"); }
    image5.release();
    dimage5.release();	
   double minVal55; 
	double maxVal55; 
	Point minLoc55; 
	Point maxLoc55;
	minMaxLoc( image55, &minVal55, &maxVal55, &minLoc55, &maxLoc55 );
	image55=255*(image55-minVal55)/(maxVal55-minVal55);
    imwrite(OutputImagesB6,image55);// it will store the image in name "result.jpg"
	image55.release();

//=========================================================================================
// Calibracion de Banda 6
//=========================================================================================
    Mat image6(filas,columnas,CV_64F);
    image6= imread(inputImagesPath5, IMREAD_ANYDEPTH);
    Mat dimage6;
    image6.convertTo(dimage6, CV_64F);
    cout<<"El tipo de Mat para dimage6 es:   "<<dimage6.type()<<endl;
    Mat image66(filas,columnas,CV_64F);
    image66=(dimage6*MB7+A7)*result2;
    if( image66.type() != 6 ){ throw std::runtime_error("Image type must be CV_64F"); }
    image6.release();
    dimage6.release();	
  double minVal66; 
	double maxVal66; 
	Point minLoc66; 
	Point maxLoc66;
	minMaxLoc( image66, &minVal66, &maxVal66, &minLoc66, &maxLoc66 );
	image66=255*(image66-minVal66)/(maxVal66-minVal66);
    imwrite(OutputImagesB7,image66);// it will store the image in name "result.jpg"
	image66.release();

//=========================================================================================
// Calibracion de Banda 7
//=========================================================================================
    Mat image7(filas,columnas,CV_64F);
    image7= imread(inputImagesPath6, IMREAD_ANYDEPTH);
    Mat dimage7;
    image7.convertTo(dimage7, CV_64F);
    cout<<"El tipo de Mat para dimage7 es:   "<<dimage7.type()<<endl;
    Mat image77(filas,columnas,CV_64F);
    image77=(dimage7*MB8+A8)*result2;
    if( image77.type() != 6 ){ throw std::runtime_error("Image type must be CV_64F"); }
    image7.release();
    dimage7.release();	
   double minVal77; 
	double maxVal77; 
	Point minLoc77; 
	Point maxLoc77;
	minMaxLoc( image77, &minVal77, &maxVal77, &minLoc77, &maxLoc77 );
	image77=255*(image77-minVal77)/(maxVal77-minVal77);
    imwrite(OutputImagesB9,image77);// it will store the image in name "result.jpg"
	image77.release();




     waitKey(0);
            }}
                     // Wait for a keystroke in the window
       return 0;

}

}
