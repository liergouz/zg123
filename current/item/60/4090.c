
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit ARMOR;

// ��������������
int get_family() { return 4; }

// ���������촦��
void create()
{
        set_name("��������");
        set_picid_1(6040);
        set_picid_2(6040);

        set_level(90);
        set_value(42000);
        set_max_lasting(31599);
        set("dp", 167);
        set("pp", 123);

        setup();

        set_gender(1);
        set_armor_code(6);
}

// ��������ȡ����
string get_desc()
{
        return "��������";
}
