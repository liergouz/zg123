/******************
    ʦ����������
*******************/
#include <ansi.h>
#include <item.h>
#include <city.h>

// �����������
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
			send_user(me,"%c%s",'!',"����ȡ��ʦ����������");
			"sys/task/master"->hide_quest(me);		
		}
		break;
	case 1:					
		send_user(me,"%c%s",'!',"�������ʦ����������");
		me->delete("m_hide");
		break;
	}
}