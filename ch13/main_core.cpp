#include <algorithm>
#include <ios>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>

#include "Core.h"

using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::setprecision;
using std::setw;
using std::sort;
using std::streamsize;
using std::string;
using std::vector;

using std::max;

int main()
{
	vector<Core> students;
	Core record;
	string::size_type maxlen = 0;

	while (record.read(cin))
	{
		maxlen = max(maxlen, record.name().size());
		students.push_back(record);
	}

	sort(students.begin(), students.end(), compare);
	for (vector<Core>::size_type i = 0; i != students.size(); ++i)
	{
		cout << students[i].name()
			 << string(maxlen + 1 - students[i].name().size(), ' ');
		try
		{
			double final_grade = students[i].grade();
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade
				 << setprecision(prec) << endl;
		}
		catch (domain_error e)
		{
			cout << e.what() << endl;
		}
	}
	return 0;
}
