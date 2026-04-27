#include<iostream>
#include"student.h"
#include"MA.h"
#include"BA.h"
#include"PHD.h"
#include <vector>
void righformilga(vector<Student*> v);
/*id:211820824
name:linoy boni
the program is checking whom student is eligable for milga
*/
int main()
{
//îòøê ñèåãðèéí, áùáéì ùäéåøùéí îîðå éåëìå ìäéåú áå(äîøä ëìôé îòìä îåúøú)
//ùéîåù áôåìéîåøôéæéí
	vector<Student*> students(7);
	double a1[3] = { 90,100,90 };
	double a2[10] = { 100,100,90,100,90,100,90,100,90,100 };
	double a3[7] = { 90,100,90,100,90,100,90 };
	double *gradess[3] = { a1,a2,a3 };

	students[0] = new BA(3,a1,"123","abe","avraham",3);
	students[1] = new BA(10,a2,"234", "yitzhak", "avrahamson", 10);
	students[2] = new MA(0,7,a3,"345", "yaacov", "jacobson", 7);
	students[3] = new MA(1,7,a3,"456", "sara", "emanu", 7);
	students[4] = new PHD(30,"567", "rivka", "imanu", 1);
	students[5] = new PHD(20,"678", "rachel", "jacobs", 2);
	students[6] = new PHD(30,"789", "leah", "jacobs", 2);
	righformilga(students);
	return 0;
}
void righformilga(vector<Student*> v)
{
	for (int i = 0; i < 7; i++)
	{
	if (v[i]->milga())
		v[i]->print();
	}
}