/************************************************/
/* Author    : Assem Khaled						*/
/* Version   : V01								*/
/* Date      : 6 Sep 2020						*/
/************************************************/
#ifndef OS_PRIVATE_H
#define OS_PRIVATE_H


typedef struct
{
	u16 periodicity;
	void (*ptr) (void);
	u16 FirstDelay;
	u8 State;
}Task;


void Scheduler(void);


#define TASK_READY		0
#define TASK_SUSPEND	3

#endif
