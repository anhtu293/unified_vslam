# Unified Visual SLAM
Personal implementation and benchmark of Visual SLAM algorithms


## Environment
```bash
install cmake wget

wget -O opencv.zip https://github.com/opencv/opencv/archive/4.x.zip
wget -O opencv_contrib.zip https://github.com/opencv/opencv_contrib/archive/4.x.zip
unzip opencv.zip
unzip opencv_contrib.zip 
mkdir -p build && cd build
cmake -DOPENCV_EXTRA_MODULES_PATH=../opencv_contrib-4.x/modules ../opencv-4.x
cmake --build .
pkg-config --modversion opencv4
```


# Compile
```bash
cd test
g++ -std=c++11 main.cpp -o main `pkg-config --cflags --libs opencv4`
```

