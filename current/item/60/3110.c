
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit ARMOR;

// ��������������
int get_family() { return 3; }

// ���������촦��
void create()
{
        set_name("��������");
        set_picid_1(6042);
        set_picid_2(6042);

        set_level(110);
        set_value(64500);
        set_max_lasting(34599);
        set("dp", 258);
        set("pp", 156);

        setup();

        set_gender(1);
        set_armor_code(8);
}

// ��������ȡ����
string get_desc()
{
        return "��������";
}
