#include"task1.hpp"
#include"task2.hpp"
#include"task3.hpp"
int main()
{
    int task=1,result=1;
    switch(task)
    {
        case 1:
            result=task1();
            break;
        case 2:
            result=task2();
            break;
        case 3:
            result=task3();
            break;
        default:
            break;
    }
    return result;
}

//15  |  1.5  |  2.10  |  3.2