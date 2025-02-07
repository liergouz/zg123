
#include <ansi.h>
#include <skill.h>
#include <action.h>
#include <effect.h>

// º¯Êı£ºÃüÁî´¦Àí
int reset( )
{
        int i, size, j;	
	object * temp;
	string arg;
	remove_call_out("reset");
	for (i = 1;i<=7;i++)
	{
		arg = sprintf("/npc/base/%d", i*1000+20);
		temp = children(arg);
		size = sizeof(temp);
		if (size>0)
		{
			for (j=0;j<size;j++)
			{
				if (objectp(temp[j])) temp[j]->reset();
			}
		}
	}	        		
	call_out("reset",600);   		
}
