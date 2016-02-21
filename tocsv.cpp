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
  int num_files=atoi(argv[1]);

  ofstream csv_outfile;
  csv_outfile.open("Data/TrainingSet1.csv");
  if(!csv_outfile.is_open()){
    cout<<"Could not open output file "<<endl;
    exit(EXIT_FAILURE);
  }

  ifstream results_data;
  results_data.open("Data/TrainingSet1_results.txt");
  if(!results_data.is_open()){
    cout<<"Could not open results_data file "<<endl;
    exit(EXIT_FAILURE);
  }

  for(int i=1; i<=num_files; i++){
    Mat src_im, dst_im;

    // Load Image
    src_im = imread( get_input_filename(i), 1 );
    cout<<get_input_filename(i)<<endl;
    if( argc != 2 || !src_im.data ){
      printf( " No image data \n " );
      return -1;
    }


    int result;
    results_data>>result;
    cout<<result<<endl;
    csv_outfile<< result <<endl;
    csv_outfile<< format(src_im, "csv")  <<endl;
    csv_outfile.clear();


  }
  
  csv_outfile.close();
  results_data.close();  
 
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
  file<<"OutputResized/images";
  file<<idx;
  file<<".resized.jpg";
  return file.str();
}

string get_output_filename(const int& idx){
  stringstream file;
  file<<"CSV_images/images";
  file<<idx;
  file<<".resized.jpg";

  return file.str();
}