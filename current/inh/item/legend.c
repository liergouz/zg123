#include <ansi.h>
#include <task.h>

int is_legend_item() { return 1;}
//��ִ��ITEM��RESET
void reset() {}
//
int is_usable() { return 1; }
// ������ʹ��Ч��
int get_use_effect( object me ) 
{
	return TASK_LEGEND_D->use_legend_item(me,this_object());	
}