/* 
 * File:   main.cpp
 * Author: Fabian Witt
 * 
 */


#include <iostream>
#include <vector>
#include <iterator>
#include <unistd.h>
#include <algorithm>

#include "Point_2.h"
#include "Sort.h"
#include "Import.h"


//using namespace std;

struct myLess
{
    bool operator()( const Point_2& p, const Point_2& q){
        if ( p.x() < q.x() ){
            return true;
        } else {
            if ( ( p.x() == q.x() ) && ( p.y() < q.y() ) ){
                return true;
            }
        }
        return false;
    }
};

bool fileExists(const std::string& name) {
    return ( access( name.c_str(), F_OK ) != -1 );
}


int main(int argc, char** argv) {

    if(!fileExists("data/artificialPolygons/H.txt")){
        std::cout << "File does not exist" << std::endl;
    } else {
        
        myLess myLessFct;
        
        std::ostream_iterator<Point_2> out_it (std::cout);
    
        Import import = Import(2, "data/artificialPolygons/H.txt");
        
        std::cout << import.getAnzExamples() << std::endl;
        
        std::vector<Point_2> data = import.getData();
        
        for(int i = 0; i < import.getAnzExamples(); i++){
            std::cout << data.at(i).x() << "/" << data.at(i).y() << std::endl;
        }
        
        Sort sort;
        
        std::cout << "sorted quickSort: " << std::endl;
        out_it = sort.quickSort(data.begin(), data.end(), out_it, myLessFct);
        
        //std::cout << "sorted bubbleSort: " << std::endl;
        //out_it = sort.bubbleSort(data.begin(), data.end(), out_it, myLessFct);
    }
    return EXIT_SUCCESS;
}







