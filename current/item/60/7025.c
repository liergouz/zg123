
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit ARMOR;

// ��������������
int get_family() { return 7; }

// ���������촦��
void create()
{
        set_name("������");
        set_picid_1(6074);
        set_picid_2(6074);

        set_level(25);
        set_value(3500);
        set_max_lasting(5499);
        set("dp", 46);
        set("pp", 70);

        setup();

        set_gender(1);
        set_armor_code(1);
}

// ��������ȡ����
string get_desc()
{
        return "������";
}
