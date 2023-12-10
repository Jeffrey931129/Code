#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contestant;
typedef void (*Attack)(struct Contestant*, struct Contestant*);

struct Contestant
{
    char name[100];
    int health;
    int strength;
    int magic;
    int defense;
    int resistance;
    Attack attackType;
};

void magicalAttack(struct Contestant* self, struct Contestant* target);
void physicalAttack(struct Contestant* self, struct Contestant* target);
void getContestants(struct Contestant* contestants, int len);
int findTarget(struct Contestant* contestants, int idx, int len);

int main()
{
    struct Contestant contestants[105];

    int num;

    scanf("%d", &num);

    getContestants(contestants, num);

    int idx = 0;
    int temp = 0;
    while(1)
    {
        if(contestants[idx].health <= 0)
        {
            idx = (idx + 1) % num;
            continue;
        }

        int targetIndex = findTarget(contestants, idx, num);

        if(targetIndex == idx)
        {
            break;
        }

        contestants[idx].attackType(&contestants[idx], &contestants[targetIndex]);

        idx = (idx + 1) % num;
    }

    printf("%s wins the tournament\n", contestants[idx].name);

    return 0;
}

void getContestants(struct Contestant* contestants, int len)
{
    for(int i=0;i<len;i++)
    {
        scanf(" %s",contestants[i].name); scanf("%d",&contestants[i].health); scanf("%d",&contestants[i].strength); scanf("%d",&contestants[i].magic); scanf("%d",&contestants[i].defense); scanf("%d",&contestants[i].resistance); 
        char temp[20]; scanf(" %s",temp); 
        if(strcmp(temp,"physical")==0) contestants[i].attackType=physicalAttack;
        else contestants[i].attackType=magicalAttack; 
    }
}

int findTarget(struct Contestant* contestants, int idx, int len)
{
    for(int i=0;i<len;i++)
    {
        idx=(idx+1)%len;
        if(contestants[idx].health<= 0)
        {
            continue;
        }
        else
        {
            return idx;
        }
    }
    return idx;
}

void magicalAttack(struct Contestant* self, struct Contestant* target)
{
    int damage=self->magic-target->resistance;
    target->health-=damage;
    return;
}

void physicalAttack(struct Contestant* self, struct Contestant* target)
{
    int damage=self->strength-target->defense;
    target->health-=damage;
    return;
}