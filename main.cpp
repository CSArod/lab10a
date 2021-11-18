/*Name:Alejandro Rodriquez, 2001889172, lab10a
*Description:Read/manipulate file contents into array & column/row sums
*Input:Filename to be stored in array
*Output:Array row and column sums
*/ 
//user proper header files
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

//prototypes 
void openFile(std::ifstream& iFile, std::string prompt);
void readFile(std::ifstream& iFile, double arr[][10], int rowCount, int colCount);
void rowSumCalculator(double arr[][10], int rowCount, int colCount);
void columnSumCalculator(double arr[][10], int rowCount, int colCount);

//global constants
const int row = 7;
const int col = 10;
int main(){
    std::ifstream usrFile;
    double arr[row][col];

    /* variable prompting user for file input
      to passed into function.*/
    std::string prompt = "Enter file name\n**";
  
    /*****function calls*******/
    
    /*function will make sure file opens
    and continue to prompt user to input file
    until valid file is input */
    openFile(usrFile,prompt); 
    
    /*funtion will read the contents of a file
    into an array*/
    readFile(usrFile,arr,row,col);

    /*This function will sum up 
    all the elements in each row of
    array and cout<< the equation and
    results into the console*/
    rowSumCalculator(arr,row,col);

    /*This function will sum up all
    the elements in eack column and
    cout<< the equation and results
    into the console.*/
    columnSumCalculator(arr,row,col);

    return 0;

}
/****************Functions******************/
//function that will open files
void openFile(std::ifstream& iFile, std::string prompt){

    //variable to store user inputs
    std::string userInput;
    const int ignoreNum = 130; //magic number const
    do
    {
    std::cout << prompt;
    std::cin >> userInput;
    //will open user input file
    iFile.open(userInput);
        //if file will not open will prompt user for input again
        if(!iFile.is_open())
        {   //will clear failstate from console
            std::cin.clear();
            std::cin.ignore(ignoreNum,'\n');
            std::cout<<"Error: Invalid File Name"<<std::endl;
        }
       
    }
    while(!iFile.is_open());
    //do while will continue while the input is invalid
}
//should read all the contents of iFile into an array
void readFile(std::ifstream& iFile, double arr[][10], int rowCount, int colCount){
    do{

        for(int i = 0; i< rowCount; i++)
        {
            for(int j = 0; j < colCount; j++)
            {
                iFile >> arr[i][j];
            }
        }
    }while(!iFile.eof());
    //while read through the contents of the file 
    //until the end if the file and input into
    //an array
}
void rowSumCalculator(double arr[][10], int rowCount, int colCount){
    //header for row outputs
    std::cout<<"\nROW SUMS:"<<std::endl;   
    for(int i = 0; i < rowCount; i++)
    {
        double numSum = 0;
        for(int j = 0; j < colCount-1; j++)
        {
            //sets floating point 
            std::cout<<std::setprecision(1) << 
            std::fixed;
            //will output contents of array and set margins
            std::cout << std::setw(4) << std::left<< arr[i][j] << " + ";
            numSum += arr[i][j];
        }
        //sets floating point
        std::cout<<std::setprecision(1) << 
        std::fixed;
        //add up array row
        numSum += arr[i][9];
        std::cout << std::setw(4) << std::left<<arr[i][9] 
        //outputs sum of row
        <<std::setw(2) << std::right << " = " << numSum <<std::endl;

    }
}
void columnSumCalculator(double arr[][10], int rowCount, int colCount){
    std::cout<< "\nCOLUMN SUMS:"<<std::endl;
    for (int i = 0; i < colCount; i++)
    {
        double numSum = 0;
        for (int j = 0; j < rowCount-1; j++)
        {
            //sets floating point
            std::cout<<std::setprecision(1) << 
            std::fixed;
            //will output contents of columns
            std::cout <<std::setw(4) << std::left<< arr[j][i] <<" + ";
            //will sum up columns
            numSum += arr[j][i];
        }
        //sets floating point
        std::cout<<std::setprecision(1) << 
        std::fixed;
        //adds up the sum of eack column
        numSum += arr[6][i];
        //outputs the sum of each column at the end
        //of each row
        std::cout << std::setw(4) << std::left<< arr[6][i] 
        <<std::setw(2) << std::right <<" = " << numSum <<std::endl;
    }
}
