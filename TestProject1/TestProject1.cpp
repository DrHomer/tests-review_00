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
	char* myText;


public:
	MyFileData() {
		myText = new char[10];
	}

	~MyFileData() {
		if(myText)
			delete [] myText;
	}

	void copy(MyFileData& a, MyFileData b) {
		a = b;
		MyFileData c = a;
	}
};

int main(int argc, char* argv[])
{
	printf("String Builder test...\n");
	CStringBuilder StringBuilder;
	// generating test data
	StringBuilder.GenerateTestData(10000);
	time_t nStartTime = time(NULL);

	// get data
	string sData = StringBuilder.GetData();

	printf("Data created in %f secs\n", difftime(time(NULL), nStartTime));

	MyFileData data;
	MyFileData dataCopy = data;
	MyFileData data1;
	data1= data;

	return 0;
}

