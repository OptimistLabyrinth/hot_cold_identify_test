#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <exception>
#include <cstdlib>
#include <cmath>
#include <iomanip>

const std::string path = "../test_data/";
const std::string file_name = "test_case_04.txt";
// const std::string file_name = "test_case_10.txt";
const std::string output_name = "output.txt";

constexpr int RANGE =  8;
constexpr int W     = 10;

inline void execute_test(void);
inline void preprocess_output_file(void);
inline void preprocess_input_data(std::ifstream&);
inline void collect_data(std::ifstream&, std::vector<int>&);
inline void postprocess_input_data(std::ifstream&);
inline void print_vector(const std::vector<int>&);
inline void start_test_algorithm(
    const std::vector<int>&, std::vector<int>&, long long&);
inline void postprocess_output_file(void);





std::ofstream outfile;
std::ostringstream oss;





int main(const int argc, const char* argv[]) {
    execute_test();
    return 0;
}

inline void execute_test(void) {
    try {
        preprocess_output_file();
    }
    catch (std::ios_base::failure f) {
        std::cerr<<f.what()<<std::endl;
        exit(EXIT_FAILURE);
    }

    std::vector<int> INPUT;
    {
        std::ifstream infile;
        try {
            preprocess_input_data(infile);
            collect_data(infile, INPUT);
            postprocess_input_data(infile);
        }
        catch (std::ios_base::failure f) {
            std::cerr<<f.what()<<std::endl;
            exit(EXIT_FAILURE);
        }
    }
    print_vector(INPUT);
    oss<<std::endl;
    outfile<<oss.str();
    std::cout<<oss.str(); oss = std::ostringstream();

    long long ST_DIST_VAR = 0;
    std::vector<int> SLOT_NUM(RANGE);
    start_test_algorithm(INPUT, SLOT_NUM, ST_DIST_VAR);

    oss<<std::endl;
    for(int i=0; i < RANGE; ++i) {
        oss<<SLOT_NUM[i]<<' ';
    }
    outfile<<oss.str()<<std::endl;
    std::cout<<oss.str()<<std::endl; oss = std::ostringstream();
    
    oss<<"\n(eventual) stack distance: "<<ST_DIST_VAR<<std::endl;
    outfile<<oss.str();
    std::cout<<oss.str(); oss = std::ostringstream();

    try {
        postprocess_output_file();
    }
    catch (std::ios_base::failure f) {
        std::cerr<<f.what()<<std::endl;
        exit(EXIT_FAILURE);
    }
}





inline void preprocess_output_file(void) {
    outfile.open(path+output_name, std::ios_base::out);
    if (!outfile.is_open()) {
        oss<<"output file opening FAILED";
        outfile<<oss.str()<<std::endl;
        std::cout<<oss.str()<<std::endl; oss = std::ostringstream();
        throw outfile.exceptions();
    }

    oss<<"file name -> "<<file_name<<std::endl;
    outfile<<oss.str();
    std::cout<<oss.str(); oss = std::ostringstream();
    // oss<<"???";
    // outfile<<oss.str();
}

inline void preprocess_input_data(std::ifstream& infile) {
    infile.open(path+file_name, std::ios::in);
    if (!infile.is_open()) {
        oss<<"Opening file FAILED...";
        std::cout<<oss.str()<<std::endl; oss = std::ostringstream();
        throw infile.exceptions();
    }
}

inline void collect_data(std::ifstream& infile, std::vector<int>& INPUT) {
    std::string line;
    while (getline(infile, line)) {
        std::stringstream ss{line};
        std::string each;
        while (ss >> each) {
            if (each == "") break;
            INPUT.push_back(stoi(each));
        }
    }
}

inline void postprocess_input_data(std::ifstream& infile){
    infile.close();
    if (infile.is_open()) {
        oss<<"Not Closed...???";
        std::cout<<oss.str()<<std::endl; oss = std::ostringstream();
        throw infile.exceptions();
    }
}

inline void print_vector(const std::vector<int>& V) {
    int cnt = 0;
    for(auto x : V) {
        oss<<std::setw(1)<<x<<' ';
        if (++cnt % 10 == 0) oss<<std::endl;
    }
    outfile<<oss.str();
    std::cout<<oss.str(); oss = std::ostringstream();
}

inline void start_test_algorithm(
    const std::vector<int>& INPUT,
    std::vector<int>& SLOT_NUM,
    long long& ST_DIST_VAR)
{
    int cnt = 0;
    int slot = 1;
    /*
     *  At first, I though of using variable "increase_degree."
     *  Accordance with this, I thought I could change the value of 
     *  ST_DIST_VAR (= stack distance variable), but it wasn't successful.
     */
    // int increase_degree = 0;
    for (auto it=INPUT.begin(); it != INPUT.end(); ++it) {
        if (SLOT_NUM[*it] == slot) {
            /*
             *  This is a decreasing phase.
             * 
             *  I roughly thought decreasing 10% for every hit occurrence
             *  is appropriate.
             * 
             *  We can try with another value.
             * 
             */
            oss<<"the same  "
                <<"("<<std::setw(4)<<' '<<"->"<<std::setw(4)<<' '<<") ";
            if (10 < ST_DIST_VAR) {
                ST_DIST_VAR = static_cast<long long>(ST_DIST_VAR * 0.9);
            }
            else { --ST_DIST_VAR; }
            // if (increase_degree <= 0) { --ST_DIST_VAR; }
            // else { increase_degree -= 2; }
        }
        else {
            /*
             *  This is an increasing phase
             * 
             *  I roughly thought increasing the amount of difference between
             *  current slot sequence and previous slot sequence for every miss occurrence
             *  is appropriate.
             * 
             *   -> (CASE 1) : if the current slot_number is bigger
             *   -> (CASE 2) : if the previous slot_number is bigger
             * 
             *  We can try with another value.
             */
            oss<<"different "
                <<"("<<std::setw(4)<<SLOT_NUM[*it]<<"->"<<std::setw(4)<<slot<<") ";
            if (SLOT_NUM[*it] < slot) {
                ST_DIST_VAR += slot - SLOT_NUM[*it];
            }
            else {
                ST_DIST_VAR += SLOT_NUM[*it] - slot;
            }
            // ++increase_degree;
        }
        SLOT_NUM[*it] = slot;

        oss<<"cnt: "<<std::setw(4)<<cnt<<", "
            <<"slot: "<<std::setw(4)<<slot<<", "
            <<"ST_DIST_VAR: "<<std::setw(4)<<ST_DIST_VAR
            <<std::endl;
        
        outfile<<oss.str();
        std::cout<<oss.str(); oss = std::ostringstream();

        if (cnt+1 == W) {
            if (slot+1 == W) {
                for(auto& x : SLOT_NUM) { x = static_cast<int>(x/2); }
                slot = 0;
            }
            else {
                ++slot;
            }
            cnt = 0;
        }
        else {
            ++cnt;
        }
    }
}

inline void postprocess_output_file(void) {
    outfile.close();
    if (outfile.is_open()) {
        oss<<"closing outfile FAILED"<<std::endl;
        std::cout<<oss.str(); oss = std::ostringstream();
        throw outfile.exceptions();
    }
}

