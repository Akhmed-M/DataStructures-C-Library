#include "../Stack.c"

/*---------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------*/
// PROTO-TYPES

int Reverse(stack *s);
int InsertBottom(stack *s, element e);

/*---------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------*/

int Reverse(stack *s)
{
    if (isEmptyStack(*s))
        return 0;
    // REMOVE TOP & STORE IT IN A TEMP VARIABLE
    element temp;
    Top(*s, &temp);
    Pop(s);

    // KEEP REMOVING TILL EMPTY
    Reverse(s);

    // WILL START WITH INTIAL BOTTOM, THEN EACH ELEMENT WILL BE ADDED BELOW IT
    InsertBottom(s, temp);
    return 1;
}

int InsertBottom(stack *s, element e)
{
    if (isEmptyStack(*s))
        return Push(s, e);
    // REMOVE TOP & STORE IT IN A TEMP VARIABLE
    element temp;
    Top(*s, &temp);
    Pop(s);

    // KEEP REMOVING TILL EMPTY => PUSH AT BOTTOM
    InsertBottom(s, e);

    // RESTORE CONTENT
    Push(s, temp);
    return 1;
}

/*---------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------*/
