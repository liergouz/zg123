
// �Զ����ɣ�/make/npc/make0001

#include <npc.h>
#include <cmd.h>

inherit OFFICER;

// �����������ϰ�
int is_banker() { return 1; }

// ��������ȡ��������
int get_char_picid() { return 5301; }

// ���������촦��
void create()
{
        set_name("�����ϰ�");
        set_real_name("�ֿ����Ա");

        setup();
}

// �������Ի�����
void do_look( object who )
{
	"/quest/help"->send_help_tips(who, 4);
        PAWN_CMD->main( who, sprintf( "%x# %d", getoid( this_object() ), 0 ) );    // who->get("pawn#") + 1
}
