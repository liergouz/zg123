
// �Զ����ɣ�/make/npc/make0007

#include <npc.h>
#include <cmd.h>

inherit OFFICER;

// ����������ʦ��
int is_repairer() { return 1; }

// ��������ȡ��������
int get_char_picid() { return 5407; }

// ���������촦��
void create()
{
        set_name("������ϰ�");
	set_real_name("���");
        set_city_name("�ع�");

        setup();
}

// �������Ի�����
void do_look( object who )
{
	"/quest/help"->send_help_tips(who, 52);
        REPAIR_CMD->main( who, sprintf( "%x#", getoid( this_object() ) ) );
}
