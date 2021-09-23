#include <iostream>
#include <fstream>
#include <vector>


/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
struct Parser
{
	string name;
	int req;
	int hour;
	string info;
};
int main(int argc, char** argv) {
	vector<Parser> arr;
	Parser temp;
	int i = 0;
	int j = 0;
	Parser line;
	ifstream in("1.txt");
	if (in.is_open())
    {
        while (!in.eof())
        {
            in >> line.name >> line.req >> line.hour >> line.info;
            arr.push_back(line);
        }
    }
    
    for(i = 0; i < arr.size(); i++)
    {
    	if(arr[i].req != 0)
    	{
    		for (j = 0; j < arr.size(); j++)
    		{
    			if(arr[i].name == arr[j].name && i!=j)
    			{
    				arr[i].req += arr[j].req;
    				arr[j].req = 0;
    				arr[i].hour += arr[j].hour;
    				arr[j].hour = 0;
    			}
    		}
    	}
    }
    for (i = 0; i < arr.size() - 1; i++) {
        for (j = 0; j < arr.size() - i - 1; j++) {
            if (arr[j].name > arr[j + 1].name) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    
    in.close();
	ofstream out;
	out.open("2.txt");
	if (out.is_open())
    {
    	for( i = 0; i < arr.size(); i++)
	    {
	    	if(arr[i].req != 0)
	    	{
	    		cout << arr[i].name << ' ' << arr[i].req << ' ' << arr[i].hour << ' ' << arr[i].info << endl;
	    		out << arr[i].name << ' ' << arr[i].req << ' ' << arr[i].hour << ' ' << arr[i].info << endl;
	    	}
	    }  
    }

	return 0;
}
