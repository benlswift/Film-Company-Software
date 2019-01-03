#include "abdkutility.h"

namespace ABDK
{
	bool checkAlphabeticalOrder(std::string str1,std::string str2)
	{
		for(int i =0; (i<str1.length())&&(i<str2.length());i++)
		{
			if (str1[i]<str2[i])
			{
				return 1;
			}
		}

		if (str2.length() > str1.length())
		{
			return 1;
		}

		else
		{
			return 0;
		}
	}


    std::string getNextValue(std::string& line){
        int n = line.find_first_of(',');
        std::string returnValue = line.substr(0,n);
        line.erase(0,n+1);
        return returnValue;
    }
}
