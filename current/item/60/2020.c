
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit ARMOR;

// ��������������
int get_family() { return 2; }

// ���������촦��
void create()
{
        set_name("������");
        set_picid_1(6060);
        set_picid_2(6060);

        set_level(20);
        set_value(2500);
        set_max_lasting(8499);
        set("dp", 55);
        set("pp", 35);

        setup();

        set_gender(1);
        set_armor_code(1);
}

// ��������ȡ����
string get_desc()
{
        return "������";
}
