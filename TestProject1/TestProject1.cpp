#include <stdio.h>
#include <time.h>
#include <string>
#include "StrBuilder.h"
using namespace std;

/*
	* TASK: please address all potential performance issues in this code
*/

/*
  Change the class to either detect issues at compile time or 
  correct the potential issues.
*/
class MyFileData {
    	static const size_t _dataSize {10}; //K.Eremeev: move size array to member
	char* myText;

public:
	MyFileData() {
		myText = new char[_dataSize];
	}

	virtual ~MyFileData() { //K.Eremeev: add missed 'virtual'
		if(myText) {
			delete [] myText;
            		myText = nullptr; //K.Eremeev: sure pointer set to null
        	}
	}

    	MyFileData(const MyFileData& data) { //K.Eremeev: was missed
        	myText = new char[_dataSize];
        	memcpy(myText, data.myText, _dataSize);
    	};
    	MyFileData(MyFileData&& data) noexcept = delete; //K.Eremeev: was missed
        
    	MyFileData& operator=(const MyFileData& data) { //K.Eremeev: was missed
        	memcpy(myText, data.myText, _dataSize);
        	return *this;
    	};
    	MyFileData& operator=(MyFileData&& data) noexcept = delete; //K.Eremeev: was missed

	void copy(MyFileData& a, MyFileData b) { 
		a = b;
		MyFileData c = a;
	}
};

int main(int argc, char* argv[])
{
	printf("String Builder test...\n");
    	time_t nStartTime = time(NULL); //K.Eremeev: moved to obtain all cases

	CStringBuilder StringBuilder;
	// generating test data
	StringBuilder.GenerateTestData(1'000'000); //K.Eremeev: increase elemetns

	// get data
	string sData = StringBuilder.GetData();

    	const double& timePass { difftime(time(NULL), nStartTime) };
	printf("Data created in %.6f secs\n",  timePass);

	MyFileData data;
	MyFileData dataCopy = data;
	MyFileData data1;
	data1= data;

	return 0;
}

