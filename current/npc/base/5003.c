
// �Զ����ɣ�/make/npc/make0002

#include <npc.h>
#include <cmd.h>

inherit OFFICER;

// ������С��ʶ��
int is_seller() { return 6; }

// ��������ȡ��������
int get_char_picid() { return 5403; }

// ���������촦��
void create()
{
        set_name("ҩ���ϰ�");
	set_real_name("ҽ��");
        set_city_name("�ع�");

        set_2( "good", ([
                "01" : "/item/91/9100",
                "02" : "/item/91/9101",
                "03" : "/item/91/9110",
                "04" : "/item/91/9111",
                "05" : "/item/stuff/0106",
        ]) );

        setup();
}
