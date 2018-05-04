#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <thread>
#include <cmath>
#include <sstream>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdlib.h>
#include <algorithm>
#include <boost/filesystem.hpp>
#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <unistd.h>

namespace fs1 = boost::filesystem;
std::string get_current_directory(){
    char buf[200];
    getcwd(buf, sizeof(buf));
    return std::string(buf);
}

std::vector<std::string> vector_of_files_in_directory(){
    std::vector<std::string> dataOfVector;
    {
        std::string path1 = get_current_directory();
        for (auto & p : fs1::directory_iterator(path1))
            dataOfVector.emplace_back( p.path().string());
    }
    return dataOfVector;
}

std::vector<std::string> SplitStringToVector(std::string Name){
    std::vector<std::string> VectorOfResult;
    std::ifstream file (Name);
    if(!file){
        std::cout<<"File "<<Name<<" can not be opened!!!"<<std::endl;
    }
    else{

    std::string word;
    while( file >> word )
        VectorOfResult.push_back(word);}
    return VectorOfResult;
}


void WriteToFile(std::vector<std::string> &VectorOfWords, const std::string& NameOfFile) {
    std::ofstream fs(NameOfFile);
    for (auto &word : VectorOfWords) {
        fs <<word<<std::endl;
    }
}

void Enter(){
        std::cout<<"Please enter Y[es]/N[o]"<<std::endl;
}


void Help(){
    std::cout <<">>> mycp [-h|--help] [-f] <file1> <file2>\n Means to copy from file1 to file2, if file1 is a directory, complete by reporting an error without copying.\n"
              <<">>> mycp [-h|--help] [-f]  <file1> <file2> <file3>... <dir>\n If at least one of the Xfiles is a directory, complete, reporting an error without copying.\n"
              <<">>> mycp [-h|--help] [-f] -R  <dir_or_file_1> <dir_or_file_2> <dir_or_file_3>... <dir> \n"" Recursively copy transmitted directories to <dir> \n"<< std::endl;
}

void change_directory(char *dirPATH){
    int erno1 = chdir(dirPATH);
    if (erno1 == -1){
        //std::cout <<"No such file in directory."<< std::endl;
        perror("Error");
        exit(erno1);
    }

}
void changeDirectory(std::string Directory){
    const char *cstr = Directory.c_str();
    change_directory((char *) cstr);
}
std::vector<std::string> Vector_of_all(std::string Directory){
    std::vector<std::string>Vector;
    changeDirectory(Directory);
    for (auto &p : fs1::recursive_directory_iterator(Directory))
    {
        Vector.emplace_back(p.path().string());
    }
    return Vector;
}

bool isFileExitInDirectory(std::string dir){
    fs1::path p{dir};
    bool key = fs1::is_regular_file(p);
    return key;

}

void WriteFileToDirectory(std::string directoryTo,std::string File){
    if (boost::filesystem::is_directory(directoryTo)) {//Is last file or dir?
            boost::filesystem::path dst_path = directoryTo + "/" + File;
            boost::filesystem::path src_path = File;
                try { boost::filesystem::copy_file(src_path, dst_path, boost::filesystem::copy_option::overwrite_if_exists);
                }
                catch (const boost::filesystem::filesystem_error &e) {
                    std::cerr << "Error: " << e.what() << std::endl;
                }
        }
    }
    
std::vector<std::string> split_cmd_line(std::istream& is) {
    std::string commandline;
    std::vector<std::string> parsed_command;
    std::getline(is, commandline);
    std::stringstream ss(commandline);
    std::string word;
    while (ss >> word) {
        parsed_command.push_back(word);
    }
    return parsed_command;
}    

std::string getFromUser(){
    
    bool key = true;
    std::vector<std::string>Vector;
    while(key){
        Enter();
        Vector = split_cmd_line(std::cin);
        if(Vector[0] == "Y"|| Vector[0] == "y"|| Vector[0] == "N"|| Vector[0] == "n"|| Vector[0] == "A"|| Vector[0] == "a"){
            key = false;   
        }
    }
    return Vector[0];  
}    

void m_coopy(fs1::path pathFrom,fs1::path pathTo){
    try { boost::filesystem::copy_file(pathFrom, pathTo, boost::filesystem::copy_option::overwrite_if_exists);
        }
        catch (const boost::filesystem::filesystem_error &e){
            //std::cerr << "Error: " << e.what() << std::endl;
            }        
}


