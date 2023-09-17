#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cassert>


int main() {
    std::ifstream infile;
    infile.open("/home/zq/C-programe-practise/Driveless_PNC/Project_1_PID_ROS1/src/vehicle_control/data/reference_line_Town02.txt");
    //将文件流对象与文件连接起来
    assert(infile.is_open());                                  //若失败,则输出错误消息,并终止程序运行
    std::string s;
    std::string x_str, y_str; // Strings to store x and y values from the file
    std::cout<<"this is a test"<<std::endl;
    std::vector<std::pair<double, double>> xy_points; // Vector to store the pairs of x, y coordinates
    while (getline(infile, s)) {
        std::stringstream word(s);
        word >> x_str;
        word>> y_str;


        double pt_x = std::atof(x_str.c_str());
        double pt_y = std::atof(y_str.c_str());

        xy_points.push_back(std::make_pair(pt_x, pt_y));
    }

    infile.close();

    // Print the values to verify
    for (const auto& point : xy_points) {
        std::cout << "X: " << point.first << ", Y: " << point.second << std::endl;
    }
    std::cout<<"this is a test2"<<std::endl;
    return 0;
}
