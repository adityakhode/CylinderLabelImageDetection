To Complie the code use this command in linux terminal 

    g++ main.cpp -o main -std=c++11 `pkg-config --cflags --libs opencv4` -llept -ltesseract

To run the code after compilation use the below command

    ./main
