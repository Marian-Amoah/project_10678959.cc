#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

template <class var>

void print(var textline)
{
	cout << textline;
}

///creating struct for courses
    struct course
	{
	int level;
	string subjects[10];
    };

///struct for record
    struct record
	{
	int semester;
	int CreditHour;
	string CourseName;
	int mark;
	string Grade;
    };

///class for individual
    class individual{
	public:
	individual()
	{
///set empty student name=""
	Status = " null ";
	}
		
///setting functions for student
	void SetName(string val)
	{
	Name = val;
	}
			
	void SetStatus(string val)
	{
	Status = val;
	}
		
	void SetAge(int val)
	{
	Age = val;
	}
		
	void SetIndex(int val)
	{
	Index = val;
	}
					
	void SetId(int val)
	{
	object_Id = val;
	}
						
	void SetResidence(string val)
	{
	Residence = val;
	}
							
	void ListItems(vector<string>arrayVar)
	{
	int len = arrayVar.size();
	for (int i = 0; i < len; i++)
	{
	print(arrayVar[i]);
	if((i + 1) % 3 == 0)
	{
	print(" \n ");
	}
	else 
	{
    print(" \t\t ");
	}
	}
	}
								
///getting functions for students
	string GetName()
	{
	return Name;
	}
									
	string GetStatus()
	{
	return Status;
	}
										
	int GetAge()
	{
	return Age;
	}
											
	string GetResidence()
	{
	return Residence;
	}
												
	string GetType()
	{
	return  " individual ";
	}
													
	int GetId()
	{
	return object_Id;
	}
														
	int GetIndex()
	{
	return Index;
	}
															
	void GetInfo()
	{
    cout << "\nName     : " << GetName() << "\nAge     : " << GetAge() << "\nindividual Id     : " << GetId() << endl;
	}
	
	private:
	string Name;
	int Age;
	int Index;
	int object_Id;
	string Status;
    string Residence;	
};

///struct for student
    struct student{
    individual details;
    float schoolfees;
    int level;
    string course;
    string department;
    vector<string>subjects;
    vector<record>academic_records;	
	};
	
///struct for staff
    struct staff{
    individual details;
    string job;
    string department;
    vector<string>subjects;
	};
	
