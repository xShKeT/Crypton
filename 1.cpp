#include <iostream>
#include <fstream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {
	int i = 0;
	int current = 0;
	int past = 0;
	string str[3];
	string line;
	ifstream in("1.txt");
	if (in.is_open())
    {
        while (getline(in, line))
        {
        	str[i] = line;
        	i++;
        }
        if(str[0].length() >= str[1].length())
        {
        	str[2] = str[0] + "0";
        	i = str[1].length() - 1;
        	for(int j = str[0].length() - 1; j >= 0; j--)
        	{
        		if(i>=0){
        			current = (int)str[0][j] -  48 + (int)str[1][i] - 48;
        			i--;
        		} else {
        			current = (int)str[0][j] - 48;
        		}
        		if(current >= 10)
        		{
        			str[2][j+1] = current - 10 + past;
        			past = 1;
        		} else {
        			str[2][j+1] = current + past;
        			past = 0;
        		}
        	}
        } else {
        	str[2] = str[1] + "0";
        	int j = str[0].length() - 1;
        	for(int i = str[1].length() - 1; i >= 0; i--)
        	{
        		if(j>=0){
        			current = (int)str[1][i] -  48 + (int)str[0][j] - 48;
        			j--;
        		} else {
        			current = (int)str[1][i] - 48;
        		}
        		if(current >= 10)
        		{
        			str[2][i+1] = current - 10 + past;
        			past = 1;
        		} else {
        			str[2][i+1] = current + past;
        			past = 0;
        		}
        	}
        }
    }
    in.close();
	ofstream out;
	out.open("2.txt");
	if (out.is_open())
    {
    	if(past == 1){
    		str[2][0] = 1;
    		for(i = 0; i < str[2].length(); i++)
	        {
	        	cout << (int)str[2][i];
	        	out << (int)str[2][i];
	        }
    	} else {
    		for(i = 1; i < str[2].length(); i++)
	        {
	        	cout << (int)str[2][i];
	        	out << (int)str[2][i];
	        }
    	}
        
    }
	return 0;
}
