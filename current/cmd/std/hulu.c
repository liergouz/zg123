/**************
    ������«
***************/
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
	case 0:					//��ȡ�����«��Ϣ
		"npc/std/0003"->do_info(me);		
		break;
	case 1:					//ͬ���μ���
		"npc/std/0003"->do_agend(me);
		break;
	case 2:					//�߼��μ���
		"npc/std/0003"->do_advance_agend(me);
		break;	
	case 3:					//ȡ��
		"npc/std/0003"->take_back(me);
		break;
	case 4:					//��ȡ��«
		"npc/std/0003"->pick_hulu(me,nTmp[1]);
		break;
	case 5:					//��չ��«
		"npc/std/0003"->do_expand(me);
		break;
	case 6:					//��ȡ����
		"npc/std/0003"->do_welcome("3");
		break;
	case 7:					//�黹��«
		"npc/std/0003"->return_hulu(me);
		break;
	case 8:					//��«�б�
		"npc/std/0003"->send_info(me);
		break;
	case 9:
		"npc/std/0003"->get_exp(me);
		break;
	case 99:
		if ( is_god(me) )
			"npc/std/0003"->set_exp(me,nTmp[1],to_int(nTmp[2]));
		break;
	}
}