///*** functions prototypes **********
    void
	addStudent(),editStudent(),manageStudent(),GpaCalc(student obj);
	
	void
	addStaff(),editStaff(),manageStaff(),GpaCalc(student obj);

	string lower(string line),gradeCalc(double score);
	
	student stu_container[10000];
	
	staff sta_container[10000];
	
	int stu_base_id = 10440000;
	
	int sta_base_id = 11440000;
	
	int stu_count = 0;
	
	int sta_cout = 0;
	
	string str;int num;
	
	int main()
	{
	cout << " \n Heya! ... WeLcOmE !!\n " << endl;
	 
	string select;
	
	while(true)
	{
	cout << " \na. student \nb.staff \nc.exit\n " <<endl;
	cout << " \nchoose individual : " << endl;
	cin >> str;
	
	if(str == " a ")
	{
	cout << " \nYou are on student's path " << endl;
	
	while(true)
	{
	cout << " \n\ni. add \nii. edit \niii. manage \niv. exit " << endl;
	cout << " \n\nchoose an option : " << endl;
	cin >> select;
	
	if (select == " i ")
	{
///adding students
    addStudent();
	}
	else if (select == " ii ")
	{
///edditting student object
    editStudent();		
	}
	else if (select == " iii ")
	{
///managing student object
    manageStudent();		
	}
	else if ( select == " iv ")
	{
	break;
	}
	
	cin.clear();
	
	}
	
    }
    
    else if (str == " b ")
    {
    cout << " \nYou are on staff's path " << endl;
    
    while(true)
    {
    cout << " \n\ni. add \nii. edit \niii. manage \niv. exit " << endl;
	cout << " \n\nchoose an option : " << endl;
	cin >> select;
	
	if ( select == " i ")
	{
	addStaff();	
	}
	else if ( select == " ii ")
	{
	editStaff();
	}
	else if (select == " iii ")
	{
	manageStaff();	
	}
	else if ( select == " iv ")
	{
	break;
	}
	
	cin.clear();
		
	}
	
	}
	
	else if(str == " c ")
	{
	break;	
	}
    }
    
    return 0;
	}
	
	void addStudent()
	{
///!!!!!!!!!!!!!!!!!!!!!!!!add student detail....read class and struct
    cin.clear();
	cout << " \n**********adding new student********** " << endl;
	student temp;
	cout << " \nAssigned StudentId : " << endl;
	cout << stu_base_id+stu_count << endl;
	temp.details.SetId(stu_base_id+stu_count);
	temp.details.SetIndex(stu_count);
	stu_count++;
	
	string str;int num;
	 
	cout << " \nEnter Student's Name : " << endl;
	cin.ignore();
	getline(cin,str);
	cin.clear();

	temp.details.SetName(str);
	cout << " \nEnter Student's Age : " << endl;
	cin >> num;
	
	while(cin.fail())
	{
	cout << " \n(invalid) Try again : " << endl;
	cin.clear();
	cin.ignore();
	cin >> num;	
	}
	
	temp.details.SetAge(num);
///list department for student to choose from
	cout << " \nEnter Department's Name : " << endl;
	cin >> str;
	temp.department = str;
	
///list course using department
    cout << " \nEnter student's Course : " << endl;
	cin >> str;	
	temp.course = str;	

///set controls
    cout << " \nEnter student's level : " << endl;
	cin >> num;
	
	while(cin.fail())
	{
	cout << " \n(invalid)Try again : " << endl;
	cin.clear();
	cin.ignore();
	cin >> num;		
	}
	
	while( num !=100 && num != 200 && num != 300 && num != 400)
	{
	cout << " (invalid)Enter Level : " << endl;
	cin >> num;
	
		
	while(cin.fail())
	{
	cout << " \n(invalid)Try again : " << endl;
	cin.clear();
	cin.ignore();
	cin >> num;	
	}	
	}
	
	temp.level = num;
///set controls
    cout << " \nEnter Student's schoolfees : " << endl;
	cin >> num;
	
	while(cin.fail())
	{
	cout << " \n(invalid)Try again : " << endl;
	cin.clear();
	cin.ignore();
	cin >> num;	
	}
	
	temp.schoolfees = num;
///pushing to array
    stu_container[temp.details.GetIndex()] = temp;
	
	cout << " \nDo you want to add another student?(y/n) : " << endl;
	cin >> str;
	
	if ( str == " y ")
	{
	addStudent();
	}
	else 
	{
	///pass	
	}
    };
    
    void editStudent()
    {
    ///search student
	int pass = 1;
	cout << " \n( edit ) Enter students Id or iii. to leave " << endl;
	
	int stu_Id;
	cin >> stu_Id;
	while (cin.fail())
	{
	cout << " \n(invalid)Try again : " << endl;
	cin.clear();
	cin.ignore();
	cin >> stu_Id;
	}
	
	if (stu_Id != 0)
	{
	stu_Id -= stu_base_id;
	
///controls
    while(stu_Id < 0 || stu_Id >= stu_count)
	{
	cout << " \n(invalid)Enter Student's Id or 0 to leave : " << endl;
	cin >> stu_Id;
	
	while(cin.fail())
	{
	cin.clear();
	cin.ignore();
	cout << " \n(invalid)Enter a valid student Id : " << endl;
	cin >> stu_Id;
	}
	
	if(stu_Id != 0)
	{
	stu_Id -= stu_base_id;
	}
	else 
	{
	pass = 0;
	break;	
	}		
	}
	
	if (pass ==1 )
	{
///found student
	cout << " \nStudent Found\n" << endl;
	student obj = stu_container[stu_Id];
///editting student
///list option for edit
	
	while(true)
	{
	cout << " \n\n1. name \n2. age \n3. level \n4. course \n5. department \n6. student subjects \n7. residence \n0. exit \n" << endl;
	cout << " \n What do you want to edit : " << endl;
	string edit;
	cin >> edit;
	
	if (edit == " 1 ")
	{
	cout << " \nStudents          name         : " << endl;
	cout << obj.details.GetName() << endl;
	cout << " \nChange to : " << endl;
	cin.ignore();
	getline(cin, str);
	cin.clear();	
	}
	else if(edit == " 2 ")
	{
	cout << " \nStudents          age           : " << endl;
	cout << obj.details.GetAge() << endl;
	cout << " \n\nChange to : " << endl;
	cin >> num;
	
	while(cin.fail())
	{
	cout << " \n(invalid)Try again : " << endl;
	cin.clear();
	cin.ignore();
	cin >> num;
	}
	
	obj.details.SetAge(num);	
	}
	else if (edit == " 3 ")
	{
	cout << " \nStudents level : " << endl;
	cout << obj.level << endl;
	cout << " \n\nChange to : " << endl;
	cin >> num;
	
	while(cin.fail())
	{
	cout << " \n(invalid)Try again : " << endl;
	cin.clear();
	cin.ignore();
	cin >> num;
	}
	
	while(num != 100 && num != 200 && num != 300 && num != 400)
	{
	cout << " \n\nChange to 100, 200, 300 or 400 : " << endl;
	cin >> num;
	
	while (cin.fail())
	{
	cout << " \n(invalid)Try again : " << endl;
	cin.clear();
	cin.ignore();
	cin >> num;	
	}
	}
	
	obj.level = num;	
	}
	
	else if (edit == " 4 ")
	{
	cout << " \nStudents          course          : " << endl;
	cout << obj.course;
	cin.ignore();
	getline(cin, str);
	cin.clear();
	
	obj.course = str;	
	}
	
	else if(edit == " 6 ")
	{
	cout << " \n\nStudents     subject     :     \n " << endl;
///list
    obj.subjects;
	
	while(true)
	{
	cout << " 1. add subject \n2. remove subject \n0. exit\n " << endl;
	cout << " select an option : " << endl;
	cin >> str;
	
	if (str == " 1 ")
	{
	cin.ignore();
	
	while(true)
	{
	cout << " \nEnter subject to remove or use 0 to leave : " << endl;
	getline(cin,str);
	
	if(str == " 0 ")
	{
	break;
	}
	else 
	{
	obj.subjects.push_back(str);
	record_new;
	_new.course_name = str;
	_new.mark = -1;
	obj.academic_records.push_back(_new);	
	}	
	}	
	}	
	else if(str == " 2 ")
	{
	cin.ignore();
	
	while(true)
	{
	cout << " \nEnter subject to remove or use 0 to leave : " << endl;
	getline(cin, str);
	if (str == " 0 ")
	{
	break;	
	}
	else 
	{
	int len = obj.subject.size();
	for (int i = 0; i < len; i++)
	{
	if(lower(obj.subjects[i])==lower(str))
	{
	obj.subjects.erase(obj.subjects.begin()+i);
	obj.academic_records.erase(obj.academic_records.begin()+i);
	cout << " \nSubject has been removed successfully " << endl;
	break;	
	}
	if(i == len-1)
	{
	cout << " \n sorry cannot find subject Index...\n " << endl;
	}	
	}	
	}
	}	
	}
	else if(str == " 0 ")
	{
	break;	
	}
	}		
	}
	else if (edit == " 7 ")
	{
	cout << " \nStudents          Residence          : " << endl;
	cout << obj.details.GetResidence() << endl;
	cout << " \n\nChange to : " << endl;
	cin.ignore();
	getline(cin,str);
	cin.clear();
	cin.clear();
	obj.details.SetResidence(str);	
	}
	
	else if(edit == " 0 ")
	{
///commit changes and push
	
	stu_container[obj.details.GetIndex()] = obj;
	break;	
	}
	}
    }
	}
    };
    
    void manageStudent()
    {
///search student
	int pass = 1;
	cout << " \n( manage ) Enter students Id or iii. to leave " << endl;
	
	int stu_Id;
	cin >> stu_Id;
	while (cin.fail())
	{
	cout << " \n(invalid)Try again : " << endl;
	cin.clear();
	cin.ignore();
	cin >> stu_Id;
	}
	
	if (stu_Id != 0)
	{
	stu_Id -= stu_base_Id;
	
///controls
    while(stu_Id < 0 || stu_Id >= stu_count)
	{
	cout << " \n(invalid)Enter Student's Id or 0 to leave : " << endl;
	cin >> stu_Id;
	
	while(cin.fail())
	{
	cin.clear();
	cin.ignore();
	cout << " \n(invalid)Enter a valid student Id : " << endl;
	cin >> stu_Id;
	}
	
	if(stu_Id != 0)
	{
	stu_Id -= stu_base_Id;
	}
	else 
	{
	pass = 0;
	break;	
	}		
	}
    if (pass == 1){
///found student
    cout << " \nStudent Found\n " << endl;;
    student obj = Stu_Container[stu_id];
///editing student
    while (true)
	{
    cout << " \n\n1. enter students score \n2. show academic records \n3. remove student \n0. exit\n " << endl;
    cout << " \nWhat do you want to do : " << endl;
    string manage;
    cin >> manage;
    if (manage == " 1 ")
	{
    int len = obj.subjects.size();
    cout << " Enter the semester? (1,2) : " << endl;
    cin >> num;
    
    while (num != 1 && num != 2)
	{
    cout << " Enter the semester? (1,2) : " << endl;
    cin >> num;
    }
    for (int i=0;i<len;i++)
	{                
	if (obj.academic_records[i].mark == -1)
	{
    cout << " \n\nSubject :\t " << endl;
	cout << obj.academic_records[i].course_name << endl;
    cout << " \nDo you want to record marks for this subject : " << endl;
    cin >> str;
	str = lower(str);
                        
	while (str != "y" && str != "n")
	{
    cout << " \nplease choose 'y' or 'n' " << endl;
    cin >> str;
    str = lower(str);
    }
    if (str == "y")
	{
    int credit_Hour;
    cout << " \nCredit Hour(s)\t:\t " << endl;
    cin >> credit_Hour;
                            
	while (0 > credit_Hour || credit_Hour > 3){
    cout << " (invalid) Credit Hour(s)\t:\t " << endl;
    cin >> credit_Hour;
    }
    int score;
    cout << " Enter Mark\t:\t " << endl;
    cin >> score;
    
	while (0 > score || score >100)
	{
    cout << "(invalid) Enter Mark\t:\t " << endl;
    cin >> score;
    }
    obj.academic_records[i].mark = score;
    obj.academic_records[i].credit_hr = score;
    obj.academic_records[i].semester = num;
    obj.academic_records[i].grade = gradeCalc(score);
    }
    }
    }
    Stu_Container[obj.details.getIndex()] = obj;
    }
    else if (manage == " 2 "){
    int len = obj.subjects.size();
    cout << " \n\n############################################################################################ " << endl;
    cout << " \n******************************************************************************************** " << endl;
    cout << " \nName : " << endl;
	cout << obj.details.getName() << endl;
	cout << " \tDepartment : " << endl;
	cout << obj.department << endl;
    cout << " \tCourse : " << endl;
	cout << obj.course << endl;
	cout << " \tLevel : " << endl;
	cout << obj.level << endl;
	cout << " \tGPA :\t " << endl;
	GpaCalc(obj);
    cout << " \n******************************************************************************************** " << endl;
    cout << " \n============================================================================================ " << endl;
    for (int i=0;i<len;i++)
	{
                    
	if (obj.academic_records[i].mark != -1)
	{
    cout << " \n\nSubject :\t " << endl;
	cout << obj.academic_records[i].course_name << endl;
    cout << " \t\tMark :\t " << endl;
	cout << obj.academic_records[i].mark << endl;
    cout << " \t\tGrade :\t " << endl;
	cout << obj.academic_records[i].grade << endl;
    }
    else
	{
    cout << " \n\nSubject :\t" << endl;
	cout << obj.academic_records[i].course_name << endl;
    cout << " \t\tMark :\t " << endl;
	cout << " **N/A** " << endl;
    cout << " \t\tGrade :\t " << endl;
	cout << " **N/A** " << endl;
    }
    }
    cout << " \n\n============================================================================================ " << endl;
    cout << " \n############################################################################################ " << endl;
    }
    else if (manage == " 3 ")
	{
    cout << " \nAre you sure you want to remove student? (y/n) : " << endl;
    cin >> str;
	str = lower(str);
	
    while (str != " y " && str != " n ")
	{
    cout << " \nplease choose ' y ' or ' n ' " << endl;
    cin >> str;
    str = lower(str);
    }
    if (str == " y ")
	{
    obj.details.setStatus(" removed ");
    Stu_Container[obj.details.getIndex()] = obj;
    }
    }
    else if (manage == " 0 ")
	{
///commit changes and push
    Stu_Container[obj.details.getIndex()] = obj;
    break;
    }
    }
    }
    }
    };

    void addStaff(){
///add student detail....read class and struct
    cin.clear();
    cout << " \n**************adding new staff***************** " << endl;
    staff temp;
    cout << " \n\nAssigned Staff ID : " << endl;
	cout << sta_base_id+sta_count << endl;
    temp.details.setID(sta_base_id+sta_count);
	temp.details.setIndex(sta_count);
	sta_count++;
    string str;
	int num;
    cout << " \nEnter Staff Name : " << endl;
    cin.ignore();
	getline(cin, str);
	cin.clear();
    temp.details.setName(str);
    cout << " \nEnter Staff Age : " << endl;
    cin >> num;
    while (cin.fail())
	{
    cout << " \n( invalid ) Try Again : " << endl;
    cin.clear();
	cin.ignore();
	cin >> num;
    }
    temp.details.setAge(num);
///list department for student to choose from
    cout << " \nEnter Department Name : " << endl;
    cin >> str;
    temp.department = str;
    //list course using department

    cout << " \nEnter Staffs Job : " << endl;
    cin >> str;
    temp.job = str;
    //list course using department

    //pushing to array
    Sta_Container[temp.details.getIndex()] = temp;

    cout << " \nDo you want to add another staff? (y/n) : " << endl;
    cin >> str;
    if (str == " y ")
	{
    addStaff();
    }
    else{
///pass
    }

    };

    void editStaff(){
///search student
    int pass = 1;
    cout << " \n( edit ) Enter Staffs ID or 0 to leave : " << endl ;
    int sta_id;
    cin >> sta_id;
    
    while (cin.fail())
	{
    cout << " \n( invalid ) Try Again : " << endl;
    cin.clear();
	cin.ignore();
	cin >> sta_id;
    }
   if (sta_id != 0)
   {
   sta_id -= sta_base_id;
///controls
    while (sta_id < 0 || sta_id >= stu_count){
    cout << " \n( invalid ) Enter Staffs ID or 0 to leave : " << endl;
    cin >> sta_id;
    
    while (cin.fail())
	{
    cin.clear();
	cin.ignore();
    cout << " \n( invalid ) Enter valid Staff ID : " << endl;
    cin >> sta_id;
    }
    if(sta_id != 0)
	{
    sta_id -= sta_base_id;
    }
    else
	{
    pass = 0;
    break;
    }
    }

    if (pass == 1)
	{
///found student
    cout << " \nStaff Found\n " << endl;
    staff obj = Sta_Container[sta_id];
///editing student
///list option for edit...eg name ,age etc.

   while (true)
   {
    cout << " \n\n1. name \n2. age \n3. department \n4. staff subjects \n5. residence \n0. exit\n " << endl;
    cout << " \nWhat do you want to edit : " << endl;
    string edit;
    cin >> edit;
    if (edit == "1")
	{
    cout << " \nStaffs name : " << endl;
	cout << obj.details.getName() << endl;
    cout << " \n\nChange to : " << endl;
    cin.ignore();
	getline(cin, str);
	cin.clear();
    }
    else if (edit == " 2 ")
	{
    cout << " \n\nChange to : " << endl;
    cin >> num;
    
    while (cin.fail())
	{
    cout << " \n( invalid ) Try Again : " << endl;
    cin.clear();
	cin.ignore();
	cin >> num;
    }
    obj.details.setAge(num);
    }
    else if (edit == " 3 ") 
	{
    cout << " \nStaffs Department : " << endl;
	cout << obj.department << endl;
    cout << " \n\nChange to : " << endl;
    cin.ignore();
	getline(cin, str);
	cin.clear();
    obj.department = str;
    }
    else if (edit == " 4 ")
	{
    cout << " \n\n\nStaffs subject : \n " << endl;
///list obj.subjects;
               
    while (true)
	{
    cout << " 1. add subject \n2. remove subject \n0. exit\n " << endl;
    cout << " select an option : " << endl;
    cin >> str;
    if (str == " 1 ")
	{
    cin.ignore();
                      
	while (true)
	{
    cout << " \nenter subject to add or use 0 to leave : " << endl;
    getline(cin, str);
    if (str == " 0 ")
	{
    break;
    }
    else
	{
    obj.subjects.push_back(str);
    }
    }
    }
    else if (str == " 2 ")
	{
    cin.ignore();
                        
	while (true){
    cout << " \nenter subject to remove or use 0 to leave : " << endl;
    getline(cin, str);
    if (str == " 0 ")
	{
    break;
    }
    else
	{
    int len = obj.subjects.size();
    for (int i=0;i<len;i++)
	{
    if (lower(obj.subjects[i]) == lower(str))
	{
    obj.subjects.erase(obj.subjects.begin()+i);
    cout << " \nSubject successfully removed ..." << endl;
    break;
    }
    if (i == len-1)
	{
    cout << " \ncant find subject index ...\n" << endl;
    }
    }
    }
    }
    }else if (str == " 0 ")
	{
    break;
    }
    }
    }
    else if (edit == " 5 ")
	{
    cout << " \nStaffs Residence : " << endl;
	cout << obj.details.getResidence() << endl;
    cout << " \n\nChange to : " << endl;
    cin.ignore();
	getline(cin, str);
	cin.clear();
    cin.clear();obj.details.setResidence(str);
    }
    else if (edit == " 0 ")
	{
///commit changes and push

    Sta_Container[obj.details.getIndex()] = obj;
    break;
    }
    }
    }
    }
    };

    void manageStaff()
	{
///search student
    int pass = 1;
    cout << " \n( manage )Enter Staffs ID or 0 to leave : " << endl;
    int sta_id;
    cin >> sta_id;
    while (cin.fail())
	{
    cout << " \n( invalid ) Try Again : " << endl;
    cin.clear();
	cin.ignore();
	cin >> sta_id;
    }
    if (sta_id != 0)
	{
    sta_id -= sta_base_id;
///controls
    while (sta_id < 0 || sta_id >= sta_count)
	{
    cout << " \n( invalid ) Enter Staff ID or 0 to leave : " << endl;
    cin >> sta_id;
    
	while (cin.fail())
	{
    cin.clear();
	cin.ignore();
    cout << " \n( invalid ) Enter valid staff ID : " << endl;
    cin >> sta_id;
    }
    if(sta_id != 0)
	{
    sta_id -= sta_base_id;
    }
    else
	{
    pass = 0;
    break;
    }
    }

    if (pass == 1){
///found student
    cout << " \nStaff Found\n" << endl;
    staff obj = Sta_Container[sta_id];
///editing student
    while (true)
	{
    cout << " \n\n1. remove staff \n0. exit\n " << endl;
    cout << " \nWhat do you want to do : " << endl;
    string manage;
    cin >> manage;
    if (manage == " 1 ")
	{
    cout << " \nAre you sure you want to remove staff? (y/n) : " << endl;
    cin >> str;
	str = lower(str);
    while (str != " y " && str != " n ")
	{
    print("\nplease choose ' y ' or ' n ' " << endl;
    cin >> str;
    str = lower(str);
    }
    if (str == " y ")
	{
    obj.details.setStatus("removed");
    Sta_Container[obj.details.getIndex()] = obj;
    }
    }
    else if (manage == " 0 ")
	{
///commit changes and push
    Sta_Container[obj.details.getIndex()] = obj;
    break;
    }
    }
    }
    }
    };


    string lower(string line)
	{
    string LOWER = "abcdefghijklmnopqrstuvwxyz";
    string UPPER = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string ret_lower = "";
    int len = line.length();
    for (int i=0;i<len;i++)
	{
///boy
    for (int j=0;j<26;j++)
	{
    if (line[i] == UPPER[j])
	{
    ret_lower += LOWER[j];
    break;
    }
    else if (j == 25)
	{
    ret_lower += line[i];
    }
    }
    }
    return ret_lower;
	}


    string gradeCalc(double score)
	{
    if (79 < score && score <= 100)
	{
    return "A";
    }
    else if(74 < score && score <= 79)
	{
    return "B+";
    }
    else if(69 < score && score <= 74)
	{
    return "B";
    }
    else if(64 < score && score <= 69)
	{
    return "C+";
    }
    else if(59 < score && score <= 64)
	{
    return "C";
    }
    else if(54 < score && score <= 59)
	{
    return "D+";
    }
    else if(49 < score && score <= 54)
	{
    return "D";
    }
    else if(44 < score && score <= 49)
	{
    return "E";
    }
    else if(-1 < score && score <= 44)
	{
    return "F";
    }
    else
	{
    return "invalid mark";
    }
    }


    float getGpaScore(string grade)
	{
    if (grade == "A")
	{
    return 4.0;
    }
    else if (grade == "B+")
	{
    return 3.5;
    }
    else if (grade == "B")
	{
    return 3.0;
    }
    else if (grade == "C+")
	{
    return 2.5;
    }
    else if (grade == "C")
	{
    return 2.0;
    }
    else if (grade == "D+")
	{
    return 1.5;
    }
    else if (grade == "D")
	{
    return 1.0;
    }
    else if (grade == "E")
	{
    return 0.5;
    }
    else if (grade == "F")
	{
    return 0.0;
    }
    return -1;
    }

    void GpaCalc(student obj)
	{
    float gpa = 0.0;int tch=0;bool empty_score = false;
    int len = obj.academic_records.size();
    vector<record> temp_record = obj.academic_records;
    for (int i=0;i<len;i++){
    if (temp_record[i].mark == -1)
	{
    empty_score = true;
    cout << "**N/A**";
    break;
    }
    else
	{
    tch += temp_record[i].credit_hr;
    gpa += getGpaScore(temp_record[i].grade)*temp_record[i].credit_hr;
    }
    }
    if (empty_score == false)
	{
    if (len != 0)
	{
    cout << gpa/tch;
    }
    else
	{
    cout << "**N/A**";
    }
    }
	}
	
	
    
	
	

	
			
  

