#include<vector>
#include<boost/format.hpp>
#include "imageStitch.hpp"


int match_num = 10;
void Stitch::matchImg(cv::Mat parentImg ,cv::Mat image,cv::Mat flattenImg,cv::Point central){
    if(parentImg.empty() || image.empty()){
        std::cerr<<"can't read image"<<std::endl;
    }

    if(needCrop){
        parentImg = parentImg(cv::Rect(xMin,yMin,parentImg.cols-xMin-xMax,parentImg.rows-yMin-yMax));
        image = image(cv::Rect(xMin,yMin,image.cols-xMin-xMax,image.rows-yMin-yMax));
    }
    
    int minHession = 400;
    cv::Ptr<cv::xfeatures2d::SURF> detector = cv::xfeatures2d::SURF::create(minHession);
    cv::Mat descriptors1,descriptors2;
    std::vector<cv::KeyPoint> keypoints1,keypoints2;

    detector->detectAndCompute(image,cv::noArray(),keypoints1,descriptors1);
    detector->detectAndCompute(parentImg,cv::noArray(),keypoints2,descriptors2);

    cv::Ptr<cv::DescriptorMatcher> matcher = cv::DescriptorMatcher::create(cv::DescriptorMatcher::BRUTEFORCE);
    std::vector<cv::DMatch> matches;

    matcher->match(descriptors1,descriptors2,matches);
    std::sort(matches.begin(),matches.end());
    matches.erase(matches.begin()+5,matches.end());
    

    std::vector<cv::Point> goodkeypoint1,goodkeypoint2;
    for(int i=0;i<matches.size();i++){
        goodkeypoint1.push_back(keypoints1[matches[i].queryIdx].pt);
        goodkeypoint2.push_back(keypoints2[matches[i].trainIdx].pt);
    }

    cv::Mat matchImg;
    cv::drawMatches(image,keypoints1,parentImg,keypoints2,matches,matchImg);
    cv::Mat homo = cv::findHomography(goodkeypoint1,goodkeypoint2);

    cv::Mat warpedImg;
    cv::warpPerspective(image,warpedImg,homo,parentImg.size());
    std::cout<<"home"<<homo<<std::endl;
    cv::imshow("warpImg",warpedImg);
    cv::imshow("matchImg",matchImg);
    cv::waitKey(0);
}

