
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit WAIST;

// ��������������
int get_family() { return 4; }

// ���������촦��
void create()
{
        set_name("��Ƥ����");
        set_picid_1(8705);
        set_picid_2(8705);

        set_level(65);
        set_value(13750);
        set_max_lasting(8599);
        set("dp", 55);
        set("pp", 55);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��Ƥ����";
}
