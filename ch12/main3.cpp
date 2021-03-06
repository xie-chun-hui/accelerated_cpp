#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include "Str.h"
#include "Vec.h"
#include "grade.h"
#include "Student_info.h"

using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::max;
using std::setprecision;
using std::sort;
using std::streamsize;

int main()
{
	Vec<Student_info> students;
	Student_info record;
	Str::size_type maxlen = 0;
	while (read(cin, record))
	{
		maxlen = max(maxlen, record.name.size());
		students.push_back(record);
	}

	sort(students.begin(), students.end(), compare);
	for (Vec<Student_info>::size_type i = 0;
		 i != students.size(); ++i)
	{

		cout << students[i].name
			 << Str(maxlen + 1 - students[i].name.size(), ' ');

		try
		{
			double final_grade = grade(students[i]);
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade
				 << setprecision(prec);
		}
		catch (domain_error e)
		{
			cout << e.what();
		}
		cout << endl;
	}
	return 0;
}
