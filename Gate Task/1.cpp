#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <bits/stdc++.h>

using namespace cv;
using namespace std;


Mat resized, hsv, mask1, mask2, maskf;

int main()
{
    Mat image = imread("gate.jpeg");

    resize(image, resized, Size(), 2, 2);
    cvtColor(resized, hsv, CV_BGR2HSV);


    int hmin = 0, smin = 185, vmin = 21;
    int hmax = 22, smax = 255, vmax = 93;
    Scalar lower(hmin, smin, vmin);
    Scalar upper(hmax, smax, vmax);
    inRange(hsv, lower, upper, mask1);

    hmin = 0, smin = 0, vmin = 0;
    hmax = 180, smax = 255, vmax = 30;
    Scalar lower2(hmin, smin, vmin);
    Scalar upper2(hmax, smax, vmax);
    inRange(hsv, lower2, upper2, mask2);

    bitwise_or(mask1, mask2, maskf);

    // imshow("Image1", mask1);
    // imshow("Image2", mask2);
    // imshow("Image3", maskf);
    imwrite("mask2.jpeg", maskf);
    waitKey(0);
    return 0;

}