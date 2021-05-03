#include <cmath>
#include "util.hpp" 
#define PI 3.141592653589793


void pereCV::fixedAreaBinary(cv::Mat src,cv::Mat &dst,int areaLow,int areaHigh,cv::Rect cropRect){

    cv::Mat binary;
    cv::Mat eroImage;
    float sum;
    
    cv::Mat cutedImage = src(cropRect);
    int i=0;
    while(i++<100){
        cv::threshold( cutedImage, binary, baseThreshold, 1, cv::THRESH_BINARY_INV);
        
        // sum pixel values in the specified rectangle area
        // get the rectangle area
        int step = binary.step/sizeof(uchar);
        uchar *imageData = binary.data;
        sum = 0;
        for(int x = 0;x<binary.cols;x++){
            for(int y = 0;y<binary.rows;y++){
                sum+=(int)imageData[y*step+x*binary.channels()];
            }
        }
        if(sum<areaHigh && sum>areaLow){
            break;
        }
        else if(sum>=areaHigh){
            baseThreshold -= lr;
        }
        else if(sum<=areaLow){
            baseThreshold += lr;
        }
        if(baseThreshold>250 || baseThreshold<1){
            
            std::cout<<"baseThreshold Error need to be fixed"<<baseThreshold<<std::endl;
            break;
        }
    }
    cv::erode(binary,eroImage,eroElement);
    cv::dilate(eroImage,dst,eroElement);
    binary.release();
    eroImage.release();

}

void pereCV::findCentral(const cv::Mat &image,cv::Point &p){
    int num=0,pointy,pointx;
    cv::Mat dst;
    cv::Mat gray;
    cv::cvtColor(image,gray,cv::COLOR_BGR2GRAY);
    float sum;
    int width,height;


    horizontalCut = (int)image.cols/3;
    upperCut = (int)image.rows/4;
    lowerCut = upperCut;//(int)src.rows/3;
    
    //cut central hole, that deep hole locatated in 
    cv::Point pt1(horizontalCut,upperCut);
    cv::Point pt2(image.cols-horizontalCut,image.rows-lowerCut);
    cv::Rect cropRect(pt1,pt2);

    int areaLow=2000,areaHigh=3800;

    fixedAreaBinary(gray,dst,areaLow,areaHigh,cropRect);
    gray.release();
    cv::Mat dist;
    fillhole(dst,dist);
    

    cv::distanceTransform(dist, dst, cv::DIST_L2, 3);

    dist.release();
    for(int i=0;i<dst.rows;i++){
        for(int j=0;j<dst.cols;j++){
            float dis = dst.at<float>(i,j);
            if(dis>num){
                num = dis;
                pointy = i;
                pointx = j;
            }
        }
    }
    p.x = pointx+horizontalCut;
    p.y = pointy+upperCut;

    dst.release();
        
}
cv::Point pereCV::find_point(int R,int y,int x,cv::Point c,int rows,int cols){
    cv::Point P;
    double theta = (double)x/(double)R;
    
    double dynamicR = R-(y*R/(D+y));

    P.y = std::max(0,(int)(R-dynamicR*std::cos(theta)));
    P.x = std::max(0,(int)(dynamicR*std::sin(theta)+c.x));
    P.y = std::min(P.y,rows);
    P.x = std::min(P.x,cols);
    return P;
}

void pereCV::flattenCore(cv::Mat processImage,cv::Mat &dst,cv::Point central){

    int R = std::min(central.y,processImage.rows-central.y);
    if(R<central.y) //hole central y is greater than image central y; 
         processImage = processImage(cv::Rect(0,central.y-R,processImage.cols,processImage.rows-(central.y-R)));

    int newWidth =(int)2*PI*R; 
    cv::Mat flattened(processImage.rows,(int)2*PI*R,processImage.type());
    uchar *data = flattened.data;
    int step = flattened.step/sizeof(uchar);
    int step1 = processImage.step/sizeof(uchar);
    int channel = flattened.channels();
    cv::Point p;

    for(int i = 0;i<flattened.rows;i++){
        for(int j=0;j<flattened.cols;j++){
            p = find_point(R,i,j,central,flattened.rows,flattened.cols);
            data[i*step+j*channel+0] = processImage.data[p.y*step1+p.x*channel+0];  
            data[i*step+j*channel+1] = processImage.data[p.y*step1+p.x*channel+1];
            data[i*step+j*channel+2] = processImage.data[p.y*step1+p.x*channel+2];
        }
    }
    
    dst = flattened;

}

void pereCV::flatten(cv::Mat &image,cv::Mat &dst){
    findCentral(image,central);
    flattenCore(image,dst,central);

}



