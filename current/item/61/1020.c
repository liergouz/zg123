
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit ARMOR;

// ��������������
int get_family() { return 1; }

// ���������촦��
void create()
{
        set_name("Ƥȹ");
        set_picid_1(6134);
        set_picid_2(6134);

        set_level(20);
        set_value(2500);
        set_max_lasting(8499);
        set("dp", 55);
        set("pp", 32);

        setup();

        set_gender(2);
        set_armor_code(21);
}

// ��������ȡ����
string get_desc()
{
        return "Ƥȹ";
}
