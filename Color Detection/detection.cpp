#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <bits/stdc++.h>

using namespace cv;
using namespace std;

int main()
{
    int hmin = 40, smin = 36, vmin = 153;
    int hmax = 74, smax = 236, vmax = 191;

    Mat hsv, mask;
    Mat image = imread("sample.jpeg");

    cvtColor(image, hsv, COLOR_BGR2HSV);
    namedWindow("Trackbars", (500, 250));

    createTrackbar("Hue min", "Trackbars", &hmin, 179);
    createTrackbar("Sat min", "Trackbars", &smin, 255);
    createTrackbar("Val min", "Trackbars", &vmin, 255);

    createTrackbar("Hue max", "Trackbars", &hmax, 179);
    createTrackbar("Sat max", "Trackbars", &smax, 255);
    createTrackbar("Val max", "Trackbars", &vmax, 255);

    while (true)
    {
        Scalar lower(hmin, smin, vmin);
        Scalar upper(hmax, smax, vmax);
        inRange(hsv, lower, upper, mask);
        imshow("Image", image);
        imshow("Image HSV", hsv);
        imshow("Image Mask", mask);
        imwrite("hsv.jpg", hsv);
        imwrite("mask.jpg", mask);
        waitKey(1);
    }
    return 0;
}