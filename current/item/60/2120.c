
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit ARMOR;

// ��������������
int get_family() { return 2; }

// ���������촦��
void create()
{
        set_name("��������");
        set_picid_1(6062);
        set_picid_2(6062);

        set_level(120);
        set_value(71500);
        set_max_lasting(37599);
        set("dp", 275);
        set("pp", 175);

        setup();

        set_gender(1);
        set_armor_code(8);
}

// ��������ȡ����
string get_desc()
{
        return "��������";
}
