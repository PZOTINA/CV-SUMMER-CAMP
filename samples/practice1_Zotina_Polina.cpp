#include <iostream>
#include <string>

#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

#include "filter.h"

using namespace cv;
using namespace std;

const char* cmdAbout = "Sample of OpenCV usage. ";

const char* cmdOptions =
"{ i  image         | <none> | image to process        }"
"{ w  width         | <none> | width for image resize  }"
"{ h  height        | <none> | height for image resize }"
"{ q ? help usage   | <none> | print help message      }";

int main(int argc, char** argv)
{
    // Process input arguments
    CommandLineParser parser(argc, argv, cmdOptions);
    parser.about(cmdAbout);

    if (parser.has("help"))
    {
        parser.printMessage();
        return 0;
    }
    if (!parser.check())
    {
        parser.printErrors();
        return 0;
    }
    
    // Load image
	String imgName(parser.get<String>("image"));
	int width = parser.get<int>("width");
	int height = parser.get<int>("height");

    
    // Filter image
	Mat I = imread(imgName, 1);
	Mat J = imread(imgName, 1);
	Filter* grayF = new GrayFilter();
	Filter* grayR = new ResizeFilter(width,height);
	I = grayF->ProcessImage(I);
	J = grayR->ProcessImage(J);

    // Show image
    
    
	imshow("Hello", I);
	imshow("Hello1", J);

	waitKey();
    return 0;
}
