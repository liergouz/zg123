
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit ARMOR;

// ��������������
int get_family() { return 1; }

// ���������촦��
void create()
{
        set_name("̤����ȹ");
        set_picid_1(6154);
        set_picid_2(6154);

        set_level(50);
        set_value(20500);
        set_max_lasting(16599);
        set("dp", 121);
        set("pp", 74);

        setup();

        set_gender(2);
        set_armor_code(23);
}

// ��������ȡ����
string get_desc()
{
        return "̤����ȹ";
}
