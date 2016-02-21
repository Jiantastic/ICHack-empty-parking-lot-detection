//#include <cv.h>
//#include "/usr/include/opencv2/opencv.hpp"
//#include "/usr/include/opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <math.h>
//#include "/usr/include/opencv/highgui.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>

using namespace cv;
using namespace std;

string get_input_filename(const int& idx);
string get_output_filename(const int& idx);
void saveMatToCsv(const Mat& matrix, const string& filename);


int main( int argc, char** argv ){

 //char* imageName = argv[1];
  int i=atoi(argv[1]);

    Mat src_im, dst_im;

    // Load Image
    src_im = imread( get_input_filename(i), 1 );
    cout<<get_input_filename(i)<<endl;
    if( argc != 2 || !src_im.data ){
      printf( " No image data \n " );
      return -1;
    }

    int rows = src_im.rows;
    int cols = src_im.cols;

    double def_rows = 200.0, def_cols = 200.0;
    double x_scale = def_rows/((double)rows);
    double y_scale = def_cols/((double)cols);
  
    // Get the min scale to do a better resize
    double min_scale = max(x_scale, y_scale);
  
    // Resize image
    //resize(src_im, dst_im, Size(), x_scale, x_scale, INTER_CUBIC);
    resize(src_im, dst_im, Size(), min_scale, min_scale, INTER_CUBIC);
    //resize(src_im, dst_im, Size(1024, 768), 0, 0, INTER_CUBIC);

    int dst_width = dst_im.cols;
  
    int step;
  
    Rect* myROI;
  
    if(dst_im.cols>dst_im.rows){
      step = (int)(((double)(dst_im.cols-def_cols))/2.0);
    
      // Setup a rectangle to define your region of interest
      myROI = new Rect(step, 0, 200, 200);
    }
    else{
      step = (int)(((double)(dst_im.rows-def_rows))/2.0);
    
      // Setup a rectangle to define your region of interest
      myROI = new Rect(0, step, 200, 200);
    }
    //cout<<"step="<<step<<" height_im="<<dst_im.rows<<" width_im="<<dst_im.cols<<endl;

    // Crop the full image to that image contained by the rectangle myROI
    // Note that this doesn't copy the data
    Mat crop_img = dst_im(*myROI).clone();

    delete myROI;


    //saveMatToCsv(dst_im, "testcsv.csv");
    imwrite( get_output_filename(i), crop_img );
 
 	//waitKey(0);
	return 0;
}


void saveMatToCsv(const Mat& matrix, const string& filename){
    ofstream outputFile;
    outputFile.open(filename.c_str());
    if(!outputFile.is_open()){
      cout<<"Could not open output csv file"<<endl;
      exit(EXIT_FAILURE);
    }
    outputFile << format(matrix, "CSV") << endl;
    outputFile.close();
}

string get_input_filename(const int& idx){
  stringstream file;
  file<<"TestImages/images";
  file<<idx;
  file<<".jpg";
  return file.str();
}

string get_output_filename(const int& idx){
  stringstream file;
  file<<"TestResized/images";
  file<<idx;
  file<<".resized.jpg";

  return file.str();
}