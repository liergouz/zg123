
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit ARMOR;

// ��������������
int get_family() { return 1; }

// ���������촦��
void create()
{
        set_name("������");
        set_picid_1(6078);
        set_picid_2(6078);

        set_level(55);
        set_value(24500);
        set_max_lasting(18099);
        set("dp", 132);
        set("pp", 81);

        setup();

        set_gender(1);
        set_armor_code(4);
}

// ��������ȡ����
string get_desc()
{
        return "������";
}
