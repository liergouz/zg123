
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit ARMOR;

// ��������������
int get_family() { return 4; }

// ���������촦��
void create()
{
        set_name("��������");
        set_picid_1(6140);
        set_picid_2(6140);

        set_level(70);
        set_value(30000);
        set_max_lasting(24099);
        set("dp", 142);
        set("pp", 95);

        setup();

        set_gender(2);
        set_armor_code(25);
}

// ��������ȡ����
string get_desc()
{
        return "��������";
}
