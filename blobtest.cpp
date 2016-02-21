
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
//#include "types.hpp"
//#include "/usr/include/opencv2/imgproc/types_c.h"
#include "/usr/include/opencv2/core/core.hpp"
#include "/usr/include/opencv2/opencv.hpp"
//#include "/usr/include/opencv2/core/types.hpp"
//#include <types.hpp>
using namespace cv;
using namespace std;

string get_input_filename(const int& idx);
string get_output_filename(const int& idx);
void saveMatToCsv(const Mat& matrix, const string& filename);


int main( int argc, char** argv ){


// Read image
Mat im = imread( argv[1], 1);
 
// Set up the detector with default parameters.
SimpleBlobDetector detector;
 
// Detect blobs.
std::vector<KeyPoint> keypoints;
detector.detect( im, keypoints);
 
// Draw detected blobs as red circles.
// DrawMatchesFlags::DRAW_RICH_KEYPOINTS flag ensures the size of the circle corresponds to the size of blob
Mat im_with_keypoints;
drawKeypoints( im, keypoints, im_with_keypoints, Scalar(0,0,255), DrawMatchesFlags::DRAW_RICH_KEYPOINTS );
 
// Show blobs
imshow("keypoints", im_with_keypoints );
waitKey(0);

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
  file<<"ParkingLot_new/images";
  file<<idx;
  file<<".jpg";
  return file.str();
}

string get_output_filename(const int& idx){
  stringstream file;
  file<<"OutputResized_new/images";
  file<<idx;
  file<<".resized.jpg";

  return file.str();
}