void CoopyFileToDirectory(fs1::path pathFrom,fs1::path pathTo,bool keyf){
    if(keyf){
        if(pathFrom.parent_path().empty()){
            boost::filesystem::path dst_path = pathTo /pathFrom.filename().string();
            boost::filesystem::path src_path = get_current_directory() + "/" + pathFrom.filename().string();
            m_coopy(src_path,dst_path);
        }
        else{
            boost::filesystem::path pathTo2 =  pathTo /pathFrom.filename().string();
            m_coopy(pathFrom,pathTo2);
        }
    }
    else{
        if(fs1::is_regular_file(pathTo /pathFrom.filename().string())){
            std::cout<<pathFrom<<std::endl;
            std::string simbol = getFromUser();
            
            if(simbol == "Y" || simbol == "y"){                
                CoopyFileToDirectory(pathFrom,pathTo, not keyf);
            }
            
        }
        else{
            CoopyFileToDirectory(pathFrom,pathTo, not keyf);
        }
    }  
}

int main(int argc, char *argv[]) {
    
    std::string R = "-R";
    std::string f = "-f";
    bool EXIT = false;
    bool helpKey = false;
    bool regimeKey = false;
    bool lastRegimeR = false;
    bool erorOfR = false;
    bool keyf = false;
    std::vector<std::string> DataFromConsol1;
    std::vector<std::string> DataFromConsol;
    for(int i = 0; i < argc; ++i){
        DataFromConsol1.push_back(argv[i]);
        if(strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0){
            helpKey = true;
        }
        else if(strcmp(argv[i], "-R") == 0){
            lastRegimeR = true;
        }
        else if((strcmp(argv[i], "-f") == 0)){
            keyf = true;
        }
    }
    if(helpKey){
        Help();
        exit(0);
    }
    for(int i = 0; i < DataFromConsol1.size(); ++i){
        if( not (std::find(DataFromConsol.begin(), DataFromConsol.end(), DataFromConsol1[i]) != DataFromConsol.end())){
            if(DataFromConsol1[i] != R || DataFromConsol1[i] != f){
                DataFromConsol.push_back(DataFromConsol1[i]);
            }
            
        }
    }
    
    //CoopyFileToDirectory(DataFromConsol[DataFromConsol.size()-2],DataFromConsol[DataFromConsol.size()-1],keyf);
    if(fs1::is_directory(DataFromConsol[DataFromConsol.size() - 1])){
        if(lastRegimeR){
            int n = 0;
            if(keyf){
                n = 2;
            }
            else{
                n = 1;
            }
            std::vector<std::string> VectorAll;
        for(int i = DataFromConsol.size() - 2; i > n; --i) {
            //if (DataFromConsol[i] != "-R" || DataFromConsol[i] != "-f") {
                
                if ( not (fs1::is_directory(DataFromConsol[i]))) {
                    std::string path = get_current_directory() + "/" + DataFromConsol[i];
                    VectorAll.emplace_back(path);
                }
                else{
                    std::vector<std::string> Vector1 = Vector_of_all(DataFromConsol[i]);
                    for (auto &path : Vector1) {
                        
                        VectorAll.emplace_back(path);
                        }
                    }
                
            }
            for(int i = 0; i < VectorAll.size(); ++i){
                fs1::path p = VectorAll[i];
                //std::cout<<VectorAll[i]<<std::endl;
                CoopyFileToDirectory(p,DataFromConsol[DataFromConsol.size() - 1],keyf);
            }   
        }
        else{
            if(keyf){
                for(int i = 2; i < DataFromConsol.size()-1; ++i){
                    CoopyFileToDirectory(DataFromConsol[i], DataFromConsol[DataFromConsol.size() - 1], keyf);
                }
            }
            else{
                for(int i = 1; i < DataFromConsol.size()-1; ++i){
                    CoopyFileToDirectory(DataFromConsol[i], DataFromConsol[DataFromConsol.size() - 1], keyf);
                }
            }
        }
    }
    else{
        if(argc == 3 || argc == 4){
            std::vector<std::string> Vector = SplitStringToVector(DataFromConsol[DataFromConsol.size()-2]);
            WriteToFile(Vector,DataFromConsol[DataFromConsol.size()-1]);
        }
        else{
            std::cout<<"Incorrect arguments (for more information use mycp -h/--help)"<<std::endl;
        }
    }
}   