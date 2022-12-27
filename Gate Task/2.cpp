#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>

using namespace cv;
using namespace std;

Mat src, img;
Mat src_gray;

void draw();

int main() {
    img = imread("gate.jpeg", IMREAD_COLOR);
    resize(img, img, Size(), 2, 2);
    src = imread("mask2.jpeg", IMREAD_COLOR);
    cvtColor(src, src_gray, COLOR_BGR2GRAY);
    blur(src_gray, src_gray, Size(3, 3));
    imshow("Source", img);

    imshow("Mask", src);
    draw();
    waitKey(0);
    return (0);
}

int areaRec(Rect r) {
    int x = r.br().x - r.tl().x;
    int y = r.br().y - r.tl().y;
    return x * y;
}

Point getCenter(Rect r) {
    int x, y;
    x = r.x + (r.width / 2);
    y = r.y + (r.height / 2);
    Point c(x, y);
    return c;
}   

void draw() {
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    findContours(src_gray, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));

    vector<vector<Point>> contours_poly(contours.size());
    vector<Rect> boundRect(contours.size());

    for (int i = 0; i < contours.size(); i++) {
        approxPolyDP(Mat(contours[i]), contours_poly[i], 3, true);
        boundRect[i] = boundingRect(Mat(contours_poly[i]));
    }

    Mat drawing = img.clone();
    Mat drawing2 = src.clone();
    for (int i = 0; i < contours.size(); i++) {
        Scalar color = Scalar(255, 0, 0);
        if (areaRec(boundRect[i]) > 5000) {


            Point p = getCenter(boundRect[i]);
            rectangle(drawing, boundRect[i].tl(), boundRect[i].br(), color, 2, 8, 0);
            circle(drawing, p, 5, Scalar(255, 0, 0), FILLED);


            rectangle(drawing2, boundRect[i].tl(), boundRect[i].br(), color, 2, 8, 0);
            circle(drawing2, p, 5, Scalar(255, 0, 0), FILLED);
            putText(drawing2, format("(%d,%d)", p.x, p.y), Point(p.x - 50, p.y + 40), FONT_HERSHEY_DUPLEX, 1.0, Scalar(255, 0, 255), 2);
        }
    }
    imshow("Contours", drawing);
    imshow("Contours2", drawing2);
}