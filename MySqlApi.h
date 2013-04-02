#ifndef MySqlAPI_H
#define MySqlAPI_H

#include <iostream>
#include <string>
#include <fstream>

#include <stdlib.h>
#include <dirent.h>
#include <string.h>

#define DEFAULT_WIN_PATH "C:/mysql/bin/mysql.exe"
#define XAMPP_WIN_PATH "C:/xampp/mysql/bin/mysql.exe"

#define LINUX_PATH "mysql" // est dans $PATH par defaut sur linux

using namespace std;

class MySqlAPI{

    private:
        string mysql_path;
        string file_param;
        string string_param;

    public:
        MySqlAPI(string path, string bdd, string adr="localhost" ,string user="root", string pwd="");

        int file_req_exec(string sql_file_path, string outputfile = "");
        int string_req_exec(string sql_string, string outputfile = "");
        int rep_exec(string path, string outfile = "");

};

#endif // MySqlAPI_H
