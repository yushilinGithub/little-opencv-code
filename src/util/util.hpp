#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc_c.h>
#include <vector>
#include <iostream>

void fillhole(cv::Mat srcBw,cv::Mat &dstBw);


class pereCV{
    private:
        int titleCut = 80;
        int moveStep = 3;
        int baseThreshold = 24;
        int lr = 2;
        int D=210;
        int horizontalCut;
        int upperCut;
        int lowerCut;

        cv::Mat croped;

        cv::Mat eroElement = cv::getStructuringElement(cv::MORPH_RECT,cv::Size(3,3),cv::Point(1,1));
    public:
        int averageCentralNumber = 3;
        cv::Mat prosessImage;
        cv::Point central;

        pereCV(){};

        void flattenCore(cv::Mat processImage,cv::Mat &dst,cv::Point central);
        cv::Point find_point(int R,int y,int x,cv::Point c,int rows,int cols);
        void fixedAreaBinary(cv::Mat src,cv::Mat &dst,int areaLow,int areaHigh,cv::Rect cropRect);
        void findCentral(const cv::Mat &image,cv::Point &p);
        
        void flatten(cv::Mat &image,cv::Mat &dst);
};

