
// �Զ����ɣ�/make/npc/make0007

#include <npc.h>
#include <cmd.h>

inherit OFFICER;

// ����������ʦ��
int is_repairer() { return 1; }

// ��������ȡ��������
int get_char_picid() { return %04d; }

// ���������촦��
void create()
{
        set_name("%s");
        set_city_name("%s");

        setup();
}

// �������Ի�����
void do_look( object who )
{
        REPAIR_CMD->main( who, sprintf( "%%x#", getoid( this_object() ) ) );
}
