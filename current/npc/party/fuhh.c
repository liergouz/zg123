
#include <npc.h>
#include <ansi.h>

inherit OFFICER;

// ��������ȡ��������
int get_char_picid() { return 8112; }

// ���������촦��
void create()
{
        set_name("������");
        setup();
}

// �������Ի�����
void do_look( object who )
{
	string result,cmd;
	int i=random(8);
        switch(i)
        {
	        case 0:
			cmd="������������������ů�͡���";
		break;
	        case 1:
			cmd="���������������굽�����������������֡���";
		break;
	        case 2:
			cmd="���������������굽�ˡ����Ͽ�ȥ����үү������ȡ����ɡ���";
		break;
		case 3:
			cmd="���������������굽�������󣬴��ҲӦ�ÿ������ġ���";
		break;
		case 4:
			cmd="�������������Һÿ���Ŷ����";
		break;
		case 5:
			cmd="�������������������긣�����еĸ����������ֹ۵ĸ���������^_^��";
		break;
		case 6:
			cmd="�������������ˡ��С����������롫�ϣ��¡��С������硫�С�ȱ����������";
		break;
		case 7:
			cmd="���������������굽�ˣ�������ѹ��Ǯ����";
		break;
	}
        result = get_name() + "��\n    "+cmd+"\n"+
       		ESC "ȷ��\nCLOSE\n";
        send_user( who, "%c%c%w%s", ':', 3, 8112, result );  
}

