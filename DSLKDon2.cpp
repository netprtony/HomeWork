#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
typedef char keytype;
struct pointSub
{
    float essay;
    float endTerm;
    float main;
};

struct subjects
{
    keytype codeSub[10];
    keytype nameSub[20];
    int credits;
    pointSub score;
};
struct name
{
    keytype first[25];
    keytype last[8];
};
struct SNodeSub
{
    subjects data;
    SNodeSub* link;
};
struct SlistSub
{
    SNodeSub* head;
    SNodeSub* tail;
};
//==============================================================================
struct ST
{
    keytype code[10];
    name fullName;
    unsigned int yearBirth;
    SlistSub scoreSub;
};
typedef ST Itemtype;
struct SNode
{
    Itemtype data;
    SNode* link;
};
struct Slist
{
    SNode* head;
    SNode* tail;
};
//==============================================================================
SNodeSub* createSNodeSub(subjects x) {
    SNodeSub* p = new SNodeSub;
    if (!p) {
        printf("Not enough!");
        return NULL;
    }
    p->data = x;
    p->link = NULL;
    return p;
}
//==============================================================================
SNode* createSNodeST(Itemtype x) {
    SNode* p = new SNode;
    if (!p) {
        printf("Not enough!");
        return NULL;
    }
    p->data = x;
    p->link = NULL;
    return p;
}
//==============================================================================
void initSlistSub(SlistSub& sl) {
    sl.head = sl.tail = NULL;
}
//==============================================================================
bool isEmpty(SlistSub sl) {
    return sl.head == NULL;
}
//==============================================================================
void initSlist(Slist& sl) {
    sl.head = sl.tail = NULL;
}
//==============================================================================
bool isEmpty(Slist sl) {
    return sl.head == NULL;
}
//==============================================================================
bool insertTailSlistSub(SlistSub& sl, SNodeSub* add) {
    if (!add) return false;
    if (isEmpty(sl)) sl.head = sl.tail = add;
    else {
        sl.tail->link = add;
        sl.tail = add;
    }
    return true;
}
//==============================================================================
void inputInfoSubjects(subjects& x) {
    printf("\nEnter code of subjects : ");
    fflush;
    gets_s(x.codeSub);
    printf("\nEnter name of subjects : ");
    fflush;
    gets_s(x.nameSub);
    srand((unsigned)time(NULL));
    x.credits = rand() % 5 + 1;
    printf("Credits : %d", x.credits);
    x.score.essay = (rand() % 101 * 0.1);
    x.score.endTerm = (rand() % 101 * 0.1);
    x.score.main = x.score.essay * 30 / 100 + 70 / 100 * x.score.endTerm;
    printf("Score main: %.2.f\n", x.score.main);
}
//==============================================================================
void intputSubjects(SlistSub& sl) {
    initSlistSub(sl);
    int amo, res;
    do
    {
        printf("\nAmount subject : "); scanf_s("%d", &amo);
    } while (amo <= 0);
    for (int i = 1; i <= amo; i++)
    {
        subjects x;
        inputInfoSubjects(x);
        SNodeSub* p = createSNodeSub(x);
        res = insertTailSlistSub(sl, p);
        if (!res) printf("\n Can not add this subject!");
    }
}
//==============================================================================
void inputInfoST(ST& x) {
    printf("Enter code of student : ");
    fflush;
    gets_s(x.code);
    printf("Enter first and last name : ");
    fflush;
    gets_s(x.fullName.first,25); gets_s(x.fullName.last,8);
    printf("Enter birth year of student : ");
    scanf_s("%d", x.yearBirth);
    intputSubjects(x.scoreSub);
}
//==============================================================================
float averageScore(SlistSub slSub) {
    int cre = 0;
    float td = 0;
    for (SNodeSub* p = slSub.head; p; p = p->link)
    {
        subjects x = p->data;
        cre += x.credits;
        td += x.score.main * x.credits;
    }
    return(cre > 0) ? (td / cre) : 0;
}
//==============================================================================
void outputSubjects(subjects x) {
    printf("%-10s%-20s%-10d%-5.1f%-5.1f%-5.1f", x.codeSub, x.nameSub, x.credits, x.score.endTerm, x.score.essay, x.score.main);
}
//==============================================================================
void outputListSub(SlistSub slSub) {
    printf("Result :");
    int i = 1;
    printf("\n%-5s%-10s%-20s%-10s%-5s%-5s%-5s", "ORDER", "CODE", "SUBJECT", "CREDITS", "END TERM", "ESSAY", "AVERAGE");
    for (SNodeSub* p = slSub.head; p; p = p->link)
    {
        printf("\n%-5d", i++);
        outputSubjects(p->data);
    }
}
//==============================================================================
void outputInfoST(ST x) {
    float aver = averageScore(x.scoreSub);
    printf("%-12s%-23s%-10s%10.1f", x.code, x.fullName.first, x.fullName.last, x.scoreSub);
    outputListSub(x.scoreSub);
}
//==============================================================================
bool insertTail(Slist& sl, SNode* add) {
    if (!add) return false;
    if (isEmpty(sl)) {
        sl.head = sl.tail = add;
    }
    else {
        sl.tail->link = add;
        sl.tail = add;
    }
    return true;
}
//==============================================================================
void createSlist(Slist& sl) {
    int n, res;
    do
    {
        printf("Amount student : "); scanf_s("%d", &n);
    } while (n <= 0);
    initSlist(sl);
    for (int i = 1; i <= n; i++)
    {
        ST x;
        inputInfoST(x);
        SNode* p = createSNodeST(x);
        res = insertTail(sl, p);
        if (!res) printf("Can not add student!");
    }
}
//==============================================================================
void showSList(Slist sl) {
    if (isEmpty(sl)) {
        printf("List nothing student!");
        return;
    }
    int i = 1;
    printf("\nList of Student : ");
    printf("\n%-5s%-12s%-33s%-10s", "CODE ST", "NAME ST", "SCORE");
    for (SNode* p = sl.head; p; p = p->link)
    {
        printf("\n\n%-5d", i++);
        outputInfoST(p->data);
    }
}
//==============================================================================
void findCodeST(Slist sl, char code[]) {
    for (SNode* p = sl.head; p; p = p->link)
    {
        if (!strcmp(p->data.code, code)) {
            outputInfoST(p->data);
            return;
        }
    }
    printf("Student non-exist!");
}
//==============================================================================
bool findNameST(Slist sl, char firstName[], char lastName[]) {
    if(isEmpty(sl)) return false;
    for (SNode* p = sl.head; p; p = p->link)
    {
        if (!strcmp(p->data.fullName.first, firstName) &&!strcmp(p->data.fullName.last, lastName)){
            outputInfoST(p->data);
            return true;
        }
    }
    return false;
}
//==============================================================================
void swapInfoST(Itemtype& ST1, Itemtype& ST2) {
    Itemtype x = ST1;
    ST1 = ST2;
    ST2 = x;
}
void sortSTCodeIncrease(Slist sl) {
    for (SNode* p = sl.head; p != sl.tail; p = p->link)
    {
        for (SNode* q = p->link; q != NULL ; q = q->link)
        {
            if (strcmp(p->data.code, q->data.code) > 0) swapInfoST(p->data, q->data);
        }
    }
    printf("Sort done!");
}
//==============================================================================
void sortSTNameIncrease(Slist sl) {
    for (SNode* p = sl.head; p != sl.tail; p = p->link)
    {
        for (SNode* q = p->link; q != NULL; q = q->link)
        {
            if (strcmp(p->data.fullName.first, q->data.fullName.first) > 0 && strcmp(p->data.fullName.last, q->data.fullName.last) > 0) swapInfoST(p->data, q->data);
        }
    }
    printf("Sort done!");
}
//==============================================================================
bool addAfter(Slist& sl, SNode* p, SNode* add) {
    if (!add) return false;
    add->link = p->link;
    p->link = add;
    if (p == sl.tail) sl.tail = add;
    return true;
}
bool addBefore(Slist& sl, SNode* p, SNode* add) {
    if (!add) return false;
    addAfter(sl, p, add);
    swapInfoST(p->data, add->data);
}
void addSTOrder(Slist& sl, SNode* add) {
    bool res;
    if (isEmpty(sl)) {
        sl.head = sl.tail = add;
    }
    else {
        for (SNode* p = 0; p ; p = p->link)
        {
            if(strcmp(p->data.code, add->data.code) > 0){
                res = addBefore(sl, p, add);
                break;
            } else {
                res = addBefore(sl, p, add);
                break;
            }
        }
    }
    if(!res) printf("Can not add student please try later!");
}
//==============================================================================
bool deleteAfter(Slist &sl, SNode* p, Itemtype &x){
    if(isEmpty(sl)) return false;
    
    SNode* tep = p->link;
    if(tep == sl.tail) sl.tail = p;
    x = tep->data;
    p->link = tep->link;
    delete tep;
    return true;
}
bool deleteSTCode(Slist &sl, char code[], Itemtype &x){
    if(isEmpty(sl)) return false;
    bool res;
    for (SNode* p = sl.head; p; p= p->link)
    {
        if(!stricmp(p->data.code, code)){
            swapInfoST(p->data, p->link->data);
            res = deleteAfter(sl, p, x);
            if(res) return true;
        }
    }
    return false;
}
bool deleteAllSTName(Slist &sl, char firstName[], char lastName[]){
    Itemtype x;
    if(isEmpty(sl)) return false;
    for (SNode* p = sl.head; p; p= p->link)
    {
        if(findNameST(sl, firstName, lastName)){
            swapInfoST(p->data, p->link->data);
            deleteAfter(sl, p, x);
        }
    }  
    return true;
}
//==============================================================================
void listSTMiddling(Slist sl ){
    if(isEmpty(sl)) return;
    for (SNode* p = sl.head; p; p= p->link)
    {
        if(averageScore(p->data.scoreSub) >= 8.5 && averageScore(p->data.scoreSub) >= 7.0)  outputInfoST(p->data);
    } 
}
//==============================================================================
int bestOfScore(Slist sl){
    if(isEmpty(sl)) return 0;
    float best = averageScore(sl.head->data.scoreSub.head);
    for (SNode* p = sl.head; p; p= p->link)
    {
        if(averageScore(p->data.scoreSub) > best) best = averageScore(p->data.scoreSub);
    }
    return best;
}
//==============================================================================

int main() {
    Slist sl;
    createSlist(sl);
    showSList(sl);
    return 0;
}