
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit ARMOR;

// ��������������
int get_family() { return 5; }

// ���������촦��
void create()
{
        set_name("�������");
        set_picid_1(6140);
        set_picid_2(6140);

        set_level(70);
        set_value(38500);
        set_max_lasting(10899);
        set("dp", 97);
        set("pp", 175);

        setup();

        set_gender(2);
        set_armor_code(25);
}

// ��������ȡ����
string get_desc()
{
        return "�������";
}
