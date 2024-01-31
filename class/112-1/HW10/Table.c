#include <stdio.h>
#include <stdlib.h>
#include "function.h"
#define TABLE_COUNT 50
#define GUEST_COUNT 50
#define OPEN_TIME 660
#define CLOSE_TIME 900

Table *table[TABLE_COUNT];
Guest *guest[GUEST_COUNT];
int tableCount, guestCount;
int currentGuest = 0;

void tableStatus(int time) {
    printf("%02d:%02d (%d) -> table: |", time/60, time%60, time);
    for (int i=0; i<tableCount; i++) {
        if (table[i]->guest) printf("%s(%dmin)", table[i]->guest->guestName, table[i]->leaveTime-time);
        printf("|");
    }
    printf("\n");
}

int main() {
    scanf("%d", &tableCount);
    for (int i=0; i<tableCount; i++) table[i] = createTable();
    //for (int i=0; i<tableCount; i++) printf("%d ",table[i]->tableSize);
    scanf("%d", &guestCount);
    for (int i=0; i<guestCount; i++) guest[i] = createGuest();
    //for (int i=0; i<guestCount; i++) printf("%s %d %d %d\n",guest[i]->guestName,guest[i]->groupSize,guest[i]->arriveTime,guest[i]->diningTime);
    for (int i=OPEN_TIME; i<=CLOSE_TIME; i++) {
        while (1) {
            Guest *leave = checkLeave(table, tableCount, i);
            if (!leave) break;
            printf("%02d:%02d (%d) -> %s: leave\n", i/60, i%60, i, leave->guestName);
        }
        while (currentGuest < guestCount && guest[currentGuest]->arriveTime <= i) {
            int success = assignTable(table, tableCount, i, guest[currentGuest]);
            if (!success) break;
            printf("%02d:%02d (%d) -> %s: enter\n", i/60, i%60, i, guest[currentGuest]->guestName);
            currentGuest++;
        }
        if (i % 60 == 0) tableStatus(i);
    }
}

Table* createTable()
{
    Table* temp_table=malloc(sizeof(Table));
    scanf("%d",&temp_table->tableSize); temp_table->guest=NULL; temp_table->leaveTime=0;
    return temp_table;
}

Guest* createGuest()
{
    Guest* temp_guest=malloc(sizeof(Guest)); temp_guest->guestName=malloc(sizeof(char)*15);
    scanf(" %s",temp_guest->guestName); scanf("%d",&temp_guest->groupSize); scanf("%d",&temp_guest->arriveTime); scanf("%d",&temp_guest->diningTime);
    return temp_guest;
}

Guest* checkLeave(Table **table, int tableCount, int currentTime)
{
    for(int i=0;i<tableCount;i++)
    {
        if(table[i]->leaveTime==currentTime)
        {
            Guest* temp=table[i]->guest;
            table[i]->leaveTime=0; table[i]->guest=NULL; return temp;
        }
    }
    return NULL;
}

int assignTable(Table **table, int tableCount, int currentTime, Guest *guest)
{
    for(int i=0;i<tableCount;i++)
    {
        if(table[i]->leaveTime==0&&table[i]->tableSize>=guest->groupSize)
        {
            table[i]->guest=guest,table[i]->leaveTime=currentTime+guest->diningTime;
            return 1;
        }
    }
    return 0;
}