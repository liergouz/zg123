
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit ARMOR;

// ��������������
int get_family() { return 8; }

// ���������촦��
void create()
{
        set_name("�޲���");
        set_picid_1(6003);
        set_picid_2(6003);

        set_level(10);
        set_value(1200);
        set_max_lasting(4599);
        set("dp", 19);
        set("pp", 0);

        setup();

        set_gender(1);
        set_armor_code(0);
}

// ��������ȡ����
string get_desc()
{
        return "�޲���";
}
