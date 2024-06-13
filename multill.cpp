Multi-LL.cpp#include <iostream>
#include <stdlib.h>
using namespace std;

struct students
{
    int SID;
    students* snext;
};

struct courses
{
    int CID;
    courses* cnext;
    students* fstud;
};

void cinsert(courses** cstart)
{
    courses* cptr = new courses;
    cout << "Insert Course Number: ";
    cin >> cptr->CID;
    cptr->cnext = NULL;
    cptr->fstud = NULL;
    if (*cstart == NULL)
    {
        *cstart = cptr;
    }
    else 
    {
        courses* curr = *cstart;
        while (curr->cnext != NULL)
        {
            curr = curr->cnext;
        } 
        curr->cnext = cptr;
    }
}

void cprint(courses** cstart)
{
    courses* curr = *cstart;
    while (curr != NULL)
    {
        cout << "Course Number: " << curr->CID << endl;
        cout << "" << endl;
        curr = curr->cnext;
    }
}

void csearch(courses** cstart)
{
    int toSearch;
    cout << "Enter course number: ";
    cin >> toSearch;

    courses* curr = *cstart;
    while (curr != NULL)
    {
        if (curr->CID == toSearch)
        {
            cout << "Course Exists " << endl;
            break;
        }
        else
        {
            curr = curr->cnext;
        }
        if (curr == NULL)
        {
            cout << "Course doesn't exist" << endl;
        }
    }
}

void cdel(courses** cstart)
{
    courses* curr = *cstart;
    int toDelete;
    cout << "Insert course number: ";
    cin >> toDelete;
    if (toDelete == (*cstart)->CID)
    {
        *cstart = (*cstart)->cnext;
        free(curr);
    }
    else
    {
        courses* prev = (*cstart);
        curr = (*cstart)->cnext;
        while (curr != NULL)
        {
            if (curr->CID == toDelete)
            {
                prev->cnext = curr->cnext;
                free(curr);
                break;
            }
            else
            {
                curr = curr->cnext;
                prev = prev->cnext;
            }
        }
        if (curr == NULL)
        {
            cout << "Doesn't Exist";
        }
    }
}

void studinsert(students** studstart, courses** cstart)
{
    students* sptr = (students*)malloc(sizeof(students))
    cout << "Insert Student ID: ";
    cin >> sptr->SID;
    sptr->snext = NULL;
    int CID;
    cout << "Insert course number in which you want to enroll the student: ";
    cin >> CID;
    courses* curr = *cstart;
    while (curr != NULL)
    {
        if (CID == curr->CID)
        {
            if (curr->fstud == NULL)
            {
                curr->fstud = sptr;
                cout << "successful 1" << endl;

            }
            else
            {
                students* stcurr = curr->fstud;
                while (stcurr->snext != NULL)
                {
                    stcurr = stcurr->snext;
                }
                stcurr->snext = sptr;

                cout << "successful 2" << endl;

            }
               break;
        }
            curr = curr->cnext;
        
    }
        
		}


void serstd(courses** cstart)
{
	int toserstd;
    cout << "search Student ID: ";
    cin >> toserstd;

    int CID;
    cout << "Insert course number in which you want to get the student: ";
    cin >> CID;
    courses* curr = *cstart;
    while (curr != NULL)
    {
        if (CID == curr->CID)
        {
            if (curr->fstud == NULL)
            {
                cout<<"no student found";
            }
            else
            {
                students* stcurr = curr->fstud;
                while (stcurr != NULL)
                {
                	if(stcurr->SID==toserstd){
						cout<<"your searched student"<<stcurr->SID
					}
					sturr=sturr->snext;
                }                
            }
               break;
            curr = curr->cnext;
        }
        
    }


 void studprint(students* studstart,courses** cstart)
 {
     

    int CID;
    cout << "Insert course number in which you want to get the student: ";
    cin >> CID;
    courses* curr = *cstart;
    while (curr != NULL)
    {
        if (CID == curr->CID)
        {
                students* stcurr = curr->fstud;
                while (stcurr != NULL)
                {
                	if(stcurr->SID==toserstd){
						cout<<<<stcurr->sid;
					}
					sturr=sturr->snext;
                               
            }
               break;
        }
            curr = curr->cnext;
 }

int main()
{
    courses* cstart = NULL;
    students* studstart = NULL;
    cinsert(&cstart);
    int select = 1;
    cout << "Press 1 to insert a course" << endl;
    // cout << "Press 2 to delete a course" << endl;
    cout << "Press 2 to print courses" << endl;
    // cout << "Press 4 to search a course" << endl;
    cout << "Press 3 to insert a student" << endl;
    // cout << "Press 4 to print students" << endl;
    cout << "Press 4 to print course and enrolled students";
    cout << "Press 0 to exit" << endl;
    cout << "Enter your choice: " << "";
    cin >> select;
    while (select != 0)
    {
        if (select == 1)
        {
            cinsert(&cstart);
        }
        // if (select == 2)
        // {
        //     cdel(&cstart);
        // }
         if (select == 2)
        {
            cprint(&cstart);
        }
        // if (select == 4)
        // {
        //     csearch(&cstart);
        // }
        if (select == 3)
        {
            studinsert(&studstart, &cstart);
        }
        // if (select == 4)
        // {
        //     studprint(&studstart);
        // }
        if (select == 4)
        {
            pstudwrtcour(&cstart);
        }
        cout << "Enter your choice again: " << "";
        cin >> select;
    }
}