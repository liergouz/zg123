
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit ARMOR;

// ��������������
int get_family() { return 1; }

// ���������촦��
void create()
{
        set_name("̤����");
        set_picid_1(6058);
        set_picid_2(6058);

        set_level(50);
        set_value(20500);
        set_max_lasting(16599);
        set("dp", 121);
        set("pp", 74);

        setup();

        set_gender(1);
        set_armor_code(3);
}

// ��������ȡ����
string get_desc()
{
        return "̤����";
}
