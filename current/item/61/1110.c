
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit ARMOR;

// ��������������
int get_family() { return 1; }

// ���������촦��
void create()
{
        set_name("����ս��");
        set_picid_1(6162);
        set_picid_2(6162);

        set_level(110);
        set_value(64500);
        set_max_lasting(34599);
        set("dp", 253);
        set("pp", 158);

        setup();

        set_gender(2);
        set_armor_code(28);
}

// ��������ȡ����
string get_desc()
{
        return "����ս��";
}
