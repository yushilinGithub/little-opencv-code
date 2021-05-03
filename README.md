# run this code
## install opencv with contrib module
 official document useful to install opencv with contrib module https://docs.opencv.org/master/d7/d9f/tutorial_linux_install.html
 
 ### attention
  I should not put the video that this repository deal with, if you would like to run this code and see what actually this code do, please contect me with email, 1329239119@qq.com

 ### dependence
  1. We need CMake to configure the installation, GCC for compilation, Python-devel and Numpy for building Python bindings etc.

        - sudo apt-get install cmake
        - sudo apt-get install gcc g++
  2. Next we need GTK support for GUI features, Camera support (v4l), Media Support (ffmpeg, gstreamer) etc.
        - sudo apt-get install libavcodec-dev libavformat-dev libswscale-dev
        - sudo apt-get install libgstreamer-plugins-base1.0-dev libgstreamer1.0-dev
  3. to support gtk2
        - sudo apt-get install libgtk2.0-dev
  4. to support gtk3
        - sudo apt-get install libgtk-3-dev
  5. install ffmpeg
        - sudo apt install ffmpeg

 ### install opencv
  1. Download and unpack sources
     - wget -O opencv.zip https://github.com/opencv/opencv/archive/master.zip
     - wget -O opencv_contrib.zip https://github.com/opencv/opencv_contrib/archive/master.zip
     - unzip opencv.zip
     - unzip opencv_contrib.zip
     - mkdir -p build && cd build
     - cmake -DOPENCV_ENABLE_NONFREE:BOOL=ON -DWITH_FFMPEG=ON -DOPENCV_EXTRA_MODULES_PATH=../opencv_contrib-master/modules ../opencv-master  
     - cmake --build .
     - sudo make install
## install boost
    boost is needed to run the code
     - sudo apt-get install libboost-dev

## build
    in the code root directory, 
        - mkdir build
        - cd build
        - cmake ..
        - make 
        - ./app