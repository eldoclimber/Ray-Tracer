//// Ray Tracer.cpp : This file contains the 'main' function. Program execution begins and ends there.


//VERSION 2 of Program

#include <iostream>
#include <string>
#include <ostream>
#include <fstream>
#include <conio.h>
#include <chrono>
#include <Windows.h>

using namespace std;
int main() {

    // Image

    const int image_width = 256;
    const int image_height = 256;
    string filename = "logbook.ppm";
    ofstream filestr;
    string renderLine;

    // File Handling
    // Clear file from previous info with trunc
    filestr.open(filename, std::ofstream::trunc);

    // Render
    renderLine = "P3\n" + to_string(image_width) + " " + to_string(image_height) + "\n255\n";

    cout << renderLine;
    filestr << renderLine;
    system("cls");

    for (int j = image_height - 1; j >= 0; --j) {

        
        //cout << "Progress:" << '\n';
        cout << "\rScanlines remaining: " << j << ' ' << std::flush;
        //To see the counter
        Sleep(1);

        for (int i = 0; i < image_width; ++i) {
            auto r = double(i) / (image_width - 1);
            auto g = double(j) / (image_height - 1);
            auto b = 0.25;

            int ir = static_cast<int>(255.999 * r);
            int ig = static_cast<int>(255.999 * g);
            int ib = static_cast<int>(255.999 * b);
            renderLine = to_string(ir) + ' ' + to_string(ig) + ' ' + to_string(ib) + '\n';
            filestr << renderLine;
            //cout << ir << ' ' << ig << ' ' << ib << '\n';
            
        }
    }
    filestr.close();
    cout << "\nDone.\n";
}


//// OLD VERISON OF CODE
//
//#include <iostream>
//#include <string>
////#include <sstream>  
//#include <fstream>
//using namespace std;
//
//string filename = "logbook.ppm";
//streambuf *psbuf, *backup;
//ofstream filestr;
//
//int main()
//{
//    int nx = 200;
//    int ny = 100;
//    string space = " ";
//    filestr.open(filename);
//
//    // TODO: Code "copied" from internet examples. Investigate what rdbuf does exactly and explore how the output of the file can be printed to console as well as the text file.
//    backup = cout.rdbuf();
//    psbuf = filestr.rdbuf();
//    cout.rdbuf(psbuf);
//    cout << "P3\n" << nx << space << ny << "\n 255\n";
//    cout.rdbuf(backup);
//
//
//    for (int j = ny-1; j >= 0; j--)
//    {
//        for (int i = 0; i < nx; i++)
//        {
//            float r = float(i) / float(nx);
//            float g = float(j) / float(ny);
//            float b = 0.2;
//            int ir = int(255.99 * r);
//            int ig = int(255.99 * g);
//            int ib = int(255.99 * b);
//
//            // TODO: Code "copied" from internet examples. Investigate what rdbuf does exactly and explore how the output of the file can be printed to console as well as the text file.
//            backup = cout.rdbuf();
//            psbuf = filestr.rdbuf();
//            cout.rdbuf(psbuf);
//            cout << ir << space << ig << space << ib << "\n";
//            cout.rdbuf(backup);
//
//
//            // TODO: Explore how stringstream is used. StackExchange suggests it is not useful when used at scale due to memory issues.
//            //stringstream outputString;
//            //outputString << ir << space << ig << space << ib << "\n";
//        }
//    }
//    filestr.close();
//
//}
//
