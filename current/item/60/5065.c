
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit ARMOR;

// ��������������
int get_family() { return 5; }

// ���������촦��
void create()
{
        set_name("��������");
        set_picid_1(6074);
        set_picid_2(6074);

        set_level(65);
        set_value(34500);
        set_max_lasting(10299);
        set("dp", 91);
        set("pp", 163);

        setup();

        set_gender(1);
        set_armor_code(5);
}

// ��������ȡ����
string get_desc()
{
        return "��������";
}
