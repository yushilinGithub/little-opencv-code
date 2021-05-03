#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <queue>
#include "src/util/util.hpp"
#include "src/imageStitch/imageStitch.hpp"


int xMin = 0,yMin=80;

std::map<std::string,std::string> readConfig(){
    //parse configuration file
    const char * cfgfile = "../resources/file.cfg";
    std::ifstream file(cfgfile);
    std::map<std::string,std::string> mp; 
    if (file.is_open())
    {
        std::cout<<cfgfile<<std::endl;
        std::string line;
        while(getline(file, line))
       {
            
            line.erase(std::remove_if(line.begin(), line.end(), isspace),
                                 line.end());
            if( line.empty() || line[0] == '#' )
            {
                continue;
            }
            auto delimiterPos = line.find("=");
            std::string name = line.substr(0, delimiterPos);
            std::string value = line.substr(delimiterPos + 1);
            std::cout << name << ": " << value << '\n';
            mp[name] = value;
        }
        return mp;
    }
    else 
    {
        std::cerr << "Couldn't open config file for reading.\n";
        std::exit(1);
    }
} 

void runVideoStitch(std::map<std::string,std::string>  config){

    std::string videoPath = config["videoPath"];
     int xmin = std::stoi(config["cutxMin"]);
     int ymin = std::stoi(config["cutxMin"]);
     int xmax = std::stoi(config["cutxMin"]);
     int ymax = std::stoi(config["cutxMin"]);
 
    std::cout<<videoPath<<std::endl;
    std::cout<<xmin<<std::endl;
    cv::VideoCapture captureFront(videoPath);
    
    cv::Mat frame;
    cv::Mat flattenImg;
    cv::Mat frameBuffer;
    cv::Mat flattenBuffer;


    pereCV perecv;

    Stitch stitch(xmin,ymin,xmax,ymax);
    if(!captureFront.isOpened()) throw "Error when reading stream_avi";

    while(true){
        if(!captureFront.read(frame)) break;
        perecv.flatten(frame,flattenImg);
        if(!frameBuffer.empty() && !flattenBuffer.empty())
            stitch.matchImg(frameBuffer,frame,flattenImg,perecv.central);

        frameBuffer = frame.clone();
        flattenBuffer = flattenImg.clone();

        cv::circle( frame,perecv.central,2,cv::Scalar( 0, 0, 255 ),cv::FILLED,cv::LINE_8 );
        cv::imshow("flattenImage",flattenImg);
        cv::imshow("image",frame);

        if(cv::waitKey(20)>=0)
            break;
    }   
    
}

int main(int argc,char **argv)
{
    std::map<std::string,std::string> config = readConfig();
    runVideoStitch(config);

}