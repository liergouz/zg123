
// �Զ����ɣ�/make/npc/make0002

#include <npc.h>
#include <cmd.h>

inherit OFFICER;

// ������С��ʶ��
int is_seller() { return 1; }

// ��������ȡ��������
int get_char_picid() { return %04d; }

// ���������촦��
void create()
{
        set_name("%s");
        set_city_name("%s");

        set_2( "good", ([
%s
        ]) );

        setup();
}
