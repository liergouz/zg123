
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit ARMOR;

// ��������������
int get_family() { return 3; }

// ���������촦��
void create()
{
        set_name("ս������");
        set_picid_1(6140);
        set_picid_2(6140);

        set_level(65);
        set_value(32500);
        set_max_lasting(21099);
        set("dp", 159);
        set("pp", 93);

        setup();

        set_gender(2);
        set_armor_code(25);
}

// ��������ȡ����
string get_desc()
{
        return "ս������";
}
