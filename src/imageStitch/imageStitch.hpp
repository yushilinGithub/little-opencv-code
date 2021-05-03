#include <iostream>
#include <utility>
#include <vector>
#include <opencv2/core/core.hpp>
#include <opencv2/features2d.hpp>
#include <opencv2/xfeatures2d.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/calib3d.hpp>
void imgMatch(cv::Mat src1,cv::Mat src2);

class Stitch{
    private:
        bool needCrop = true;
        int xMin ,yMin,xMax ,yMax;

        std::vector<std::pair<cv::Mat,cv::Mat>> subImgHomoPair;

        cv::Rect leftTopR;
        cv::Rect rightTopR;
        cv::Rect leftBottomR;
        cv::Rect rightBottomR;


        
    public:
        cv::Mat leftTop;
        cv::Mat rightTop;
        cv::Mat leftBottom;
        cv::Mat rightBottom;
        Stitch(int xmin,int ymin,int xmax,int ymax):xMin(xmin),yMin(ymin),xMax(xmax),yMax(ymax){}
        void matchImg(cv::Mat parentImg ,cv::Mat image,cv::Mat flattenImg,cv::Point central);

};