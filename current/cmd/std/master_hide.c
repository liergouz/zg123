/******************
    师门隐藏任务
*******************/
#include <ansi.h>
#include <item.h>
#include <city.h>

// 函数：命令处理
int main( object me, string arg )
{
	string *nTmp;
        if( !arg ) return 1;
	nTmp = explode(arg," ");
	switch(to_int(nTmp[0]))
	{
	default:
		break;
	case 0:					
		if (me->get("m_hide")==1)
		{
			send_user(me,"%c%s",'!',"你领取了师门隐藏任务");
			"sys/task/master"->hide_quest(me);		
		}
		break;
	case 1:					
		send_user(me,"%c%s",'!',"你放弃了师门隐藏任务");
		me->delete("m_hide");
		break;
	}
}